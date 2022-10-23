#include "json_manager/json_manager.h"

#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char **argv)
{
    system("chcp 1251");
    std::cout << "hw\n";

    std::string homeDir(argv[0]);
    int pos = homeDir.find_last_of('\\');
    homeDir = homeDir.substr(0, pos + 1);

    std::cout << homeDir << std::endl;
    // std::cout << homeDir.erase(pos + 1, homeDir.length()) << std::endl;

    JsonManager::setHome(homeDir);
    std::cout << JsonManager::home() << std::endl;

    JsonManager::JsonManagerTest();
}