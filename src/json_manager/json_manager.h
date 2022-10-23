#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <sys/stat.h>

#include "../../lib/nlohmann/json.hpp"

enum class UserType
{
    ADMIN,
    CHELYAD
};

NLOHMANN_JSON_SERIALIZE_ENUM(UserType, {{UserType::ADMIN, "ADMIN"},
                                        {UserType::CHELYAD, "CHELYAD"}})

struct StoredPassword
{
    std::string name;
    std::string value;
};

struct User
{
    std::string username;
    std::string pass;
    UserType type;

    std::vector<StoredPassword> data;
};

using json = nlohmann::json;

class JsonManager
{
    static std::string homeDir;

public:
    JsonManager();
    ~JsonManager();

    static void setHome(const std::string &path);

    inline static std::string home() { return homeDir; }

    static void JsonManagerTest();

    static bool fileExists(const std::string &path);

    static json readFile(const std::string &path);

    static void inFile(const std::string &path, json tree);

    static User jsonToUser(const json in);
    static json userToJson(const User u);
};