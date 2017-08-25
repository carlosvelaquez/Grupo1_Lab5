#include "Matriz.h"
#include <iostream>
#include <vector>

using namespace std;

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
					   matrices.insert(nuevaMatriz());
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
	Matriz m;
	return m;
}
void imprimirMatriz(Matriz*){}
Matriz* seleccionarMatriz(vector<Matriz>*){
	return new Matriz();
}
Matriz* seleccionarResultado(vector<Matriz>*){
	return new Matriz();
}
void realizarOperacion(vector<Matriz>*, vector<Matriz>*){}

