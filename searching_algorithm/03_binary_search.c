/*  ***this program illustrates the usage of binary search algorthm 
       given that all the elements are distict*** */

#include <stdio.h>

int binarySearch(int arr[], int size)
{
    int element;
    printf("Enter the Element to be searched: ");
    scanf("%d", &element);

    int low = 0;
    int high = size - 1;
    int mid;

    // searching begins
    while (low <= high)
    {
        mid = (low+high)/2;

        if (arr[mid] == element)
        {
            printf("The element %d was found at %d\n", element , mid);
            return mid;
        }
        
        
        else if (arr[mid] < element)
        {
            low = mid+1;
        }

        
        else
        {
            high = mid-1;
        }

    }
    printf("The element %d was not found!\n", element);
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
    int arr[] = {2, 5, 7, 8, 9, 23, 54, 78, 100, 106};
    int size = sizeof(arr) / sizeof(int);

    traversal(arr, size);

    int searchindex = binarySearch(arr, size);
    return 0;
}