//
// Created by hagaivinik on 11/22/22.
//

#ifndef MAMAN11_MESSAGE_HPP
#define MAMAN11_MESSAGE_HPP

#include <string>


class Message
{
public:
    Message(std::string msg) : text(std::move(msg))
    {}

    std::string getText() const
    {
        return text;
    }


private:
    std::string text;
};


#endif //MAMAN11_MESSAGE_HPP
