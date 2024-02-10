#include <iostream>

#include "linked_list.h"


using namespace std;


Node* build_new_linked_list(int list_size) {
    /*
    build_new_linked_list:
    returns a pointer to the first node in the linked list
    If 0 == total_new_elements, then return nullptr
    */
    if (0 >= list_size) {
        return nullptr;
    } else {
        Node* root = nullptr;
        Node* current_node = nullptr;

        for(int i = 0; i < list_size; i++) {
            Node* new_node = new Node;
            new_node->data = i + 1;
            new_node->next = nullptr;
            new_node->jump = nullptr;
            if(!root) {
                root = new_node;
                current_node = new_node;
            }
            else {
                current_node->next = new_node;
                current_node->jump = new_node;
                current_node = new_node;
            }
        }

        return root;
    }
}

int get_linked_list_data_item_value(Node* root, int node_number, int list_size) {
    if(node_number > list_size) {
        return -1;
    }

    for(int i = 0; i < node_number - 1; i++) {
        root = root->next;
    }

    return root->data;
}

void print_linked_list(Node* root) {
    while(root) {
        cout << "Current node's data: " << root->data << " ";
        if(root->jump != nullptr) {
            cout << "Jump node's data: " << root->jump->data << endl;
        } else {
            cout << "Not yet jumped." << endl;
        }
        root = root->next;
    }
}


bool update_data_in_linked_list(Node* root, int node_to_update, int update_val, int list_size) {
    /*
    update_data_in_linked_list:
    Returns false if node_to_update > list_size
    Returns true otherwise
    */
    if(node_to_update > list_size) {
        return false;
    }
    else {
        for(int i = 0; i < node_to_update - 1; i++) {
            root = root->next;
        }
        root->data = update_val;
        return true;
    }
}

void delete_linked_list(Node* root) {
    if(root == nullptr) {
        return;
    }
    delete_linked_list(root->next);
    delete root;
    root = nullptr; // explicitly set pointer to null after delete
}

void jump_pointers(Node* root, int jump_by) {
    Node* current_node = root;
    while(current_node->next != nullptr) {
        for(int i = 0; i < jump_by; i++) {
            if (current_node->jump->next != nullptr) {
                current_node->jump = current_node->jump->next;
            } else {
                current_node->jump = current_node->jump;
            }
        }
        current_node = current_node->next;
    }
    // set tail node to jump to itself
    current_node->jump = current_node;
}