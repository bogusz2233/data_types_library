#include <gtest/gtest.h>

extern "C" {
    #include "linked_list.h"
}

static linked_list_t *list = NULL;

class ListTest: public ::testing::Test
{

protected:
   void SetUp(void)
   {
       list = linked_list_create();
   }

   void TearDown(void)
   {
       linked_list_destroy(list);
   }
};

TEST_F(ListTest, IsListCreated) {
    EXPECT_NE((void *)NULL, list);
}

TEST_F(ListTest, Add2Elements) {
    linked_list_element_uint8_add_new(list, 10);
    linked_list_element_uint8_add_new(list, 50);

    EXPECT_EQ(2, linked_list_count_elements(list));
}

TEST_F(ListTest, removeElements)
{
    linked_list_element_uint8_add_new(list, 10);
    linked_list_element_uint8_add_new(list, 50);
    linked_list_element_uint8_add_new(list, 35);
    linked_list_element_uint8_add_new(list, 45);

    linked_list_element_remove(list, 1);
    linked_list_element_remove(list, 0);


    ASSERT_EQ(2, linked_list_count_elements(list));
    ASSERT_EQ(35, linked_list_element_uint8_get(list,0));
}
