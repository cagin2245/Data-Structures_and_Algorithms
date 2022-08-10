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
Sparse operator+(Sparse &s);
friend istream & operator>>(istream &is, Sparse &s);
friend ostream & operator<<(ostream &os, Sparse &s);


};
Sparse Sparse::operator+(Sparse &s){
    int i,j,k;
    if(m!=s.m || n!= s.n){
        return Sparse(0,0,0);
        }
    Sparse * sum = new Sparse(s.m,s.n,s.num+s.num);
    i=j=k=0;
    while(i<num && j<s.num)
    {
        if(el[i].i<s.el[j].i)
            sum-> el[k++] = el[i++];
        else if(el[i].i>s.el[j].i)
            sum-> el[k++] = s.el[j++];
        else{
            if(el[i].j<s.el[j].j)
            sum-> el[k++] = el[i++];
        else if(el[i].j>s.el[j].j)
            sum-> el[k++] = s.el[j++];
            else{
                sum->el[k] = el[i];
                sum->el[k++].x=el[i++].x+s.el[j++].x;
            }
        }

    }
    for(;i<num;i++) sum ->el[k++]= el[i];
    for(;j<s.num;j++)sum -> el[k++]= s.el[j];
    sum->num =k;
    return *sum;
}
    istream & operator>>(istream &is, Sparse &s)
    {
        cout <<"0 olmayan elemanları giriniz";
        for(int i = 0; i < s.num; i++)
        {
            cin >> s.el[i].i>>s.el[i].j>>s.el[i].x;
            
        }
        return is;
    }
    ostream & operator<<(ostream &os, Sparse &s)
    {
        int k = 0;
        for(int i = 0; i<s.m; i++)
        {
            for(int j= 0; j< s.n; j++)
            {
                if(s.el[k].i==i && s.el[k].j ==j)
                    cout << s.el[k++].x<<" ";
                else
                    cout << "0 ";
            }
            cout << endl;
        }
        return os;
    }

