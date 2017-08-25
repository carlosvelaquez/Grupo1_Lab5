#include "Matriz.h"
#include <iostream>
#include <vector>

using namespace std;

int menu();
Matriz nuevaMatriz();
void imprimirMatriz(Matriz*);
Matriz* seleccionarMatriz(vector<Matriz>*);
Matriz* seleccionarResultado(vector<Matriz>*);
void realizarOperacion(vector<Matriz>*, vector<Matriz>*);

int main(){
	vector<Matriz> matrices;
	vector<Matriz> resultados;
	bool salir = false;

	while(!salir){
		int opcion = menu();

		switch(opcion){
			case 1:{
					   matrices.push_back(nuevaMatriz());
					   cout << "Matríz agregada exitosamente." << endl;
				   }break;
			case 2:{
					   imprimirMatriz(seleccionarMatriz(&matrices));
				   }break;
			case 3:{
					   imprimirMatriz(seleccionarResultado(&resultados));
				   }break;
			case 4:{
					   realizarOperacion(&matrices, &resultados);
				   }break;
			case 5:{
					   salir = true;
				   }break;
			default:{
						cout << "[ERROR] Numero de opción inválido, por favor intente de nuevo." << endl;
					}break;
		}

	}

	return 0;;
}

int menu(){
	int opcion;

	cout << "-----------------------------------" << endl
		<< "Calculadora Matricial v0.01" << endl << endl
		<< "1. Añadir Matríz a Vector" << endl
		<< "2. Imprimir Matriz" << endl
		<< "3. Imprimir un Resultado" << endl
		<< "4. Realizar una Operación" << endl
		<< "5. Salir del Programa" << endl << endl
		<< "Ingrese el número de la opción que desea - ";

	cin >> opcion;
	cout << "-----------------------------------" << endl;

	return opcion;
}

Matriz nuevaMatriz(){
	int filas = 0;
	int columnas = 0;
	bool continuar = false;
	Matriz* nuevaMatriz;

	do{
		cout << "Ingrese el número de filas: ";
		cin >> filas;
		cout << "Ingrese el número de columnas: ";
		cin >> columnas;
		cout << endl;

		if(filas < 1 || columnas < 1){
			cout << "[ERROR] Las dimensiones no pueden ser menores a 1." << endl;
		}else{
			nuevaMatriz = new Matriz(filas, columnas);
			int** valores;

			valores = new int*[filas];
			for(int i = 0; i < filas; i++){
				valores[i] = new int[columnas];
			}

			cout << "Ingrese los valores para cada posición" << endl;

			for(int i = 0; i < filas; i++){
				for(int j = 0; j < columnas; j++){
					int valor;
					cout << "[" << i << "," << j << "]: ";
					cin >> valor;
					valores[i][j] = valor;
				}
			}

			nuevaMatriz->setMatriz(valores);
			continuar = true;
		}

		cout << endl;
	}while(!continuar);

	return (*nuevaMatriz);
}

void imprimirMatriz(Matriz* matriz){
	for(int i = 0; i < matriz->getSizeFila; i++){
		for(int j = 0; j < matriz->getSizeColumna; j++){
			cout << " | " << matriz->getValor(i,j) << endl;
		}
		cout << " |" << endl;
	}
}

Matriz* seleccionarMatriz(vector<Matriz>*){
	return new Matriz();
}

Matriz* seleccionarResultado(vector<Matriz>*){
	return new Matriz();
}

void realizarOperacion(vector<Matriz>*, vector<Matriz>*){}

