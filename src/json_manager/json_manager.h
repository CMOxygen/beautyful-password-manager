/*
    JsonManager class designed to realise store application data in JSON files.
    It represents API based on nlohmann/json library: https://github.com/nlohmann/json .

    Feature list:
        1. Convert object's data into json objects.
        2. Convert json objects into object's data.
        3. Write JSON files from json objects.
        4. Read JSON files to json objects.
*/

#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <sys/stat.h>
#include <algorithm>

#include "../../lib/nlohmann/json.hpp"

using json = nlohmann::json;

class JsonManager
{
    static std::string homeDir;

public:
    //  constructors/destructors
    JsonManager();
    ~JsonManager();

    //  getters/setters
    static void setHome(const std::string &path);
    inline static std::string getHome() { return homeDir; }

    // file IO methods
    static bool fileExists(const std::string &path);
    static json readFile(const std::string &path);
    static void inFile(const std::string &path, json tree);
};