#include <arpa/inet.h>
#include <iostream>
#include <netdb.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define SERVER_IP "178.154.252.227"
#define DEFAULT_PORT 1602
#define SERVER_CLOSE_CONNECTION_SYMBOL '#'
#define BUFFER_SIZE 1024
#define ERROR_S "SERVER ERROR "

bool is_client_connetction_closed(const char *msg);

int main(int argc, char const *argv[]) {
    int client;

    struct sockaddr_in server_address;

    client = socket(AF_INET, SOCK_STREAM, 0);

    if (client < 0) {
        std::cout << ERROR_S << '\n';
        exit(0);
    }

    server_address.sin_port = htons(DEFAULT_PORT);
    server_address.sin_family = AF_INET;
    inet_pton(AF_INET, SERVER_IP, &server_address.sin_addr);

    std::cout << "Client socket was created" << '\n';

    int ret = connect(
        client, reinterpret_cast<const struct sockaddr *>(&server_address),
        sizeof(server_address));
    if (ret == 0) {
        std::cout << "Connection to server "
                  << inet_ntoa(server_address.sin_addr) << " with port number "
                  << DEFAULT_PORT << '\n';
    }

    char buffer[BUFFER_SIZE];
    std::cout << "Waiting for server... \n";
    recv(client, buffer, BUFFER_SIZE, 0);
    std::cout << "Connection is established" << '\n';
    std::cout << "Enter " << SERVER_CLOSE_CONNECTION_SYMBOL
              << " to close connection \n";

    while (true) {
        std::cout << "Client: ";
        std::cin.getline(buffer, BUFFER_SIZE);
        send(client, buffer, BUFFER_SIZE, 0);
        if (is_client_connetction_closed(buffer)) {
            break;
        }

        std::cout << "Server: ";
        recv(client, buffer, BUFFER_SIZE, 0);
        std::cout << buffer << '\n';
        if (is_client_connetction_closed(buffer)) {
            break;
        }
        std::cout << '\n';
    }

    close(client);
    std::cout << "\n"
              << "Goodbye" << '\n';

    return 0;
}

bool is_client_connetction_closed(const char *msg) {
    for (int i = 0; i < strlen(msg); i++) {
        if (msg[i] == SERVER_CLOSE_CONNECTION_SYMBOL) {
            return true;
        }
    }
    return false;
}
