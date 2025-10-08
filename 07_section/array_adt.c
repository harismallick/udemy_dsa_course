#include<ctype.h>
#include<math.h>
#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>

// typedef struct
// {
//     /* data */
//     int *array;
//     int size;
//     int length;
// } List2;

typedef struct
{
    int array[20];
    int size;
    int length; // The number of elements currently in the array
} List;

void list_print(List arr);
void list2_print(List* arr);
int list_append(List* arr, int num);
int list_insert(List* arr, int num, int position);
int list_delete(List* arr, int index);
int list_linear_search(List* arr, int num);
void swap_values(int* x, int* y);
int list_binary_search(List* arr, int num);
void bubble_sort(int *nums_list, int length);
int list_get(List* arr, int index); // get element at index.
int list_set(List* arr, int index, int num); // set index to particular value
int list_max(List* arr);
int list_min(List* arr);
int list_sum(List *arr);
float list_average(List *arr);
void list_reverse(List* arr);
void list_rotation(List* arr, char direction);
bool list_is_sorted(List* arr);
void list_sorted_insert(List* arr, int num); // insert into a sorted list
void list_separate_positives_negatives(List* arr); // separate positive and negative numbers into different sections
char list_sort_direction(List* arr); // Check direction of sort - forward or reverse
List* list_sorted_merge(List* arr1, List* arr2);
List* lists_union(List* arr1, List* arr2);
List* lists_intersection(List* arr1, List* arr2);
void list_destroy(List* list);
List* lists_difference(List* arr1, List* arr2);

// int main()
// {
//     // Heap memory implementation
//     // List arr;
//     // printf("Enter the size of your array:\n");
//     // scanf("%d", &arr.size);
//     // arr.array = (int *)malloc(sizeof(int) * arr.size);
//     // arr.length = 0;

//     // printf("Enter the length of your array:\n");
//     // scanf("%d", &arr.length);

//     // for (int i = 0; i < arr.length; i++)
//     // {
//     //     printf("Enter a number to add to the array:\n");
//     //     scanf("%d", &arr.array[i]);
//     // }
//     // list_print(arr);
//     // free(arr.array);

//     // Stack memory implementation for demonstration
//     List arr = {{1,2,3,4,5}, 20, 5};
//     List* arr_p = &arr;
//     list_print(arr);
//     list_append(arr_p, 6);
//     list_print(arr);
//     list_insert(arr_p, 8, 3);
//     list_print(arr);
//     list_delete(arr_p, 2);
//     list_print(arr);
//     printf("%d\n", list_linear_search(arr_p, 4));
//     list_print(arr); // Check for the element swap;
//     printf("%d\n", list_linear_search(arr_p, 14));
//     bubble_sort(arr.array, arr.length);
//     printf("The array after being sorted:\n");
//     list_print(arr);
//     printf("%d\n", list_binary_search(arr_p, 4));
//     printf("%d\n", list_binary_search(arr_p, 14));

//     // List operations:
//     //get
//     printf("The number at index %d is %d\n", 3, list_get(arr_p, 3));
//     //set
//     list_set(arr_p, 1, 3);
//     printf("The list after set operation:\n");
//     list_print(arr);
//     printf("The largest number in the list: %d\n", list_max(arr_p));
//     printf("The smallest number in the list: %d\n", list_min(arr_p));
//     printf("The sum of the list is %d\n", list_sum(arr_p));
//     printf("The average of the list is %f\n", list_average(arr_p));
//     // Reverse list:
//     list_reverse(arr_p);
//     printf("The list after reverse operation:\n");
//     list_print(arr);
//     // Left rotation:
//     list_rotation(arr_p, 'l');
//     printf("List after L rotation:\n");
//     list_print(arr);
//     // Right rotation:
//     list_rotation(arr_p, 'r');
//     printf("List after R rotation:\n");
//     list_print(arr);
//     // Check if list is sorted:
//     printf("Is this list sorted?\t%s\n", list_is_sorted(arr_p) ? "True" : "False");
//     // Insert into sorted list:
//     list_sorted_insert(arr_p, 7);
//     printf("The list after a sorted insert operation:\n");
//     list_print(arr);
//     // Separate positive and negative numbers in a list:
//     List arr2 = {{1,-5,0,-3,5,-6, 9, -10}, 20, 8};
//     list_separate_positives_negatives(&arr2);
//     printf("Negatives and positives separated:\n");
//     list_print(arr2);

