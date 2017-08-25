#include "Matriz.h"
#include <iostream>
#include <vector>
#include <ofstream>
#include <ctime>

using namespace std;

int menu();
Matriz nuevaMatriz();
void imprimirMatriz(Matriz*);
Matriz* seleccionarMatriz(vector<Matriz>*);
Matriz* seleccionarResultado(vector<Matriz>*);
void realizarOperacion(vector<Matriz>*, vector<Matriz>*);
void registrarOperacion(Matriz*, Matriz*, int, Matriz);
void registrarOperacion(int, Matriz*, Matriz);
int seleccionarOperacion(int);

int main(){
	cout << "Laboratorio 5 - Carlos Velásquez y Leonardo Borjas" << endl;
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
	for(int i = 0; i < matriz->getSizeFila(); i++){
		for(int j = 0; j < matriz->getSizeColumna(); j++){
			cout << " | " << matriz->getValor(i,j);
		}
		cout << " |" << endl;
	}
}

void imprimirMatriz(Matriz* matriz, ofstream* out){
	for(int i = 0; i < matriz->getSizeFila(); i++){
		for(int j = 0; j < matriz->getSizeColumna(); j++){
			(*out) << " | " << matriz->getValor(i,j);
		}
		(*out) << " |" << endl;
	}
}


Matriz* seleccionarMatriz(vector<Matriz>* matrices){
	cout << "Seleccionar Matríz" << endl << endl;
	int opcion = -69;
	bool continuar = false;

	do{
		for(int i = 0; i < matrices->size(); i++){
			cout << (i+1) << ". Matriz Size [" << (matrices->at(i)).getSizeFila() << "," << (matrices->at(i)).getSizeColumna() << "]" << endl;
		}

		cout << endl << "Ingrese el número de la matriz que desea imprimir - ";
		cin >> opcion;

		opcion --;
		cout << "-----------------------------------" << endl;

		if(opcion < 0 || opcion > (matrices->size() - 1)){
			cout << "[ERROR] El número ingresado no corresponde a ninguna matríz." << endl;
		}else{	
			cout << "Matríz Seleccionada" << endl << endl;
			return (&(matrices->at(opcion)));
			continuar = true;
		}
	}while(!continuar);

	return new Matriz();
}

Matriz* seleccionarResultado(vector<Matriz>*){
	return new Matriz();
}

void realizarOperacion(vector<Matriz>* matrices, vector<Matriz>* resultados){
	int opcion;
	bool continuar = false;

	do{
		cout << "Seleccione el tipo de Operación" << endl << endl
			<< "1. Unaria" << endl
			<< "2. Binaria" << endl << endl
			<< "Ingrese el número de la opción que desea - ";
		cin >> opcion;
		cout << "-----------------------------------" << endl;

		if(opcion < 1 || opcion > 2){
			cout << "" << endl;
			cout << "-----------------------------------" << endl;
		}else{
			switch(opcion){
				case 1:{
						   Matriz* m = seleccionarMatriz();
						   int operacion = seleccionarOperacion(1);

						   switch(operacion){
							   case 1:{
										  resultados.push_back(-(*m));
									  }
									  break;
							   case 3:{
										  resultados.push_back((*m)--);
									  }
									  break;
							   case 2:{
										  resultados.push_back((*m)());
									  }
									  break;

						   }

						   registrarOperacion(operacion, m, resultados->at(resultados->size()-1));

					   }
					   break;
				case 2:{
						   Matriz* mLeft = seleccionarMatriz();
						   Matriz* mRight = seleccionarMatriz();

						   int operacion = seleccionarOperacion(2);

						   switch(operacion){
							   case 1:{
										  resultados.push_back((*mLeft) + (*mRight));
									  }
									  break;
							   case 2:{
										  resultados.push_back((*mLeft) - (*mRight));
									  }
									  break;
							   case 3:{
										  resultados.push_back((*mLeft) * (*mRight));
									  }
									  break;
							   case 4:{
										  if((*mLeft) == (*mRight)){
											  registrarOperacion((*mLeft), (*mRight), ((*mLeft) == (*mRight)));
										  };
									  }
									  break;

						   }

						   if(operacion != 4){
							   registrarOperacion(mLeft, mRight, operacion, resultados->at(resultados->size()-1));
						   }

					   }
					   break;
			}

		}
	}while(!continuar);
}

int seleccionarOperacion(int tipo){
	bool continuar = false;
	int opc;

	do{
		cout << "-----------------------------------" << endl << "Seleccionar Operación" << endl << endl;

		int limite = 0;

		switch(tipo){
			case 1:
				cout << "1. Menos Unario -" << endl
					<< "2. Transpuesta ()" << endl
					<< "3. Inversa --" << endl << endl;
				limite = 3;
				break;
			case 2:
				cout << "1. Suma +" << endl
					<< "2. Resta -" << endl
					<< "3. Multiplicación *" << endl
					<< "4. Comparación ==" << endl << endl;
				limite = 4;
				break;
		}

		cout << "Ingrese el número de la opción que desea - ";
		cin >> opc;
		cout << endl;

		if(opc < 1 || opc > limite){
			cout << "[ERROR] Número de opción inválido" << endl << endl;
		}else{
			continuar =  true;
		}

	}while(!continuar);

	return opc;

}

void registrarOperacion(int operacion, Matriz* m, Matriz resultado){
	string opStr = " ";

	switch(operacion){
		case 1:
			opStr = "- (Unario)";
			break;
		case 2:
			opStr = "()";
			break;
		case 3:
			opStr = "--";
			break;
	}

	cout << "Resultado" << endl << endl;
	imprimirMatriz(resultado);

	char* dt = ctime(&now);
	string outString = dt;

	ofstream out;
	out.open(outString);
	out << "--------" << dt << "--------\n";
	imprimirMatriz(*m, &out);
	out << "\n\nOperación: " << opStr << "\n\n";
	imprimirMatriz(resultado, &out);
	out << "\n\n--------FIN--------";
	out.close();

}

void registrarOperacion(Matriz* mLeft, Matriz* mRight, int operacion, Matriz resultado){
	string opStr = " ";

	switch(operacion){
		case 1:
			opStr = "+";
			break;
		case 2:
			opStr = "-";
			break;
		case 3:
			opStr = "*";
			break;
		case 4:
			opStr = "==";
			break;
	}

	cout << "Resultado" << endl << endl;
	imprimirMatriz(resultado);

	char* dt = ctime(&now);
	string outString = dt;

	ofstream out;
	out.open(outString);
	out << "--------" << dt << "--------\n";
	imprimirMatriz(*mLeft, &out);
	out << "\n\nOperación: " << opStr << "\n\n";
	imprimirMatriz(*mRight, &out);
	out << "\n\n=\n\n";
	imprimirMatriz(resultado, &out);
	out << "\n\n--------FIN--------";
	out.close();

}


