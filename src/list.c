#include <stdlib.h>
#include "list.h"

static uint8_t is_list_empty(list_t *);

typedef struct Node
{
    void                *data_ptr;
    eList_data_type_t   data_type;
    uint32_t            index;
    struct Node         *next;
    struct Node         *previous; 
}node_t;

typedef struct List
{
    list_size_t count_elements;
    node_t *head;
    node_t *tail;
};

list_t *list_create(void)
{
    list_t *list            = malloc(sizeof(list_t));
    list->count_elements    = 0;
    list->head              = NULL;

    return list;
}

list_size_t list_count_elements(list_t *list)
{
    if(list == NULL)    return -1;
    else                return list->count_elements;
}

eList_data_type_t   list_get_element_type(list_t *list, list_size_t index)
{
    node_t *node_ref;
    list_size_t i =0;

    if(list == NULL )                   return eList_data_type_none;
    if(index >= list->count_elements)   return eList_data_type_none;

    node_ref = list->head;

    for (i = 0; i < index; i++)
    {
        node_ref = node_ref->next;
    }
    
    return node_ref->data_type;
}

void list_add_new_element_uint8(list_t *list, uint8_t value)
{
    node_t *node               = malloc(sizeof(node_t));
    node->data_ptr                  = malloc(sizeof(uint8_t));
    node->data_type                 = eList_data_type_uint8;
    node->next                      = NULL;
    *((uint8_t *)node->data_ptr)    = value;

    if (is_list_empty(list))
    {
        node->previous              = NULL;
        list->head = list->tail     = node;
    }
    else
    {
        node_t *lastElement = list->tail;

        node->previous      = lastElement;
        lastElement->next   = list->tail = node;
    }

    list->count_elements++;
}

static uint8_t is_list_empty(list_t *list)
{
    if(list->count_elements == 0)       return 1;
    else                                return 0;
}