#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void linked_list_traversal(struct Node *head)
{
    struct Node *ptr = head;

    do
    {
        printf("Elements are : %d\n", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
}

struct Node * insertion_at_first(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    struct Node *p = head->next;
    while (p->next != head)
    {
        p = p->next;
    }

    p->next = ptr;
    ptr->next = head;
    head = ptr;
    return head;
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 3;
    head->next = second;
    second->data = 6;
    second->next = third;
    third->data = 7;
    third->next = fourth;
    fourth->data = 1;
    fourth->next = head;
    printf("Elements before insertion :-\n");
    linked_list_traversal(head);
    printf("\nElements after insertion :-\n");
    head = insertion_at_first(head,69);
    linked_list_traversal(head);
}