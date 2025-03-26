#include "Car.h"
#include "SUV.h"
#include "Sedan.h"
#include "Truck.h"
#include <memory>
#include <string>
#include <boost/asio.hpp>

void Car::setEngine(int engine) {
    if (engine == 1) this->engine = Engine::GM;
    else if (engine == 2) this->engine = Engine::TOYOTA;
    else if (engine == 3) this->engine = Engine::WIA;
}

void Car::setBreak(int breaksys) {
    if (breaksys == 1) this->bs = BreakSystem::MANDO;
    else if (breaksys == 2) this->bs = BreakSystem::CONTINENTAL;
    else if (breaksys == 3) this->bs = BreakSystem::BOSCH_B;
}

void Car::setSteering(int steeringsys) {
    if (steeringsys == 1) this->steer = SteeringSystem::BOSCH_S;
    else if (steeringsys == 2) this->steer = SteeringSystem::MOBIS;
}

std::string Car::getEngine() {
    if (static_cast<int>(this->engine) == 1) return "GM";
    else if (static_cast<int>(this->engine) == 2) return "TOYOTA";
    else if (static_cast<int>(this->engine) == 3) return "WIA";
}

std::string Car::getBreak() {
    if (static_cast<int>(this->bs) == 1) return "MANDO";
    else if (static_cast<int>(this->bs) == 2) return "CONTINENTAL";
    else if (static_cast<int>(this->bs) == 3) return "BOSCH_B";
}

std::string Car::getSteering() {
    if (static_cast<int>(this->steer) == 1) return "BOSCH_S";
    else if (static_cast<int>(this->steer) == 2) return "MOBIS";
}

void Car::checkSteer() {
    if (BreakSystem::BOSCH_B == bs && SteeringSystem::BOSCH_S != steer || BreakSystem::BOSCH_B != bs && SteeringSystem::BOSCH_S == steer) {
        // 에러 발생
        throw different_brand_error("BOSCH 제동장치는 BOSCH 조향장치만 호환됩니다.");
    }
}
void Car::run() {
    if (this->engine == Engine::GM || this->engine == Engine::TOYOTA || this->engine == Engine::WIA) {
        std::cout << "자동차가 동작됩니다.\n";
    }
    else {
        std::cout << "엔진이 고장났습니다.\n";
    }
    printf("동작 정지 [Enter]");
    std::cin.ignore();
    std::cin.get();
}

void Car::test() {
    using boost::asio::ip::tcp;

    bool flag = true;

    try {
        boost::asio::io_context io_context;
        tcp::socket socket(io_context);

        std::string host = "127.0.0.1";
        int port = 8080;

        // 서버에 연결
        tcp::resolver resolver(io_context);
        boost::asio::connect(socket, resolver.resolve(host, std::to_string(port)));

        // 입력 데이터 형식에 맞춰 문자열을 생성
        std::stringstream ss;
        ss << this->typeof() << "," << std::to_string(static_cast<int>(this->engine)) << ",";
        ss << std::to_string(static_cast<int>(this->bs)) << "," << std::to_string(static_cast<int>(this->steer));

        std::string message = ss.str();
        //std::cout << "Sending message: " << message << std::endl;

        // 메시지를 서버로 전송
        boost::asio::write(socket, boost::asio::buffer(message));

        // 서버로부터의 응답을 받음
        char buffer[1024];
        size_t length = socket.read_some(boost::asio::buffer(buffer));
        std::string response(buffer, length);
        //std::cout << "Server response: " << response << std::endl;
        
        // 실패라면 flag를 변환하고, 에러 메시지 출력
        if (response.substr(0, 2) == "FA") {
            flag = 0;
            std::cout << response.substr(3,response.size()-3);
        }
    }
    catch (const not_make_break& e) {
        flag = false;
        std::cerr << e.what() << std::endl;
    }
   
    if (flag)
        std::cout << "테스트가 정상적으로 마무리 되었습니다.\n";
    else
        std::cout << "\n위 이유로 인한 불량입니다.\n";

    printf("===============================\n");
    printf("정보 닫기 [Enter]");
    std::cin.ignore();
    std::cin.get();
}

Car::Car() {
    car_step = {
       {2, [this](int v) {this->setEngine(v); }},
       {3, [this](int v) {this->setBreak(v); }},
       {4, [this](int v) {this->setSteering(v); }},
       {5, [this](int v) {
          if (v == 1) this->run();
          else if (v == 2) this->info();
          else this->test();
       }},
    };
}

std::unique_ptr<Car> Factor(int type) {
    if (type == 1)
        return std::make_unique<Sedan>();
    else if (type == 2)
        return std::make_unique<SUV>();
    else if (type == 3)
        return std::make_unique<Truck>();
    return nullptr;
}
