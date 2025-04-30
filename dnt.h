#pragma once
#include "types.h"
#include "bireader.h"
#include "csv.h"

class dnt_file
{
    
public:
    ifstream stream;
    
    dnt_file* get_instance ()
    {
        return this;
    }

    bool init (const string &path)
    {
        stream.open (path, ios::binary);

        if (!stream.is_open())
        {
            cout << "An error has occured while opening the file " << path << "\n";
            return false;
        }

        return true;
    }
    
    bool close()
    {
        this->stream.close();

        if (!stream.is_open())
        {
            return true;
        }

        return false;
    }

    void switch_and_write(Column* column, bireader* reader, ifstream& file, csv_file& csv)
    {
        switch (column->type)
        {
        case TEXT:
            {
                const uint16_t length = reader->read_uint_16(file);
                std::string name(length, '\0');
                file.read(&name[0], length);

                if (name.empty()) {
                    csv.write_string(" ");
                } else {
                    std::replace(name.begin(), name.end(), ',', '^');
                    csv.write_string(name);
                }
                break;
            }
        case UINT_32:
            {
                const uint32_t value = reader->read_int_32(file);
                csv.write_string(std::to_string(value));
                break;
            }
        case INT32:
            {
                const int32_t value = reader->read_int_32(file);
                csv.write_string(std::to_string(value));
                break;
            }
        case FLOAT:
        case DOUBLE:
            {
                const float value = reader->read_float(file);
                csv.write_string(std::to_string(value));
                break;
            }
        case FLOAT64:
            {
                const double value = reader->read_dobule(file);
                csv.write_string(std::to_string(value));
                break;
            }
        default:
            {
                std::cerr << "Unsupported type: " << column->type << std::endl;
                break;
            }
        }
    }

    std::ifstream& get_stream() {
        return this->stream;
    }

};