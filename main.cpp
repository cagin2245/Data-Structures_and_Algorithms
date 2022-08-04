#include <iostream>
#include <stdio.h>
#include <stdlib.h>


#include "NQueensProblem.h"
#include "ADTArray.h"
#include "GraphColoring.h"
#include "KnightTour.h"

#include "Matrix.h"

using namespace std;

int main(){

    int d;
    cout <<"Boyutlari giriniz: ";
    cin>>d;

    lowerTriangular lm(d);

    int x;
        cout << "Tüm elemanlari giriniz: ";
        for(int i = 1;i<=d; i++)
        {
            for(int j = 1; j<=d;j++)
            {
               cin>>x;
               lm.set(i,j,x);
                                
            }
        }
    lm.Display();
    
}
