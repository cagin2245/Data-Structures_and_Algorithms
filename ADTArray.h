#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

class Array
{
private:
    int* A;
    int size;
    int length=0;


public:
    Array() {
        size = 10;
        length = 0;
        A = new int[size];
    }
    Array(int sz)
    {
        size = sz;
        length = 0;
        A = new int[size];
    }
    ~Array()
    {
        delete[]A;
    }
    void Display();
    void Append(int x);
    void Insert(int index, int x);
    int Delete(int index);
    int LinearSearch( int key);
    int LinearSearchM1( int key);
    int LinearSearchM2(int key);
    int BinarySearch(int key);
   // int RBinarySearch(int a[], int l, int h, int key);
    void InsertSort (int x);
    int isSorted();
    void REarrange();
    Array* Merge(Array arr2);
    Array* Union(Array arr2);
    Array* Intersection(Array arr2);
    Array* Difference(Array arr2);
    int Sum();


};

int Array::Sum()
{
    int sum = 0;
    for (int i = 0; i < length; i++)
    {


        sum = sum + A[i];


    }
    return sum;
}
    void Array::Display()
    {
        int i;
        cout << "\nElements are \n" << endl;
        for (i = 0; i < length; i++)
            cout << A[i] << endl;

    }
    void Array::Append(int x)
    {
        if (length < size)
            A[length++] = x;

    }
    void Array::Insert(int index, int x)
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
    int Array::Delete(int index)
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

    int Array::LinearSearch( int key)
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
    int Array::LinearSearchM1( int key)
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
    int Array::LinearSearchM2( int key)
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
    int Array::BinarySearch( int key)
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
    int RBinarySearch(int a[], int l, int h, int key)
    {
        int mid;
        if (l <= h)
        {
            mid = (l + h) / 2;
            if (key == a[mid])
            {
                return mid;
            }
            else if (key < a[mid])
                return RBinarySearch(a, l, mid - 1, key);
            else
                return RBinarySearch(a, mid + 1, h, key);
        }
        return -1;
    }
    void Array::InsertSort(int x)
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
    int Array::isSorted()
    {
        int i;
        for (i = 0; i < length - 1; i++)
        {
            if (A[i] > A[i + 1])
                return 0;

        }
        return 1;
    }
    void Array::REarrange()
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
    Array* Array::Merge(Array arr2)
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
    Array* Array::Union(Array arr2)
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
    Array* Array::Intersection(Array arr2)
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
    Array* Array::Difference(Array arr2)
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
