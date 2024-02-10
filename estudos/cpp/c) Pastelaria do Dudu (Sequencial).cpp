#include <iostream>
#include <string.h>

using namespace std;

struct produtos
{
    string nome;
    int quantidade;
};

int busca_sequecial(produtos armazem[],int tamanho ,string busca)
{
    for(int i = 0; i< tamanho; i++)
    {
        if(armazem[i].nome.compare(busca) == 0){
            return 1;
        }
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
        cin.ignore();
        cin >> armazem[i].nome;
        cin >> armazem[i].quantidade;
    }
    
    string produtoB;
    cin >> produtoB;

    int resultado = busca_sequecial(armazem, N, produtoB);

    if(resultado == 1)
        cout << produtoB << " esta em estoque!" << endl;
    
    else
        cout << "Nao existe " << produtoB << " em estoque!" << endl;

}