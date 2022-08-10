#include <stdio.h>
#include <stdlib.h>
// Bilgisayarkavramlari (Dr.Sadi Evren Seker)'e teþekkür ediyorum
struct n {
	int data;
	n* sol;
	n* sag;
};
typedef n node;
node* ekle(node* agac, int x) {
	if (agac == NULL) {
		node* root = new node;
		root->sol = NULL;
		root->sag = NULL;
		root->data = x;
		return root;

	}
	
	if (agac->data < x) {
		agac->sag = ekle(agac->sag, x);
		return agac;
	}
	agac->sol = ekle(agac->sol, x);
	return agac;
	}

void dolas(node* agac) {
	// Infix: LNR, RNL
	// Prefix: NLR, NRL
	// Postfix: LRN, RLN
	if (agac == NULL)
	{
		return;

	}
	dolas(agac->sol);
	printf(" %d ", agac->data);
	dolas(agac->sag);
}
int find(node* agac, int aranan)
{
	
	if (agac == NULL)
	{
		return -1;

	}
	if (agac->data == aranan) {
		return 1;
	}
	if (find(agac->sag, aranan) >= 0)
	{
		return 1;
	}
	if (find(agac->sol, aranan) >= 0)
	{
		return 1;
	}
	return -1;
	printf(" %d ", agac->data);
	dolas(agac->sag);
}
int max(node* agac) {
	while (agac->sag != NULL)
	{
		agac = agac->sag;
	}
	return agac->data;
}
int min(node* agac) {
	while (agac->sol != NULL)
	{
		agac = agac->sol;
	}
	return agac->data;
}
node* remove(node* agac,int x) {
	if (agac == NULL)
	{
		return NULL;
	}
	if (agac->data == x)
	{
		if (agac->sol == NULL && agac->sol == NULL)
			return NULL;
		if (agac->sag != NULL) {
			agac->data = min(agac->sag);
			agac->sag = remove(agac->sag, min(agac->sag));
			return agac;
		}
		agac->data = max(agac->sol);
		agac->sol = remove(agac->sol, max(agac->sol));
		return agac;
	}
	if (agac->data < x) {
		agac->sag = remove(agac->sag, x);
		return agac;
	}
	agac ->sol= remove(agac->sol, x);
	return agac;

}
int main() {
	node* agac = NULL;
	agac = ekle(agac, 12);
	agac = ekle(agac, 200);
	agac = ekle(agac, 190);
	agac = ekle(agac, 213);
	agac = ekle(agac, 56);
	agac = ekle(agac, 24);
	agac = ekle(agac, 18);
	agac = ekle(agac, 27);
	agac = ekle(agac, 28);
	
	printf("arama sonucu: %d \n", find(agac, 27));
	agac = remove(agac, 56);
	printf("Min deger: %d \n", min(agac));	
	printf("Max deger: %d \n", max(agac));
	

	dolas(agac);


}