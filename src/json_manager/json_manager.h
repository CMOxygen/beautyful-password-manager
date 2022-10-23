#include <string>
#include <iostream>
#include <fstream>
#include <vector>

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

    static void setHomeDir(const std::string &path);

    inline static std::string getHomeDir() { return homeDir; }

    static void readJSON(const std::string &path);
};