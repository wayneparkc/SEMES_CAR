#include <iostream>
#include <boost/asio.hpp>
#include <thread>

using namespace boost::asio;
using ip::tcp;

enum class CarType { Sedan = 1, SUV, Truck };
enum class EngineType { GM = 1, TOYOTA, WIA };
enum class BrakeType { MANDO = 1, Continental, Bosch };
enum class SteeringType { Bosch = 1, Mobis };

bool isValidCombination(CarType car, EngineType engine, BrakeType brake, SteeringType steering) {
    return true;
};


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
        sscanf(input.c_str(), "%d,%d,%d,%d", &carChoice, &engineChoice, &brakeChoice, &steeringChoice);

        CarType carType = static_cast<CarType>(carChoice);
        EngineType engineType = static_cast<EngineType>(engineChoice);
        BrakeType brakeType = static_cast<BrakeType>(brakeChoice);
        SteeringType steeringType = static_cast<SteeringType>(steeringChoice);

        if (isValidCombination(carType, engineType, brakeType, steeringType)) {
            std::string response = "자동차가 성공적으로 제조되었습니다!\n";
            boost::asio::write(socket, boost::asio::buffer(response));
        }
        else {
            std::string errorResponse = "자동차 제조에 실패했습니다.\n";
            boost::asio::write(socket, boost::asio::buffer(errorResponse));
        }

    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}


int main() {
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

    return 0;
}
