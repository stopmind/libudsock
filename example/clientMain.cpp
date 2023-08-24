//
// Created by user on 8/24/23.
//

#include <string>
#include <iostream>

#include "Client.hpp"

int main(int argc, char **argv) {
    if (argc != 2) return -1;
    std::string sockPath(argv[1]);

    UDSock::Client client(sockPath);
    std::cout
        << "Connected!"        << std::endl
        << "-Server messages-" << std::endl;

    while (true) {
        auto data = client.recv();
        if (data == nullptr) continue;
        std::cout << " " << std::string((char*)data->c_str()) << std::endl;
    }
}