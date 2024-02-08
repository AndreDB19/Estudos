#include <iostream>

using namespace std;

int main()
{
	int N, H;
	cin >> N >> H;

	int A[N];

	for(int i = 0; i < N; i++)
	{
		cin >> A[i];
	}

	int ini = 0;
	int fim = N - 1;
	int cont = 0;

	while(ini <= fim)
	{
		if(ini == fim)
		{
			if(H >= A[ini])
			{
				cont += 1;
				ini++;
				fim--;
			}
			else
			{
				ini++;
				fim--;	
			}
		}
		
		else if((H >= A[ini]) && (H >= A[fim]))
		{
			cont += 2;
			ini++;
			fim--;
		}
		else if(H >= A[ini])
		{
			cont += 1;
			ini++;
			fim--;
		}
		else if(H >= A[fim])
		{
			cont += 1;
			ini++;
			fim--;
		}
		else
		{
			ini++;
			fim--;	
		}
	}
	cout << cont << endl;

	return 0;
}
