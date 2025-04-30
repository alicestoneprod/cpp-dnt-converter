#pragma once
#include <cstdint>   
#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>


using namespace std;

enum ColumnType
{
    TEXT = 1,
    UINT_32 = 2,
    INT32 = 3,
    FLOAT = 4,
    DOUBLE = 5,
    FLOAT64 = 6,
};

struct EtString
{
    uint16_t length;
    vector<char> name;
};

struct Column
{
    EtString et_string;
    uint32_t type;
};

struct Header
{
    uint32_t magic;
    uint16_t columns_count;
    uint32_t rows_count;
};

struct Dnt
{
    Header header;
    vector<Column> columns_data;
};