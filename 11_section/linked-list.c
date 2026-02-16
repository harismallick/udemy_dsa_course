#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
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

LinkedList* ll_create();
void ll_add(LinkedList* list, int value);
void ll_add_iter(LinkedList* list, int* array, int size);
void ll_insert(LinkedList* list, int value, int position);
void ll_sorted_insert(LinkedList* list, int value);
void ll_display(LinkedList* list);
void ll_recursive_display(Node* head);
int ll_recursive_count(Node* head);
int ll_sum(LinkedList* list);
int ll_recursive_sum(Node* head);
int ll_max(LinkedList* list);
int ll_recursive_max(Node* head);
int ll_min(LinkedList* list);
int ll_recursive_min(Node* head);
Node* ll_search(LinkedList* list, int key);
Node* ll_recursive_search(Node* head, int key);
Node* ll_search_move_to_head(LinkedList* list, int key);
void ll_free(LinkedList* list);
void ll_delete_node_by_value(LinkedList* list, int value);
void ll_delete_node_by_index(LinkedList* list, int index);
bool ll_is_sorted(LinkedList* list);
bool ll_is_sorted_ascending(LinkedList* list);
bool ll_is_sorted_descending(LinkedList* list);

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

    int sum = ll_sum(test_list);
    printf("The sum of elements in this linked list is: %d\n", sum);

    int sum_r = ll_recursive_sum(test_list->head);
    printf("The sum of elements in this linked list recursively is: %d\n", sum_r);

    int max = ll_max(test_list);
    int min = ll_min(test_list);
    printf("The largest value in the list is %d, the smallest value is %d\n", max, min);

    int rmax = ll_recursive_max(test_list->head);
    int rmin = ll_recursive_min(test_list->head);
    printf("The largest value in the list is %d, the smallest value is %d, done recursively.\n", rmax, rmin);

    int search = 4;
    Node* s1 = ll_search(test_list, search);
    if (s1 != NULL)
    {
        printf("%d is in the list at %p.\n", search, s1);
    }
    Node* s2 = ll_recursive_search(test_list->head, search);
    if (s2 != NULL)
    {
        printf("%d is in the list at %p.\n", search, s2);
    }
    // Node* s3 = ll_search_move_to_head(test_list, search);
    // if (s3 != NULL)
    // {
    //     printf("%d is in the list at %p.\n", search, s3);
    // }
    // printf("Display after search move to head operation: \n");
    // ll_display(test_list);
    ll_insert(test_list, 6, 3);
    ll_insert(test_list, 7, 0);
    ll_insert(test_list, 6, 10);
    printf("Linked list after insert operation:\n");
    ll_display(test_list);

    int arr[] = {10,11,12,13};
    int size = sizeof(arr) / sizeof(int);
    printf("Size of the array is %d\n", size);
    ll_add_iter(test_list, arr, size);
    printf("Adding iteratively to an existing list:\n");
    ll_display(test_list);

    LinkedList *test_two = ll_create();
    ll_add_iter(test_two, arr, size);
    printf("Adding iteratively to a new list:\n");
    ll_display(test_two);

    // lesson 190
    ll_sorted_insert(test_two, 14);
    ll_sorted_insert(test_two, 9);
    printf("Inserting into a sorted list:\n");
    ll_display(test_two);

    // lesson 192
    // ll_delete_node_by_index(test_two, 4);
    // ll_delete_node_by_index(test_two, 1);
    // ll_delete_node_by_value(test_two, 12);
    // ll_delete_node_by_value(test_two, 9);

    // lesson 194
    ll_is_sorted(test_two) ? printf("List is sorted.\n") : printf("List is not sorted.\n");

    LinkedList* test_three = ll_create();
    int arr2[] = {13,12,10,9,8};
    ll_add_iter(test_three, arr2, 5);
    ll_is_sorted(test_three) ? printf("List is sorted.\n") : printf("List is not sorted.\n");

    ll_add(test_three, 20);
    ll_is_sorted(test_three) ? printf("List is sorted.\n") : printf("List is not sorted.\n");

    ll_free(test_list);
    ll_free(test_two);
    ll_free(test_three);

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
int ll_sum(LinkedList* list)
{
    int sum = 0;
    Node* temp = list->head;
    while (temp != NULL)
    {
        sum += temp->data;
        temp = temp->next;
    }
    return sum;
}

int ll_max(LinkedList* list)
{
    int max = INT_MIN;
    Node* temp = list->head;

    while (temp != NULL)
    {
        if (temp->data > max)
        {
            max = temp->data;
        }
        temp = temp->next;
    }
    return max;
}

int ll_min(LinkedList* list)
{
    int min = INT_MAX;
    Node* temp = list->head;

    while (temp != NULL)
    {
        if (temp->data < min)
        {
            min = temp->data;
        }
        temp = temp->next;
    }
    return min;
}

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

int ll_recursive_sum(Node* head)
{
    if (head == NULL)
    {
        return 0;
    }
    return head->data + ll_recursive_sum(head->next);
}

int ll_recursive_max(Node* head)
{
    int x;
    if (head == NULL)
    {
        return INT_MIN;
    }
    x = ll_recursive_max(head->next);
    return x > head->data ? x : head->data;
}

