//
// Created by hagaivinik on 11/24/22.
//

#include "USocial.hpp"

#include "User.hpp"
#include "BusinessUser.hpp"

USocial::~USocial()
{
    // Delete all of the users.
    for (auto user : users)
    {
        if (user.second != nullptr)
        {
            auto* userPtr = user.second;
            delete userPtr;
        }
    }
}

User *USocial::getUserById(uint64_t id) const
{
    if (users.count(id))
    {
        return users.at(id);
    }

    return nullptr;
}

User *USocial::registerUser(const std::string& name, bool isBusiness)
{
    User* userPtr = nullptr;

    if (!isBusiness)
    {
        userPtr = new User();
    }
    else
    {
        userPtr = new BusinessUser();
    }

    userPtr->name = name;
    userPtr->us = this;

    users[userPtr->getId()] = userPtr;

    return userPtr;
}

void USocial::removeUser(User *userPtr)
{
    if( users.count(userPtr->id))
    {
        users.erase(userPtr->id);
    }
}
