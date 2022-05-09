#include <iostream>
#include <fstream>
#include <string>

using namespace std;

ifstream entrada;




void matrizAdj(int vertice){
	
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
	
	matrizInc = new int*[L];
	
	for(int i = 0 ; i < L ; i++){
		matrizInc[i] = new int[C];
	}
	
	for( int i = 0; i < L ; i++){
		for(int j = 0 ; j < C ; j++){
			matrizInc[i][j] = 0;
			
		}
	}
	
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
	vertice = stoi(text.substr(0, text.find(",")));
	entrada.close();
	return vertice;
	
}

int getAresta(){
	entrada.open("entrada.txt");
	string text;
	int arestas;
	entrada.seekg(0);
	getline(entrada,text);
	arestas = stoi(text.substr( text.find(",") + 1, text.size()));
	entrada.close();
	return arestas;
	
}

 int main(){
 	
 	int vertice = getVertice();
 	int arestas = getAresta();
 	
	cout << vertice << endl;
	cout << arestas <<endl;

	/* cout << "Matriz de Adjacencia" << endl;
 	matrizAdj(vertice);
 	
	cout << endl;
	cout << endl;
 	
	cout << "Matriz de Incidencia" << endl;
 	matrizInc(vertice, arestas);
	*/	
	


 	
 	
 	
 	return 0;
 }