int ll_recursive_min(Node* head)
{
    int x;
    if (head == NULL)
    {
        return INT_MAX;
    }
    x = ll_recursive_min(head->next);
    return x < head->data ? x : head->data;
}

Node* ll_search(LinkedList* list, int key)
{
    Node* temp = list->head;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}
Node* ll_recursive_search(Node* head, int key)
{
    if (head == NULL)
    {
        return NULL;
    }
    return key == head->data ? head : ll_recursive_search(head->next, key);
}

Node* ll_search_move_to_head(LinkedList* list, int key)
{
    Node* current = list->head;
    Node* previous;
    while (current != NULL)
    {
        if (current->data == key)
        {
            previous->next = current->next;
            current->next = list->head;
            list->head = current;
            return current;
        }
        previous = current;
        current = current->next;
    }
    return NULL;
}

void ll_insert(LinkedList* list, int value, int position)
{
    if (position < 0 || position > list->node_count)
    {
        printf("Invalid index for insertion into linked list.\n");
        return;
    }

    Node *new, *p;
    new = (Node*)malloc(sizeof(Node));
    new->data = value;
    if (position == 0)
    {
        new->next = list->head;
        list->head = new;
    }
    else if (position > 0)
    {
        p = list->head;
        for (int i = 0; i < position - 1 && p; i++)
        {
            p = p->next;
        }
        if (p)
        {
            new->next = p->next;
            p->next = new;
        }
    }
    list->node_count += 1;
}

void ll_add_iter(LinkedList* list, int* array, int size)
{
    Node *last, *new, *temp;
    last = NULL;
    if (list->head != NULL)
    {
        temp = list->head;
        while (temp != NULL)
        {
            last = temp;
            temp = temp->next;
        }
    }
    for (int i = 0; i < size; i++)
    {
        new = (Node*)malloc(sizeof(Node));
        new->data = array[i];
        new->next = NULL;
        if (last)
        {
            last->next = new;
            last = new;
        }
        else
        {
            last = new;
            list->head = last;
        }
        list->node_count++;
    }
}

void ll_sorted_insert(LinkedList* list, int value)
{
    Node *new, *prev, *curr;
    new = (Node*)malloc(sizeof(Node));
    new->data = value;
    
    if (!list->head)
    {
        list->head = new;
        new->next = NULL;
        list->node_count++;
        return;        
    }

    if (value < list->head->data)
    {
        prev = list->head;
        list->head = new;
        new->next = prev;
        list->node_count++;
        return;
    }

    curr = list->head;

    while (curr && curr->data < value)
    {
        prev = curr;
        curr = curr->next;
    }

    new->next = prev->next;
    prev->next = new;
    list->node_count++;
}

void ll_delete_node_by_value(LinkedList* list, int value)
{
    Node *prev, *curr;
    int delete_value;

    if (!list->head)
    {
        printf("The linked list is empty. Nothing to delete.\n");
        return;
    }
    
    else if (list->head->data == value)
    {
        delete_value = list->head->data;
        prev = list->head;
        list->head = list->head->next;
        free(prev);
        printf("%d deleted from list\n", delete_value);
    }

    else 
    {
        curr = list->head;
        while (curr)
        {
            if (curr->data == value)
            {
                delete_value = curr->data;
                prev->next = curr->next;
                free(curr);
                printf("%d deleted from list\n", delete_value);
                break;   
            }
            else
            {
                prev = curr;
                curr = curr->next;
            }
        }
    }
    list->node_count--;
}

void ll_delete_node_by_index(LinkedList* list, int index)
{
    Node *prev, *curr;
    int delete_value;

    if (!list->head)
    {
        printf("The linked list is empty. Nothing to delete.\n");
        return;
    }
    
    else if (index == 1)
    {
        delete_value = list->head->data;
        prev = list->head;
        list->head = list->head->next;
        free(prev);
        printf("%d deleted at position %d\n", delete_value, index);
    }

    else 
    {
        curr = list->head;
        for (int i = 0; i < index-1 && curr; i++)
        {
            prev = curr;
            curr = curr->next;
        }
        if (curr)
        {
            prev->next = curr->next;
            delete_value = curr->data;
            free(curr);
        }
        printf("%d deleted at position %d\n", delete_value, index);
    }
    list->node_count--;
}

bool ll_is_sorted(LinkedList* list)
{
    bool is_sorted = false;
    is_sorted = ll_is_sorted_ascending(list);
    if (!is_sorted)
    {
        is_sorted = ll_is_sorted_descending(list);
    }
    return is_sorted;
}
bool ll_is_sorted_ascending(LinkedList* list)
{
    Node *temp = list->head;
    while (temp->next)
    {
        if (temp->data > temp->next->data)
        {
            return false;
        }
        temp = temp->next;
    }
    return true;
}

bool ll_is_sorted_descending(LinkedList* list)
{
    Node *temp = list->head;
    while (temp->next)
    {
        if (temp->data < temp->next->data)
        {
            return false;
        }
        temp = temp->next;
    }
    return true;
}