#pragma once
#include <cstdint>
#include <fstream>
#include <vector>

class bireader
{
public:
    
    int32_t readInt32(std::ifstream& stream) {
        int32_t value = 0;
        stream.read(reinterpret_cast<char*>(&value), sizeof(value));
        return value;
    }

    int16_t readInt16(std::ifstream& stream)
    {
        int16_t value = 0;
        stream.read(reinterpret_cast<char*>(&value), sizeof(value));
        return value;
    }

    uint32_t readUInt32(std::ifstream& stream)
    {
        uint32_t value = 0;
        stream.read(reinterpret_cast<char*>(&value), sizeof(value));
        return value;
    }

    uint16_t readUInt16(std::ifstream& stream)
    {
        uint16_t value = 0;
        stream.read(reinterpret_cast<char*>(&value), sizeof(value));
        return value;
    }

    uint8_t readUInt8(std::ifstream& stream)
    {
        uint8_t value = 0;
        stream.read(reinterpret_cast<char*>(&value), sizeof(value));
        return value;
    }


    float_t readFloat(std::ifstream& stream)
    {
        float value = 0;
        stream.read(reinterpret_cast<char*>(&value), sizeof(value));
        return value;
    }

    std::vector<char> readBuffer(std::ifstream& stream, const int length)
    {
        std::vector<char> buffer(length);
        stream.read(buffer.data(), length);
        return buffer;
    }

    double_t readDouble(std::ifstream& stream)
    {
        double value = 0;
        stream.read(reinterpret_cast<char*>(&value), sizeof(value));
        return value;
    }
    
    
};

