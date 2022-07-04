#include <iostream>
#include <fstream>
#include <string>
#include <typeinfo>

using namespace std;

ifstream entrada;


int encontraRaio( int ** matriz, int tam){

	int ** matriz = matriz;
	int menor;
	
	menor = matriz[0][0];
	for(int i = 0 ; i < tam; i++){
		for ( int j = 0; j < tam ; j++){
			if(matriz[i][j] == 0)
				continue;
			if(matriz[i][j] < menor){
				menor = matriz[i][j];
			}	
		}
		
	}

	return menor ; 

}

int * encontraCentro( int ** matriz, int tam){

	int ** matriz = matriz;
	int raio;
	int * centro;

	centro = new int[tam];
	int index = 0;

	raio = encontraRaio(matriz,tam);
	for(int i = 0 ; i < tam; i++){
		for ( int j = 0; j < tam ; j++){
			if(matriz[i][j] == raio){
				centro[index] = i; 
				index++;
			}
		}
		
	}

	return centro ; 

}
void matrizPeso(){

	//Inicialização de Matrizes
	int ** matrizPeso;

	//Inicializando e pegando a quantidade dos vertices

	entrada.open("entrada2.txt");
	string text;
	int V;
	entrada.seekg(0);
	getline(entrada,text);
	V = stoi(text);
	entrada.close();

	//Inicialização e Preenchimento das matrizes com 0
	matrizPeso = new int*[V];
 	
 	
 	for(int i = 0 ; i < V ; i++ ){
 		matrizPeso[i] = new int[V];
	}
	
	for(int i = 0 ; i < V ; i++){
		for(int j = 0 ; j < V ; j++){
			matrizPeso[i][j] = 0;					
		}
	}

	
	//Preenchimento das Matrizes
	entrada.open("entrada2.txt");
	entrada.seekg(0);
	getline(entrada,text);
	for(int i = 0 ; i < V ; i++){
		for(int j = 0 ; j < V ; j++){
			getline(entrada,text);	
			matrizPeso[i][j] = stoi(text);			
		}
	}
	entrada.close();
	

	//Print Matrizes
	for( int i = 0; i < V ; i++){
		for(int j = 0 ; j < V ; j++){
			cout << matrizPeso[i][j] << " ";
		}
		cout << endl;
	}
		
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