//     list_reverse(arr_p);
//     bubble_sort(arr2.array, arr2.length);
//     list_print(arr);
//     list_print(arr2);

//     // Merge two lists
//     List arr3 = {{2,4,6,8,9}, 20, 5};
//     List arr4 = {{1,2,3,5,7,9}, 20, 6};
//     List* merged_list = list_sorted_merge(&arr3, &arr4);
//     list2_print(merged_list);
//     // write destroy List function to free heap memory
//     list_destroy(merged_list);
//     merged_list = NULL;

//     // Union of lists
//     List* union_list = lists_union(&arr3, &arr4);
//     list2_print(union_list);
//     list_destroy(union_list);
//     union_list = NULL;

//     // Intersection of two lists
//     List* intersection_list = lists_intersection(&arr3, &arr4);
//     list2_print(intersection_list);
//     list_destroy(intersection_list);
//     intersection_list = NULL;

//     // Difference of two lists
//     List* arr3_diff_arr4 = lists_difference(&arr3, &arr4);
//     list2_print(arr3_diff_arr4);
//     list_destroy(arr3_diff_arr4);
//     arr3_diff_arr4 = NULL;

//     return 0;
// }

void list_print(List arr)
{
    printf("[");
    for (int i = 0; i < arr.length; i++)
    {
        printf("%d", arr.array[i]);
        if (i != arr.length - 1)
        {
            printf(",");
        }
    }
    printf("]\n");
}

void list2_print(List* arr)
{
    printf("[");
    for (int i = 0; i < arr->length; i++)
    {
        printf("%d", arr->array[i]);
        if (i != arr->length - 1)
        {
            printf(",");
        }
    }
    printf("]\n");
}

int list_append(List* arr, int num)
{
    if (arr->length == arr->size)
    {
        printf("The array is full. Cannot add more elements!");
        return 1;
    }
    // Add feature to allocate more heap memory for list
    arr->array[arr->length] = num;
    arr->length++;
    return 0;
}

int list_insert(List* arr, int num, int position)
{
    if (position >= arr->size || position < 0)
    {
        printf("Insertion position is outside the bounds of the array.");
        return 1;
    }
    if (arr->length == arr->size)
    {
        printf("The array is full. Cannot add more elements!");
        return 1;
    }
    for (int i = arr->length; i > position; i--)
    {
        arr->array[i] = arr->array[i-1];
    }
    arr->array[position] = num;
    arr->length++;
    return 0;
}

int list_delete(List* arr, int index)
{
    if (index >= arr->size || index < 0)
    {
        printf("The index is out of range.\n");
        return 1;
    }
    for (int i = index; i < arr->length; i++)
    {
        arr->array[i] = arr->array[i+1];
    }
    arr->length--;
    return 0;
}


