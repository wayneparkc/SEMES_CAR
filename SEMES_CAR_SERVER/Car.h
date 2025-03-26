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
	Engine engine;
	BreakSystem bs;
	SteeringSystem steer;
	void setEngine(int engine);
	void setBreak(int breaksys);
	void setSteering(int steeringsys);
	void checkSteer();
	virtual std::string test() = 0;
};
std::unique_ptr<Car> Factor(int type);