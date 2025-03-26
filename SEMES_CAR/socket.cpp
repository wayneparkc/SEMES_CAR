#include <boost/asio.hpp>
#include <string>
#include <iostream>
#include "part.h"
#include <stdexcept>

using namespace boost::asio;
using ip::tcp;



bool isValidCombination(int carChoice, int engineChoice, int brakeChoice, int steeringChoice) {
    return true;
}



void handleClient(tcp::socket socket) {
    try {
        char buffer[1024];
        boost::system::error_code error;
        size_t length = socket.read_some(boost::asio::buffer(buffer), error);

        if (error) {
            std::cerr << "Error receiving data: " << error.message() << std::endl;
            return;
        }

        std::string input(buffer, length);

        int carChoice, engineChoice, brakeChoice, steeringChoice;
        sscanf_s(input.c_str(), "%d,%d,%d,%d", &carChoice, &engineChoice, &brakeChoice, &steeringChoice);


        try {
            CarType carType = intToEnum(carChoice, carTypeMap);
            Engine engineType = intToEnum(engineChoice, engineMap);
            BreakSystem brakeType = intToEnum(brakeChoice, brakeMap);
            SteeringSystem steeringType = intToEnum(steeringChoice, steeringMap);

            if (isValidCombination(carChoice, engineChoice, brakeChoice, steeringChoice)) {
                std::string response = "자동차가 성공적으로 제조되었습니다!\n";
                boost::asio::write(socket, boost::asio::buffer(response));
            }
            else {
                std::string errorResponse = "자동차 제조에 실패했습니다.\n";
                boost::asio::write(socket, boost::asio::buffer(errorResponse));
            }
        }
        catch (const std::invalid_argument& e) {
            std::cerr << "Invalid combination received: " << e.what() << std::endl;
            std::string errorResponse = "잘못된 입력이 들어왔습니다. 자동차 제조에 실패했습니다.\n";
            boost::asio::write(socket, boost::asio::buffer(errorResponse));
        }

    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

void startServer() {
    try {
        io_context ioService;
        tcp::acceptor acceptor(ioService, tcp::endpoint(tcp::v4(), 8080));

        std::cout << "Server running, waiting for connections..." << std::endl;
        while (true) {
            tcp::socket socket(ioService);
            acceptor.accept(socket);
            std::thread(handleClient, std::move(socket)).detach();
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}
