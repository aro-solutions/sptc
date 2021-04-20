/********************************************************************************
 * Copyright (c) 2021 - ARO Solutions
 *
 * This code is licensed under the New BSD License (see LICENSE file in
 * the repository root directory for details)
 ********************************************************************************
 */

/**
 * @file	main.cpp
 * @author	Gunnar Ryder
 * @date	4/16/2021
 * @brief	Application main file
 *
 * Main entry point in to the application
 */

// System Includes
#include "main.h"
#include "cmsis_os.h"
#include "sys_init.h"

// User Includes
#include "GpioConfig_sptc.h"
#include "Gpio_stm32.h"

extern "C"
{
void MX_FREERTOS_Init(void);
}

int main()
{
    HAL_Init();
    SystemClock_Config();

    GpioConfig_sptc sptcConfig;
    Gpio_stm32 gpio(&sptcConfig);
    PinPtr led = gpio.configPin("LED");

    // Init scheduler
    //osKernelInitialize();  // Call init function for freertos objects (in freertos.c)
    //MX_FREERTOS_Init();

    // Start scheduler
    //osKernelStart();

    // We should never get here as control is now taken by the scheduler
    // Infinite loop
    while (1)
    {
        HAL_Delay(1000);
        gpio.toggleValue(led);
    }
}