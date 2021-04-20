/********************************************************************************
 * Copyright (c) 2021 - ARO Solutions
 *
 * This code is licensed under the New BSD License (see LICENSE file in
 * the repository root directory for details)
 ********************************************************************************
 */

/**
 * @file	sys_init.h
 * @author	Gunnar Ryder
 * @date	4/16/2021
 * @brief	System initialization declarations
 *
 * System initialization declarations of functions provided by the STM32CubeMX main.c
 * Moved here since we're not using their main or generated GPIO files.
 */

#ifndef SPTC_SYS_INIT_H
#define SPTC_SYS_INIT_H

#include "main.h"

#ifdef __cplusplus
extern "C" {
#endif

void SystemClock_Config(void);

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);

void Error_Handler(void);

#ifdef __cplusplus
};
#endif

#endif //SPTC_SYS_INIT_H
