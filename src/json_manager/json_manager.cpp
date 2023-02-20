#include "../data_models/data_models.hpp"

std::string JsonManager::homeDir = "";

JsonManager::JsonManager()
{
}

JsonManager::~JsonManager()
{
}

void JsonManager::setHome(const std::string &path)
{
    if (!path.empty() > 0)
        homeDir = path;
}

bool JsonManager::fileExists(const std::string &path)
{
    struct stat buffer;
    return (stat(path.c_str(), &buffer) == 0);
}

json JsonManager::readFile(const std::string &path)
{
    std::ifstream File(path);
    json data = json::parse(File);
    File.close();

    return data;
}

void JsonManager::inFile(const std::string &path, json tree)
{
    std::ofstream O_File(path);
    O_File << std::setw(4) << tree;
    O_File.close();
}