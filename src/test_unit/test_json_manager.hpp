#include "../data_models/data_models.hpp"

/*
    This file is intended for unit-testing of JsonManager class, methods and features.
*/

// namespace TestUnitJsonManager

namespace UnitTests
{
    namespace JsonManagerTest
    {
        void testToJson()
        {
            std::cout << "UNIT TEST:\n JSON MANAGER TEST TO JSON" << std::endl;

            DataModels::User u = {"user1", "pass1", DataModels::UserType::ADMIN};

            for (unsigned int i = 0; i < 5; i++)
            {
                u.data.push_back(DataModels::UserData{
                    i,
                    "name",
                    "value",
                });
            }

            json j = u;

            std::cout << std::setw(4) << j << std::endl
                      << std::endl;

            DataModels::User u2 = j.get<DataModels::User>();
            json j2 = u2;
            std::cout << std::setw(4) << j2 << std::endl;
        }
    }
}