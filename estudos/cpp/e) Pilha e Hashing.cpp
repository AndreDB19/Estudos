#include <iostream>
#include <vector>

using namespace std;

int hash1(int x, int N) 
{
    return x%N; /* o valor da função */
}

int hash2(int x, int N) {
    return 1+(x%(N-1)); /* o valor da função */
}


int insere(int a[], int x, int N) {
 
    int h1 = hash1(x, N);
    int h2 = hash2(x, N);
    int cont = 0;
 /* procura a próxima posição livre */

   
   while (a[h1] != -1) {
        /*
        if (a[h1] == x) 
            return -1; /* valor já existente na tabela 
        if (++cont == N) 
            return -2; /* tabela cheia 
        */ 
       
        h1 = ((h1 + h2) % N); 
    }
 


 /* achou uma posição livre */
    return h1;
}

int main()
{
    int M;
    cin >> M;

    int tabela[M];
    for(int i = 0; i < M; i++)
    {
        tabela[i] = -1;
    }


    int Q;
    cin >> Q;

    vector<int> pilha;
    int e;
    for (int i = 0; i<Q; i++)
    {
        cin >> e;
        pilha.push_back(e);
    }

    for (int i = 0; i<Q; i++)
    {
        tabela[insere(tabela, pilha.back(), M)] = pilha.back();
        pilha.pop_back();
    }

    for(int i = 0; i < M; i++)
    {
        cout << tabela[i] << " ";
    }
    return 0;
}