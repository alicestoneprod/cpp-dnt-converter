#include "types.h"
#include "bireader.h"
#include "csv.h"
#include "dnt.h"

int convert_dnt_to_csv(const string &path)
{
    auto* reader = new bireader();
    auto* dnt_f = new dnt_file();
    
    if (!dnt_f->init(path)) return 0;
    
        Dnt dnt_data;
        Header header;
        ifstream& dnt_f_stream_ptr = dnt_f->get_stream();

        header.magic = reader->read_int_32(dnt_f_stream_ptr);
        header.columns_count = reader->read_uint_16(dnt_f_stream_ptr) + 1;
        header.rows_count = reader->read_uint_32(dnt_f_stream_ptr);

        Column row_id_column;
        row_id_column.type = 3;
        row_id_column.et_string.name = vector<char>{'_', 'R', 'o', 'w', 'I', 'D'};
        row_id_column.et_string.length = 6;
        
        vector<Column> columns {row_id_column};
         
        for (uint16_t j = 0; j < header.columns_count - 1; j++)
        {
            Column column;
            EtString et_string;
            et_string.length = reader->read_uint_16(dnt_f_stream_ptr);
            et_string.name = reader->read_buffer(dnt_f_stream_ptr, et_string.length);
            column.type = reader->read_uint8(dnt_f_stream_ptr);
            column.et_string = et_string;
            columns.push_back(column);
        }

        auto* csv = new csv_file();
        
        const std::string from = ".dnt";
        const std::string to = ".csv";
        string output_name = path;
        size_t pos = output_name.rfind(from);
        if (pos != std::string::npos) {
            output_name.replace(pos, from.length(), to);
        }
        
        if (!csv->init(output_name)) return 0;
        
        for (uint16_t i = 0; i < header.columns_count;i++)
        {
           string column_type = std::to_string(columns[i].type);
            csv->write_string(column_type);
            if (i < header.columns_count - 1)
            {
                csv->column_separate();
            }
        }

        csv->row_separate();

        for (uint16_t i = 0; i < header.columns_count; i++)
        {
            std::string name(columns[i].et_string.name.begin(), columns[i].et_string.name.end());
            csv->write_string(name);
            if (i < header.columns_count - 1)
            {
                csv->column_separate();
            }
        }

        csv->row_separate();
        for (uint32_t i = 0; i < header.rows_count; i++)
        {
            for (uint16_t j = 0; j < header.columns_count; j++)                
            {
                dnt_f->switch_and_write(&columns[j], reader, dnt_f_stream_ptr, *csv);
                if (j < header.columns_count - 1)
                    csv->column_separate();
                else
                    csv->row_separate();
            }
        }
        dnt_f->close();
        csv->close();

        return 0;
}

int main(int argc, char* argv[])
{
    char* input_file_name = argv[1];

    if (!input_file_name) return 0;

    convert_dnt_to_csv(string(input_file_name));
}
    

