#include <cmath>
#include <unordered_map>

#include "Analyzer.h"

Analyzer::Analyzer(const std::vector<Data>& distribution) 
    : distr(distribution) 
{
}

std::vector<DataResult> Analyzer::operator()(const std::vector<int>& generatedSequence) const
{
    std::unordered_map<int, double> realFreq;

    for(const auto& value : generatedSequence)
    {
        auto it = realFreq.find(value);

        if (it == realFreq.end())
        {
            realFreq[value] = 1;
        }
        else
        {
            it->second++;
        }
    }

    double absoluteWeight = 0;
    for (const auto& data : distr)
    {
        absoluteWeight += data.Freq;
    }

    for (auto& kvp : realFreq)
    {
        kvp.second /= generatedSequence.size();
        kvp.second *= absoluteWeight;
    }

    std::vector<DataResult> result;

    for (const auto& data : distr)
    {
        DataResult res;
        res.Value = data.Value;
        res.Freq = data.Freq;
        res.RealFreq = realFreq[res.Value];
        res.Delta = std::abs(res.Freq - res.RealFreq);

        result.push_back(res);
    }

    return result;
}