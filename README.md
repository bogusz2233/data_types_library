# Data types library
Library to with data structures.


## Linked list
Elements of this structures are linked with each other. You can add new element
to the end or delete / edit element at any index.

#### linked_list_create(void)
Create and return handler to work with this data types. Should be called when you start
work with this data structures 

##### Return: 
`linked_list_t *`

#### linked_list_count_elements( linked_list_t *list );
Return value that show how many element is in list
##### Return: 
`list_size_t`

### Example

```c
linked_list_size_t element_count;
list_t *list = list_create();                       // create handler to work with data

//add some elements to list
linked_list_element_uint8_add_new(list, 5);
linked_list_element_uint8_add_new(list, 10);
linked_list_element_uint8_add_new(list, 10);
linked_list_element_uint8_add_new(list, 20);

linked_list_element_remove(list,2);                 // remove last elements

element_count = inked_list_count_elements(list);    // Should return 2

linked_list_destroy(list);                          //realse resources
```