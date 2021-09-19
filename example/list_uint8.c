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

    list_uint8_add_new_element(list, 5);
    list_uint8_add_new_element(list, 10);
    list_uint8_add_new_element(list, 20);
    list_uint8_add_new_element(list, 48);
    list_uint8_add_new_element(list, 51);
    list_uint8_add_new_element(list, 120);


    print_list_info(list);
    print_list_elements(list);

    list_remove_elements(list,2);
    list_remove_elements(list,4);

    print_list_info(list);
    print_list_elements(list);

    list_remove_elements(list,0);
    print_list_info(list);
    print_list_elements(list);

    list_remove_elements(list,2);
    print_list_info(list);
    print_list_elements(list);

    list_uint8_set_element(list, 1, 25);
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
        if(list_get_element_type(list, i) == list_data_type_uint8)
        {
            result = list_uint8_get_element(list, i);
            printf("[ %2d ] = %3d\n", i, result);
        }
    }
}
