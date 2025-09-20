#pragma once
#include <iostream>
#include <unordered_map>

#include "Data.h"
using namespace std;

class Analyzer
{
    const std::vector<Data>& distribution1;
public:
    Analyzer(const std::vector<Data>& distribution) : distribution1(distribution) {}

    std::vector<DataResult> operator()(const std::vector<int>& generatedSequence) const;
};