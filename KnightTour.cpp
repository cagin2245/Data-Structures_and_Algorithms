#include <iostream>
#include <iomanip>

#include"KnightTour.h"
using std::cout;
const std::array<int, 8> KnightTour::xMove = { 2,1,-1,-2,-2,-1,1,2 };
const std::array<int, 8> KnightTour::yMove = { 1,2,2,1,-1,-2,-2,-1 };

KnightTour::KnightTour() {

	cozumMatrisi.resize(TAHTA_BUYUKLUGU);

	for (auto& submatrix : cozumMatrisi)
		submatrix.resize(TAHTA_BUYUKLUGU);
	initBoard();

}

void KnightTour::KnightTourProblemiCozumu() {
	//At (0,0) noktasýndan baþlýyor
	cozumMatrisi[0][0] = 0;

	//çözüm yoksa
	if (!problemiCoz(1, 0, 0)) {
		cout << "Uygun bir çözüm bulunamadý...";
		
	}
	//çözüm varsa
	cozumuGoster();

}
bool KnightTour::problemiCoz(int stepCount, int x, int y) {
	//Eðer son adýmda ise: Baþarýlý (At tüm kareleri gezdi)
	if (stepCount == TAHTA_BUYUKLUGU * TAHTA_BUYUKLUGU)
	{
		return true;
	}
	//At'ýn yapabileceði tüm hamleler
	for (size_t i = 0; i < xMove.size(); ++i)
	{
		int nextX = x + xMove[i];
		int nextY = y + yMove[i];

		if (isValidMove(nextX, nextY))
		{
			cozumMatrisi[nextX][nextY] = stepCount;
			if (problemiCoz(stepCount + 1, nextX, nextY)) {
				return true;
			}
			cozumMatrisi[nextX][nextY] = INT_MIN;
		}

	}
	//Tüm hamleleri denedik ama hiçbiri geçerli deðil, o zaman backtrack uygularýz.
	return false;
}

void KnightTour::cozumuGoster() {
	for (int i = 0; i < TAHTA_BUYUKLUGU; ++i)
	{
		cout << std::left;
		for (int j = 0; j < TAHTA_BUYUKLUGU; ++j)
		{
			cout << std::setw(2) << cozumMatrisi[i][j] << std::setw(2) << ' ';
		}
		cout << "\n";
	}
}
void KnightTour::initBoard() {
	// INT_MIN deðeri at'ýn geçerli kareyi ziyaret etmediði anlamýna geliyor
	for (int i = 0; i < TAHTA_BUYUKLUGU; ++i)
		for (int j = 0; j < TAHTA_BUYUKLUGU; ++j)
			cozumMatrisi[i][j] = INT_MIN;
}
bool KnightTour::isValidMove(int x, int y)
{
	//At tahtanýn dýþýnda olmamalý
	if (x < 0 || x >= TAHTA_BUYUKLUGU)
		return false;
	if (y < 0 || y >= TAHTA_BUYUKLUGU)
		return false;
	//At daha önce ziyaret ettiði bir kareye uðramamalý
	if (cozumMatrisi[x][y] != INT_MIN)
		return false;

	//(x,y) karesi at için uygun
	return true;
}
