//
// Created by hagaivinik on 11/22/22.
//

#ifndef MAMAN11_USER_HPP
#define MAMAN11_USER_HPP

#include <string>
#include <list>
#include <utility>

#include "USocial.hpp"
#include "Message.hpp"
#include "Post.hpp"
#include "Photo.hpp"
#include "Audio.hpp"
#include "Video.hpp"

class User
{
public:
    friend USocial;

    uint64_t getId()
    {
        return id;
    }

    std::string getName()
    {
        return name;
    }

    void addFriend(User *userPtr)
    {
        friends.push_back(userPtr->getId());
    }

    void removeFriend(User *userPtr)
    {
        friends.remove(userPtr->getId());
    }

    void post(const std::string& arg)
    {
        std::cout << "new post: " << arg << std::endl;
        Post* postPtr = new Post(arg);
        posts.push_back(postPtr);
    }

    void post(std::string arg, Media* media)
    {
        std::cout << "new post: " << arg << std::endl;
        Post* postPtr = new Post(arg, media);
        posts.push_back(postPtr);
    }

    std::list<Post*> getPosts()
    {
        return posts;
    }

    void viewFriendsPosts()
    {
        std::list<Post*> friendsPostsList;
        for (auto& friendUserId : friends)
        {
            User* userPtr = us->getUserById(friendUserId);
            for (auto post : userPtr->posts)
            {
                friendsPostsList.push_back(post);
            }
        }

        for (auto* post : friendsPostsList)
        {
            std::cout << "post: " << post->getText() << std::endl;
        }
    }

    void receiveMessage(Message * msg)
    {
        std::cout << "User " << id << " has received a message: " << msg->getText() << std::endl;
        receivedMsgs.push_back(msg);
    }

    virtual void sendMessage(User* user, Message* msg)
    {
        std::cout << "User " << id << " is sending a message to user " << user->getId() << std::endl;
        user->receiveMessage(msg);
    }

    void viewReceivedMessages()
    {
        std:: cout << "Printing all messages for user " << id << std::endl;
        for (auto& msg : receivedMsgs)
        {
            std::cout << msg->getText() << std::endl;
        }
    }

protected:
    USocial* us;
    uint64_t id;
    std::string name;
    std::list<uint64_t> friends;
    std::list<Post*> posts;
    std::list<Message*> receivedMsgs;

    User()
    {
        id = id_counter;
        id_counter++;
    }

    ~User()
    {
        for (auto* postPtr : posts)
        {
            delete postPtr;
            postPtr = nullptr;
        }

        for (auto* msg : receivedMsgs)
        {
            delete msg;
            msg = nullptr;
        }
    }

private:
    inline static int id_counter = 1;
};


#endif //MAMAN11_USER_HPP
