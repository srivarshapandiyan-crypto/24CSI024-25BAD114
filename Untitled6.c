             #include <stdio.h>

#define MAX 100

// List ADT structure
typedef struct
{
    int arr[MAX];
    int size;
} List;

// Function to initialize the list
void initList(List *L)
{
    L->size = 0;
}

// Function to insert an element
void insert(List *L, int value)
{
    if (L->size < MAX)
    {
        L->arr[L->size] = value;
        L->size++;
    }
    else
    {
        printf("List is full\n");
    }
}

// Function to display the list
void display(List L)
{
    int i;
    printf("List elements: ");
    for (i = 0; i < L.size; i++)
    {
        printf("%d ", L.arr[i]);
    }
    printf("\n");
}

// Linear Search
int linearSearch(List L, int key)
{
    int i;

    for (i = 0; i < L.size; i++)
    {
        if (L.arr[i] == key)
        {
            return i;
        }
    }

    return -1;
}

// Binary Search (List must be sorted)
int binarySearch(List L, int key)
{
    int low = 0;
    int high = L.size - 1;
    int mid;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (L.arr[mid] == key)
        {
            return mid;
        }
        else if (L.arr[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1;
}

// Main Function
int main()
{
    List L;
    int key, pos;

    initList(&L);

    // Insert sorted elements
    insert(&L, 10);
    insert(&L, 20);
    insert(&L, 30);
    insert(&L, 40);
    insert(&L, 50);

    display(L);

    printf("Enter element to search: ");
    scanf("%d", &key);

    // Linear Search
    pos = linearSearch(L, key);

    if (pos != -1)
        printf("Linear Search: Element found at index %d\n", pos);
    else
        printf("Linear Search: Element not found\n");

    // Binary Search
    pos = binarySearch(L, key);

    if (pos != -1)
        printf("Binary Search: Element found at index %d\n", pos);
    else
        printf("Binary Search: Element not found\n");

    return 0;
}


