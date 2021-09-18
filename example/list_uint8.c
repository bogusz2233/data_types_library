#include <stdio.h>
#include "list.h"

int main(int arg_count, char *arg_values[])
{
    list_t *list;

    arg_count;
    arg_values;

    printf("List example - uint8_t\n");
    list = list_create_uint8();
    
    printf("List of uint8_t elements created %ld\n", (long int)list);
    printf("List ptr: %d\n", list->countElements);
    printf("Element in list: %d\n", list->countElements);
    printf("HEAD ptr: %ld\n", (long int)list->head);
}