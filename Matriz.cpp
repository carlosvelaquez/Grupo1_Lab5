#include "Matriz.h"
#include <iostream>
using namespace std;

Matriz::Matriz(){

}

Matriz::Matriz(int pFila, int pColumna){
	sizeColumna=pColumna;
	sizeFila=pFila;
	matriz=new int*[sizeFila];
	for(int i=0;i<sizeFila;i++){
		matriz[sizeFila]=new int[sizeColumna];
	}
}

int** Matriz::getMatriz(){
	return matriz;
}

int Matriz::getSizeColumna(){
	return sizeColumna;
}

int Matriz::getSizeFila(){
	return sizeFila;
}

void Matriz::setMatriz(int** pMatriz){
	matriz=pMatriz;
}

void Matriz::setSizeColumna(int pColumna){
	sizeColumna=pColumna;
}

void Matriz::setSizeFila(int pFila){
	sizeFila=pFila;
}

int Matriz::getValor(int fila, int columna){
	return matriz[fila][columna];
}

