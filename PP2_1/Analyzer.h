#pragma once
#include <vector>

#include "Data.h"
using namespace std;

class Analyzer
{
public:
    Analyzer(const std::vector<Data>& distribution);

    std::vector<DataResult> operator()(const std::vector<int>& generatedSequence) const;

private:
    std::vector<Data> distr;
};