#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

template <typename T>
class Array
{
private:
    T* A;
    int size;
    int length=0;


public:
template <typename T>
    Array(T A ) {
        size = 10;
        length = 0;
        A = new int[size];
    }
    template <typename T>
    Array(T A ,int sz)
    {
        size = sz;
        length = 0;
        A = new int[size];
    }
    template <typename T>
    ~Array()
    {
        delete[]A;
    }
    template <typename T>
    Array<T>::Array::Display()
    {
        int i;
        cout << "\nElements are \n" << endl;
        for (i = 0; i < length; i++)
            cout << A[i] << endl;

    }
    template <typename T>
    Array<T>::Append(T x)
    {
        if (length < size)
            A[length++] = x;

    }
    template <typename T>
    Array<T>::Insert(int index, T x)
    {
        int i;
        if (index >= 0 && index <= length)
        {
            for (i = length; i > index; i--)
            {
                A[i] = A[i - 1];
            }
           A[index] = x;
           length++;

        }
    }
    template <typename T>
    Array<T>::Delete(int index)
    {
        int x = 0;
        int i;
        if (index >= 0 && index < length)
        {
            x = A[index];
            for (i = index; i < length - 1; i++)
            {
                A[i] = A[i + 1];

            }
            length--;
            return x;
        }

    }
    template <typename T>
    Array<T>::LinearSearch( T key)
    {
        int i;
        for (i = 0; i < length; i++)
        {
            if (key == A[i])
            {
                return i;
            }
            return -1;
        }
    }
    template <typename T>
    Array<T>::LinearSearchM1( T key)
    {
        int i;
        for (i = 0; i < length; i++)
        {
            if (key == A[i])
            {
                swap(A[i], A[i - 1]);
                return i;
            }
            return -1;
        }
    }
    template <typename T>
    Array<T>::LinearSearchM2( int key)
    {
        int i;
        for (i = 0; i < length; i++)
        {
            if (key == A[i])
            {
                swap(A[i], A[0]);
                return i;
            }
            return -1;
        }
    }
    template <typename T>
    Array<T>::BinarySearch( T key)
    {
        int l, mid, h;
        l = 0;
        h = length - 1;

        while (l <= h)
        {
            mid = (l + h) / 2;
            if (key == A[mid])
            {
                return mid;
            }
            else if (key <A[mid])
            {
                h = mid - 1;
            }
            else
            {
                l = mid + 1;
            }

        }
        return -1;
    }
   // int RBinarySearch(int a[], int l, int h, int key);
    template <typename T>
    Array<T>::InsertSort(T x)
    {
        int i = length - 1;
        if (length == size)
            return;
        while (i >= 0 && A[i] > x)
        {
            A[i + 1] = A[i];
            i--;
        }
        A[i + 1] = x;
        length++;
    }
    template <typename T>
    Array<T>::isSorted()
    {
        int i;
        for (i = 0; i < length - 1; i++)
        {
            if (A[i] > A[i + 1])
                return 0;

        }
        return 1;
    }
    template <typename T>
    void Array<T>::REarrange()
    {
        int i, j;
        i = 0;
        j = length - 1;
        while (i < j)
        {
            while (A[i] < 0)i++;
            while (A[i] == 0)j--;
            if (i < j)swap(A[i], A[j]);
        }
    }
    template<typename ValueT>
    Array* Merge(Array arr2);
    Array* Union(Array arr2);
    Array* Intersection(Array arr2);
    Array* Difference(Array arr2);
    template <typename T>
    Array<T>::Sum()
{
    int sum = 0;
    for (int i = 0; i < length; i++)
    {


        sum = sum + A[i];


    }
    return sum;
}
    void Array<T>::arrayInit() {
        Array* arr1 = new Array;
        int ch, x, index, sz;
        printf("Enter Size of an Array");
        scanf_s("%d", &sz);
        arr1 = new  Array(sz);

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
                arr1->Insert(index, x);
                break;
            case 2:
                printf("Enter Index: ");
                scanf_s("%d", &index);
                x = arr1->Delete(index);
                printf("Deleted Element is %d\n", x);
                break;
            case 3:
                printf("Enter element to search");
                scanf_s("%d", &x);
                index = arr1->LinearSearchM1(x);
                printf("Element index %d", index);
                break;
            case 4:
                cout << "Sum is %d\n" << arr1->Sum() << endl;
                break;
            case 5: arr1->Display();


            }
        } while (ch < 6);
    }



};

    
    
    template <typename T>
    Array<T>* Merge(Array<T> arr2)
    {
        int i, j, k;
        i = j = k = 0;
        Array* arr3 = new Array(length + arr2.length);
        while (i < length && j < arr2.length) {
            if (A[i] < arr2.A[j]) {
                arr3->A[k++] = A[i++];
            }
            else
            {
                arr3->A[k++] = arr2.A[j++];
            }
        }
        for (; i <length; i++)
        {
            arr3->A[k++] = A[i];
        }
        for (; j < arr2.length; j++)
        {
            arr3->A[k++] = arr2.A[j];
        }
        arr3->length = length + arr2.length;
        arr3->size = 10;
        return arr3;
    }
    template <typename T>
    Array<T>* Union(Array<T> arr2)
    
    {
        int i, j, k;
        i = j = k = 0;
        Array* arr3 = new Array(length + arr2.length);
        while (i < length && j < arr2.length) {
            if (A[i] < arr2.A[j]) {
                arr3->A[k++] = A[i++];
            }
            else if (arr2.A[j] < A[i])
            {
                arr3->A[k++] = arr2.A[j++];
            }
            else {
                arr3->A[k++] = A[i++];
                j++;
            }
        }
        for (; i < length; i++)
        {
            arr3->A[k++] = A[i];
        }
        for (; j < arr2.length; j++)
        {
            arr3->A[k++] = arr2.A[j];
        }
        arr3->length = k;
        arr3->size = 10;
        return arr3;
    }
    template <typename T>
    Array<T>* Intersection(Array<T> arr2)
    
    {
        int i, j, k;
        i = j = k = 0;
        Array* arr3 = new Array(length + arr2.length);
        while (i < length && j < arr2.length) {
            if (A[i] < arr2.A[j]) {
                i++;
            }
            else if (arr2.A[j] < A[i])
            {
                j++;
            }
            else if (A[i] == arr2.A[j]) {
                arr3->A[k++] = A[i++];
                j++;
            }
        }

        arr3->length = k;
        arr3->size = 10;
        return arr3;
    }
    template <typename T>
    Array<T>* Difference(Array<T> arr2)
    {
        int i, j, k;
        i = j = k = 0;
        Array* arr3 = new Array(length + arr2.length);
        while (i < length && j < arr2.length) {
            if (A[i] < arr2.A[j]) {
                arr3->A[k++] = A[i++];
            }
            else if (arr2.A[j] < A[i])
            {
                j++;
            }
            else {
                i++;
                j++;
            }
        }
        for (; i < length; i++)
        {
            arr3->A[k++] = A[i];
        }

        arr3->length = k;
        arr3->size = 10;
        return arr3;
    }
    
    