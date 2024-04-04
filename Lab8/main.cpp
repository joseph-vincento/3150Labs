#include <iostream>
#include "linked_list_sp.h"

using namespace std;

int main() {
    cout << "Creating a new LinkedList struct, node count = 10" << endl;
    LinkedList ll = LinkedList();
    ll.build_node_list(5);
    
    cout << "Shared pointer list:" << endl;
    ll.print_node_list_shared_ptrs();

    cout << "Creating an array of CopyNodes from the shared pointer list" << endl;
    LinkedList::CopyNode *copies = ll.build_copyNodes_weak_ptrs();

    cout << "Weak pointer array:" << endl;
    ll.print_node_array_weak_ptrs(copies);

    cout << "Deleting shared pointer list" << endl;
    ll.delete_node_shared_ptr_list();

    cout << "Shared pointer list after deletion:" << endl;
    ll.print_node_list_shared_ptrs();
    
    cout << "Weak pointer array after deletion:" << endl;
    ll.print_node_array_weak_ptrs(copies);

    delete[] copies;

    return 0;
}