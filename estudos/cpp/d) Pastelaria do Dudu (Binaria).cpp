#include <iostream>
#include <string.h>

using namespace std;

struct produtos
{
    int pos;
    string nome;
    int quantidade;
};

int busca_binaria(produtos armazem[],int comeco, int fim,int busca)
{
    if(comeco > fim)
        return 0;

    int ind = (comeco + fim)/2;

    if(armazem[ind].pos < busca)
    {
        return busca_binaria(armazem, comeco, ind-1, busca);
    }

    else if(armazem[ind].pos > busca)
    {
        return busca_binaria(armazem, ind+1, fim, busca);
    }
    else{
        return ind;
    }

    return 0;
}

int main()
{
    int N;
    cin >> N;

    produtos armazem[N];

    for(int i = 0; i < N; i++)
    {
        cin >> armazem[i].pos;
        cin.ignore();
        cin >> armazem[i].nome;
        cin >> armazem[i].quantidade;
    }
    
    int produtoB;
    cin >> produtoB;

    int procura = busca_binaria(armazem, 0, N-1, produtoB);

    if(procura == 0)
    {
        cout << "Nao existem produtos com esse codigo em estoque!" << endl;
    }
    else
    {
        cout << armazem[produtoB].nome << " em estoque!" << endl;
    }
    return 0;
}