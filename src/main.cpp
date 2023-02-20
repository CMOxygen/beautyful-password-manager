#include "test_unit/test_json_manager.hpp"
// #include "user_service/user_service.h"

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
    std::cout << JsonManager::getHome() << std::endl;

    UnitTests::JsonManagerTest::testToJson();
}