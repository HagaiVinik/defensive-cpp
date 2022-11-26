//
// Created by hagaivinik on 11/22/22.
//

#ifndef MAMAN11_POST_HPP
#define MAMAN11_POST_HPP

#include <string>

#include "Media.hpp"


class Post
{
public:
    Post(std::string msg) : text(std::move(msg))
    {}

    Post(std::string msg, Media* media) : text(std::move(msg)), media(media)
    {}

    std::string getText() const
    {
        return text;
    }

    Media* getMedia() const
    {
        return media;
    }

private:
    std::string text;
    Media* media;
};


#endif //MAMAN11_POST_HPP
