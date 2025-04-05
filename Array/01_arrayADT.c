/*This program illustrates the usage of array as an Abstract Data Type
with an interaactive GUI based menu*/

#include<stdio.h>
#include<stdlib.h>

struct MyArray{
    int total_size;
    int used_size;
    int *ptr;
};

void createArray(struct MyArray *arr, int tSize, int uSize){
     arr->total_size = tSize;
     arr->used_size = uSize;
     arr->ptr = (int *)malloc(tSize*sizeof(int));
}

void showArray(struct MyArray *arr){
    printf("Array Elements are: ");
    for (int i = 0; i <  arr->used_size; i++)
    {
        printf("|  %d  |", arr->ptr[i]);
    }
  printf("\n");
}

void setValue(struct MyArray *arr){
    for (int i = 0; i < arr->used_size; i++)
    {
       printf("Enter %d Element:", i+1 );
       scanf("%d", &(arr->ptr)[i]);
    }
}

/*Creating the GUI*/
#ifdef _WIN32
    #define CLEAR_SCREEN "cls"    //Windows
#else
    #define CLEAR_SCREEN "clear"    //Linux/Mac
#endif

int choice = 1;

void display_menu(){
    printf("\n====================================\n");
    printf("            ARRAY MENU          \n");
    printf("====================================\n");
    printf("1  ENTER Element\n");
    printf("2  DISPLAY Array\n");
    printf("3  EXIT\n");
    printf("------------------------------------\n");
    printf(" Enter your choice: ");
}



int main()
{
    struct MyArray *A;
    A = (struct MyArray *)malloc(sizeof(struct MyArray));

    createArray(A, 5, 3);

        
    do {
        system(CLEAR_SCREEN); // Clears the screen for a clean UI
        display_menu();
        
        scanf("%d", &choice);
        switch (choice) {
            case 1:

                setValue(A);
                break;

            case 2:
                showArray(A);
                break;

            case 3:
                printf("\n Exiting... Thank you!\n");
                break;

            default:
                printf("\n Invalid choice! Please try again.\n");
        }
        
        printf("\nPress Enter to continue...");
        getchar(); 
        getchar(); 
    } while (choice != 3);


    free(A->ptr);
    free(A);
    
return 0;
}
