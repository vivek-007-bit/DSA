/*  ***this program illustrates the usage of binary search algorthm such 
       that it matches for all the occurences of any given element*** */

#include <stdio.h>

int findFirstOccurence(int arr[], int size, int element)
{
    int low = 0;
    int high = size - 1;
    int mid;
    int result = -1;

    // searching begins
    while (low <= high)
    {
        mid = (low + high) / 2;

        if (arr[mid] == element)
        {
            result = mid;
            high = mid - 1; // searches in left half
        }

        else if (arr[mid] < element)
        {
            low = mid + 1;
        }

        else
        {
            high = mid - 1;
        }
    }
    return result;
}

int findLastOccurence(int arr[], int size, int element)
{
    int low = 0;
    int high = size - 1;
    int mid;
    int result = -1;

    // searching begins
    while (low <= high)
    {
        mid = (low + high) / 2;

        if (arr[mid] == element)
        {
            result = mid;
            low = mid + 1; // searches in right half
        }

        else if (arr[mid] < element)
        {
            low = mid + 1;
        }

        else
        {
            high = mid - 1;
        }
    }
    return result;
}

void findAllOccurences(int arr[], int size, int element)
{
    int first = findFirstOccurence(arr, size, element);
    int last = findLastOccurence(arr, size, element);

    if (first == -1)
    {
        printf("Element %d was not found in the array,\n", element);
        return;
    }

    printf("Element %d found at indices: ", element);
    for (int i = first; i <= last; i++)
    {
        printf("%d ", i);
    }
    printf("\n");
}


void traversal(int arr[], int size)
{
    printf("...Array elements...\n");
    for (int i = 0; i < size; i++)
    {
        printf("  %d  |", arr[i]);
    }
    printf("\n");
}


int main()
{
    int arr[] = {2, 2, 2, 2, 4, 5, 5, 5, 7, 8, 9, 23, 54, 78, 100, 106};
    int size = sizeof(arr) / sizeof(int);

    traversal(arr, size);

    int element;
    printf("Enter the element to be searched: ");
    scanf("%d", &element);

    findAllOccurences(arr, size, element);

    return 0;
}