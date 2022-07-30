#include <iostream>
#include <fstream>
#include <string>
#include <typeinfo>

using namespace std;

ifstream entrada;


int encontraRaio( int  matriz[9][9]){

	//Inicializando o retorno
	int raio = 0;
	
	//Lê a matriz e pega o primeiro valor diferente de zero atribuindo ao raio
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (matriz[i][j] == 0)
				continue;
			else {
				raio = matriz[i][j];
				break;
			}
		}
		break;
	}
	
	// Lê e procura o menor numero(raio) da matriz alterando o valor do raio toda vez que encontra um numero menor que ele
	for(int i = 0 ; i < 9; i++){
		for ( int j = 0; j < 9 ; j++){
			if(matriz[i][j] == 0)
				continue;
			if(matriz[i][j] < raio){
				raio = matriz[i][j];
			}	
		}
		
	}

	return raio ; 

}

int * encontraCentro( int matriz[9][9],int raio) {

	//Inicializando o vetor do centro e o seu indice 
	int *centro;
	centro = new int[9];
	int index = 0;

	//limpando lixo de memoria
	for (int i = 0; i < 9; i++) {
		centro[i] = 0;
	}

	//Lê a matriz e ao encontrar um valor igual a raio adciona ao vetor em seu indice 
	for(int i = 0 ; i < 9; i++){
		for ( int j = 0; j < 9 ; j++){
			if(matriz[i][j] == raio){
				centro[index] = i + 1; 
				index++;
			}
		}
		
	}

	return centro ; 

}

int encontraDiametro(int  matriz[9][9]) {

	//Inicializando o retorno
	int diametro = 0;

	//Lê a matriz e pega o primeiro valor diferente de zero atribuindo ao raio
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (matriz[i][j] == 0)
				continue;
			else {
				diametro = matriz[i][j];
				break;
			}
		}
		break;
	}

	// Lê e procura o maior numero(diametro) da matriz alterando o valor do raio toda vez que encontra um numero menor que ele
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (matriz[i][j] == 0)
				continue;
			if (matriz[i][j] > diametro) {
				diametro = matriz[i][j];
			}
		}

	}

	return diametro;

}

int* encontraAnticentro(int matriz[9][9], int diametro) {

	//Inicializando o vetor do centro e o seu indice 
	int* anticentro;
	anticentro = new int[9];
	int index = 0;

	//limpando lixo de memoria
	for (int i = 0; i < 9; i++) {
		anticentro[i] = 0;
	}


	//Lê a matriz e ao encontrar um valor igual a raio adciona ao vetor em seu indice 
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (matriz[i][j] == diametro) {
				anticentro[index] = i + 1;
				index++;
			}
		}

	}

	return anticentro;

}

int encotrarMediana(int matriz[9][9]) {
	//Inicializando as variaveis
	int soma = 0, aux = 0,mediana;

	//Lendo toda a matriz
	for (int i = 0; i < 9; i++) {
		// soma é resetada toda linha para assim fazer o somatorio das colunas de cada linha
		soma = 0;
		for (int j = 0;j < 9; j++) {		
			soma += matriz[i][j];
			if (soma > aux) {
				aux = soma;
				mediana = i + 1;
			}
		}
	}

	return mediana;
}

