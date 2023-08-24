//
// Created by user on 8/24/23.
//

#include "ClientException.hpp"

#include <cstring>
#include <cerrno>

namespace UDSock {
    ClientException::ClientException(std::string msg) {
        _msg = std::move(msg);
    }

    const char *ClientException::what() const noexcept {
        std::string fullMsg = "Client error: " + _msg + " Errno: " + std::to_string(errno);
        char *cStr = new char[fullMsg.size() + 1];
        strcpy(cStr, fullMsg.c_str());
        return cStr;
    }
}