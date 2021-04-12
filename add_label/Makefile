all: server client1 client2

server: 
	g++ server.cpp label.cpp -std=c++17 -lboost_thread -I/Users/alexandrasorokovikova/boost_1_72_0 -pthread -o server

client1:
	g++ client.cpp label.cpp  -std=c++17 -lboost_thread -I/Users/alexandrasorokovikova/boost_1_72_0 -pthread -o client1

client2:
	g++ client.cpp label.cpp  -std=c++17 -lboost_thread -I/Users/alexandrasorokovikova/boost_1_72_0 -pthread -o client2

