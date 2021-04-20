/********************************************************************************
 * Copyright (c) 2021 - ARO Solutions
 *
 * This code is licensed under the New BSD License (see LICENSE file in
 * the repository root directory for details)
 ********************************************************************************
 */

/**
 * @file	Gpio_stm32.h
 * @author	Gunnar Ryder
 * @date	4/15/2021
 * @brief	STM32 Gpio interaction derived class declaration
 *
 * Derived Gpio class that implements the interaction a STM32's GPIO
 */

#ifndef SPTC_GPIOSTM32_H
#define SPTC_GPIOSTM32_H

// System Includes
// <none>

// User Includes
#include "GpioConfig_base.h"
#include "Gpio_base.h"


class Gpio_stm32 : public Gpio_base
{
public:
    explicit Gpio_stm32(GpioConfig_base *config);
    ~Gpio_stm32() = default;

    enum Ports
    {
        PortA,
        PortB,
        PortC,
        PortD,
        PortH
    };

    const GpioConfig_base::PinConfig *configPin(const char *name) override;

    void toggleValue(PinPtr pin) override;
    void setValue(PinPtr pin, DigitalValue val) override;
    DigitalValue getValue(PinPtr pin) override;

private:
    void initPort(const void *port) override;

    GPIO_InitTypeDef _initStruct = {0};
};


#endif //SPTC_GPIOSTM32_H
