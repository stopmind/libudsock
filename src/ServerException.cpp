//
// Created by user on 8/24/23.
//

#include "ServerException.hpp"

#include <cstring>
#include <cerrno>

namespace UDSock {
    ServerException::ServerException(std::string msg) {
        _msg = std::move(msg);
    }

    const char *ServerException::what() const noexcept {
        std::string fullMsg = "Server error: " + _msg + " Errno: " + std::to_string(errno);
        char *cStr = new char[fullMsg.size() + 1];
        strcpy(cStr, fullMsg.c_str());
        return cStr;
    }
} // UDSock