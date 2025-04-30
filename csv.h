#pragma once
#include "types.h"

class csv_file
{
public:
    ofstream stream;
    csv_file* get_instance ()
    {
        return this;
    }

    bool init (const string &path)
    {
        stream.open (path, ios::binary);

        if (!stream.is_open())
        {
            cout << "An error has occured while opening the file " << path << endl;
            return false;
        }

        return true;
    }
    
    void column_separate()
    {
        this->stream.write(",", 1);
    }

    void row_separate()
    {
        this->stream.write("\r\n", 2);
    }

    void write_string(const string &str)
    {
        this->stream.write(str.c_str(), str.size());
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

    std::ofstream& get_stream() {
        return this->stream;
    }

};