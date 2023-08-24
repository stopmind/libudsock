//
// Created by user on 8/24/23.
//

#include "../include/Connection.hpp"

#include "ServerException.hpp"

#include <sys/socket.h>
#include <unistd.h>

namespace UDSock {
    Connection::Connection(int sock) {
        _sock = sock;
    }

    Connection::~Connection() {
        close();
    }

    void Connection::close() {
        if (!closed()) {
            ::close(_sock);
            _sock = 0;
        }
    }

    bool Connection::closed() {
        return _sock == 0;
    }

    void Connection::send(Data &data) {
        if (::send(_sock, data.c_str(), data.size() + 1, 0) == -1) throw ServerException("Failed send data!");
    }

    Data* Connection::recv() {
        uint8_t buffer[1024];
        int dataLen = ::recv(_sock, buffer, 1024, 0);

        if (dataLen < 0) throw ServerException("Failed receive data!");

        return new Data(buffer, dataLen);
    }
}