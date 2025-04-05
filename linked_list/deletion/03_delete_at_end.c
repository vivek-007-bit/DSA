/*This program illustrates how to delete a node at the end of a linked list*/
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next; // self referncing structure
};


struct Node *deletelastNode(struct Node *head){
    struct Node *p = head;
    struct Node *q = head->next;

    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    
    p->next = NULL;
    free(q);
    return head;
}


void linkedListTraversal(struct Node *ptr)
{
    int count = 0;
    while (ptr != NULL)
    {
        count++;
        printf("Element %d : %d\n", count, ptr->data);
        ptr = ptr->next;
    }
}

// A function to display the visual representation of the linked list
void display(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("|  %d  |", ptr->data);
        if (ptr->next != NULL)
        {
            printf(" --> ");
        }
        ptr = ptr->next;
    }
    printf(" --> NULL\n");
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    struct Node *fifth;

    struct Node *temp;

    // Memory allocation for the nodes in the linked list
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

    printf("\n...The Elements of the linked list are...\n");
    linkedListTraversal(head);

    printf("\n... Deleting Last Node...\n");
    head = deletelastNode(head);
    printf("\n");
    display(head);

    // freeing all the nodes
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}