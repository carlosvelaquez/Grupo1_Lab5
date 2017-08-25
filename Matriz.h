#ifndef MATRIZ_H
#ifndef MATRIZ_H

class Matriz{
	private:
		int** matriz;
		int sizeColumna;
		int sizeFila;
	public:
		matriz();
		matriz(int, int);
		int** getMatriz();
		int getSizeColumna();
		int getSizeFila();
		void setMatriz(int**);
		void setSizeColumna(int);
		void setSizeFila(int);

		
};
#endif
