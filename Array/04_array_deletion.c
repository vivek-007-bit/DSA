/*This program illustrates the usage of array as an Abstract Data Type
  as well how to delete a particular element at a given index.*/

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

int insert(struct MyArray *arr, int index, int val)
{
    if (arr->used_size == arr->total_size)
    {
        printf("\nCANNOT INSERT...The Array is full\n");
        return -1;
    }

    if (index < 0 || index > arr->used_size)
    {
        printf("\nINVALID INSERTION...\n");
        return -1;
    }

    // Inserting the value
    for (int i = arr->used_size - 1; i >= index; i--)
    {
        arr->ptr[i + 1] = arr->ptr[i];
    }
    arr->ptr[index] = val;
    arr->used_size += 1;
    showArray(arr);
    return 1;
}



int delete(struct MyArray *arr, int index)
{
    if (index < 0 || index > arr->used_size)
    {
        printf("\n...INVALID DELETION...\n");
        return -1;
    }

    // Deleting the value
    for (int i = index; i >= arr->used_size - 1; i++)
    {
        arr->ptr[i] = arr->ptr[i + 1];
    }
    arr->used_size -= 1;
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
    printf("3  INSERT at a particular index\n");
    printf("4  DELETE at a particular index\n");
    printf("5  EXIT\n");
    printf("------------------------------------\n");
    printf(" Enter your choice: ");
}

int main()
{
    struct MyArray *A;
    A = (struct MyArray *)malloc(sizeof(struct MyArray));

    int capacity, size;
    // capacity is total size of the array
    // size is the used size of the array
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

            printf("\nEnter the Value to be inserted: ");
            scanf("%d", &val);

            insert(A, index, val);
            break;

        case 4:
            printf("\nEnter the Index to be deleted: ");
            scanf("%d", &index);

            delete(A, index);
            break;

        case 5:
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