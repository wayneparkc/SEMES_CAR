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
    SUV=2,
    TRUCK=3
};

enum class Engine : uint8_t {
    GM = 1,
    TOYOTA = 2,
    WIA = 3
};

enum class BreakSystem : uint8_t {
    MANDO = 1,
    CONTINENTAL = 2,
    BOSCH_B = 3
};

enum class SteeringSystem : uint8_t {
    BOSCH_S = 1,
    MOBIS = 2
};
