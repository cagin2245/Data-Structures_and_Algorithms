#pragma once
#include <vector>
#include <array>
using std::vector;

class KnightTour {
	//sayýlarý tutacak vektör
	vector<vector<int>> cozumMatrisi;
	//yatay adým
	const static std::array<int, 8> xMove;
	const static std::array<int, 8> yMove;

	constexpr static int TAHTA_BUYUKLUGU = 8;

public:
	KnightTour();

	void KnightTourProblemiCozumu();
	bool problemiCoz(int stepCount, int x, int y);

	bool isValidMove(int x, int y);
	void cozumuGoster();
private:
	void initBoard();

};