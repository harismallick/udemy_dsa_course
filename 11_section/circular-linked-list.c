#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
    int data;
    struct Node* next;
} Node;

typedef struct
{
    Node* head;
    int node_count;
} LinkedList;

LinkedList* circular_ll_create(int* arr, int arr_size);
void circular_ll_display(LinkedList* list);
void circular_ll_recursive_display(LinkedList* list, Node* p);
void ll_circular_free_by_address(LinkedList* list);
bool ll_is_cyclic(LinkedList* list);
void circular_ll_insert(LinkedList* list, int value, int position);
int circular_ll_delete(LinkedList* list, int position);

int main()
{
    // lesson 210
    int arr1[] = {1,2,3,4,5};
    LinkedList* cll_210 = circular_ll_create(arr1, sizeof(arr1)/sizeof(int));
    printf("Is the given linked list circular: %d\n", ll_is_cyclic(cll_210));
    circular_ll_display(cll_210);

    // lesson 211
    circular_ll_insert(cll_210, 6, 0);
    circular_ll_insert(cll_210, 7, 2);
    printf("Is the given linked list circular: %d\n", ll_is_cyclic(cll_210));
    circular_ll_display(cll_210);

    // lesson 213
    circular_ll_delete(cll_210, 1); // 6 deleted
    circular_ll_display(cll_210);
    circular_ll_delete(cll_210, 3); // 2 deleted
    circular_ll_display(cll_210);

    ll_circular_free_by_address(cll_210);

    return 0;
}

LinkedList* circular_ll_create(int* arr, int arr_size)
{
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    list->head = NULL;
    
    // Assign head node
    Node* new = (Node*)malloc(sizeof(Node));
    new->data = arr[0];
    new->next = NULL;
    
    list->head = new;
    list->node_count = 1;
    Node* temp = list->head;
    if (arr)
    {
        for (int i = 1; i < arr_size; i++)
        {
            Node* new = (Node*)malloc(sizeof(Node));
            new->data = arr[i];
            new->next = NULL;       

            temp->next = new;
            temp = new;
            list->node_count++;
        }
    }
    temp->next = list->head;

    return list;
}

void circular_ll_display(LinkedList* list)
{
    Node* p = list->head;

    do
    {
        printf("%d ", p->data);
        p = p->next;
    } while (p && p != list->head);
    printf("\n");
}

void ll_circular_free_by_address(LinkedList* list) {
    if (list == NULL || list->head == NULL) {
        if (list) free(list);
        return;
    }

    Node* head = list->head;
    Node* current = head;
    Node* next_node;

    // We use a 'do-while' or manual break to ensure 
    // we process the first node before checking the condition
    do {
        next_node = current->next;
        free(current);
        current = next_node;
    } while (current != head);

    list->head = NULL;
    list->node_count = 0;
    free(list);
}

void circular_ll_recursive_display(LinkedList* list, Node* p)
{
    static int flag = 0;

    if (p != list->head || flag == 0)
    {
        flag = 1;
        printf("%d ", p->data);
        circular_ll_recursive_display(list, p->next);
    }
    else
    {
        printf("\n");
    }
    flag = 0;
}

bool ll_is_cyclic(LinkedList* list)
{
    Node *p1, *p2;
    p1 = p2 = list->head;

    do
    {
        if (!p1 || !p2)
        {
            return false;
        }

        p1 = p1->next;
        p2 = p2->next->next;
    } while (p1 != p2);
    
    return true;
}

void circular_ll_insert(LinkedList* list, int value, int position)
{
    if (position < 0 || position > list->node_count)
    {
        printf("Invalid index for insertion.\n");
        return;
    }

    Node* p = list->head;
    Node* new = (Node*)malloc(sizeof(Node));
    new->data = value;

    if (!p)
    {
        list->head = new;
        list->head->next = list->head;
        list->node_count++;
        return;
    }

    if (position == 0)
    {
        new->next = list->head;

        while (p->next != list->head)
        {
            p = p->next;
        }
        p->next = new;
        list->head = new;
    }

    else
    {
        for (int i = 0; i < position-1; i++)
        {
            p = p->next;
        }
        new->next = p->next;
        p->next = new;
    }
    list->node_count++;
}

int circular_ll_delete(LinkedList* list, int position)
{
    if (position < 1 || position > list->node_count)
    {
        printf("Invalid index for node deletion.\n");
        return -1;
    }
    Node *p, *q;
    p = list->head;
    int node_data;

    if (position == 1)
    {
        while (p->next != list->head)
        {
            p = p->next;
        }

        node_data = list->head->data;
        // Check if head is the only node
        if (p == list->head)
        {
            free(list->head);
            list->head = NULL;
        }
        else
        {
            p->next = list->head->next;
            free(list->head);
            list->head = p->next;
        }
    }
    else
    {
        for (int i = 1; i < position-1; i++)
        {
            p = p->next;
        }
        q = p->next;
        p->next = q->next;
        node_data = q->data;
        free(q);
    }
    list->node_count--;
    return node_data;
}