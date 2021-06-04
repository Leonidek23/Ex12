// Copyright Leonidek23 2021

#include<ctime>
#include<string>
#include <TimedDoor.h>

TimedDoor::TimedDoor(int time)
        : iTimeout(time), opened(false), adapter(new DoorTimerAdapter(*this)) {}

bool TimedDoor::isDoorOpened() { return this->opened; }

void TimedDoor::unlock() {
    opened = false;
    adapter->Timeout();
}

void TimedDoor::lock() { opened = false; }


void TimedDoor::throwState() const {
    if (opened)
        throw std::string("the door is opened!");
    else
        throw std::string("the door is closed!");
}

void TimedDoor::DoorTimeOut() {
    throw std::string("please close the door!");
}


DoorTimerAdapter::DoorTimerAdapter(const TimedDoor &_door) : door(_door) {}

void Timer::sleep(int iTimeout) {
    time_t start = time(nullptr);
    while (time(nullptr) - start < iTimeout) {
        continue;
    }
}

void Timer::tregister(int time, TimerClient *timer) {
    sleep(time);
}

void DoorTimerAdapter::Timeout() {
    this->door.DoorTimeOut();
}
