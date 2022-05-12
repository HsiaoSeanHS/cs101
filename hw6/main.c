#include <stdio.h>
#include <stdlib.h>

/*typedef struct node {
    int data;
    struct node* next;
}node_t;*/

struct node {
    int data;
    struct node* next;
};
typedef struct node node_t;

node_t* allocate_node(int data) {
   node_t *newNode = malloc(sizeof(node_t));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void show_list(node_t* list) {
    node_t* tmp = list;
    while(tmp != NULL) {
        printf("[%d]->", tmp->data);
        tmp = tmp->next;
    }
    printf("NULL\n");
}

node_t* append_node(node_t* list, int new_data) {
    node_t* newNode = allocate_node(new_data);
    newNode->data = new_data;
    newNode->next     = NULL;
    if(list == NULL)
         list = newNode;
    else
    {
        node_t* lastNode = list;
        while(lastNode->next != NULL)
        {
            lastNode = lastNode->next;
        }
        lastNode->next = newNode;
    }
    return list;
}

void free_all_node(node_t* list) {
     while (list != NULL){ 
        node_t* temp = list; 
        list = list -> next;
        printf("free([%d])->",temp->data);
        free(temp);
    }
    printf("NULL");
}

node_t* add_node(node_t* head, int new_data) {
    node_t* new_node = malloc(sizeof(node_t));
    new_node->data = new_data;
    new_node->next = head;
    head = new_node;
    return head;
}

node_t* del_node(node_t* head, int n) {
     if (head == NULL)
      return head;
   node_t* temp = head;
    if (n == 0){
        head = temp->next;   
        free(temp);               
        return temp;
    }
    for (int i=0; temp!=NULL && i<n-1; i++)
         temp = temp->next;
    if (temp == NULL || temp->next == NULL)
         return temp;
    node_t *next = temp->next->next;
    free(temp->next);  
    temp->next = next;  
}


int main() {
    node_t* head = NULL;
    head = append_node(head, 0);
    show_list(head);
    head = append_node(head, 1);
    show_list(head);
    head = add_node(head, -1);
    show_list(head);
    del_node(head, 1);
    show_list(head);
    free_all_node(head);
    return 0;
}
