/*This program illustrates the usage of array as an Abstract Data Type
  as well how to update the value of a particular index*/

#include <stdio.h>
#include <stdlib.h>

struct MyArray
{
    int total_size;
    int used_size;
    int *ptr;
};

void createArray(struct MyArray *arr, int tSize, int uSize)
{
    arr->total_size = tSize;
    arr->used_size = uSize;
    arr->ptr = (int *)malloc(tSize * sizeof(int));
}

void showArray(struct MyArray *arr)
{
    printf("Array Elements are: ");
    for (int i = 0; i < arr->used_size; i++)
    {
        printf("|  %d  |", arr->ptr[i]);
    }
    printf("\n");
}

void setValue(struct MyArray *arr)
{
    for (int i = 0; i < arr->used_size; i++)
    {
        printf("Enter %d Element: ", i + 1);
        scanf("%d", &(arr->ptr)[i]);
    }
}

int update(struct MyArray *arr, int index, int val)
{
    if (index < 0 || index > arr->used_size)
    {
        printf("\nINVALID INDEX...\n");
        return -1;
    }

    // over writing the previous value
    arr->ptr[index] = val;

  //  if(index >= arr->used_size)
    //{
      //  arr->used_size = index + 1;
    //}
    showArray(arr);
    return 1;

}

/*Creating the GUI*/
#ifdef _WIN32
#define CLEAR_SCREEN "cls" // Windows
#else
#define CLEAR_SCREEN "clear" // Linux/Mac
#endif

int choice = 1;

void display_menu()
{
    printf("\n====================================\n");
    printf("            ARRAY MENU          \n");
    printf("====================================\n");
    printf("1  ENTER Element\n");
    printf("2  DISPLAY Array\n");
    printf("3  UPDATE the value of a particular index\n");
    printf("4  EXIT\n");
    printf("------------------------------------\n");
    printf(" Enter your choice: ");
}

int main()
{
    struct MyArray *A;
    A = (struct MyArray *)malloc(sizeof(struct MyArray));

    int capacity, size;
    //capacity is total size of the array
    //size is the used size of the array 
    printf("\nEnter the Total Size of the Array : ");
    scanf("%d", &capacity);

    printf("\nEnter the Used size of the Array: ");
    scanf("%d", &size);

    createArray(A, capacity, size);
    int index, val;

    do
    {
        system(CLEAR_SCREEN); // Clears the screen for a clean UI
        display_menu();

        scanf("%d", &choice);
        switch (choice)
        {
        case 1:

            setValue(A);
            break;

        case 2:
            showArray(A);
            break;

        case 3:
            printf("\nEnter the Index : ");
            scanf("%d", &index);

            printf("\nEnter the new Value: ");
            scanf("%d", &val);

            update(A, index, val);
            break;

        case 4:
            printf("\n Exiting... Thank you!\n");
            break;

        default:
            printf("\n Invalid choice! Please try again.\n");
        }

        printf("\nPress Enter to continue...");
        getchar();
        getchar();
    } while (choice != 4);

    free(A->ptr);
    free(A);

    return 0;
}