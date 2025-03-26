#pragma once
#include <unordered_map>
#include <functional>

class Console {
public:
    int step;
    int flag;
    Console();
    // ��� �Լ� ������Ÿ��
    void connect();
    int get_step();
    int get_flag();
    int input();
    int choose_type();
    int choose_engine();
    int choose_break();
    int choose_steering();
    int choose_action();
    void set_step(int input);
    // �Լ� ����
    // unordered_map �ʱ�ȭ �� ��� ����
    std::unordered_map<int, std::function<int()>> console_step;
};