void swap_values(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int list_linear_search(List* arr, int num)
{
    for (int i = 0; i < arr->length; i++)
    {
        if (arr->array[i] == num)
        {
            swap_values(&arr->array[i], &arr->array[i-1]);
            return i;
        }
    }
    return -1;
    // To speed up future searches, two things can be done:
    // 1. Transposition - The search element is moved one position up the array for each search action.
    // This means that element that are searched the most will be in the front of the list, for faster compute.
    // 2. Move to front - As the name suggests, move the searched element to index 0.
    // Thus if the same element is searched again, its O(n) would be O(1).
}

void bubble_sort(int *nums_list, int length)
{
    bool swap = true;
    int swap_count = 0;
    while (swap)
    {
        swap_count = 0;
        for (int i = 1; i < length; i++)
        {
            if (nums_list[i] < nums_list[i-1])
            {
                swap_values(&nums_list[i], &nums_list[i-1]);
                swap_count++;
            }
        }
        if (swap_count == 0)
        {
            swap = false;
        }
    }
}

int list_binary_search(List* arr, int num)
{
    int start = 0;
    int end = arr->length - 1;
    
    while (start <= end)
    {
        int middle = floor((start + end) / 2);
        if (arr->array[middle] == num)
        {
            return middle;
        }
        else if (arr->array[middle] < num)
        {
            start = middle + 1;
        }
        else
        {
            end = middle - 1;
        }
    }
    return -1;
}

int list_get(List* arr, int index)
{
    if (index < 0 || index > arr->length - 1)
    {
        printf("Index out of range\n");
        return -1;
    }
    return arr->array[index];
}

int list_set(List* arr, int index, int num)
{
    if (index < 0 || index > arr->length - 1)
    {
        printf("Index out of range\n");
        return 1;
    }
    arr->array[index] = num;
    return 0;
}

int list_max(List* arr)
{
    if (arr->length == 0)
    {
        printf("The list is empty!\n");
        return -1;
    }
    int max = arr->array[0];
    for (int i = 1; i < arr->length; i++)
    {
        if (arr->array[i] > max)
        {
            max = arr->array[i];
        }
    }
    return max;
}

int list_min(List* arr)
{
    if (arr->length == 0)
    {
        printf("The list is empty!\n");
        return -1;
    }
    int min = arr->array[0];
    for (int i = 1; i < arr->length; i++)
    {
        if (arr->array[i] < min)
        {
            min = arr->array[i];
        }
    }
    return min;
}

int list_sum(List *arr)
{
    if (arr->length == 0)
    {
        printf("The list is empty!\n");
        return -1;
    }
    int sum = 0;
    for (int i = 0; i < arr->length; i++)
    {
        sum = sum + arr->array[i];
    }
    return sum;
}

float list_average(List *arr)
{
    if (arr->length == 0)
    {
        printf("The list is empty!\n");
        return -1;
    }
    return (float)list_sum(arr) / arr->length;
}

void list_reverse(List* arr)
{
    int start = 0;
    int end = arr->length - 1;
    while (start < end)
    {
        swap_values(&arr->array[start], &arr->array[end]);
        start++;
        end--;
    }
}

void list_rotation(List* arr, char direction)
{
    int temp;
    if (tolower(direction) == 'l')
    {
        temp = arr->array[0];
        for (int i = 0; i < arr->length-1; i++)
        {
            arr->array[i] = arr->array[i+1];
        }
        arr->array[arr->length-1] = temp;
    }
    else if (tolower(direction) == 'r')
    {
        temp = arr->array[arr->length-1];
        for (int i = arr->length-1; i > 0; i--)
        {
            arr->array[i] = arr->array[i-1];
        }
        arr->array[0] = temp;
    }
}

bool list_is_sorted(List* arr)
{
    bool sorted = true;

    for (int i = 0; i < arr->length-1; i++)
    {
        if (arr->array[i] > arr->array[i+1])
        {
            sorted = false;
            break;
        }
    }
    if (!sorted)
    {
        sorted = true;
        for (int i = 0; i < arr->length-1; i++)
        {
            if (arr->array[i] < arr->array[i+1])
            {
                sorted = false;
                break;
            }
        }
    }

    return sorted;
}

char list_sort_direction(List* arr)
{
    if (!list_is_sorted(arr))
    {
        printf("The given list is not sorted.\n");
        return 'e';
    }
    char direction;
    if (arr->array[0] < arr->array[1])
    {
        direction = 'f';
    }
    else
    {
        direction = 'r';
    }
    return direction;
}

void list_sorted_insert(List* arr, int num)
{
    if (arr->length == arr->size)
    {
        printf("The list is full, can't add more elements.");
        return;
    }
    char sort_direction = list_sort_direction(arr);
    int i = arr->length - 1;
    if (sort_direction == 'f')
    {
        while (arr->array[i] > num)
        {
            arr->array[i+1] = arr->array[i];
            i--;
        }
        arr->array[i+1] = num;
    }
    else if (sort_direction == 'r')
    {
        while (arr->array[i] < num)
        {
            arr->array[i+1] = arr->array[i];
            i--;
        }
        arr->array[i+1] = num;
    }
    arr->length++;
}

void list_separate_positives_negatives(List* arr)
{
    int pos_tracker = 0;
    int neg_tracker = arr->length - 1;
    while (neg_tracker > pos_tracker)
    {
        while (arr->array[pos_tracker] < 0)
        {
            pos_tracker++;
        }
        while (arr->array[neg_tracker] >= 0)
        {
            neg_tracker--;
        }
        if (neg_tracker > pos_tracker)
        {
        swap_values(&arr->array[pos_tracker], &arr->array[neg_tracker]);
        }
    }

}

List* list_sorted_merge(List* arr1, List* arr2)
{
    List* merged_list = (List *)malloc(sizeof(List));
    merged_list->size = 20;
    // merged_list->size = arr1->size + arr2->size;
    // merged_list->array = (int *)malloc(sizeof(int) * merged_list->size);
    
    int i = 0, j = 0, k = 0;
    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->array[i] < arr2->array[j])
        {
            merged_list->array[k] = arr1->array[i];
            i++, k++;
        }
        else
        {
            merged_list->array[k] = arr2->array[j];
            j++, k++;
        }
    }
    for (; i < arr1->length; i++)
    {
        merged_list->array[k] = arr1->array[i];
        k++;
    }
    for (; j < arr2->length; j++)
    {
        merged_list->array[k] = arr2->array[j];
        k++;
    }
    merged_list->length = arr1->length + arr2->length;
    return merged_list;
}

