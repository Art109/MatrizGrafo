#include <iostream>
#include <fstream>
#include <string>
#include <typeinfo>

using namespace std;

ifstream entrada;
ifstream entrada2;


void matrizPeso(){

	//Inicialização de Matrizes
	int ** matrizPeso;
	int ** matrizMaxMin;

	//Inicializando e pegando a quantidade dos vertices

	entrada2.open("entrada2.txt");
	string text;
	int V;
	entrada2.seekg(0);
	getline(entrada2,text);
	V = stoi(text);
	entrada2.close();

	//Inicialização e Preenchimento das matrizes com 0
	matrizPeso = new int*[V];
	matrizMaxMin = new int*[V];
 	
 	
 	for(int i = 0 ; i < V ; i++ ){
 		matrizPeso[i] = new int[V];
	}
	
	for(int i = 0 ; i < V ; i++){
		for(int j = 0 ; j < V ; j++){
			matrizPeso[i][j] = 0;					
		}
	}

	for(int i = 0 ; i < V ; i++ ){
 		matrizMaxMin[i] = new int[3];
	}
	
	for(int i = 0 ; i < V ; i++){
		for(int j = 0 ; j < 3 ; j++){
			matrizMaxMin[i][j] = 0;					
		}
	}
	//Preenchimento das Matrizes
	entrada2.open("entrada2.txt");
	for(int i = 0 ; i < V ; i++){
		for(int j = 0 ; getline(entrada2,text); j++){
			if(j > 0){
				cout << j << endl;
				

				if(j > V){
					matrizMaxMin[i][j - V - 1 ] = stoi(text);
					cout<< "oi" << endl;
				}
				else{
					matrizPeso[i][j-1] = stoi(text);
				}

				if(j == (V + 3)){
					break;
				}
			
			}					
		}
	}
	entrada2.close();


	//Print Matrizes
	for( int i = 0; i < V ; i++){
		for(int j = 0 ; j < V ; j++){
			cout << matrizPeso[i][j] << " ";
		}
		cout << " " ;
		for(int j = 0 ; j < 3 ; j++){
			cout << matrizMaxMin[i][j] << " ";
		}
		cout << endl;
	}
		cout << endl;
}
	



void matrizAdj(int vertice){
	
	entrada.open("entrada.txt");
	string text;
	int liga1, liga2;
	
	int ** matrizAdjacencia;
 	int V = vertice;
 	
 	
 	matrizAdjacencia= new int*[V];
 	
 	
 	for(int i = 0 ; i < V ; i++ ){
 		matrizAdjacencia[i] = new int[V];
	}
	
	for(int i = 0 ; i < V ; i++){
		for(int j = 0 ; j < V ; j++){
			matrizAdjacencia[i][j] = 0;					
		}		
	}
	
	for(int i = 0 ; getline(entrada, text) ; i++ ){
		if(i > 1){
			liga1 = stoi(text.substr(0,text.find(";"))) - 1;
			liga2 = stoi(text.substr(text.find(";") + 1, text.size())) - 1;
			matrizAdjacencia[liga1][liga2] = 1;
			matrizAdjacencia[liga2][liga1] = 1;
		}
	} 
	
	entrada.close();
		
	for(int i = 0 ; i < V ; i++){
		for(int j = 0 ; j < V ; j++){
			cout  << matrizAdjacencia[i][j] << " ";		
		}
		cout << endl;
	}	
	
}

void matrizInc(int vertice, int arestas){
	
	int ** matrizInc;
	int C = vertice;
	int L = arestas;
	
	entrada.open("entrada.txt");
	matrizInc = new int*[L];
	
	for(int i = 0 ; i < L ; i++){
		matrizInc[i] = new int[C];
	}
	
	for( int i = 0; i < L ; i++){
		for(int j = 0 ; j < C ; j++){
			matrizInc[i][j] = 0;	
		}
	}
	
	
	entrada.close();
	for( int i = 0; i < L ; i++){
		for(int j = 0 ; j < C ; j++){
			cout << matrizInc[i][j] << " ";
		}
		cout << endl;
	}
}
	
int getVertice(){
	entrada.open("entrada.txt");
	string text;
	int vertice;
	entrada.seekg(0);
	getline(entrada,text);
	vertice = stoi(text);
	entrada.close();
	return vertice;
	
}

int getAresta(){
	entrada.open("entrada.txt");
	string text;
	int arestas;
	getline(entrada,text);
	arestas = stoi(text);
	entrada.close();
	return arestas;
	
}

 int main(){
 	
 	
 	int vertice = getVertice();
 	int arestas = getAresta();
 	

	//cout << "Matriz de Adjacencia" << endl;
 	//matrizAdj(vertice);
 	
	cout << endl;
	cout << endl;
 	
	//cout << "Matriz de Incidencia" << endl;
 	//matrizInc(vertice, arestas);
	
	matrizPeso();
	


 	
 	
 	
 	return 0;
 }