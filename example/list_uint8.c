#include <stdio.h>
#include "list.h"

static void print_list_info(list_t *list);

int main(int arg_count, char *arg_values[])
{
    list_t *list;

    arg_count;
    arg_values;

    printf("List example - uint8_t\n");
    list = list_create_uint8();
    
    printf("List created\n");
    print_list_info(list);
}

static void print_list_info(list_t *list)
{
    printf("List ptr:           %ld\n", (long int)list);
    printf("List elemets:       %d\n", list->countElements);
    printf("Element in list:    %d\n", list->countElements);
    printf("HEAD ptr:           %ld\n", (long int)list->head);
}