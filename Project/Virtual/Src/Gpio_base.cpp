/********************************************************************************
 * Copyright (c) 2021 - ARO Solutions
 *
 * This code is licensed under the New BSD License (see LICENSE file in
 * the repository root directory for details)
 ********************************************************************************
 */

/**
 * @file	Gpio_base.cpp
 * @author	Gunnar Ryder
 * @date	4/16/2021
 * @brief	Gpio virtual base class implementation
 *
 * Virtually declares all required functions to be provided by the Gpio class.
 * This generalized class is could be used as a foundation point for translating
 * the system to another platform as a means for implementing unit testing fakes.
 */

// System Includes
#include <cstdint>

// User Includes
#include "Gpio_base.h"

/// @brief Sets a port as configured
/// @param portNum - Index of the configured port
void Gpio_base::setConfigured(uint8_t portNum)
{
    _portConfigMap |= (1 << portNum);
}

/// @brief Determines if a port is configured
/// @param portNum - Index of the configured port
/// @return Error: -1, Zero: not configures, One: configured
uint8_t Gpio_base::isConfigured(uint8_t portNum)
{
    uint8_t status = 0;
    if (portNum == _numPorts)
    {
        status = -1;
    }
    else
    {
        status = _portConfigMap & (1 << portNum);
    }

    return status;
}

/// @brief Finds the position of the port provided
/// @param port - Port to be indexed
/// @return Index of the port provided
uint8_t Gpio_base::findPort(const void *port)
{
    uint8_t index = 0;
    for (; index < _numPorts; index++)
    {
        if (_ports[index] == port)
        {
            break;
        }
    }

    return index;
}