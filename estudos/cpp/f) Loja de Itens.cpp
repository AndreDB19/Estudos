#include <iostream>
#include <list>
#include <string>

using namespace std;

struct cadastro
{
    int codigo;
    string nome;
    int preco;
};


int hash1(int x, int M) 
{
    return x%M; /* o valor da função */
}

int hash_linear(int h1, int M, int i)
{
    return (h1+i)%M;
}


int insere(cadastro a[], int x, int M) {
 
    int h1 = hash1(x, M);
    int i = 0;
 /* procura a próxima posição livre */

   
   while (a[h1].codigo != -1) {
        /*
        if (a[h1] == x) 
            return -1; /* valor já existente na tabela 
        if (++cont == M) 
            return -2; /* tabela cheia 
        */    
        h1 = hash_linear(h1,M,i); 
        i++;
    }
 


 /* achou uma posição livre */
    return h1;
}

int hash_busca(cadastro a[], int x, int M)
{
    int pos;
    int i = 0;
    do
    {
    pos= hash_linear(pos,M,i); 
    i++;
    }while(a[pos].codigo != x || i<M);
    
    return pos;
}

int main()
{
    int M;
    cin >> M;

    cadastro produtos[M];
    for(int i = 0; i < M; i++)
    {
        produtos[i].codigo = -1;
    }

    int pos;
    int codigo;
    for (int i = 0; i<M; i++)
    {
        cin >> codigo;
        pos = insere(produtos, codigo, M);
        produtos[pos].codigo = codigo;
        cin >> produtos[pos].nome;
        cin >> produtos[pos].preco;
    }

    list<int> venda;
    list<int> compra;
    int entrada;

    do{
        cin >> entrada;
        if(entrada != -1)
            venda.push_back(entrada);
    }while(entrada != -1);

    do{
        cin >> entrada;
        if(entrada != -1)
            compra.push_back(entrada);
    }while(entrada != -1);

    int tVenda;
    int tCompra;

    cin >> tVenda >> tCompra;

    int Lucro=0;

    for(int i = 0; i<tVenda;i++)
    {
        Lucro += produtos[hash_busca(produtos, venda.front(), M)].preco;
        venda.pop_front();
    }

    for(int i = 0; i<tCompra;i++)
    {
        Lucro -= produtos[hash_busca(produtos, compra.back(), M)].preco;
        compra.pop_back();
    }

    cout << Lucro << " moeda(s).";

    return 0;
}