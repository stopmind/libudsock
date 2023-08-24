//
// Created by user on 8/24/23.
//

#ifndef CLIENTEXCEPTION_HPP
#define CLIENTEXCEPTION_HPP

#include <exception>
#include <string>

namespace UDSock {
    class ClientException : public std::exception {
    private:
        std::string _msg;
    public:
        ClientException(std::string msg);

        const char *what() const noexcept override;
    };
}

#endif //CLIENTEXCEPTION_HPP
