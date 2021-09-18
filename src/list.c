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
}list_node_t;

typedef struct List
{
    list_size_t count_elements;
    list_node_t *head;
    list_node_t *tail;
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

void list_add_new_element_uint8(list_t *list, uint8_t value)
{
    list_node_t *node               = malloc(sizeof(list_node_t));
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
        list_node_t *lastElement = list->tail;

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