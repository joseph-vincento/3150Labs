#include <iostream>
#include <memory>
#include "linked_list_sp.h"

using namespace std;

void LinkedList::build_node_list(int k) {
    nodeCount = k;
    shared_ptr<Node> prev = nullptr;
    for(int i = nodeCount; i >= 1; i--) {
        shared_ptr<Node> new_node = make_shared<Node>(i, prev);
        prev = new_node;
    }
    root = prev;
}

LinkedList::CopyNode *LinkedList::build_copyNodes_weak_ptrs() {
    CopyNode *copy_nodes = new CopyNode[nodeCount];
    shared_ptr<Node> curr = root;
    for(int i = 0; i < nodeCount; i++) {
        copy_nodes[i].weak_node_ptr = curr;
        curr = curr->next;
    }

    return  copy_nodes;
}

void LinkedList::delete_node_shared_ptr_list() {
    nodeCount = 0;
    root = nullptr;  // all nodes in list will be out of scope when root = null, nodes will be auto deleted.
}

void LinkedList::print_node_list_shared_ptrs() {
    shared_ptr<Node> current = root;
    while(current) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void LinkedList::print_node_array_weak_ptrs(CopyNode *copy_nodes) {
    for(int i = 0; i < nodeCount; i++) {
        auto sp = copy_nodes[i].weak_node_ptr.lock();
        if(sp) {
            cout << sp->data << " ";
        } else {
            cout << "Expired ";
        }
    }
    cout << endl;
}

int LinkedList::get_node_count() {
    return nodeCount;
}

shared_ptr<LinkedList::Node> LinkedList::get_root() {
    return root;
}