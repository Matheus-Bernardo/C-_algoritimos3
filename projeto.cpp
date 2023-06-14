#include <iostream>
#include <string.h>


using namespace std;


typedef struct Pokemon
{
	string nome;
	string habilidade;
	string tipo;
	int id;
} Pokemon;



typedef struct Node
{
	Pokemon dados;
	Node * right;
	Node * left;
} Node;



Node * insert(Node * aux, Pokemon newData)
{
	if(aux == NULL)
	{
		Node * n = new Node;
		n->dados = newData;
		n->right = NULL;
		n->left = NULL;
		return n;
	}
	else
	{
		if(newData.id > aux->dados.id)
		{
			//inserir na direita
			aux->right = insert(aux->right, newData);
		}
		else if(newData.id < aux->dados.id)
		{
			//inserir na esquerda
			aux->left = insert(aux->left, newData);
		}
	}
	return aux;
}


Node * search(Node * aux, int id)
{

	if(aux == NULL)
		return NULL;
	
	if(aux->dados.id == id){
		cout<< "o Pokemon da posição "<< id << "é o " << aux->dados.nome;
	}

	if(id > aux->dados.id)
	{
		return search(aux->right, id);
	}
	else
	{
		return search(aux->left, id);
	}
}


void show_ordered(Node * aux)
{
	//varredura a esquerda
	if(aux->left != NULL)
		show_ordered(aux->left);
	cout << aux->dados.nome << endl;
	//varredura a direita
	if(aux->right != NULL)
		show_ordered(aux->right);
}


Node * menor(Node *& curr)
{
	Node * aux = curr;
	if(aux == NULL)
		return NULL;
	if(aux->left == NULL)
	{
		curr = curr->right;
		return aux;
	}
	else
	{
		return menor(aux->left);
	}
}


int remove(Node *& aux, int id)
{
	Node * p = aux;
	if(aux == NULL)
		return 0;
	if(aux->dados.id == id )
	{
		if(aux->left == NULL)
		{
			aux = aux->right;
		}
		else if(aux->right == NULL)
		{
			aux = aux->left;
		}
		else
		{
			p = menor(aux->right);
			aux->dados = p->dados;
		}
		delete p;
	}
	else
	{

		if(id > aux->dados.id)
		{
			return remove(aux->right, id);
		}
		else if(id < aux->dados.id)
		{
			return remove(aux->left, id);
		}
	}
}


int main()
{
	cout << "Bem Vindo" << endl;

	Node * root;
	root = NULL;


	int controle;
	Pokemon novoPokemon;



	while(1)
	{
		cout<<"XXXXXXXXXXXXXXXXXXX"<<endl;
		cout << "1-adicionar um pokémon da Pokédex \n2- para remover um pokémon\n3-Procurar Pokemom\n4-Listar pokemons\n5- para sair " << endl;
		cin >> controle;


		switch(controle)
		{
		case 1:
			//string nome;
			//string habilidade;
			//string tipo;
			//

			cout << "informe um nome:" << endl;
			cin >> novoPokemon.nome;


			cout << "informe uma habilidade:" << endl;
			cin >> novoPokemon.habilidade;

			cout << "informe o tipo:" << endl;
			cin >> novoPokemon.tipo;

			cout << "informe o id" << endl;
			cin >> novoPokemon.id;


			root = insert(root, novoPokemon);


			break;
		case 2:
			int id;
			cout << "informe o id do pokemon a ser removido" << endl;
			cin >> id;

			remove(root, id);

			break;
		case 3:
			int indice;
			cout << "informe o id do pokemon a ser pesquisado" << endl;
			cin >> indice;
			
			search(root,indice);

			break;
		case 4:
			show_ordered(root);
			break;
		default:
			return 0;
			break;
		}



	}


	return 0;
}
