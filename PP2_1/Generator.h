#pragma once

#include <random>
#include <vector>

#include "Data.h"


class Generator
{
public: 

	Generator(const std::vector<Data>& distribution);

	int operator()();

private:
	std::vector<int> values;
	std::vector<double> weights;

	std::mt19937 gen;
	std::discrete_distribution<size_t> disc_distr;
};

