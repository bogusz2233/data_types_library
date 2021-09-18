#include <stdlib.h>
#include "list.h"

static uint8_t is_list_empty(list_t *);

list_t *list_create(void)
{
    list_t *list        = malloc(sizeof(list_t));
    list->countElements = 0;
    list->head          = NULL;

    return list;
}

void list_add_new_element_uint8(list_t *list, uint8_t value)
{
    list_node_t *node           = malloc(sizeof(list_node_t));
    node->dataPtr               = malloc(sizeof(uint8_t));
    node->dataType              = eList_data_type_uint8;
    *((uint8_t *)node->dataPtr) = value;

    if (is_list_empty(list))
    {
        node->next              = NULL;
        node->previous          = NULL;
        list->head = list->tail = node;
        list->countElements     = 1;
    }
    
}

static uint8_t is_list_empty(list_t *list)
{
    if(list->countElements == 0)    return 1;
    else                            return 0;
}