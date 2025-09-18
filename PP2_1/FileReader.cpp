#include <fstream>
#include <sstream>

#include "FileReader.h"

FileReader::FileReader(const std::string& path)
    : filePath(path)
{
}

TaskData FileReader::ReadTaskData() const
{
    TaskData res;

    std::ifstream file(filePath);
    if (!file.is_open())
    {
        throw std::invalid_argument("File \"" + filePath + "\" is not open.");
    }

    auto isNCountLine = true;

    std::string line;
    while (std::getline(file, line))
    {
        std::istringstream iss(line);

        auto isLineCorrect = false;

        if (isNCountLine)
        {
            isNCountLine = false;

            isLineCorrect = static_cast<bool>(iss >> res.N);
            if (isLineCorrect)
            {
                std::string extra;
                isLineCorrect = !static_cast<bool>(iss >> extra);
            }
        }
        else
        {
            Data data;
            isLineCorrect = static_cast<bool>(iss >> data.Value >> data.Freq);

            if (isLineCorrect)
            {
                std::string extra;
                isLineCorrect = !static_cast<bool>(iss >> extra);
                if (isLineCorrect)
                {
                    res.Distribution.push_back(data);
                }
            }
        }

        if (!isLineCorrect)
        {
            throw std::invalid_argument("Wrong file format.");
        }
    }

    return res;
}
