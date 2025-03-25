#include <utility>

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
