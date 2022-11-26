//
// Created by hagaivinik on 11/22/22.
//

#ifndef MAMAN11_USOCIAL_HPP
#define MAMAN11_USOCIAL_HPP

#include <map>
#include <string>
#include <cstdint>


class User;

class USocial
{

public:
    USocial() = default;
    ~USocial();

    User* registerUser(const std::string& name, bool isBusiness = false);
    User* getUserById(uint64_t id) const;
    void removeUser(User* userPtr);

private:
    std::map<unsigned long, User*> users;
};


#endif //MAMAN11_USOCIAL_HPP
