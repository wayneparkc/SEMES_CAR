#pragma once
#include <boost/asio.hpp>

using namespace boost::asio;
using ip::tcp;

bool isValidCombination(int carChoice, int engineChoice, int brakeChoice, int steeringChoice);
void handleClient(tcp::socket socket);
void startServer();


