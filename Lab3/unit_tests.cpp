#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
/*
  https://hackingcpp.com/cpp/tools/testing_frameworks.html
 */

#include "doctest.h"
#include "linked_list.h"

TEST_CASE("linked_list testing") {

    SUBCASE("build_new_linked_list") {
        int zero_linked_list_elts = 0;
        Node* zero_linked_list_elts_null_node = NULL;
        int one_element_linked_list = 1;
        int data_value_of_initial_linked_list_elt = 1;
        Node* linked_list_one_elt = build_new_linked_list(one_element_linked_list);
        int two_element_linked_list = 2;
        int data_value_of_second_elt = 2;
        Node* linked_list_two_elts = build_new_linked_list(two_element_linked_list);

        CHECK_EQ(
            build_new_linked_list(zero_linked_list_elts), 
            zero_linked_list_elts_null_node
        );
        CHECK_EQ(
            get_linked_list_data_item_value( 
                linked_list_one_elt,
                one_element_linked_list,
                one_element_linked_list
            ), 
            data_value_of_initial_linked_list_elt
        );

        CHECK_EQ(
            get_linked_list_data_item_value( 
                linked_list_two_elts,
                two_element_linked_list,
                two_element_linked_list
            ), 
            data_value_of_second_elt
        );
    }

    SUBCASE("delete linked list") {
        Node* linked_list = build_new_linked_list(5);
        delete_linked_list(linked_list);
        linked_list = nullptr;
        CHECK_FALSE(linked_list);
    }

    SUBCASE("pointer jump") {
        Node* list = build_new_linked_list(6);
        Node* head = list;
        int expected_order[6] = {3, 4, 5, 6 , 6, 6};

        jump_pointers(list, 1);
        for(int i = 0; i < 6; i++) {
            CHECK_EQ(head->jump->data, expected_order[i]);
            head = head->next;
        }
    }
}