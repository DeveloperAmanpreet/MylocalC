#pragma once

#include <cstdio>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>
#include <stdio.h>
#include <stdlib.h>

std::string exec(const char* cmd) {
	std::array<char, 128> buffer;
	std::string result;
	std::string command = "start /B ";
	std::unique_ptr<FILE, decltype(&pclose)> pipe(_popen("start /B ". $cmd, "r"), pclose);
	if (!pipe) {
		throw std::runtime_error("popen() failed!");
	}
	while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
		result += buffer.data();
	}
	return result;
}
