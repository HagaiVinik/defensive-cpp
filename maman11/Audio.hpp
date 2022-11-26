//
// Created by hagaivinik on 11/22/22.
//

#ifndef MAMAN11_AUDIO_HPP
#define MAMAN11_AUDIO_HPP

#include <iostream>

#include "Media.hpp"


class Audio : public Media
{
    void display()
    {
        std::cout << "Displaying a Audio" << std::endl;
    }
};


#endif //MAMAN11_AUDIO_HPP
