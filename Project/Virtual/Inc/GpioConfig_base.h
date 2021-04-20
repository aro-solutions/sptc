/********************************************************************************
 * Copyright (c) 2021 - ARO Solutions
 *
 * This code is licensed under the New BSD License (see LICENSE file in
 * the repository root directory for details)
 ********************************************************************************
 */

/**
 * @file	GpioConfig_base.h
 * @author	Gunnar Ryder
 * @date	4/16/2021
 * @brief	Gpio Configuration class base
 *
 * Declares the gpio configuration base class and variables.  The derived class
 * will need to define its pin configuration and count.
 */

#ifndef SPTC_GPIOCONFIG_BASE_H
#define SPTC_GPIOCONFIG_BASE_H

// System Includes
#include <cstdint>
#include <string>

// User Includes
// <none>

using namespace std;

class GpioConfig_base
{
public:
    enum class Direction
    {
        Input,
        Output
    };

    enum class Type
    {
        Digital,
        Analog,
        Serial
    };

    struct PinConfig
    {
        string name;
        Direction dir;
        Type type;
        void *port;
        uint16_t pin;
        uint8_t initVal;
        uint32_t mode;
        uint32_t pull;
        uint32_t speed;
        uint32_t alt;
    };

    const PinConfig *getConfig(const char *name) const;

protected:
    uint8_t findPin(const char *name) const;

    static const PinConfig _pinConfig[];
    static const uint8_t _numPins;
};

// Public Type definitions
typedef const GpioConfig_base::PinConfig *PinPtr;


#endif //SPTC_GPIOCONFIG_BASE_H
