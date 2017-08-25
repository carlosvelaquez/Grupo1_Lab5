#ifndef MATRIZ_H
#define MATRIZ_H

class Matriz{
	private:
		int** matriz;
		int sizeColumna;
		int sizeFila;
	public:
		Matriz();
		Matriz(int, int);
		int** getMatriz();
		int getSizeColumna();
		int getSizeFila();
		int getValor(int, int);
		void setMatriz(int**);
		void setSizeColumna(int);
		void setSizeFila(int);

		Matriz operator+(Matriz& value){
			Matriz matrizRetorno(this->getSizeFila(), this->getSizeColumna());
			
			//Dos matrices que se suman y matriz retorno
			int** matrizr=matrizRetorno.getMatriz();
			int** matriz1=this->getMatriz();
			int** matriz2=value.getMatriz();

			for(int i=0;i<this->getSizeFila();i++){
				for(int j=0;j<this->getSizeColumna();j++){
					matrizr[i][j]=matriz1[i][j]+matriz2[i][j];
				}
			}
			matrizRetorno.setMatriz(matrizr);			
			return matrizRetorno;
		}

		Matriz operator-(Matriz& value){
			Matriz matrizRetorno(this->getSizeFila(), value->getSizeColumna());
			
			//Dos matrices que se restan y matriz retorno
			int** matrizr=matrizRetorno.getMatriz();
			int** matriz1=this->getMatriz();
			int** matriz2=value.getMatriz();

			for(int i=0;i<this->getSizeFila();i++){
				for(int j=0;j<this->getSizeColumna();j++){
					matrizr[i][j]=matriz1[i][j]-matriz2[i][j];
				}
			}
			matrizRetorno.setMatriz(matrizr);			
			return matrizRetorno;
		}

		Matriz operator()(){
			Matriz matrizRetorno(this->getSizeColumna, this->getSizeFila);
			int** matrizr=matrizRetorno.getMatriz();
			int** matriz1=this->getmatriz();

			for(int i=0;i<this->getSizeColumna();i++){
				for(int j=0;j<this->getSizeFila();j++){
					matrizr[i][j]=matriz1[j][i];
				}
			}
			matrizRetorno.setMatriz(matrizr);
			return matrizRetorno;
		}


		
		/*Matriz operator*(Matriz& value){
			Matriz matrizRetorno(this->getSizeFila(), this.getSizeColumna());
			
			//Dos matrices que se suman y matriz retorno
			int** matrizr=matrizRetorno.getMatriz();
			int** matriz1=this->getMatriz();
			int** matriz2=value.getMatriz();

			for(int r=0;r<this->getSizeFila();r++){
				for(int k=0;k<value.getSizeColumna();k++){
					

					for(int i=0;i<10;i++){
						for(int j=0;j<10;j++){

						}
					}
				}
			}
			matrizRetorno.setMatriz(matrizr);			
			return matrizRetorno;
		}*/
		
};
#endif
