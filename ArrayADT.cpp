#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "ADTArray.h"

using namespace std;


int main()
{
    struct Array arr1;
    int ch, x, index;
    printf("Enter Size of an Array");
    scanf_s("%d", &arr1.size);
    arr1.A = (int*)malloc(arr1.size * sizeof(int));
    arr1.length = 0;
    do {
        printf("Menu\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Sum\n");
        printf("5. Display\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf_s("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter an element and index: ");
            scanf_s("%d%d", &x, &index);
            Insert(&arr1, index, x);
            break;
        case 2:
            printf("Enter Index: ");
            scanf_s("%d", &index);
            x = Delete(&arr1, index);
            printf("Deleted Element is %d\n", x);
            break;
        case 3:
            printf("Enter element to search");
            scanf_s("%d", &x);
            index = LinearSearchM1(&arr1, x);
            printf("Element index %d", index);
            break;
        case 4:
            printf("Sum is %d\n", Sum(arr1));
            break;
        case 5: Display(arr1);


        }
    } while (ch < 6);



    
    std::cout << "Hello World!\n";
}

