//
// Created by hagaivinik on 11/22/22.
//

#ifndef MAMAN11_VIDEO_HPP
#define MAMAN11_VIDEO_HPP

#include <iostream>

#include "Media.hpp"


class Video : public Media
{
    void display()
    {
        std::cout << "Displaying a video" << std::endl;
    }
};


#endif //MAMAN11_VIDEO_HPP
