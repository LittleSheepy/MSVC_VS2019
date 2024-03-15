#include <Windows.h>
#include <iostream>
#include <sstream>
#include <string>
#include <chrono>
#include <ctime>
#include <iomanip>

using namespace std;
// 获取秒级时间
string getTimeStringSec() {
    std::time_t now = std::time(nullptr);
    tm ltm;
    localtime_s(&ltm, &now);
    std::ostringstream oss;
    oss << std::put_time(&ltm, "%Y%m%d%H%M%S");
    std::string time_str = oss.str();
    return time_str;
}

string getTimeStringMS() {
    std::ostringstream oss;
    oss << std::setfill('0') << std::setw(3) << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count() % 1000;
    std::string time_str = oss.str();
    return time_str;
}

string Convert_time_point2tm(long long timestamp) {
    //// Convert timestamp to time_point
    //std::chrono::system_clock::time_point tp(std::chrono::milliseconds(timestamp));

    //// Convert time_point to tm struct
    //std::time_t tt = std::chrono::system_clock::to_time_t(tp);
    //std::tm tm = *std::localtime(&tt);

    //// Format tm struct as string with millisecond precision
    //std::ostringstream oss;
    //oss << std::put_time(&tm, "%Y-%m-%d %H:%M:%S");
    //oss << "." << std::setfill('0') << std::setw(3) << 1682589330983 % 1000;
    //std::string time_str = oss.str();

    //std::cout << time_str << std::endl; // Output: 2022-05-27 08:35:30.983
    return 0;
}

string getTimeStringMS2() {
    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
    std::chrono::system_clock::duration duration = now.time_since_epoch();
    long long millis = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
    long long limited_millis = millis % 1000;
    std::ostringstream oss;
    oss << std::setfill('0') << std::setw(6) << limited_millis;
    std::string time_str = oss.str();
    return time_str;
}

void TimeTest() {
    string time_ms = getTimeStringMS2();
    printf(time_ms.c_str());
    //time.sleep(1);
    //string time_ms = getTimeStringMS2();
    //printf(time_ms.c_str());
}

/*
1682592872879
1682592913606

*/