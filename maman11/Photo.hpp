//
// Created by hagaivinik on 11/22/22.
//

#ifndef MAMAN11_PHOTO_HPP
#define MAMAN11_PHOTO_HPP

#include <iostream>

#include "Media.hpp"

class Photo : public Media
{
    void display()
    {
        std::cout << "Displaying a Photo" << std::endl;
    }
};


#endif //MAMAN11_PHOTO_HPP