void matrizPeso(){

	
	//Inicialização de Matrizes ePreenchendo matriz
	int  matrizPeso[9][9] = {
		{0, 12, 20, 15, 28, 37, 25, 38, 46},
		{12, 0, 8, 27, 16, 25, 37, 32, 43},
		{20, 8, 0, 35, 24, 17, 45, 40, 35},
		{15, 27, 35, 0, 15, 25, 14, 17, 35},
		{28, 16, 24, 15, 0, 10, 29, 16, 27},
		{37, 25, 17, 25, 10, 0, 39, 26, 18},
		{25, 37, 45, 14, 29, 39, 0, 13, 21},
		{38, 32, 40, 27, 16, 26, 13, 0, 11},
		{46, 43, 35, 35, 27, 18, 21, 11, 0}
	};

	
	

	//Print Matriz
	for( int i = 0; i < 9 ; i++){
		for(int j = 0 ; j < 9 ; j++){
			cout << matrizPeso[i][j] << " ";
		}
		cout << endl;
	}

	//Armazenando o Valor do raio e printando o mesmo
	int raio = encontraRaio(matrizPeso);
	cout << "O raio e': " << raio << endl;

	//Armazenando o cojunto de vertices e printando o mesmo
	int * centro = encontraCentro(matrizPeso,raio);
	cout << "Os vertices centro sao: ";
	for (int i = 0; ; i++) {
		if (centro[i] != 0) {
			cout << centro[i] << ", ";
			continue;
		}
		break;
	}
	cout << endl;
	//Armazenando o Valor do raio e printando o mesmo
	int diametro = encontraDiametro(matrizPeso);
	cout << "O diametro e': " << diametro << endl;
	cout << endl;
	//Armazenando o cojunto de vertices e printando o mesmo
	int* anticentro = encontraAnticentro(matrizPeso, diametro);
	cout << "Os vertices anticentro sao: ";
	for (int i = 0; ; i++) {
		if (anticentro[i] != 0) {
			cout << anticentro[i] << ", ";
			continue;
		}
		break;
	}


		
}

	


bool isCompleto(int matriz[][], int v) {

	for (int i = 0; i < v; i++) {
		for (int j = 0; j < v; j++) {
			if (i != j && matriz[i][j] != 1)
				return false;
		}
	}
	return true;
}

bool isConexo(int matriz[][], int v) {
	//Lê toda a matriz
	for (int i = 0; i < v; i++) {
		for (int j = 0; j < v; j++) {
			//Caso ele encontre 1 vai para o proximo vertice , caso não encontre nenhum 1 retorna false indicando que o grafo não é conexo
			if (matriz[i][j] = 1)
				break;
			else if (matriz[i][v - 1] == 0)
				return false
		}
	}
	return true;
}

bool isRegular(int matriz[][], int v, int a) {
	
	int soma = 0, aux = 0;
	//Lê toda a matriz
	for (int i = 0; i < v; i++) {
		soma = 0;
		for (int j = 0; j < a; j++) {
			//Atribui o grau do primeiro vertice a variavel auxiliar e a compara com o grau dos outro vertices caso algum deles seja diferente ele retorna false caso sejam todos igual retorna true 
			soma += matriz[i][j]
			if (aux == 0)
				aux = soma;
			else if (soma != aux)
				return false;
		}
	}
	return true;
}

bool isMultigrafo(int matriz[][], int v, int a) {


	//Lê toda a matriz de incidencia e caso encontre algum vertice que possui mais de uma ligação ligando em um mesmo vertice retorna true caso não continua a procurar até não achar e retorna true
	for (int i = 0; i < v; i++) {
		for (int j = 0; j < a; j++) {
			//Atribui o grau do primeiro vertice a variavel auxiliar e a compara com o grau dos outro vertices caso algum deles seja diferente ele retorna false caso sejam todos igual retorna true 
			if (matriz[i][j] > 1) {
				return true;
			}
		}
	}
	return false;
}

bool isPseudografo(int matriz[][], int v) {


	//Lê apenas a diagonal principal da matriz de adjacencia e caso exista um 1 retorna false caso não true
	for (int i = 0; i < v; i++) { 
		if (matriz[i][i] == 1) {
			return false;
		}

	}
	return true;
}

bool isSimples(int matriz[][], int v,int a) {


	if (!isPseudografo(matriz, v) && !isMultigrafo(matriz, v, a))
		return true;
	else
		return false;
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

	if (isCompleto(matrizAdj,V))
		cout << "O grafo e' Completo"<< endl;
	
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
	
	//matrizPeso();
	


 	
 	
 	
 	return 0;
 }