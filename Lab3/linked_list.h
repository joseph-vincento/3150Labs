#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_


typedef struct Node { 
	int data;
	struct Node* next;
    struct Node* jump;
} Node;


Node* build_new_linked_list(int list_size);
void delete_linked_list(Node* root);

int get_linked_list_data_item_value(Node* root, int node_number, int list_size);
void print_linked_list(Node* root);
bool update_data_in_linked_list(Node* root, int node_to_update, int update_val, int list_size);
void jump_pointers(Node* root, int jump_by);

#endif
