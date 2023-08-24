//
// Created by user on 8/24/23.
//

#include "../include/Server.hpp"

#include "ServerException.hpp"

#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

namespace UDSock {
    Server::Server(std::string &sockPath, int maxIncomingConnections) {
        _sock = socket(AF_UNIX, SOCK_STREAM, 0);

        sockaddr_un addr{};
        addr.sun_family = AF_UNIX;
        strcpy(addr.sun_path, sockPath.c_str());

        if (bind(_sock, (sockaddr*)&addr, sizeof addr) != 0) throw ServerException("Failed bind call!");
        if (listen(_sock, maxIncomingConnections) != 0) throw ServerException("Failed listen call!");
    }

    Server::~Server() {
        close();
    }

    Connection *Server::waitConnection() {
        sockaddr addr{};
        socklen_t len;
        int sock2 = accept(_sock, &addr, &len);

        if (sock2 == -1) throw ServerException("Failed accept call!");

        return new Connection(sock2);
    }

    void Server::close() {
        if (!closed()) {
            ::close(_sock);
            _sock = 0;
        }
    }

    bool Server::closed() {
        return _sock == 0;
    }
} // UDSock
