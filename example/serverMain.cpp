//
// Created by user on 8/24/23.
//

#include <string>
#include <iostream>
#include <vector>

#include "Server.hpp"

int main(int argc, char **argv) {
    if (argc != 2) return -1;
    std::string sockPath(argv[1]);

    UDSock::Server server(sockPath, 10);
    std::vector<UDSock::Connection*> connections;

    std::cout
        << "Server sock path : " << sockPath << std::endl
        << "-Shell-"                         << std::endl;

    std::string command;
    while (true) {
        std::cout << " > ";
        std::cin >> command;

        if (command == "send") {
            std::string msg;
            std::cout <<  "  ? ";
            std::cin >> msg;
            UDSock::Data data((uint8_t*)msg.c_str());

            for (auto &connection: connections) {
                connection->send(data);
            }

        } else if (command == "wait") {
            std::cout <<  "  Wait connection..." << std::endl;
            auto connection = server.waitConnection();
            connections.push_back(connection);
            std::cout <<  "  New connection!" << std::endl;

        } else if (command == "exit") {
            std::cout <<  "  Exiting..." << std::endl;
            break;
        }
    }

    return 0;
}