// this program illustrates the usage of linear search but it only works for distinct elements
#include <stdio.h>

int linearSearch(int arr[], int size)
{
    int element;
    printf("Enter the Element to be searched: ");
    scanf("%d", &element);

    // searching begins
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            printf("The Element %d was found at index : %d", element, i);
            return i;
        }
    }
    printf("The Element %d was not found!", element);
    return 0;
}

void traversal(int arr[], int size)
{
    printf("...Array elements...\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


int main()
{
    int arr[] = {65, 36, 43, 89, 43, 67, 233, 67, 2, 3, 3};
    int size = sizeof(arr) / sizeof(int);

    traversal(arr, size);

    int searchIndex = linearSearch(arr, size);
    return 0;
}
