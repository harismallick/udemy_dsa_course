
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