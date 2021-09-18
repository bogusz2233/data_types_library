#include <stdio.h>
#include "list.h"

static void print_list_info(list_t *list);
static void print_list_elements(list_t *list);

int main(int arg_count, char *arg_values[])
{
    list_t *list = NULL;

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

    print_list_elements(list);
}

static void print_list_info(list_t *list)
{
    printf("List ptr:           %ld\n", (long int)list);
    printf("List elemets:       %d\n", list_count_elements(list));
}

static void print_list_elements(list_t *list)
{
    list_size_t i;
    list_size_t count_elements = list_count_elements(list);
    uint8_t result;

    printf("Elements types uint8_t in list:\n");
    for (list_size_t i = 0; i < count_elements; i++)
    {
        if(list_get_element_type(list, i) == eList_data_type_uint8)
        {
            result = list_get_element_uint8(list, i);
            printf("[ %2d ] = %3d\n", i, result);
        }
    }
    
}