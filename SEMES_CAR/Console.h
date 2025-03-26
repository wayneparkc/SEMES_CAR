#pragma once
#include <unordered_map>
#include <functional>

class Console {
public:
    int step;
    Console();
    // 멤버 함수 프로토타입
    int get_step();
    int input();
    int choose_type();
    int choose_engine();
    int choose_break();
    int choose_steering();
    int choose_action();
    void set_step(int input);
    // 함수 실행
    //void run_step(int step);
    // unordered_map 초기화 및 멤버 변수
    std::unordered_map<int, std::function<int()>> console_step;
};
