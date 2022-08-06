#include <iostream>
#include <stdio.h>
#include <stdlib.h>


#include "NQueensProblem.h"
#include "ADTArray.h"
#include "GraphColoring.h"
#include "KnightTour.h"

#include "Matrix.h"
#include "sparseMatrix.h"

using namespace std;

int main(){

  Sparse s1(5,5,5);
  s1.read();
  s1.display();
  return 0;
}
