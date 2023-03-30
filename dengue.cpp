#include <iostream> // Entrada e sa?da
#include <climits> // INT_MAX


//exercicio método guloso


using namespace std;

int main()
{
	int custo[8][8]; // 8 -> numero maximo de focos
	// custo[i][j] = custo de ir do foco 'i' para o foco 'j'
	int foco_inicial; // Primeira e ultima cidade
	int n; // numero de cidades

	//cout << "Entre com o numero de focos" << endl;
	cin >> n;

	while(n < 2 || n > 8)
	{
		//cout << "Entre com o numero de focos" << endl;
		cin >> n;
	}

	for(int i = 0; i < n ; i++)
	{

		for(int j = i + 1; j < n; j++)
		{
			//cout << "Entre com o custo de ir do foco " << i << " para o foco " << j << endl;
			cin >> custo[i][j];
			custo[j][i] = custo[i][j]; // Custo de i->j = custo de j->i
		}

	}

	//cout << "Entre com a distancia do foco inicial" << endl;
	cin >> foco_inicial;

	bool vis[8]; // marca se ja visitou ou nao um foco
	int menor_custo; // menor custo da viagem
	int custo_at; // menor custo atual
	int foco_atual; // foco atual
	int proximo_foco; // proxima foco


	// inicializando vetor vis (nenhum foco foi visitada no inicio)
	for(int i = 0; i < n; i++)
		vis[i] = false;

	// guloso
	menor_custo = 0;
	foco_atual = foco_inicial;

	for(int i = 0; i < n - 1; i++) // n-1 vezes = qnt de caminhos (exceto a volta para a cidade inicial)
	{
		vis[foco_atual] = true; // marco que ja visitei a cidade atual
		// encontrar qual a proxima cidade mais proxima
		custo_at = INT_MAX;
		for(int j = 0; j < n; j++)
		{
			if(!vis[j] && custo_at > custo[foco_atual][j])
			{
				proximo_foco = j;
				custo_at = custo[foco_atual][j];
			}
		}
		menor_custo += custo_at;
		foco_atual = proximo_foco;
	}
	menor_custo += custo[foco_atual][foco_inicial];
	//cout << "Menor custo = " << menor_custo << endl;
	cout << menor_custo << endl;
	return 0;
}







