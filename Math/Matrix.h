#pragma once
#include <iostream>

using namespace std;

class Matrix {

    protected:
    int n; // boyut
    int * A; // array pointer
    public:
    Matrix()
    {
        n = 2;
        A = new int[n];
    }
    Matrix(int n)
    {
        this->n = n;
        A = new int[n];
    }
    
    virtual void set(int i, int j, int x){};
    virtual int get(int i, int j){ if(i==j)
        return A[i-1];
        else return 0;};
    void Display();
    
    

};
class Diagonal : Matrix {

    
    public:
    Diagonal(){
        n=2;
        A = new int[2];
    }
    Diagonal(int N){
        this-> n = N;
        A = new int[n];
    }
    void set(int i,int j, int x)
    {
        if(i==j)
        A[i-1] = x;
    }

    int get(int i, int j)
    {
        if(i==j)
        return A[i-1];
        else return 0;
    }
    void Display()
    {
        for(int i= 0 ;i<n;i++)
            for(int j=0; j<n;j++)
            {
                if(i==j) cout<< A[i-1];
                else cout<<"0";
            }
            cout << endl;
    }
};
class lowerTriangular : Matrix {

    public:
    // 0 lar depolanmayacak, row by row veya column by column

    // index(A[i][j]) = [ (i-(i-1)/2] + j - 1                     -> row by row
    // index(A[i][j]) = [n + n-1 + n-2 ...]      + (i-j)          -> column by column
    //                = [n(j-1)-[1+2+3+...j-2]   + (i-j)            }
    //                = [n(j-1)-((j-2)*(j-1))/2] + (i-j)            }
    lowerTriangular()
    {
            n=2;
            A = new int[2*(2+1)/2];
    }
    lowerTriangular(int n)
    {
            this->n = n;
            A = new int[n*(n+1)/2];
    }
    
    void set(int i, int j, int x)
    {
        if(i>=j){
            A[i*(i-1) /2+j-1] = x;
            }
    }
    int get(int i, int j)
    {
        if(i>=j)
        {
        return A[i*(i-1 /2+j-1)];
        }
        return 0;
    }
    void Display(){
         for(int i= 1 ;i<=n;i++){
            for(int j=1; j<=n;j++)
            {
                if(i>=j){ cout<< A[i*(i-1)/2+j-1] << " ";}
                else{ cout<<"0 ";}
            }
            cout << endl;
            }
            
    }
    
};
class upperTriangular : Matrix {
    public:
    /*
        Row Major Mapping:

        index(A[i][j]) = [n+ n-1+ n-2+...+ n-(i-2] + (j-i)
                       = [(i-1)n - ((i-2)(i-1))/2] + (j-i)
        
        Column Major Mapping:

        index(A[i][j]) = [(j*(j-1))/2] + i-1

    */
    upperTriangular()
    {
            n=2;
            A = new int[2*(2+1)/2];
    }
    upperTriangular(int n)
    {
            this->n = n;
            A = new int[n*(n+1)/2];
    }
    void set(int i, int j, int x)
    {
        if(i<=j){
            A[j*(j-1) /2+j-1] = x;
            }
    }
    int get(int i, int j)
    {
        if(i<=j)
        {
        return A[j*(j-1) /2+j-1];
        }
        return 0;
    }
    void Display(){
         for(int i= 1 ;i<=n;i++){
            for(int j=1; j<=n;j++)
            {
                if(i<=j){ cout<< A[j*(j-1) /2+j-1] << " ";}
                else{ cout<<"0 ";}
            }
            cout << endl;
            }
            
    }

};
class symmetricMatrix : Matrix {
    public:
    // 0 lar depolanmayacak, row by row veya column by column

    // index(A[i][j]) = [ (i-(i-1)/2] + j - 1                     -> row by row
    // index(A[i][j]) = [n + n-1 + n-2 ...]      + (i-j)          -> column by column
    //                = [n(j-1)-[1+2+3+...j-2]   + (i-j)            }
    //                = [n(j-1)-((j-2)*(j-1))/2] + (i-j)            }
    symmetricMatrix()
    {
            n=2;
            A = new int[2*(2+1)/2];
    }
    symmetricMatrix(int n)
    {
            this->n = n;
            A = new int[n*(n+1)/2];
    }
    
    void set(int i, int j, int x)
    {
        if(i>=j){
            A[i*(i-1) /2+j-1] = x;
            }
    }
    int get(int i, int j)
    {
        if(i>=j)
        {
        return A[i*(i-1 /2+j-1)];
        }
        return 0;
    }
    void Display(){
         for(int i= 1 ;i<=n;i++){
            for(int j=1; j<=n;j++)
            {
                if(i>=j){ cout<< A[i*(i-1)/2+j-1] << " ";}
                else{ cout<<"0 ";}
            }
            cout << endl;
            }
            
    }
};
class triDiagonalMatrix : Matrix {
    
    public:
    // 0 lar depolanmayacak, row by row veya column by column

    // index(A[i][j]) = [ (i-(i-1)/2] + j - 1                     -> row by row
    // index(A[i][j]) = [n + n-1 + n-2 ...]      + (i-j)          -> column by column
    //                = [n(j-1)-[1+2+3+...j-2]   + (i-j)            }
    //                = [n(j-1)-((j-2)*(j-1))/2] + (i-j)            }
    triDiagonalMatrix()
    {
            n=2;
            A = new int[4];
    }
    triDiagonalMatrix(int n)
    {
            this->n = n;
            A = new int[3*n-2];
    }
    
    void set(int i, int j, int x)
    {
        if(i-j == 1)
        {
            A[i-1] = x;
        }
        else if (i-j == 0)
        {
            A[n-1+i-1] == x;
        }
        else if(i-j == -1)
        {
            A[2*n-1+i-1] = x;
        }        
    }
    int get(int i, int j)
    {
        if(i>=j)
        {
        return A[i*(i-1 /2+j-1)];
        }
        return 0;
    }
    void Display(){
         for(int i= 1 ;i<=n;i++){
            for(int j=1; j<=n;j++)
            {
                if(i-j == 0 || i-j == 1 || i-j == -1){ cout<< A[i*(i-1)/2+j-1] << " ";}
                else{ cout<<"0 ";}
            }
            cout << endl;
            }
            
    }
};