void list_destroy(List* list) 
{
    if (list == NULL) {
        return; // Nothing to free
    }

    // 1. Free the dynamically allocated array first
    // This is crucial because list->array points to a separate block of heap memory.
    // if (list->array != NULL) {
    //     free(list->array);
    //     list->array = NULL; // Good practice to set to NULL after freeing
    // }

    // 2. Free the List2 struct itself (if it was dynamically allocated)
    free(list);
    list = NULL; // Good practice to set the passed pointer to NULL, though
                 // this won't affect the caller's copy of the pointer.
                 // To affect the caller, you'd pass a **List2 pointer.
}

List* lists_union(List* arr1, List* arr2)
{
    // Must include all unique items in both lists

    List* merged_list = (List *)malloc(sizeof(List));
    // merged_list->size = arr1->size + arr2->size;
    merged_list->size = 20; // Based on current implementation
    // merged_list->array = (int *)malloc(sizeof(int) * merged_list->size);
    
    int i = 0, j = 0, k = 0;
    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->array[i] < arr2->array[j])
        {
            merged_list->array[k] = arr1->array[i];
            i++, k++;
        }
        else if (arr2->array[j] < arr1->array[i])
        {
            merged_list->array[k] = arr2->array[j];
            j++, k++;
        }
        else
        {
            merged_list->array[k] = arr2->array[j];
            i++, j++, k++;
        }
    }
    for (; i < arr1->length; i++)
    {
        merged_list->array[k] = arr1->array[i];
        k++;
    }
    for (; j < arr2->length; j++)
    {
        merged_list->array[k] = arr2->array[j];
        k++;
    }
    merged_list->length = k;
    return merged_list;
    
}

List* lists_intersection(List* arr1, List* arr2)
{
    List* intersection_list = (List*)malloc(sizeof(List));
    intersection_list->size = 20;

    int i = 0, j = 0, k = 0;
    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->array[i] < arr2->array[j])
        {
            i++;
        }
        else if (arr2->array[j] < arr1->array[i])
        {
            j++;
        }
        else
        {
            intersection_list->array[k] = arr1->array[i];
            i++, j++, k++;
        }
        intersection_list->length = k;
    }
    return intersection_list;
}

List* lists_difference(List* arr1, List* arr2)
{
    // Return a list of elements that are unique to the first list
    List* arr1_diff_arr2 = (List*)malloc(sizeof(List));
    arr1_diff_arr2->size = 20;

    int i=0, j=0, k=0;
    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->array[i] == arr2->array[j])
        {
            i++, j++;
        }
        else if (arr1->array[i] > arr2->array[j])
        {
            j++;
        }
        else
        {
            arr1_diff_arr2->array[k] = arr1->array[i];
            i++, k++;
        }

    }
    for (; i < arr1->length; i++)
    {
        arr1_diff_arr2->array[k] = arr1->array[i];
        k++;
    }
    arr1_diff_arr2->length = k;

    return arr1_diff_arr2;
}