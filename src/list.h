#ifndef __LIST_H__
#define __LIST_H__

#include <stdint.h>

typedef int32_t list_size_t;

typedef enum
{
    eList_data_type_uint8,

    eList_data_type_none = -1
}eList_data_type_t;

typedef struct List list_t;

list_t              *list_create(void);
list_size_t         list_count_elements(list_t *list);
eList_data_type_t   list_get_element_type(list_t *list, list_size_t index);
list_t              *list_clear(void);
void                list_destroy(list_t *list);

void    list_add_new_element_uint8(list_t *list, uint8_t value);
uint8_t list_get_element_uint8(list_t *list, list_size_t index);


#endif /* __LIST_H__ */