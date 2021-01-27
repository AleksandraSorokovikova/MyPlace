#include <iostream>
#include <string>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>

#define ERROR_S "SERVER ERROR "
#define DEFAULT_PORT 1602
#define BUFFER_SIZE 1024
#define CLIENT_CLOSE_CONNECTION_SYMBOL '#'

bool is_client_connetction_closed(const char *msg);


int main(int argc, char const *argv[]) {
    int client;
    int server;
    struct sockaddr_in server_address;
    
    client = socket(AF_INET, SOCK_STREAM, 0);
    
    if (client < 0) {
        std::cout << ERROR_S << '\n';
        exit(0);
    }
    std::cout << "SOCKET: Socket for server was successfully created" << '\n';
    
    server_address.sin_port = htons(DEFAULT_PORT);
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htons(INADDR_ANY);
    
    int ret = bind(client, reinterpret_cast<struct sockaddr*>(&server_address), sizeof(server_address));
    
    if (ret < 0) {
        std::cout << ERROR_S << "server has benn already established" << '\n';
        return -1;
    }
    
    socklen_t size = sizeof(server_address);
    std::cout << "SERVER: " << "Listening clients ..." << '\n';
    listen(client, 1);
    
    server = accept(client,reinterpret_cast<struct sockaddr*>(&server_address), &size);
    
    if (server < 0) {
        std::cout << ERROR_S << '\n';
    }
    
    char buffer[BUFFER_SIZE];
    bool is_exit = false;
    while (server > 0) {
        strcpy(buffer, "Server connected '\n");
        send(server, buffer, BUFFER_SIZE, 0);
        std::cout << "Connected to client 1" << '\n';
        std::cout << "Enter" << CLIENT_CLOSE_CONNECTION_SYMBOL << "to end connetction" << '\n';
        
        std::cout << "Client: ";
        recv(server, buffer, BUFFER_SIZE, 0);
        std::cout << buffer << '\n';
        
        if (is_client_connetction_closed) {
            is_exit = true;
        }
        
        while (is_exit) {
            std::cout << "Server: ";
            std::cin.getline(buffer, BUFFER_SIZE);
            send(server, buffer, BUFFER_SIZE, 0);
            if (is_client_connetction_closed(buffer)) {
                break;
            }
            
            std::cout << "Client: ";
            recv(server, buffer, BUFFER_SIZE, 0);
            std::cout << buffer << '\n';
            if (is_client_connetction_closed(buffer)) {
                break;
            }
        }
        std::cout << "\n" << "Goodbye" << '\n';
        is_exit = false;
        exit(1);
    
        
    }
    return 0;
    
}


bool is_client_connetction_closed(const char *msg) {
    for (int i = 0; i < strlen(msg); i++) {
        if (msg[i] == CLIENT_CLOSE_CONNECTION_SYMBOL) {
            return true;
        }
    }
    return false;
}
