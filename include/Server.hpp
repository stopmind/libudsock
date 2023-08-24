//
// Created by user on 8/24/23.
//

#ifndef SERVER_HPP
#define SERVER_HPP

#include <string>

#include "Connection.hpp"

namespace UDSock {

    class Server {
    private:
        int _sock;
    public:
        Server(std::string &sockPath, int maxIncomingConnections);
        ~Server();

        Connection *waitConnection();
        void close();
        bool closed();
    };

} // UDSock

#endif //SERVER_HPP
