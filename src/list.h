#ifndef __LIST_H__
#define __LIST_H__

#include <stdint.h>

typedef struct List list_t;
typedef uint32_t    list_size_t;

typedef enum
{
    list_data_type_uint8,
    list_data_type_none    = -1
}list_data_type_t;

typedef enum
{
    list_status_SUCCESS,
    list_status_LIST_EMPTY,
    list_status_INDEX_BEYOND
}list_status_t;

list_t              *list_create(void);
list_size_t         list_count_elements(list_t *list);
list_data_type_t    list_get_element_type(list_t *list, list_size_t index);
list_status_t       list_remove_elements(list_t *list, list_size_t index);
void                list_clear(list_t *list);
void                list_destroy(list_t *list);

void    list_add_new_element_uint8(list_t *list, uint8_t value);
uint8_t list_get_element_uint8(list_t *list, list_size_t index);


#endif /* __LIST_H__ */