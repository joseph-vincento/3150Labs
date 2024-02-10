#include <iostream>
#include "linked_list.h"

using namespace std;

int main() {
    int list_size = 6;
    Node* list = build_new_linked_list(list_size);
    print_linked_list(list);
    jump_pointers(list, 1);
    cout << endl;
    print_linked_list(list);
    delete_linked_list(list);
    list = nullptr; // explicitly set pointer to null after delete
    return 0;
}