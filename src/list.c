#include <stdlib.h>
#include "list.h"

list_t *list_create_uint8()
{
    list_t *list        = malloc(sizeof(list_t));
    list->dataType      = eList_data_type_uint8;
    list->countElements = 0;
    list->head          = NULL;

    return list;
}
