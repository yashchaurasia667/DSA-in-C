#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

//
//  Traversal
void traversal(struct Node *head) {
    struct Node *new = head;

    while(new != NULL) {
        printf("%d", new->data);
    }
}

//
//  Insertion
struct Node * insertAt(struct Node *head, int data, int position){
    struct Node *new, *curr = head;
    new = (struct Node *) malloc(sizeof(struct Node));

    if(position != 1) {
        while(position-2) {
            curr = curr->next;
            position--;
        }

        new->next = curr->next;
        new->prev = curr;
        curr->next = new;
        return head;
    }

    new->prev = NULL;
    new->next = head;
    head->prev = new;
    return new;
}

int main() {
    struct Node *head;
    struct Node *second;
    struct Node *third;

    head = (struct Node *) malloc(sizeof(struct Node));
    second = (struct Node *) malloc(sizeof(struct Node));
    third = (struct Node *) malloc(sizeof(struct Node));

    head->data = 1;
    head->prev = NULL;
    head->next = second;

    second->data = 2;
    second->prev = head;
    second->next = third;

    third->data = 3;
    third->prev = second;
    third->next = NULL;

    return 0;
}