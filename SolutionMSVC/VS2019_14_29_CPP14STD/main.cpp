#include "src/functions.h"
#include <Windows.h>
#include <iostream>
#include <sstream>
#include <string>
#include <chrono>
#include <ctime>
#include <iomanip>
void main() {
    SetConsoleOutputCP(65001);

    // Convert timestamp to time_point
    std::chrono::system_clock::time_point tp(std::chrono::milliseconds(1682589330983));

    // Convert time_point to tm struct
    std::time_t tt = std::chrono::system_clock::to_time_t(tp);
    tm ltm;
    localtime_s(&ltm, &tt);

    // Format tm struct as string with millisecond precision
    std::ostringstream oss;
    oss << std::put_time(&ltm, "%Y-%m-%d %H:%M:%S");
    oss << "." << std::setfill('0') << std::setw(3) << 1682589330983 % 1000;
    std::string time_str = oss.str();

    std::cout << time_str << std::endl; // Output: 2022-05-27 08:35:30.983
    ///TimeTest();
}