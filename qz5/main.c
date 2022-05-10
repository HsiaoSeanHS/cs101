#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node* next;
} node_t;


node_t* allocate_node(int data){
	node_t* next_node = (node_t*)calloc(1, sizeof(node_t));
	next_node->data = data;
	next_node->next = NULL;
	return next_node;
}

void show_list(node_t* list) {
	while(list != NULL) {
		printf("[%d]->", list->data);
		list = list->next;
	}
	printf("null\n");
}

node_t* append_node(node_t* list, int new_data) {
	if(list == NULL) {
		return allocate_node(new_data);
	}
	node_t* head = list;
	//find tail
	while(list->next != NULL) {
		list = list->next;
	}
	list->next = allocate_node(new_data);
	return head;
}

void free_all_node(node_t* list) {
	while(list != NULL) {
		printf("free([%d])->", list->data);
		list = list->next;
	}
	printf("null\n");
}

int main(void) {
	node_t* head = NULL;
	head = append_node(head, 0);
	show_list(head);
	head = append_node(head, 11);
	show_list(head);
	head = append_node(head, 222);
	show_list(head);
	head = append_node(head, 3333);
	show_list(head);
	free_all_node(head);
	return 0;
}
