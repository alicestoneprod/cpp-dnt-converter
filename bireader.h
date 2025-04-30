#pragma once
#include <cstdint>
#include <fstream>
#include <vector>

class bireader
{
public:
    
    int32_t read_int_32(std::ifstream& stream) {
        int32_t value = 0;
        stream.read(reinterpret_cast<char*>(&value), sizeof(value));
        return value;
    }

    int16_t read_int_16(std::ifstream& stream)
    {
        int16_t value = 0;
        stream.read(reinterpret_cast<char*>(&value), sizeof(value));
        return value;
    }

    uint32_t read_uint_32(std::ifstream& stream)
    {
        uint32_t value = 0;
        stream.read(reinterpret_cast<char*>(&value), sizeof(value));
        return value;
    }

    uint16_t read_uint_16(std::ifstream& stream)
    {
        uint16_t value = 0;
        stream.read(reinterpret_cast<char*>(&value), sizeof(value));
        return value;
    }

    uint8_t read_uint8(std::ifstream& stream)
    {
        uint8_t value = 0;
        stream.read(reinterpret_cast<char*>(&value), sizeof(value));
        return value;
    }


    float_t read_float(std::ifstream& stream)
    {
        float value = 0;
        stream.read(reinterpret_cast<char*>(&value), sizeof(value));
        return value;
    }

    std::vector<char> read_buffer(std::ifstream& stream, const int length)
    {
        std::vector<char> buffer(length);
        stream.read(buffer.data(), length);
        return buffer;
    }

    double_t read_dobule(std::ifstream& stream)
    {
        double value = 0;
        stream.read(reinterpret_cast<char*>(&value), sizeof(value));
        return value;
    }
    
    
};

