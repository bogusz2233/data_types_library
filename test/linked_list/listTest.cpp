#include <gtest/gtest.h>

extern "C" {
    #include "linked_list.h"
}
// Demonstrate some basic assertions.
TEST(HelloTest, BasicAssertions) {
    linked_list_t *list = linked_list_create();

    
    EXPECT_NE(list, (void *)NULL);
}