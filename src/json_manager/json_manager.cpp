#include "json_manager.h"

std::string JsonManager::homeDir = "";

JsonManager::JsonManager()
{
}

JsonManager::~JsonManager()
{
}

void JsonManager::setHomeDir(const std::string &path)
{
    if (!path.empty() > 0)
        homeDir = path;
}

void JsonManager::readJSON(const std::string &path)
{
    std::ifstream f(path);
    json data = json::parse(f);
    std::cout << std::setw(4) << data << std::endl;

    // UserType t = UserType::ADMIN;

    // switch (t)
    // {
    // case UserType::ADMIN:
    //     std::cout << "kaef\n";
    //     break;
    // case UserType::CHELYAD:
    //     std::cout << "ne kaef\n";
    //     break;

    // default:
    //     break;
    // }

    User dbg_user = {data["username"], data["pass"], data["type"]};

    std::cout << dbg_user.username << "\t" << dbg_user.pass << std::endl;

    switch (dbg_user.type)
    {
    case UserType::ADMIN:
        std::cout << "ADMIN" << std::endl;
        break;

    case UserType::CHELYAD:
        std::cout << "CHELYAD" << std::endl;
        break;
    default:
        break;
    }

    dbg_user.data.push_back(StoredPassword{"SUPER PAROL", "12345"});

    f.close();
}