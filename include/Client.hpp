//
// Created by user on 8/23/23.
//

#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <string>

#include "Data.hpp"

namespace UDSock {
    class Client {
    private:
        int _sock;
    public:
        Client(std::string &sockPath);
        ~Client();

        void send(Data &data);
        Data* recv();
        void close();
        bool closed();
    };
}

#endif //CLIENT_HPP
