#include <iostream>
#include <string.h>

using namespace std;

struct insetos{
    string nome;
    float tamanho;

};

void troca ( insetos vetor[], int p1, int p2, insetos* vetorA[])
{
   insetos manter = vetor[p1];

    vetor[p1] = vetor[p2];
    vetor[p2] = manter; 
    *vetorA = vetor;
}

void dividir(insetos vetor[], int final, int comeco, int* pivo, insetos* vetorA[])
{
    int principal = comeco;
    for(int i = comeco; i < final; i++)
    {
        if(vetor[i].tamanho <= vetor[final].tamanho)
        {
            troca(vetor, principal, i, &vetor);
            principal++;
        }
    }
    troca(vetor, final, principal, &vetor);
    *pivo = principal;
    *vetorA = vetor;
}

void quicksort(insetos vetor[], int comeco, int final, insetos* vetorA)
{

    if(comeco >= final)
        return;

    int pivo;

    dividir(vetor, final, comeco, &pivo, &vetor);

    quicksort(vetor, comeco, pivo-1, vetor);
    quicksort(vetor, pivo+1, final, vetor);

    vetorA = vetor;
    return;

}

int main()
{
    int N;
    cin >> N;

    insetos borboleta[N];

    for (int i = 0; i<N; i++)
    {
        getline(cin >> ws, borboleta[i].nome);
        cin >> borboleta[i].tamanho;
    }

    quicksort(borboleta, 0, N-1, borboleta);

    for (int i = 0; i<N; i++)
    {
    cout << borboleta[i].nome << endl;
    }

    return 0;
}