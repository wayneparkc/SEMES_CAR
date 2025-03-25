#pragma once
#include <unordered_map>
#include <functional>

class Console {
public:
    int step;
    Console();
    // ��� �Լ� ������Ÿ��
    int get_step();
    int input();
    int choose_type();
    int choose_engine();
    int choose_break();
    int choose_steering();
    int choose_action();
    void set_step(int input);
    // �Լ� ����
    //void run_step(int step);
    // unordered_map �ʱ�ȭ �� ��� ����
    std::unordered_map<int, std::function<int()>> console_step;
};
