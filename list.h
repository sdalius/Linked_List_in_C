#pragma once

#include <stdint.h>

typedef struct list* list_t;

typedef enum {
    LIST_OK
    ,LIST_EMPTY
    ,LIST_NOT_FOUND
    ,LIST_NULL
    ,LIST_ERROR
} list_ReturnCode_t;

list_t list_create(void);

list_ReturnCode_t list_destroy(list_t self);

list_ReturnCode_t list_addItem(list_t self, void* item);

list_ReturnCode_t list_getItem(list_t self, void** item, uint16_t index);

list_ReturnCode_t list_removeItem(list_t self, void* item);

uint16_t list_noOfItems(list_t self);