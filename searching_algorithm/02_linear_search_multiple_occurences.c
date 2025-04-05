/*  ***this program illustrates the usage of linear search algorthm such 
that it matches for all the occurences of any given element*** */

#include <stdio.h>

void linearSearch(int arr[], int size)
{
    int element;
    int found = 0;
    printf("Enter the Element to be searched: ");
    scanf("%d", &element);

    printf("The Element %d  was found at index : ", element);

    // searching begins
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            printf("%d ", i);
            found = 1;
        }
    }
    if (!found) 
    {
       printf("\nThe Element %d was not found!", element);
    }
    printf("\n");
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
    linearSearch(arr, size);
    return 0;
}