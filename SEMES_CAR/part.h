#pragma once
#include <utility>
#include <map>
#include <stdexcept>
enum class QuestionType : uint8_t {
    CarType_Q = 1,
    Engine_Q = 2,
    BreakSystem_Q = 3,
    SteeringSystem_Q = 4,
    Run_Test = 5
};

enum class CarType : uint8_t {
    SEDAN = 1,
    SUV,
    TRUCK
};

enum class Engine : uint8_t {
    GM = 1,
    TOYOTA,
    WIA
};

enum class BreakSystem : uint8_t {
    MANDO = 1,
    CONTINENTAL,
    BOSCH_B
};

enum class SteeringSystem : uint8_t {
    BOSCH_S = 1,
    MOBIS
};

inline const std::map<int, CarType> carTypeMap = {
    {1, CarType::SEDAN},
    {2, CarType::SUV},
    {3, CarType::TRUCK},
};

inline const std::map<int, Engine> engineMap = {
    {1, Engine::GM},
    {2, Engine::TOYOTA},
    {3, Engine::WIA}
};

inline const std::map<int, BreakSystem> brakeMap = {
    {1, BreakSystem::MANDO},
    {2, BreakSystem::CONTINENTAL},
    {3, BreakSystem::BOSCH_B}
};

inline const std::map<int, SteeringSystem> steeringMap = {
    {1, SteeringSystem::BOSCH_S},
    {2, SteeringSystem::MOBIS}
};

template <typename T>
T intToEnum(int value, const std::map<int, T>& enumMap) {
    auto it = enumMap.find(value);
    if (it != enumMap.end()) {
        return it->second;
    }
    throw std::invalid_argument("Invalid enum value");
}