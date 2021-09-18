#include <stdio.h>
#include "list.h"

static void print_list_info(list_t *list);

int main(int arg_count, char *arg_values[])
{
    list_t *list;

    arg_count;
    arg_values;

    printf("List example - uint8_t\n");
    list = list_create();

    printf("List created\n");
    print_list_info(list);

    list_add_new_element_uint8(list, 5);
    printf("\nElement dodany\n");
    print_list_info(list);

    list_add_new_element_uint8(list, 10);
    printf("\nElement dodany\n");
    print_list_info(list);

    list_add_new_element_uint8(list, 20);
    printf("\nElement dodany\n");
    print_list_info(list);
}

static void print_list_info(list_t *list)
{
    printf("List ptr:           %ld\n", (long int)list);
    //printf("List elemets:       %d\n", list->count_elements);
    //printf("Element in list:    %d\n", list->count_elements);
    //printf("HEAD ptr:           %ld\n", (long int)list->head);
    //printf("TAIL ptr:           %ld\n", (long int)list->tail);
}