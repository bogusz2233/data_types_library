#include <stdlib.h>
#include "list.h"

typedef struct Node
{
    void                *data_ptr;
    list_data_type_t    data_type;
    uint32_t            index;
    struct Node         *next;
    struct Node         *previous; 
}node_t;

typedef struct List
{
    list_size_t count_elements;
    node_t      *head;
    node_t      *tail;
};

static uint8_t  is_list_empty(list_t *);
static node_t   *get_node_at(list_t *, list_size_t);
static uint8_t  is_element_first(list_t *, node_t *);
static uint8_t  is_element_last(list_t *, node_t *);

list_t *list_create(void)
{
    list_t *list            = malloc(sizeof(list_t));
    list->count_elements    = 0;
    list->head              = NULL;
    list->tail              = NULL;

    return list;
}

list_size_t list_count_elements(list_t *list)
{
    if(list == NULL)    return -1;
    else                return list->count_elements;
}

list_data_type_t list_get_element_type(list_t *list, list_size_t index)
{
    node_t *node_ref;

    if(list == NULL )                   return list_data_type_none;
    if(index >= list->count_elements)   return list_data_type_none;

    node_ref = get_node_at(list, index);
    
    return node_ref->data_type;
}

list_status_t list_remove_elements(list_t *list, list_size_t index)
{
    node_t *current_element;
    node_t *next_element;
    node_t *previous_element;

    if(is_list_empty(list))             return list_status_LIST_EMPTY;
    if(index >= list->count_elements)   return list_status_INDEX_BEYOND;

    current_element     = get_node_at(list, index);
    next_element        = current_element->next;
    previous_element    = current_element->previous;

    if( list->count_elements == 1 )
    {
        list->head = list->tail = NULL;
    }
    else if( is_element_first(list, current_element) )
    {
        // when element is first, point to itself as previous 
        next_element->previous  = next_element;
        list->head              = next_element;
    }
    else if( is_element_last(list, current_element) )
    {
        // when element is last, point to itself as next
        previous_element->next  = previous_element;
        list->tail              = previous_element;
    }
    else
    {
        next_element->previous = previous_element;
        previous_element->next = next_element;
    }

    free(current_element->data_ptr);
    free(current_element);
    list->count_elements--;

    return list_status_SUCCESS;
}

void list_uint8_add_new_element(list_t *list, uint8_t value)
{
    node_t *node                    = malloc(sizeof(node_t));
    node->data_ptr                  = malloc(sizeof(uint8_t));
    node->data_type                 = list_data_type_uint8;
    node->next                      = node;
    *((uint8_t *)node->data_ptr)    = value;

    if (is_list_empty(list))
    {
        node->previous              = node;
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

uint8_t list_uint8_get_element(list_t *list, list_size_t index)
{
    node_t * node_ref;

    if(list == NULL )                               return 0;
    if(index >= list->count_elements)               return 0;
   
    node_ref = get_node_at(list, index);

    if(node_ref->data_type == list_data_type_uint8) return *((uint8_t *)node_ref->data_ptr);

    return 0;
}


static uint8_t is_list_empty(list_t *list)
{
    if(list->count_elements == 0)       return 1;
    else                                return 0;
}

static node_t *get_node_at(list_t *list, list_size_t index)
{
    node_t *node_ref;
    list_size_t i =0;

    node_ref = list->head;

    for (i = 0; i < index; i++)
    {
        node_ref = node_ref->next;
    }

    return node_ref;
}

static uint8_t is_element_first(list_t *list, node_t *element)
{
    return list->head == element;
}

static uint8_t is_element_last(list_t *list, node_t *element)
{
    return list->tail == element;
}