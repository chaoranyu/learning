/****************************************************************
 * Copyright (C) UFO Quantum Technologies Co., Ltd. 2017-2020.
 * All rights reserved.
 *
 * @file	uq_memory_allocator.h
 * @author	ufo
 * @version	v1.0
 * @date	2017/03/26
 * @brief	
 * @details
 ****************************************************************/

#include <limits.h>
#include <assert.h>

#include "uq_memory_allocator.h"

/*
#ifndef min
#define min(a,b) ((a)<(b)?(a):(b))
#endif
*/

#ifndef UINT_MAX
#define UINT_MAX    4294967295U
#endif

#ifndef NULL
#define NULL    (void *)0
#endif

// static uint8_t *g_data;
void **g_data = NULL;
//static void **g_data = NULL;
static int g_MAX_NUM;
static int g_ELEM_SIZE;
//static int32_t *g_idx_array;

static int32_t g_cur_pos = 0;

void init_allocator(uint32_t element_size, uint32_t max_num)
{
    uint64_t max_space = element_size * max_num;
    assert(element_size && max_num);
    assert(max_num < UINT_MAX / element_size);/* or allocate max probable space */
    g_data = calloc(max_num, sizeof(void *));
    for (uint32_t i = 0; i < max_num; i++) {
        g_data[i] = (void *)calloc(element_size, sizeof(uint8_t));
    }

/*
    g_data = calloc(element_size * max_num);
    if (!g_data)
        return FALSE;
*/
    g_MAX_NUM = max_num;
    g_ELEM_SIZE = element_size;

/*
    g_idx_array = (int32_t *)calloc(sizeof(uint32_t) * max_num);
    if (!g_idx_array)
        return FALSE;

    for (uint32_t i = 0; i < g_MAX_NUM; i++) {
        g_idx_array = i;
    }
*/

//    return TRUE;
}

void get_buffer(void **p)
{
  // Error Check: Make sure we aren't exceeding the maximum storage space
  assert(g_cur_pos < g_MAX_NUM);

  *p = g_data[g_cur_pos++];
}

void free_buffer(void **p)
{
    assert(g_cur_pos > 0);

    g_data[--g_cur_pos] = (void *)*p;
    *p = NULL;
}

void release_allocator()
{
    for (uint32_t i = 0; i < g_MAX_NUM; i++) {
        for (uint32_t j = 0; j < g_MAX_NUM; j++)
            free(((uint8_t *)g_data[i])+j);
            //free((uint8_t **)&g_data[i][j]);
        g_data[i] = NULL;
    }
    free(g_data);
}

