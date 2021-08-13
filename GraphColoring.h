#pragma once
#include <iostream>
#include <vector>
using std::vector;

class GraphColoring {
	vector<vector<int>> graphMatrix;
	int renkSayisi;
	vector<int> renkler;

public:
	GraphColoring(const vector<vector<int>>& graph, int _renkSayisi);
	
		// problem çözümü 
		void operator()();
	
private:
	// renkleri recursive þekilde atayacak fonksiyon
	bool solve(size_t nodeIndex);

	// renk atamasýnýn geçerli olup olmadýðýný kontrol edecek fonksiyon
	bool isColorValid(size_t nodeIndex, size_t colorIndex);
	void sonucuGoster();

};