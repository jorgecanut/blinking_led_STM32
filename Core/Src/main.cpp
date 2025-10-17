#ifndef SIM_ON
#include "main.h"

#include "lwip.h"
#endif

#include "ST-LIB.hpp"

int main(void) {
#ifdef SIM_ON
    SharedMemory::start();
#endif

    DigitalOutput yellow_led(PE1);
    Pin::start();
    //COmentario de prueba
}

void Error_Handler(void) {
    ErrorHandler("HAL error handler triggered");
    while (1) {
    }
}
