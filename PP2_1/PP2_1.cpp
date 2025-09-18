#include <iostream>
#include <string>

#include "Data.h"
#include "FileReader.h"
#include "Generator.h"

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
        auto data = dataReader.ReadTaskData();

        Generator gen(data.Distribution);

        std::vector<int> generatedValues;
        for (int n = 0; n < data.N; n++)
        {
           generatedValues.push_back(gen());
        }
    }
    catch (std::exception ex)
    {
        std::cout << std::endl;
        std::cout << "Error:" << ex.what();
    }
}
