#include <iostream>
#include <string.h>

using namespace std;

struct gladiador
{
		string nome;
		int forca;
		int hab;
		int idade;
		int vida;
};


bool luta(gladiador g1, gladiador g2)
{
	do{
		g2.vida = g2.vida-(g1.forca+ (2*g1.hab));
		if(g2.vida <= 0)
			return 0;
		
		g1.vida = g1.vida-(g2.forca+ (2*g2.hab));
		if(g1.vida <= 0)
			return 1;
		
	}while(g1.vida > 0 || g2.vida > 0);
}


int main()
{
	gladiador lutador[5];
	for(int i = 0; i<5; i++)
	{
		getline(cin >> ws, lutador[i].nome);
		cin >> lutador[i].forca;
		cin >> lutador[i].hab;
		cin >> lutador[i].idade;
		lutador[i].vida = 100;
	}	
	
	int pg, sg;
	
	do{
	cin >> pg >> sg;
	if(pg == -1 || sg == -1){
		return 0;
	}
	bool vencedor = luta(lutador[pg], lutador[sg]);
	
	if(vencedor == 0)
	{
		cout << lutador[pg].nome << " ganhou a batalha contra " << lutador[sg].nome << endl;
	}
	else
	{
		cout << lutador[sg].nome << " ganhou a batalha contra " << lutador[pg].nome<<endl;
	}	
	
	}while(pg != -1 || sg != -1);
	
	
	return 0;
}