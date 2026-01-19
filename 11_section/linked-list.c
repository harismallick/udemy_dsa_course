#include <stdio.h>
#include <stdlib.h>

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

LinkedList* ll_create();
void ll_add(LinkedList* list, int value);
void ll_display(LinkedList* list);
void ll_recursive_display(Node* head);
int ll_recursive_count(Node* head);
int ll_sum(LinkedList* list);
int ll_max(LinkedList* list);
int ll_min(LinkedList* list);
void ll_free(LinkedList* list);

int main()
{
    LinkedList* test_list = ll_create();
    ll_add(test_list, 1);
    ll_add(test_list, 2);
    ll_add(test_list, 3);
    ll_add(test_list, 4);
    ll_add(test_list, 5);

    ll_display(test_list);
    printf("Recursive display of list:\n");
    ll_recursive_display(test_list->head);

    int count = ll_recursive_count(test_list->head);
    printf("This linked list has %d elements.\n", count);

    ll_free(test_list);

    return 0;
}

LinkedList* ll_create()
{
    LinkedList* new_list = (LinkedList*)malloc(sizeof(LinkedList));
    new_list->node_count = 0;
    new_list->head = NULL;
    return new_list;
}

void ll_add(LinkedList* list, int value)
{
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = NULL;
    if (list->head == NULL)
    {
        list->head = new_node;
    }
    else
    {
        Node* temp = list->head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
    }
    list->node_count += 1;
}

void ll_display(LinkedList* list)
{
    Node* temp = list->head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\nThere are %d elements in this linked list.\n", list->node_count);
}

void ll_recursive_display(Node* head)
{
    if (head == NULL)
    {
        printf("\n");
        return;
    }
    printf("%d ", head->data);
    ll_recursive_display(head->next);
}

int ll_recursive_count(Node* head)
{
    int x = 0;
    if (head != NULL)
    {
        x = 1 + ll_recursive_count(head->next);
    }
    return x;
}
// int ll_sum(LinkedList* list);
// int ll_max(LinkedList* list);
// int ll_min(LinkedList* list);
void ll_free(LinkedList* list)
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