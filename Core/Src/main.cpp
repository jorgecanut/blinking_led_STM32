#ifndef SIM_ON
#include "main.h"

#include "lwip.h"
#endif

#include "ST-LIB.hpp"

int main(void) {
#ifdef SIM_ON
    SharedMemory::start();
#endif

    // Esto habilita todos los RCC de los gpio?
    DigitalOutput yellow_led(PE1);
    //Pin::start();

    STLIB::start();
    //Time::start();
    Time::register_low_precision_alarm(1000, [&]() { yellow_led.toggle(); });

    while(1){
        STLIB::update();
    }
}

void Error_Handler(void) {
    ErrorHandler("HAL error handler triggered");
    while (1) {    }
}
