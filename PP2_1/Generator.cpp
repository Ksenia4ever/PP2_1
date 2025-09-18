#include "Generator.h"


Generator::Generator(const std::vector<Data>& distribution)
{
	for (auto data : distribution)
	{
		values.push_back(data.Value);
		weights.push_back(data.Freq);
	}

	gen = std::mt19937(std::random_device{}());
	disc_distr = std::discrete_distribution<size_t>(weights.begin(), weights.end());
}

int Generator::operator()()
{
	auto value_index = disc_distr(gen);
	auto value = values[value_index];

	return value;
}
