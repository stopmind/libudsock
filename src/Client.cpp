//
// Created by user on 8/23/23.
//

#include "../include/Client.hpp"
#include "ClientException.hpp"

#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

namespace UDSock {
    Client::Client(std::string &sockPath) {
        _sock = socket(AF_UNIX, SOCK_STREAM, 0);

        if (_sock == -1) throw ClientException("Failed create socket!");

        sockaddr_un addr{};
        addr.sun_family = AF_UNIX;
        strcpy(addr.sun_path, sockPath.c_str());



        if (connect(_sock, (sockaddr *) &addr, sizeof addr) == -1) throw ClientException("Failed connect socket!");
    }

    Client::~Client() {
        close();
    }

    void Client::send(Data &data) {
        if (::send(_sock, data.c_str(), data.size() + 1, 0) == -1) throw ClientException("Failed send data!");
    }

    Data* Client::recv() {
        uint8_t buffer[1024];
        int dataLen = ::recv(_sock, buffer, 1024, 0);

        if (dataLen < 0) throw ClientException("Failed receive data!");
        if (dataLen == 0) return nullptr;
        return new Data(buffer, dataLen);
    }

    void Client::close() {
        if (!closed()) {
            ::close(_sock);
            _sock = 0;
        }
    }

    bool Client::closed() {
        return _sock == 0;
    }
}