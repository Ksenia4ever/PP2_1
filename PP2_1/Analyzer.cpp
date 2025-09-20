#include "Analyzer.h"

std::vector<DataResult> Analyzer::operator()(const std::vector<int>& generatedSequence) const {
    std::unordered_map<int, int> realFreq;
    std::vector<DataResult> result;
    for (size_t i = 0; i < generatedSequence.size(); i++) {
        ++realFreq[generatedSequence[i]];
    }
    for (size_t i = 0; i < distribution1.size(); i++) {
        DataResult num;
        num.Value = distribution1[i].Value;
        num.Freq = distribution1[i].Freq;
        num.RealFreq = realFreq[num.Value];
        num.Delta = num.Freq - num.RealFreq;
        result.push_back(num);
    }
    return result;
}