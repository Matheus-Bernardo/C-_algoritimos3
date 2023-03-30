#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int buscaBinaria(vector<int> &v, int x){

    int ini,meio,fim;
    ini = 0;
    fim = v.size()-1;

    while(ini <= fim){
        meio = (ini+fim)/2;
        if(v[meio] == x)
            break;
        else if (v[meio]>x)
            fim = meio - 1;
        else
            ini = meio + 1;
    }

    if(v[meio] == x){
        int p = meio;
        while(p-1 >= 0 and v[p-1] == x)
            p--;
        return p;
    }
    return -1;
}


//algoritimo dos marmores

int main(){

    int marmore,consultas,x,t=1;
    
    //Entrada de dados 
    cout<< "Entre com o numero de marmores:"<<endl;
    cin>> marmore;
    cout<< "Entre com o numero de consultas a serem feitas:"<<endl;
    cin>> consultas;
    

    while( marmore+consultas > 0 ){

        cout << "caso n° " << t++ << ":" << endl;

        vector<int> v;
        while(marmore--){
			cin >> x;
            if( x)
            v.push_back(x);
        }

        sort(v.begin(), v.end());

        while(consultas--){
            cin >> x;
            int pos = buscaBinaria(v,x);

            if(pos >= 0)
                cout << x << " found at " << pos+1 << endl;
            else
                cout << x << " not found" << endl;
        }
    }

    return 0;
}

//questao 2 nao consegui