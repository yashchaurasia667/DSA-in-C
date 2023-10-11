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

//
//  Insertion
struct Node * insertionAsHead(struct Node *head, int data) {
    struct Node *new, *ptr = head;
    new = (struct Node *) malloc(sizeof(struct Node));

    new->data = data;
    new->next = head;

    while(ptr->next != head)
        ptr = ptr->next;
    
    ptr->next = new;

    return new;
}

struct Node * insertAt(struct Node *head, int data, int position) {
    struct Node *ptr = head, *new;
    new = (struct Node *) malloc(sizeof(struct Node));
    new->data = data;

    while(position-2) {
        ptr = ptr->next;
        position--;
    }

    new->next = ptr->next;
    ptr->next = new;

    return head;
}

//
//  Deletion
struct Node * deleteElement(struct Node *head, int position) {
    struct Node *prev = head, *current = head->next;

    if(position-1) {
        while(position-1) {
            prev = current;
            current = current->next;
            position--;
        }

        prev->next = current->next;
        return head;
    }

    return head->next;
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

    head = insertionAsHead(head, 45);
    head = insertAt(head, 99, 3);
    traversal(head);

    return 0;
}