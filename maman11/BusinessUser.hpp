//
// Created by hagaivinik on 11/22/22.
//

#ifndef MAMAN11_BUSINESSUSER_HPP
#define MAMAN11_BUSINESSUSER_HPP

#include "User.hpp"

class BusinessUser : public User
{
public:
    void sendMessage(User* user, Message* msg) override
    {
        std::cout << "Business User " << id << " is sending a message to user " << user->getId() << std::endl;
        user->receiveMessage(msg);
    }
};


#endif //MAMAN11_BUSINESSUSER_HPP
