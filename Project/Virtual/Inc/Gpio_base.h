/********************************************************************************
 * Copyright (c) 2021 - ARO Solutions
 *
 * This code is licensed under the New BSD License (see LICENSE file in
 * the repository root directory for details)
 ********************************************************************************
 */

/**
 * @file	Gpio_base.h
 * @author	Gunnar Ryder
 * @date	4/16/2021
 * @brief	Gpio virtual base class
 *
 * Virtually declares all required functions to be provided by the Gpio class.
 * This generalized class is could be used as a foundation point for translating
 * the system to another platform as a means for implementing unit testing fakes.
 */

#ifndef SPTC_GPIO_BASE_H
#define SPTC_GPIO_BASE_H

// System Includes
#include <cstdint>

// User Includes
#include "GpioConfig_base.h"

using namespace std;

class Gpio_base
{
public:
    explicit Gpio_base(GpioConfig_base *config) : _config(config), _portConfigMap(0)
    {};

    ~Gpio_base() = default;

    virtual const GpioConfig_base::PinConfig *configPin(const char *name) = 0;

    enum class DigitalValue
    {
        High,
        Low
    };

    virtual void toggleValue(PinPtr pin) = 0;
    virtual void setValue(PinPtr pin, DigitalValue val) = 0;
    virtual DigitalValue getValue(PinPtr pin) = 0;

protected:
    uint8_t findPort(const void *port);
    virtual void initPort(const void *port) = 0;

    uint8_t isConfigured(uint8_t portNum);
    void setConfigured(uint8_t portNum);

    static const void *_ports[];
    static const uint8_t _numPorts;

    const GpioConfig_base *_config;
    uint32_t _portConfigMap;

private:
};


#endif //SPTC_GPIO_BASE_H
