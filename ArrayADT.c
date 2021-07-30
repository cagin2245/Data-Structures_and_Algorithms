#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "ADTArray.h"

using namespace std;


int main()
{
    struct Array arr = { {2,6,10,15,25},10,5 };
    struct Array arr2 = { {3,4,7,15,20},10,5 };
    struct Array* arr3;
    arr3 =  Difference(&arr, &arr2);

    Display(*arr3);
    std::cout << "Hello World!\n";
}

