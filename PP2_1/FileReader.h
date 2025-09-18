#pragma once

#include <string>
#include "Data.h"

class FileReader
{
public:
    FileReader(const std::string& path);

    TaskData ReadTaskData() const;

private:
    std::string filePath;
};

