/*This program illustrates how to insert a node at the end of a linked list*/
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next; // self referncing structure
};


struct Node *insertAtEnd(struct Node *head){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;

    int data = 0;
    printf("\n...Enter the value of the Node: ");
    scanf("%d", &data);

    ptr->data = data;

    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
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

    printf("\n... Insertion...\n");
    head = insertAtEnd(head);
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