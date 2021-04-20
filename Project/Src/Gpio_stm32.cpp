/********************************************************************************
 * Copyright (c) 2021 - ARO Solutions
 *
 * This code is licensed under the New BSD License (see LICENSE file in
 * the repository root directory for details)
 ********************************************************************************
 */

/**
 * @file	Gpio_stm32.cpp
 * @author	Gunnar Ryder
 * @date	4/15/2021
 * @brief	STM32 Gpio interaction derived class implementation
 *
 * Derived Gpio class that implements the interaction a STM32's GPIO
 */

// System Includes
#include <cstdint>
#include <cstring>
#include <main.h>
#include <stm32l4xx_hal_gpio.h>

// User Includes
#include "GpioConfig_base.h"
#include "Gpio_base.h"
#include "Gpio_stm32.h"

/// @brief Class constructor
/// @param config - Gpio configuration that's passed to the base class
Gpio_stm32::Gpio_stm32(GpioConfig_base *config) : Gpio_base(config)
{}

/// @brief Define port array for mapping
const void *Gpio_base::_ports[] = {
        [Gpio_stm32::Ports::PortA] = GPIOA,
        [Gpio_stm32::Ports::PortB] = GPIOB,
        [Gpio_stm32::Ports::PortC] = GPIOC,
        [Gpio_stm32::Ports::PortD] = GPIOC,
        [Gpio_stm32::Ports::PortH] = GPIOH,
};

/// @brief Define the number of ports provided
const uint8_t Gpio_base::_numPorts = sizeof(_ports) / sizeof(void *);

/// @brief Initializes clock for provided GPIO port
/// @param portNum Port to enable clock for - Providing a non-valid port do nothing
void Gpio_stm32::initPort(const void *port)
{
    // Find the port
    uint8_t portNum = findPort(port);

    // Determine if the port is configured
    if (isConfigured(portNum) == false)
    {
        // Port isn't configured, so let's configure it
        switch (portNum)
        {
            case PortA:
            {
                __HAL_RCC_GPIOA_CLK_ENABLE();
                break;
            }
            case PortB:
            {
                __HAL_RCC_GPIOB_CLK_ENABLE();
                break;
            }
            case PortC:
            {
                __HAL_RCC_GPIOC_CLK_ENABLE();
                break;
            }
            case PortD:
            {
                __HAL_RCC_GPIOD_CLK_ENABLE();
                break;
            }
            case PortH:
            {
                __HAL_RCC_GPIOH_CLK_ENABLE();
                break;
            }
            default:
            {
                // Do nothing...
                break;
            }
        }

        // If the port number is valid, set it as configured
        if (portNum < _numPorts)
        {
            setConfigured(portNum);
        }
    }

}

/// @brief Configure a Gpio pin
/// @param name - Name of the pin to configure
/// @return Constant pointer to the pin that was configured
const GpioConfig_base::PinConfig *Gpio_stm32::configPin(const char *name)
{
    // Reset the initialization structure
    memset(&_initStruct, 0, sizeof(GPIO_InitTypeDef));

    // Fet the configuration for the pin we need to handle
    const GpioConfig_base::PinConfig *config = _config->getConfig(name);

    // Determine if the pin name provided was valid
    if (config != nullptr)
    {
        // Initialize the port and write the initial pin state
        initPort(config->port);
        HAL_GPIO_WritePin((GPIO_TypeDef *) config->port, config->pin, (GPIO_PinState) config->initVal);

        // Call to the system to initialize the pin
        _initStruct.Pin = config->pin;
        _initStruct.Mode = config->mode;
        _initStruct.Pull = config->pull;
        _initStruct.Speed = config->speed;
        HAL_GPIO_Init((GPIO_TypeDef *) config->port, &_initStruct);
    }
    else
    {
        /// @todo Add error case for nullptr
    }

    return config;
}

/// @brief Toggle the value of the pin provided
/// @param pin - Pointer to the configuration of the pin to take action on
void Gpio_stm32::toggleValue(PinPtr pin)
{
    HAL_GPIO_TogglePin((GPIO_TypeDef *) pin->port, pin->pin);
}

/// @brief Set the value of the pin provided
/// @param pin - Pointer to the configuration of the pin to take action on
/// @param val - Value to set for the pin
void Gpio_stm32::setValue(PinPtr pin, DigitalValue val)
{
    GPIO_PinState value = (val == DigitalValue::High) ? GPIO_PIN_SET : GPIO_PIN_RESET;
    HAL_GPIO_WritePin((GPIO_TypeDef *) pin->port, pin->pin, value);
}

/// @brief Read the value of the pin provided
/// @param pin - Pointer to the configuration of the pin to take action on
/// @return Current value for the pin provided
Gpio_base::DigitalValue Gpio_stm32::getValue(PinPtr pin)
{
    GPIO_PinState readVal = HAL_GPIO_ReadPin((GPIO_TypeDef *) pin->port, pin->pin);
    return (readVal == GPIO_PIN_SET) ? DigitalValue::High : DigitalValue::Low;
}