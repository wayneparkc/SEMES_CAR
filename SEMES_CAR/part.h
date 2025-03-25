#include <utility>

enum class QuestionType : uint8_t {
    CarType_Q,
    Engine_Q,
    BreakSystem_Q,
    SteeringSystem_Q,
    Run_Test,
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
