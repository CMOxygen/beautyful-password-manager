#include "../json_manager/json_manager.h"

namespace UnitTests
{
    // namespace DataModelsTest
    // {
    //     void test()
    //     {
    //         std::cout << "Testing" << std::endl;
    //     }
    // }
}

namespace DataModels
{
    enum class UserType
    {
        ADMIN,
        CHELYAD
    };

    NLOHMANN_JSON_SERIALIZE_ENUM(UserType, {
                                               {UserType::ADMIN, "ADMIN"},
                                               {UserType::CHELYAD, "CHELYAD"},
                                           })

    struct UserData
    {
        unsigned int id;
        std::string name;
        std::string value;
    };

    struct User
    {
        std::string username;
        std::string pass;
        UserType type;

        std::vector<UserData> data;
    };

    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(UserData, id, name, value);
    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(User, username, pass, type, data);
};