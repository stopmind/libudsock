//
// Created by user on 8/24/23.
//

#ifndef CONNECTION_HPP
#define CONNECTION_HPP

#include "Data.hpp"

namespace UDSock {
    class Connection {
    private:
        int _sock;
    public:
        Connection(int sock);
        ~Connection();

        void close();
        bool closed();
        void send(Data &data);
        Data* recv();
    };
}

#endif //CONNECTION_HPP
