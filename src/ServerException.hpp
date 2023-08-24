//
// Created by user on 8/24/23.
//

#ifndef SERVEREXCEPTION_HPP
#define SERVEREXCEPTION_HPP

#include <exception>
#include <string>

namespace UDSock {

    class ServerException : public std::exception {
    private:
        std::string _msg;
    public:
        ServerException(std::string msg);

        const char *what() const noexcept override;
    };

} // UDSock

#endif //SERVEREXCEPTION_HPP
