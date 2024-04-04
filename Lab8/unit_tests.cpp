#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <memory>
#include "doctest.h"
#include "linked_list_sp.h"

using namespace std;

TEST_CASE("linked_list_sp") {
    SUBCASE("list copy") {
        LinkedList ll = LinkedList();
        ll.build_node_list(5);
        LinkedList::CopyNode *copies = ll.build_copyNodes_weak_ptrs();

        for(int i = 0; i < 5; i++) {
            auto sp = copies[i].weak_node_ptr.lock();
            CHECK(sp->data == i + 1);
        }
    }

    SUBCASE("List create") {
        LinkedList ll = LinkedList();

        CHECK(ll.get_node_count() == 0);
        CHECK(ll.get_root() == nullptr);

        ll.build_node_list(5);

        CHECK(ll.get_node_count() == 5);
        CHECK(ll.get_root() != nullptr);
    }

    SUBCASE("list delete") {
        LinkedList ll = LinkedList();
        ll.build_node_list(5);

        CHECK(ll.get_node_count() == 5);
        CHECK(ll.get_root() != nullptr);

        ll.delete_node_shared_ptr_list();

        CHECK(ll.get_node_count() == 0);
        CHECK(ll.get_root() == nullptr);
    }
}