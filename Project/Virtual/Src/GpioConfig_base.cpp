/********************************************************************************
 * Copyright (c) 2021 - ARO Solutions
 *
 * This code is licensed under the New BSD License (see LICENSE file in
 * the repository root directory for details)
 ********************************************************************************
 */

/**
 * @file	GpioConfig_base.cpp
 * @author	Gunnar Ryder
 * @date	4/16/2021
 * @brief	Gpio Configuration class base
 *
 * Implementation of the gpio configuration base class.  The derived class will
 * still need to define its pin configuration and count.
 */

// System Includes
#include <cstring>
#include <main.h>

// User Includes
#include "GpioConfig_base.h"

/// @brief Get a pin configuration based on the name
/// @param name - Name of the pin to configure
/// @return Pointer to the pin's configuration struct, nullptr if not found
const GpioConfig_base::PinConfig *GpioConfig_base::getConfig(const char *name) const
{
    uint8_t pinIndex = findPin(name);

    return (pinIndex != 0xFFu) ? &_pinConfig[pinIndex] : nullptr;
}

/// @brief Find the index of the pin based on the name provided
/// @param name - Name of the pin to find
/// @return Index of the pin to be found, 0xFFu if not found
uint8_t GpioConfig_base::findPin(const char *name) const
{
    // Determine the length of the name
    uint32_t nameLen = strlen(name);

    // Setup and iterate through all the pins
    uint8_t index = 0u;
    for (; index < _numPins; index++)
    {
        // Compare the name provided to the name in the configuration and make sure
        // they are the same length
        if (strncmp(name, _pinConfig[index].name.c_str(), nameLen) == 0 &&
            _pinConfig[index].name.length() == nameLen)
        {
            // If we found right one stop looking
            break;
        }
    }

    // Return the index if it isn't the count of pins, otherwise return 0xFF
    // If the index is the pin count we didn't find the pin
    return (index != _numPins) ? index : 0xFFu;
}