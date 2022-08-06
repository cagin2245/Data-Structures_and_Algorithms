#pragma once
#include <iostream>

using namespace std;
class Element
{
    public:
    int i;
    int j;
    int x;
};
class Sparse {
    private:
    int m;
    int n;
    int num;
    Element *el;
    public:
    Sparse(int m, int n, int num){
        this -> m=m;
        this -> n=n;
        this -> num=num;
        el = new Element[this->num];

    }
    ~Sparse()
    {
        delete [] el;
    }

    void read()
    {
        cout <<"0 olmayan elemanları giriniz";
        for(int i = 0; i < num; i++)
        {
            cin >> el[i].i>>el[i].j>>el[i].x;
            
        }
    }
    void display()
    {
        int k = 0;
        for(int i = 0; i<m; i++)
        {
            for(int j= 0; j< n; j++)
            {
                if(el[k].i==i && el[k].j ==j)
                    cout << el[k++].x<<" ";
                else
                    cout << "0 ";
            }
            cout << endl;
        }
    }
};
