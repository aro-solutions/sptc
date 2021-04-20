/********************************************************************************
 * Copyright (c) 2021 - ARO Solutions
 *
 * This code is licensed under the New BSD License (see LICENSE file in
 * the repository root directory for details)
 ********************************************************************************
 */

/**
 * @file	GpioConfig_sptc.h
 * @author	Gunnar Ryder
 * @date	4/16/2021
 * @brief	Serial Pass Through Controller Gpio configuration derived class implementation
 *
 * Class used to define the Gpio configuration of the Serial Pass Through Controller
 */

// System Includes
#include <main.h>

// User Includes
#include "GpioConfig_sptc.h"

/// @brief Define the gpio configuration table
const GpioConfig_base::PinConfig GpioConfig_base::_pinConfig[] = {
        //   Name,          Direction,           Type,      Port,         Pin,           Initial Value,                 Mode,   Pull-Up/Down,                  Speed
        {"LED", Direction::Output, Type::Digital, GPIOA, LD2_Pin, GPIO_PIN_RESET, GPIO_MODE_OUTPUT_PP, GPIO_NOPULL, GPIO_SPEED_FREQ_LOW}
};

/// @brief Define the number of pins to configure
const uint8_t GpioConfig_base::_numPins = sizeof(GpioConfig_base::_pinConfig) / sizeof(GpioConfig_base::PinConfig);