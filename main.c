#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void printall(list_t self){

    void *getItemByPntr = malloc(1);
    int  * int_get = getItemByPntr;
    uint16_t sizeofList = list_noOfItems(self);
    printf("list_noOfItems %d\n" ,sizeofList);

    for(int i = 1; i <= sizeofList; i++)
    {
        list_getItem((self),getItemByPntr,i);
        printf("list_getItem %d: %d\n" ,i,*int_get);
    }
}

void destroyList(list_t self)
{
    list_destroy(self);
}

void removeItem(list_t self,void *item)
{
    list_removeItem(self,item);
}

int main() {
    void *getItemByPntr = malloc(1);
    int  * int_get = getItemByPntr;
    list_t list = list_create();
    list_addItem(list,1);
    list_addItem(list,2);
    list_addItem(list,3);
    list_addItem(list,4);
    list_addItem(list,5);
    list_addItem(list,6);
    printall(list);
    printf("Removing 2 from the list\n");
    removeItem(list,2);
    printall(list);
    printf("Removing 1 from the list\n");
    removeItem(list,1);
    printall(list);
    printf("Removing 3 from the list\n");
    removeItem(list,3);
    printall(list);
    destroyList(list);
    return 0;
}
