//
// Created by semin on 10/27/2020.
//
#include "list.h"
#include <stdlib.h>

struct list {
    void* value;
    struct list* next;
};

list_t list_create(void)
{
    struct list *_newList = NULL;
    _newList = malloc(sizeof(struct list));

    if (_newList == NULL)
    {
        return NULL;
    }
    _newList -> next = NULL;
    _newList-> value = NULL;
    return _newList;
}

list_ReturnCode_t list_addItem(list_t self, void* item)
{
    if(self == NULL)
    {
        return LIST_NULL;
    }
    /* Allocate node */
    struct list *new_node = NULL;
    new_node = malloc(sizeof(struct list));
    if(new_node == NULL)
    {
        return LIST_ERROR;
    }
    /* Put in the data  */
    new_node->value = item;

    /* 3. Make next node of the new list to NULL, cause we dont have a next item */
    new_node->next = NULL;

    /* get the last node in the list*/
    while (self->next != NULL)
    {
        /* keep on searching the last node, till the next will be NULL*/
        self = self->next;
    }
    /* 4. point the next item of the list to the new node */
    self->next = new_node;
    return LIST_OK;
}

list_ReturnCode_t list_getItem(list_t self, void** item, uint16_t index)
{
    if(self == NULL)
    {
        return LIST_NULL;
    }
    /* length will be an index*/
    uint16_t length = 0;
    //Pointer to pointer, so we are making a new pointer
    void *_tempItem;

    // Initializing self , so that we could use it
    struct list *_tmp = self;

    while(_tmp ->next != NULL)
    {
        //if input index is equals to our index, set pointer to pointer and return item;
        if (index == length)
        {
            _tempItem = _tmp ->value;
            *item = _tempItem;
            return LIST_OK;
        }
        else{
            // if the index is not that the user asked,keep on going till we find it.
            length++;
            // go to next node
            _tmp = _tmp -> next;
        }
    }
    return LIST_NOT_FOUND;
}

uint16_t list_noOfItems(list_t self)
{
    if(self == NULL)
    {
        return -1;
    }
    uint16_t length = 0;
    //initializing the list;
    struct list *_tempList = self;
    //taking first element in the list, because 0 is reserved.
    while(_tempList != NULL)
    {
        length++;
        _tempList = _tempList ->next;
    }
    /* Don't need to include 0 , cause it is a head*/
    return length-1;
}

list_ReturnCode_t list_removeItem(list_t self, void* item)
{
    if(self == NULL)
    {
        return LIST_NULL;
    }

    struct list* previousNode;
    struct list* nextNode;
    struct list *current = self;

    while(current->next != NULL)
    {
        previousNode = current;
        current = current ->next;
        nextNode = current ->next;
        if (current -> value == item)
        {
            previousNode->next = nextNode;
            free(current);
            return LIST_OK;
        }
    }
    return LIST_NOT_FOUND;
}

list_ReturnCode_t list_destroy(list_t self) {

    if(self == NULL)
    {
        return LIST_NULL;
    }
    // Saving the next node
    struct list *next_node;

    while( self != NULL)
    {
        // setting next node which will be from the list that we got
        next_node = self->next;
        // Free
        free(self);
        // setting Self to the nextNode, cause we need to proceed looking for the nodes inside the list
        self = next_node;
    }
    return LIST_OK;
}

