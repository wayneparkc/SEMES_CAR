#pragma once
#include <iostream>
#include <string>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

void startClient(const std::string& server_address, int port) {
    try {
        boost::asio::io_context io_context;
        tcp::socket socket(io_context);
        tcp::resolver resolver(io_context);
        boost::asio::connect(socket, resolver.resolve(server_address, std::to_string(port)));

        while (true) {
            std::cout << "자동차 구성 요소를 입력하세요 (car,engine,brake,steering) 또는 'exit' 입력: ";
            std::string input;
            std::getline(std::cin, input);

            if (input == "exit") break;

            boost::asio::write(socket, boost::asio::buffer(input));

            char buffer[1024];
            boost::system::error_code error;
            size_t length = socket.read_some(boost::asio::buffer(buffer), error);

            if (error) {
                std::cerr << "Error receiving response: " << error.message() << std::endl;
                break;
            }

            std::cout << "서버 응답: " << std::string(buffer, length) << std::endl;
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

int main() {
    std::string server_address = "127.0.0.1";
    int port = 8080;
    startClient(server_address, port);
    return 0;
}