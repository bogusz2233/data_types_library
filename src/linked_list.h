#ifndef __LIST_H__
#define __LIST_H__

#include <stdint.h>

typedef struct List linked_list_t;
typedef uint32_t    linked_list_size_t;

typedef enum
{
    list_data_type_uint8,
    list_data_type_none    = -1
}list_data_type_t;

typedef enum
{
    list_status_SUCCESS,
    list_status_LIST_EMPTY,
    list_status_INDEX_BEYOND,
    list_status_LIST_NULL_PTR
}list_status_t;

linked_list_t       *linked_list_create(void);
linked_list_size_t  linked_list_count_elements(linked_list_t *list);
void                linked_list_clear(linked_list_t *list);
void                linked_list_destroy(linked_list_t *list);

list_data_type_t    linked_list_element_get_type(linked_list_t *list, linked_list_size_t index);
list_status_t       linked_list_element_remove(linked_list_t *list, linked_list_size_t index);

void                linked_list_element_uint8_add_new(linked_list_t *list, uint8_t value);
uint8_t             linked_list_element_uint8_get(linked_list_t *list, linked_list_size_t index);
list_status_t       linked_list_element_uint8_set(linked_list_t *list, linked_list_size_t index, uint8_t value);

#endif /* __LIST_H__ */
