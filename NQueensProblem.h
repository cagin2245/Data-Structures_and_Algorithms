#pragma once

#include <iostream>
#include <vector>
using std::vector;

class QueensProblem
{
	
	vector<vector<int>> satrancTahtasi;
	int numofQueens = 0;

public:
	QueensProblem() {};
	QueensProblem(int _numofQueens);
	void cozum();
	void initProgram();
	
private:
	bool setQueens(int colIndex);
	bool gecerliHamle(int rowIndex, int colIndex);

	void printQueens() const;

};