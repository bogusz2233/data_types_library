#include <stdlib.h>
#include "list.h"

static uint8_t is_list_empty(list_t *);

list_t *list_create(void)
{
    list_t *list            = malloc(sizeof(list_t));
    list->count_elements    = 0;
    list->head              = NULL;

    return list;
}

void list_add_new_element_uint8(list_t *list, uint8_t value)
{
    list_node_t *node            = malloc(sizeof(list_node_t));
    node->data_ptr               = malloc(sizeof(uint8_t));
    node->data_type              = eList_data_type_uint8;
    *((uint8_t *)node->data_ptr) = value;

    if (is_list_empty(list))
    {
        node->next              = NULL;
        node->previous          = NULL;
        list->head = list->tail = node;
        list->count_elements     = 1;
    }
    else
    {
        list_node_t *last_node;
        
    }
}

static uint8_t is_list_empty(list_t *list)
{
    if(list->count_elements == 0)    return 1;
    else                            return 0;
}