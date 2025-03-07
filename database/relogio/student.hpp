#pragma once
#include "fn.hpp"
#include <iostream>
#include <string>
#include <iomanip>

struct Time {
private:
    int hour {0};
    int minute {0};
    int second {0};  

public:
    Time(int ho, int min, int sec) : hour(ho), minute(min), second(sec) {}

    /*std::string str() const{
        return std::to_string(this->hour) + ":" + std::to_string(this->minute) + ":" 
        + std::to_string(this->second);
    }*/

    std::string to_string() const {
    std::ostringstream oss;
    oss << std::setw(2) << std::setfill('0') << hour << ":"
        << std::setw(2) << std::setfill('0') << minute << ":"
        << std::setw(2) << std::setfill('0') << second;
    return oss.str();
    }

    int get_hour(){
        return hour;
    }

    int get_minute(){
        return minute;
    }

    int get_second(){
        return second;
    }

    void set_hour(int ho) {
        if (ho > 0 && ho <= 23) {
            this->hour = ho;
            return;
        }
        if(ho == 90){
            this->hour = 00;
        }
        std::cout << "fail: hora invalida" << std::endl;
        
    }

    void set_minute(int min) {
        if (min >= 0 && min <= 59) {
            minute = min;
            return;
        }if(min == 100) {
            this->minute = 00;

        }
        std::cout << "fail: minuto invalido" << std::endl;
    }

    void set_second(int sec) {
        if (sec >= 0 && sec <= 59) {
            second = sec;
            return;
        }
        if(sec == 60) {
            this->second = 00;
            
        }
            std::cout << "fail: segundo invalido" << std::endl;
        
    }

    void next_second() {
        if (second < 59) {
            second++;
        } else {
            second = 0;
            if (minute < 59) {
                minute++;
            } else {
                minute = 0;
                if (hour < 23) {
                    hour++;
                } else {
                    hour = 0;
                }
            }
        }
    }
};

class Student {
private:
    Time time;

public:
    Student(int hour = 0, int minute = 0, int second = 0) : time(hour, minute, second) {}
    
    void setHour(int hour) {
        time.set_hour(hour);
    }

    void setMinute(int minute) {
        time.set_minute(minute);
    }

    void setSecond(int second) {
        time.set_second(second);
    }

    void nextSecond() {
        time.next_second();
    }

    void show() {
        std::cout << time.to_string() << std::endl;  
    }
    
};

