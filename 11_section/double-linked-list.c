
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
    struct Node* prev;
    int data;
    struct Node* next;
} Node;

typedef struct
{
    Node* head;
    Node* tail;
    int node_count;
} DLinkedList;

DLinkedList* dll_create(int* arr, int size);
void dll_display(DLinkedList* list, bool direction);
void ll_free(DLinkedList* list);
void dll_insert(DLinkedList* list, int value, int position);
int dll_delete(DLinkedList* list, int position);
void dll_reverse(DLinkedList* list);

int main()
{
    // lesson 216
    int arr1[] = {1,2,3,4,5};
    DLinkedList* list1 = dll_create(arr1, sizeof(arr1)/sizeof(int));

    dll_display(list1, 0);
    dll_display(list1, 1);

    // lesson 218
    dll_insert(list1, 6, 0);
    dll_insert(list1, 7, 3);
    dll_insert(list1, 8, list1->node_count);
    dll_display(list1, 1);
    dll_display(list1, 0);

    // lesson 220
    dll_delete(list1, list1->node_count);
    dll_delete(list1, 3);
    dll_delete(list1, 0);
    dll_display(list1, 0);
    dll_display(list1, 1);

    // lesson 222
    dll_reverse(list1);
    printf("display after reversing the list.\n");
    dll_display(list1, 0);
    dll_display(list1, 1);

    ll_free(list1);
    return 0;
}

DLinkedList* dll_create(int* arr, int size)
{
    DLinkedList* list = (DLinkedList*)malloc(sizeof(DLinkedList));
    
    if (!arr)
    {
        list->head = NULL;
        list->tail = NULL;
        list->node_count = 0;
        return list;
    }

    Node *new, *prev;

    // Assigning head
    new = (Node*)malloc(sizeof(Node));
    new->data = arr[0];
    new->prev = NULL;
    
    list->head = new;
    list->node_count = 1;
    prev = new;

    for (int i = 1; i < size; i++)
    {
        new = (Node*)malloc(sizeof(Node));
        new->data = arr[i];
        prev->next = new;
        new->prev = prev;

        prev = new;
        list->node_count++;
    }
    prev->next = NULL;
    list->tail = prev;
    return list;
}

void dll_display(DLinkedList* list, bool direction)
{
    Node *p;
    if (direction)
    {
        // forward
        p = list->head;
        while (p)
        {
            printf("%d ", p->data);
            p = p->next;
        }
    }
    else
    {
        // reverse
        p = list->tail;
        while (p)
        {
            printf("%d ", p->data);
            p = p->prev;
        }
    }
    printf("\n");
}

void ll_free(DLinkedList* list)
{
    Node* temp;
    if (list->head != NULL)
    {
        while (list->head->next != NULL)
        {
            temp = list->head->next;
            free(list->head);
            list->head = temp;
        }
        free(list->head);
    }
    free(list);
}

void dll_insert(DLinkedList* list, int value, int position)
{
    if (position < 0 || position > list->node_count)
    {
        printf("Invalid index position.\n");
        return;
    }

    Node* new = (Node*)malloc(sizeof(Node));
    new->next = new->prev = NULL;
    new->data = value;
    if (position == 0)
    {
        new->next = list->head;
        list->head->prev = new;
        list->head = new;
    }
    else
    {
        Node* p = list->head;
        for (int i = 0; i < position-1; i++)
        {
            p = p->next;
        }
        Node* q = p->next;
        p->next = new;
        new->prev = p;
        new->next = q;
        if (q)
        {
            q->prev = new;
        }
        else
        {
            list->tail = new;
        }
    }
    list->node_count++;
}

int dll_delete(DLinkedList* list, int position)
{
    if (position < 0 || position > list->node_count)
    {
        printf("Invalid index for node deletion.\n");
        return -1;
    }

    Node *temp;
    int node_data;
    if (position == 0)
    {
        temp = list->head;
        list->head->next->prev = NULL;
        list->head = list->head->next;
    }
    else if (position == list->node_count)
    {
        temp = list->tail;
        list->tail->prev->next = NULL;
        list->tail = list->tail->prev;
    }
    else
    {
        temp = list->head;
        for (int i = 0; i < position; i++)
        {
            temp = temp->next;
        }
        temp->prev->next = temp->next;
        if (temp->next)
        {
            temp->next->prev = temp->prev;
        }
    }
    node_data = temp->data;
    free(temp);

    list->node_count--;
    return node_data;
}

void dll_reverse(DLinkedList* list)
{
    // In our implementation, just switch the tail and the head to reverse the dll
    if (!list->head)
    {
        printf("Empty list \n");
    }
    Node *temp = list->head;
    Node *swap_ends;
    while (temp->next)
    {
        printf("temp's value: %d\n", temp->data);
        swap_ends = temp->next;
        temp->next = temp->prev;
        temp->prev = swap_ends;

        temp = temp->prev;
    }
    
    temp->next = temp->prev;
    temp->prev = NULL;
    // swap head and tail
    list->tail = list->head;
    list->head = temp;

    printf("head: %d, tail: %d\n", list->head->data, list->tail->data);
}