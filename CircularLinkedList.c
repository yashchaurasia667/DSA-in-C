#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

//
//  Traversal
void traversal(struct Node *head) {
    struct Node *ptr = head;

    do {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    } 
    while(ptr!=head);
}

int main() {

    struct Node *head;
    struct Node *second;
    struct Node *third;

    //  Allocate memory for the Nodes in linked list in Heap
    head = (struct Node *) malloc(sizeof(struct Node));
    second = (struct Node *) malloc(sizeof(struct Node));
    third = (struct Node *) malloc(sizeof(struct Node));

    head->data = 7;
    head->next = second;        // Linking head to the second node


    second->data = 8;
    second->next = third;        // Linking head to the second node


    third->data = 9;
    third->next = head;        // Linking head to the second node

    traversal(head);

    return 0;
}