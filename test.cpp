#include <iostream>
#include <thread>

#include "include/event_loop.hpp"

#include <chrono>

namespace EventTypes
{
    std::string Event1 = "test:Event1";
    std::string Event2 = "test:Event2";
};

int main(int, char**) {

    klib::KEventLoop eventloop([](klib::KEvent event){
        if(event.eventType == EventTypes::Event1) {
            std::cout << " event 1 " << std::endl;
        }
        else if(event.eventType == EventTypes::Event2) {
            std::cout << " event 2 " << std::endl;
        }        
    });

    using namespace std::chrono_literals;
    std::thread thread1([&](){
        while (1)
        {
            klib::KEvent event;
            event.eventType = EventTypes::Event1;
            eventloop.pushEvent(event);
            std::this_thread::sleep_for(1s);
        }
        
    }); 

    std::thread thread2([&](){
        while (1)
        {
            klib::KEvent event;
            event.eventType = EventTypes::Event2;
            eventloop.pushEvent(event);
            std::this_thread::sleep_for(1s);
        }
        
    }); 


    while (1)
    {
        eventloop.step();
    }
    
    
    return 0;
}
