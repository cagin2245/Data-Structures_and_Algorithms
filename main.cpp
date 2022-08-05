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

  Array<int>  arr(17);
  arr.Insert(0,2354);
  arr.Insert(1,2354);
  arr.Insert(2,2354);
  arr.Display();
  arr.Delete(0);
  arr.Display();
    
}
