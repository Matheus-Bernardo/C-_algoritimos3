#include <iostream> // Entrada e sa?da
#include <climits> // INT_MAX

//USAR METODO GULOSO

using namespace std;

int main()
{
	int custo[8][8]; // 8 -> numero maximo de paises
	// custo[i][j] = custo de ir do foco 'i' para o foco 'j'
	int pais_inicial; // Primeiro e ultimo pais
	int n; // numero de paises
	int caminho[8][8]; 	// utilizado para recuperar quais itens foram escolhidos
	// 0 -> nao pegar o item
	// 1 -> pegar o item

	//cout << "Entre com o numero de paises" << endl;
	cin >> n;

	while(n <= 0 || n >= 8)
	{
		//cout << "Entre com o numero de paises" << endl;
		cin >> n;
	}
  
	for(int i = 0; i < n ; i++)
	{
		for(int j = i + 1; j < n; j++)
		{
			//cout << "Entre com o custo de ir do pais " << i << " para o pais " << j << endl;
			cin >> custo[i][j];
			custo[j][i] = custo[i][j]; // Custo de i->j = custo de j->i
		}
	}
	//cout << "Entre com a distancia do país inicial" << endl;
	pais_inicial = 0;

	bool vis[8]; // marca se ja visitou ou nao um país
	int menor_custo; // menor custo
	int custo_at; // menor custo atual
	int pais_atual; 
	int proximo_pais;
  
	// inicializando vetor vis (nenhum país foi visitado no inicio)
	for(int i = 0; i < n; i++)
		vis[i] = false;

	// guloso
	menor_custo = 0;
	pais_atual = pais_inicial;

	for(int i = 0; i < n - 1; i++) // n-1 vezes = qnt de caminhos (exceto a volta para o foco inicial)
	{
		vis[pais_atual] = true; // marco que ja visitei o foco
		// encontrar qual o foco mais proximo
		custo_at = INT_MAX;
		for(int j = 0; j < n; j++)
		{
			if(!vis[j] && custo_at > custo[pais_atual][j])
			{
				proximo_pais = j;
				custo_at = custo[pais_atual][j];
			}
		}
		menor_custo += custo_at;
		pais_atual = proximo_pais;
		menor_custo += custo[pais_atual][pais_inicial];
		cout << pais_atual << endl;
		
	}
	return 0;
}
