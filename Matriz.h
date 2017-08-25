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

		Matriz operator+(Matriz& value){
			Matriz matrizRetorno(this->getSizeFila(), this->getSizeColumna());
			
			//Dos matrices que se suman
			int** matriz1=this->getMatriz();
			int** matriz2=value.getMatriz();

			for(int i=0;i<this->getSizeFila();i++){
				for(int j=0;j<this->getSizeColumna();j++){
					matrizRetorno[i][j]=matriz1[i][j]+matriz2[i][j];
				}
			}
			return matrizRetorno;
		}

		
};
#endif
