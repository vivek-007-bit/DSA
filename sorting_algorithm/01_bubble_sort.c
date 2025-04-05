#include<stdio.h>

void traversal(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf(" %d |", arr[i]);
    }
    printf("\n");
}


void bubbleSort(int *Arr, int size){
    int temp;
    for (int i = 0; i < size-1; i++)
    {
        for (int j = 0; j < size-1-i; j++)
        {
            if (Arr[j] > Arr[j+1])
            {
                temp = Arr[j];
                Arr[j] = Arr[j+1];
                Arr[j+1] = temp;
            }
        }

    }

    traversal(Arr, size);
}


int main()
{
    int myArr[] = {5,3,43,2,7,97,46,34};
    int size = sizeof(myArr)/sizeof(int);
    printf("...Array elements...\n");
    traversal(myArr, size);
    printf("...Array elements after sorting...\n");
    bubbleSort(myArr, size);

    
return 0;
}
