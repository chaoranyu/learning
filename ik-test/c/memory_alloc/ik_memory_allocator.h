/****************************************************************
 * Copyright (C) Beijing Yufeng Technologies Co., Ltd. 2017-2020.
 * All rights reserved.
 *
 * @file	ik_memory_allocator.h
 * @author	Yuchaoran
 * @version	v1.0
 * @date	2017/03/26
 * @brief	
 * @details
 ****************************************************************/

#include <stdint.h>

void init_allocator(uint32_t element_size, uint32_t max_num);

void get_buffer(void **p);

void free_buffer(void **p);

void release_allocator();
