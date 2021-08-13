#include <iostream>
#include <stdio.h>
#include "GraphColoring.h"
using std::cout;

// NP-Complete problem
// Muhtemel durumlarýn sayýsý üstel artýþ gösterir
// O(n^v) (v: köþe) karmaþýklýðýnda çalýþýr
// Brute force ile üstel zaman karmaþýklýðý yakalanýr
// Bipartite graf, sýnav takvimi, radyo frekans atanmasý, register allocation, harita renklendirme vs.

/* Yaklaþýmlar
1) Greedy: Çözüm bulunur ancak en uygun çözüm olma zorunluluðu yoktur
2) Backtracking: Bad state'lerin çoðunluðunu tek iterasyonda reddeder (veya recursive fonksiyon çaðrýsýnda) 
3) Powell-Welsh algorithm: node'larýn derecesine göre sýralanmasýna dayanýr (köþe sayýsýna göre)
*/

GraphColoring::GraphColoring(const vector<vector<int>>& graph, int _renkSayisi): graphMatrix(graph), renkSayisi(_renkSayisi)
{
	renkler.resize(graphMatrix.size());

}
void GraphColoring::operator()() {
	
		if (solve(0))
		{
			sonucuGoster();
		}
		else {
			cout << "Girilen parametrelere uygun çözüm yok...";
		}
	}

// recursive þekilde renkleri atayacak fonksiyon
bool GraphColoring::solve(size_t nodeIndex)
{
	//grafdaki tüm nodelarý göze alýp renkleri istenen þekilde atayabildiysek backtracking ile renklendirme problemini baþarýyla sonuçlandýrdýk
	if (nodeIndex == graphMatrix.size()) {
		return true;
	}
	//tüm renkleri dene
	for (int colorIndex = 1; colorIndex <= renkSayisi; colorIndex++)
	{
		//Eðer geçerliyse renk atama
		if (isColorValid(nodeIndex, colorIndex)) {
			renkler[nodeIndex] = colorIndex;


			//sonraki node'un rengini bulma
			if (solve(nodeIndex + 1))
			{
				return true;
			}
			return false;
		}

	}
}

//verilen köþede doðru renk olup olmadýðýný kontrol eden fonksiyon
bool GraphColoring::isColorValid(size_t nodeIndex,size_t colorIndex)
{
	for (size_t i = 0; i < graphMatrix.size(); i++)
	{
		if (graphMatrix[nodeIndex][i] == 1 && colorIndex == renkler[i])
			return false;
	}

}


void GraphColoring::sonucuGoster() {
	for (size_t  i = 0; i < graphMatrix.size(); i++)
	{
		cout << "Node " << i + 1 <<":  " << renkler[i] << " renk indexine sahip" << "\n";
	}
}
