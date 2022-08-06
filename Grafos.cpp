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
		// soma é resetada toda linha para assim fazer o somatorio das colunas de cada lin
		soma = 0;
		for (int j = 0;j < 9; j++) {		
			soma += matriz[i][j];
			if (soma < aux) {
				aux = soma;
				mediana = i + 1;
			}
		}
	}

	return mediana;
}

void matrizPeso(){

	
	//Inicialização da Matrize Preenchida
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

	


bool isCompleto(int ** matriz, int v, int a) {
	//Verifica se o numero de arestas é igual ao valor equivalente para o grafo ser completo
	if (a == ((v - 1) * v) / 2) {
		//Verifica se existe um zero na matriz da adjacencia não coferindo a diagonal principal 
		for (int i = 0; i < v; i++) {
			for (int j = 0; j < v; j++) {
				if (i != j && matriz[i][j] == 0)
					return false;
			}
		}
		return true;
	}
	else
		return false;
}


bool isConexo(int ** matriz, int v,int a) {
	//Verifica se o numero de aresta é pelo menos igual a n - 1 ou seja o minimo de ligações para ser conexo
	bool ctrl = false;
	if (a >= v - 1) {
		//Lê toda a matriz
		for (int i = 0; i < v; i++) {
			for (int j = 0; j < v; j++) {
				//Caso ele encontre 1 vai para o proximo vertice , caso não encontre nenhum 1 retorna false indicando que o grafo não é conexo
				if (matriz[i][i] == 0 || matriz[i][j] == 1) {
					ctrl = true;
					break;
				}
				ctrl = false;
			}
			if (!ctrl)
				return false;
		}
		return true;
	}
}

bool isRegular(int ** matriz, int v) {
	
	int soma = 0, aux = 0;
	//Lê toda a matriz
	for (int i = 0; i < v; i++) {
		soma = 0;
		for (int j = 0; j < v; j++) {
			
			soma += matriz[i][j];
		}
		//Atribui o grau do primeiro vertice a variavel auxiliar e a compara com o grau dos outro vertices caso algum deles seja diferente ele retorna false caso sejam todos igual retorna true 
		if (aux == 0)
			aux = soma;
		else if (soma != aux)
			return false;
	}
	return true;
}


//auxiliar para a função do multigrafo
bool equals_vetor(int* vetor1, int* vetor2, int tamanho) {
	int i, cont = 1;
	for (i = 0; i < tamanho; i++) {
		if (vetor1[i] != vetor2[i]) {
			return false;
		}
	}

	return true;
}

bool isMultigrafo(int** matriz, int v, int a) {
	//Verifica se existe alguma aresta igual a outra caso sim o grafo é um multigrafo

	//Lê toda a matriz de incidencia e caso encontre alguma aresta igual a outra 
	int* vetor_teste = new int[a];

	for (int i = 0; i < a; i++) {
		vetor_teste = matriz[i];

		for (int j = i + 1; j < a; j++) {
			if (equals_vetor(vetor_teste, matriz[j], v)) {
				return true;
			}
		}
	}
	return false;
}


bool isPseudografo(int ** matriz, int v) {


	//Lê apenas a diagonal principal da matriz de adjacencia e caso exista um 1 retorna true caso não false
	for (int i = 0; i < v; i++) { 
		if (matriz[i][i] == 1) {
			return true;
		}

	}
	return false;
}
//Verifica o diagonal principal da matriz de adjacencia e caso todos os valores forem 1 ele será reflexivo
bool isReflexivo(int** matriz, int v) {
	if (v > 0) {
		for (int i = 0; i < v; i++) {
			if (matriz[i][i] != 1) {
				return false;
			}
		}
		return true;
	}
	return false;
}

bool isSimples(int ** matrizADJ,int** matrizINC, int v,int a) {


	if (!isPseudografo(matrizADJ, v) /* && !isMultigrafo(matrizINC, v, a)*/)
		return true;
	else
		return false;
}

bool isTrivial(int v, int a) {
	//Caso só exista um 1 vertice e 0 arestas ele será trivial
	if (v == 1 && a == 0) {
		return true;
	}
	else
		return false;

}

bool isNulo(int v,int a) {
	if (v == 0)
		return true;
	else
		return false;
}


int ** matrizAdj(int vertice){
	
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

	return matrizAdjacencia;
}



int ** matrizInc(int vertice, int arestas){
	
	int ** matrizIncidencia;
	int L = vertice;
	int C = arestas;
	string text;
	int liga1, liga2;
	 
	matrizIncidencia = new int*[L];
	for(int i = 0 ; i < L ; i++){
		matrizIncidencia[i] = new int[C];
	}

	for (int i = 0; i < L; i++) {
		for (int j = 0; j < C; j++) {
			matrizIncidencia[i][j] = 0;
		}
	}
	
	entrada.open("entrada.txt");
	for (int i = 0; getline(entrada, text); i++) {
		if (i > 1) {
			liga1 = stoi(text.substr(0, text.find(";"))) - 1;
			liga2 = stoi(text.substr(text.find(";") + 1, text.size())) - 1;
			matrizIncidencia[liga1][i - 2] += 1;
			matrizIncidencia[liga2][i - 2] += 1;
		}
	}
	entrada.close();

	for( int i = 0; i < L ; i++){
		for(int j = 0 ; j < C ; j++){
			cout << matrizIncidencia[i][j] << " ";
		}
		cout << endl;
	}

	return matrizIncidencia;
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
	for (int i = 0;getline(entrada, text);i++) {
		if (i == 1) {
			arestas = stoi(text);
			entrada.close();
			return arestas;
		}
	}
	
	
}

 int main(){
 	
 	
 	int vertice = getVertice();
 	int arestas = getAresta();
	cout << "Matriz de Adjacencia" << endl;
	int** matrizAdjacencia = matrizAdj(vertice);
	cout << endl;
	cout << endl;
	cout << "Matriz de Incidencia" << endl ;
	int** matrizIncidencia = matrizInc(vertice, arestas);

	//cout << isRegular(matrizAdjacencia, vertice, arestas) << endl;
	
	if (!isNulo(vertice, arestas)) {
		
		if (!isTrivial(vertice, arestas)) {
			
			if (isSimples(matrizAdjacencia, matrizIncidencia, vertice, arestas)) {
				
				cout << "O grafo e' simples" << endl;
				if (isCompleto(matrizAdjacencia, vertice, arestas))
					cout << "O grafo e' completo" << endl;
				if (isRegular(matrizAdjacencia, vertice))
					cout << "O grafo e' regular" << endl;
				if (isConexo(matrizAdjacencia, vertice, arestas))
					cout << "O grafo e' conexo" << endl;
			}
			else if (isPseudografo(matrizAdjacencia, vertice)) {
				cout << "o grafo e' um pseudografo" << endl;
				if (isReflexivo(matrizAdjacencia, vertice))
					cout << "O grafo e' reflexivo" << endl;
				if (isRegular(matrizAdjacencia, vertice))
					cout << "O grafo e' regular" << endl;
				if (isConexo(matrizAdjacencia, vertice, arestas))
					cout << "O grafo e' conexo" << endl;

			}
			else
				cout << "Nao possivel classificar o grafo" << endl;
		}
		else {
			cout << "O grafo e' trivial" << endl;
		}
	}
	else {
		cout << "O grafo e' nulo" << endl;
	}
	
	//matrizPeso();
	


 	
 	
 	
 	return 0;
 }