#include <string>
#include <iostream>
#include "part.h"
#include "socket.h"
#include "Car.h"
#include <stdexcept>
#include <sstream>

bool isValidCombination(int carChoice, int engineChoice, int brakeChoice, int steeringChoice) {
    return true;
}

void handleClient(tcp::socket socket) {
    try {
        char buffer[1024] = { 0 };
        boost::system::error_code error;
        size_t length = socket.receive(boost::asio::buffer(buffer), 0, error);

        if (error) {
            std::cerr << "Error receiving data: " << error.message() << std::endl;
            return;
        }

        std::string input(buffer, length);

        int carChoice, engineChoice, brakeChoice, steeringChoice;
        sscanf_s(input.c_str(), "%d,%d,%d,%d", &carChoice, &engineChoice, &brakeChoice, &steeringChoice);


        try {
            std::unique_ptr<Car> car = Factor(carChoice);
            car->setEngine(engineChoice);
            car->setBreak(brakeChoice);
            car->setSteering(steeringChoice);

            std::string message = car->test();
            boost::asio::write(socket, boost::asio::buffer(message));
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

        std::cout << "차량 조립 테스트 서버를 구동합니다." << std::endl;
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
