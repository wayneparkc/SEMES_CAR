#pragma once
#include <iostream>
#include <string>
#include <unordered_map>
#include <functional>
#include "part.h"

#define interface struct

class different_brand_error : public std::exception {
private:
	std::string message;
public:
	different_brand_error(const char* msg) : message(msg) {}
	const char* what() const noexcept override {
		return message.c_str();
	}
};

class not_make_break : public std::exception {
private:
	std::string message;
public:
	not_make_break(const char* msg) : message(msg) {}
	const char* what() const noexcept override {
		return message.c_str();
	}
};

class not_make_engine : public std::exception {
private:
	std::string message;
public:
	not_make_engine(const char* msg) : message(msg) {}
	const char* what() const noexcept override {
		return message.c_str();
	}
};

interface Car{
	//Enum Class Type는 1부터 시작.
	Car();
	Engine engine;
	BreakSystem bs;
	SteeringSystem steer;
	std::unordered_map<int, std::function<void(int)>> car_step;
	void setEngine(int engine);
	void setBreak(int breaksys);
	void setSteering(int steeringsys);
	std::string getEngine();
	std::string getBreak();
	std::string getSteering();
	void checkSteer();
	void run();
	virtual void test() = 0;
	virtual void info() = 0;
};
std::unique_ptr<Car> Factor(int type);