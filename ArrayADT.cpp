#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "ADTArray.h"

using namespace std;


int main()
{
    Array* arr1 = new Array;
    int ch, x, index,sz;
    printf("Enter Size of an Array");
    scanf_s("%d", &sz);
    arr1 =new  Array(sz);
   
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
            arr1->Insert(index,x);
            break;
        case 2:
            printf("Enter Index: ");
            scanf_s("%d", &index);
            x = arr1->Delete( index);
            printf("Deleted Element is %d\n", x);
            break;
        case 3:
            printf("Enter element to search");
            scanf_s("%d", &x);
            index = arr1->LinearSearchM1( x);
            printf("Element index %d", index);
            break;
        case 4:
            cout << "Sum is %d\n" << arr1->Sum() << endl;
            break;
        case 5: arr1->Display();


        }
    } while (ch < 6);




    std::cout << "Hello World!\n";
}

