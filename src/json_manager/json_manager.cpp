#include "json_manager.h"

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

void JsonManager::JsonManagerTest()
{
    std::string path = JsonManager::home() + "/data/dbg_user.json";
    if (JsonManager::fileExists(path))
    {
        User u = JsonManager::jsonToUser(JsonManager::readFile(path));
        u.data.push_back(StoredPassword{"pass", "qwerty12345"});

        JsonManager::inFile(path, JsonManager::userToJson(u));
    }
}

bool JsonManager::fileExists(const std::string &path)
{
    struct stat buffer;
    return (stat(path.c_str(), &buffer) == 0);
}

User JsonManager::jsonToUser(const json in)
{
    User u = {in["username"], in["pass"], in["type"], std::vector<StoredPassword>()};

    for (auto p : in["data"])
    {
        u.data.push_back(StoredPassword{p["name"], p["value"]});
    }
    return u;
}

json JsonManager::userToJson(const User u)
{
    json data = {
        {"username", u.username},
        {"pass", u.pass},
        {"type", u.type},
    };

    for (int i = 0; i < u.data.size(); i++)
    {
        data["data"][i] = {
            {"name", u.data[i].name},
            {"value", u.data[i].value}};
    }
    return data;
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