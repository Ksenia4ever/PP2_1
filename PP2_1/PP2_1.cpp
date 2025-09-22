// Visual Studio 2022
#include <iostream>
#include <string>

#include "Data.h"
#include "FileReader.h"
#include "Generator.h"
#include "Analyzer.h"

int main(int argc, char* argv[])
{
    try
    {
        std::string dataFilePath;

        if (argc < 2)
        {
            std::cout << "Enter data file path:";
            std::cin >> dataFilePath;
        }
        else
        {
            dataFilePath = std::string(argv[1]);
        }

        FileReader dataReader(dataFilePath);
        auto taskData = dataReader.ReadTaskData();

        Generator gen(taskData.Distribution);

        std::vector<int> generatedValues;
        for (int experiment = 0; experiment < taskData.ExperimentCount; experiment++)
        {
           generatedValues.push_back(gen());
        }

        Analyzer analyzer(taskData.Distribution);
        auto results = analyzer(generatedValues);

		for (const auto& res : results)
		{
            std::cout << res.Value << ", ";
            std::cout << res.Freq << ", ";
			std::cout << res.RealFreq << std::endl;
		}

        auto maxDelta = 0.0;
        for (const auto& res : results)
        {
            if (res.Delta > maxDelta)
            {
                maxDelta = res.Delta;
            }
        }
        std::cout <<"Max delta: " << maxDelta;
    }
    catch (std::exception ex)
    {
        std::cout << std::endl;
        std::cout << "Error:" << ex.what();
    }
}
