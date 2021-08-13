#include "NQueensProblem.h"
#include <iostream>
using std::cout;using std::cin;

QueensProblem::QueensProblem(int _numOfQueens):numofQueens(_numOfQueens)
{
	satrancTahtasi.resize(numofQueens);
	for (auto& chessrow : satrancTahtasi)
	{
		chessrow.resize(numofQueens);
	}
}
	void QueensProblem::cozum() {
		if (setQueens(0)) {
			printQueens();

		}
		else {
			cout << "Bir çözüm yok...\n";
		}

	}
	bool QueensProblem::setQueens(int colIndex)
	{
		if (colIndex == numofQueens)
		{
			return true;
		}
		for (int rowIndex = 0; rowIndex < numofQueens; ++rowIndex)
		{
			if (gecerliHamle(rowIndex, colIndex)) {
				satrancTahtasi[rowIndex][colIndex] = 1;


				if (setQueens(colIndex + 1)) {
					return true;
				}
			// Vezir taþýný verilen sütuna yerleþtiremediysek BACKTRACKING uygulanýr
			// Ne yapmalýyýz? Ýtere etmeye devam etmeli ve sýradaki satýr için iþlemi tekrarlamalýyýz

				satrancTahtasi[rowIndex][colIndex] = 0; //Backtracking iþlemi
			}
			
		}
		//tüm satýrlara baktýk ancak bir sonuca ulaiamadýk
		//vezirleri yerleþtiremedik çünkü geçersiz hamle
		//backtrack uygularýz -> önceki vezirin yerini deðiþtirirsek çözüme ulaþabiliriz
		return false;
	}
	void QueensProblem::printQueens() const
	{
		for (size_t i = 0; i < satrancTahtasi.size(); i++)
		{
			for (size_t j = 0;j < satrancTahtasi.size(); j++)
			{
				if (satrancTahtasi[i][j] == 1)
				{
					cout << " * ";
				}
				else
				{
					cout << " - ";

				}
			}
			cout << '\n';
		}
	}
	bool QueensProblem::gecerliHamle(int rowIndex, int colIndex)
	{
		for (int i = 0; i < colIndex; i++) {
			if (satrancTahtasi[rowIndex][i] == 1)
				return false;
		}
		for (int i = rowIndex, j = colIndex; i >= 0 && j >= 0; i--, j--)
		{
			if (satrancTahtasi[i][j] == 1)
				return false;
		}
		for (int i = rowIndex, j = colIndex; i < numofQueens&& j >= 0; i++, j--)
		{
			if (satrancTahtasi[i][j] == 1)
			{
				return false;
			}
		}
		return true;
	}

	void QueensProblem::initProgram()

	{
		
		int x;
		cout << "Please enter the size of the chess table: ";
		cin >> x;
		QueensProblem problem{ x };
		problem.cozum();
		
	}
	
