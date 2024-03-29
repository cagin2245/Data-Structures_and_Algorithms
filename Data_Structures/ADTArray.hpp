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

    Array() {
        this->size = 10;
        length = 0;
        this->A = new T [size];
    }
    
    Array(int sz)
    {
        this->size = sz;
        length = 0;
        this->A = new T[size];
    }
    
    ~Array()
    {
        delete[]A;
    }
    
    void Display()
    {
        int i;
        cout << "\nElements are \n" << endl;
        for (i = 0; i < length; i++)
            cout << A[i] << endl;

    }
    
    void Append(const T& x)
    {
        if (length < size)
            A[length++] = x;

    }
    
    void Insert(int index, const T& x)
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
    
    Array getA(){
        return A;
    }
    int getLength(){
        return length;
    }
    Array Delete(int index)
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
    return 0;
    }
    
    Array LinearSearch( const T& key)
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
    
    Array ArrayLinearSearchM1( const T& key)
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
    
    Array LinearSearchM2( int key,const T& t)
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
    
    Array BinarySearch( T key, const T&)
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
    
    Array InsertSort(const T& x)
    {
        int i = length - 1;
        if (length == size)
            return 0;
        while (i >= 0 && A[i] > x)
        {
            A[i + 1] = A[i];
            i--;
        }
        A[i + 1] = x;
        length++;
    }
    
    Array isSorted(const T& t)
    {
        int i;
        for (i = 0; i < length - 1; i++)
        {
            if (A[i] > A[i + 1])
                return 0;

        }
        return 1;
    }
    
    void REarrange(const T&t)
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
    
    Array Sum(const T& t)
{
    int sum = 0;
    for (int i = 0; i < length; i++)
    {


        sum = sum + A[i];


    }
    return sum;
}
        Array arrayInit(const T& t) {
        Array* arr1 = new Array;
        int ch, x, index, sz;
        printf("Enter Size of an Array");
        scanf("%d", &sz);
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
            scanf("%d", &ch);

            switch (ch)
            {
            case 1:
                printf("Enter an element and index: ");
                scanf("%d%d", &x, &index);
                arr1->Insert(index, x);
                break;
            case 2:
                printf("Enter Index: ");
                scanf("%d", &index);
                x = arr1->Delete(index);
                printf("Deleted Element is %d\n", x);
                break;
            case 3:
                printf("Enter element to search");
                scanf("%d", &x);
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
        Array A = arr2.getA();
        int length = arr2.getLength();
        arr2 = new Array(length + arr2.length);
        while (i < length && j < arr2.length) {
            if (A[i] < arr2.A[j]) {
                arr2->A[k++] = A[i++];
            }
            else
            {
                arr2->A[k++] = arr2.A[j++];
            }
        }
        for (; i <length; i++)
        {
            arr2->A[k++] = A[i];
        }
        for (; j < arr2.length; j++)
        {
            arr2->A[k++] = arr2.A[j];
        }
        arr2->length = length + arr2.length;
        arr2->size = 10;
        return arr2;
    }
    template <typename T>
    Array<T>* Union(Array<T> arr2)
    
    {
        int i, j, k;
        i = j = k = 0;
        Array A = arr2.getA();
        int length = arr2.getLength();
        arr2 = new Array(length + arr2.length);
        while (i < length && j < arr2.length) {
            if (A[i] < arr2.A[j]) {
                arr2->A[k++] = A[i++];
            }
            else if (arr2.A[j] < A[i])
            {
                arr2->A[k++] = arr2.A[j++];
            }
            else {
                arr2->A[k++] = A[i++];
                j++;
            }
        }
        for (; i < length; i++)
        {
            arr2->A[k++] = A[i];
        }
        for (; j < arr2.length; j++)
        {
            arr2->A[k++] = arr2.A[j];
        }
        arr2->length = k;
        arr2->size = 10;
        return arr2;
    }
    template <typename T>
    Array<T>* Intersection(Array<T> arr2)
    
    {
        int i, j, k;
        i = j = k = 0;
        Array A = arr2.getA();
        int length = arr2.getLength();
        arr2 = new Array(length + arr2.length);
        while (i < length && j < arr2.length) {
            if (A[i] < arr2.A[j]) {
                i++;
            }
            else if (arr2.A[j] < A[i])
            {
                j++;
            }
            else if (A[i] == arr2.A[j]) {
                arr2->A[k++] = A[i++];
                j++;
            }
        }

        arr2->length = k;
        arr2->size = 10;
        return arr2;
    }
    template <typename T>
    Array<T>* Difference(Array<T> arr2)
    {
        int i, j, k;
        i = j = k = 0;
        Array A = arr2.getA();
        int length = arr2.getLength();
        arr2 = new Array(length + arr2.length);
        while (i < length && j < arr2.length) {
            if (A[i] < arr2.A[j]) {
                arr2->A[k++] = A[i++];
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
            arr2->A[k++] = A[i];
        }

        arr2->length = k;
        arr2->size = 10;
        return arr2;
    }
    
    