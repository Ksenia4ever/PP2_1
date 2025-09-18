#pragma once

#include <vector>

struct Data
{
    int Value = 0;
    double Freq = 1;
};

struct DataResult : public Data
{
    double RealFreq = 1;
    double Delta = 0;
};

struct TaskData
{
    int N = 0;
    std::vector<Data> Distribution;
};
