#ifndef __LIST_H__
#define __LIST_H__

#include <stdint.h>

typedef enum
{
    eList_data_type_uint8
}eList_data_type_t;

typedef struct node
{
    void        *dataPtr;
    uint32_t    index;
    struct node *next; 
}list_node_t;

typedef struct List
{
    eList_data_type_t   dataType;
    uint32_t            countElements;
    list_node_t         *head;
}list_t;


list_t *list_create_uint8();
void    list_add_new_element_uint8(list_t *list, uint8_t value);
uint8_t list_get_element_uint8(list_t *list, uint32_t index);
void    list_destroy(list_t *list);

#endif /* __LIST_H__ */