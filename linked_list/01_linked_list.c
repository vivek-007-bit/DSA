/*This program illustrates the creation of linked list*/
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next; // self referncing structure
};

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    struct Node *fifth;

    struct Node *temp;

    //Memory allocation for the nodes in the linked list 
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
    fifth = (struct Node *)malloc(sizeof(struct Node));


    // linking all the nodes
    head->data = 55;
    head->next = second;

    second->data = 97;
    second->next = third;

    third->data = 5;
    third->next = fourth;

    fourth->data = 25;
    fourth->next = fifth;

    fifth->data = 46;
    fifth->next = NULL;

    //freeing all the nodes
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
    
    return 0;
}
