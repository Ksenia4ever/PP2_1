#pragma once

#include <vector>

struct Data
{
    int Value = 0;
    int Freq = 1;
};

struct DataResult : public Data
{
    int RealFreq = 1;
    int Delta = 0;
};

struct TaskData
{
    int N = 0;
    std::vector<Data> Distribution;
};
