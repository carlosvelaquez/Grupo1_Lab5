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
			Matriz matrizRetorno(this->sizeFila, this->sizeColumna);
			
			//Dos matrices que se suman y matriz retorno
			int** matrizr=matrizRetorno.getMatriz();
			int** matriz1=this->matriz;
			int** matriz2=value.getMatriz();

			for(int i=0;i<this->sizeFila;i++){
				for(int j=0;j<this->sizeColumna;j++){
					matrizr[i][j]=matriz1[i][j]+matriz2[i][j];
				}
			}
			matrizRetorno.setMatriz(matrizr);			
			return matrizRetorno;
		}


		Matriz operator-(Matriz& value){
			Matriz matrizRetorno(this->sizeFila, this->sizeColumna);
			
			//Dos matrices que se restan y matriz retorno
			int** matrizr=matrizRetorno.getMatriz();
			int** matriz1=this->matriz;
			int** matriz2=value.getMatriz();

			for(int i=0;i<this->sizeFila;i++){
				for(int j=0;j<this->sizeColumna;j++){
					matrizr[i][j]=matriz1[i][j]-matriz2[i][j];
				}
			}
			matrizRetorno.setMatriz(matrizr);			
			return matrizRetorno;
		}

		Matriz operator()(){
			Matriz matrizRetorno(this->sizeColumna, this->sizeFila);
			int** matrizr=matrizRetorno.getMatriz();
			int** matriz1=this->matriz;

			for(int i=0;i<this->getSizeColumna();i++){
				for(int j=0;j<this->getSizeFila();j++){
					matrizr[i][j]=matriz1[j][i];
				}
			}
			matrizRetorno.setMatriz(matrizr);
			return matrizRetorno;
		}
		
		Matriz operator-(){
			Matriz matrizRetorno(this->sizeFila, this->sizeColumna);
			int** matrizr=matrizRetorno.getMatriz();
			int** matriz1=this->matriz;

			for(int i=0;i<this->sizeFila;i++){
				for(int j=0;j<this->sizeColumna;j++){
					matrizr[i][j]=(matriz1[i][j])*(-1);
				}
			}
			matrizRetorno.setMatriz(matrizr);
			return matrizRetorno;
		}

		bool operator==(Matriz& value){
			bool comparar=true;
			int** matriz1=this->matriz;
			int** matriz2=value.getMatriz();

			for(int i=0;i<this->sizeFila;i++){
				for(int j=0;j<this->sizeColumna;j++){
					if(matriz1[i][j] != matriz2[i][j]){
						comparar=false;
					}
				}
			}			
			return comparar;
		}
	
		Matriz operator*(Matriz& value){
			Matriz matrizRetorno(this->sizeFila, this->sizeColumna);
			
			int** matrizr=matrizRetorno.getMatriz();
			int** matriz1=this->matriz;
			int** matriz2=value.getMatriz();
			int valor1=0, valor2=0, algo=0;
			
			for(int i=0;i<this->sizeFila;i++){
				for(int j=0;j<value.getSizeColumna();j++){
					matrizr[i][j]=matriz1[i][j]*matriz2[j][i];
				}
			}


			for(int r=0;r<this->sizeFila;r++){
				for(int k=0;k<value.getSizeColumna();k++){
					algo=r;
					if((r+1)>=value.getSizeColumna()){
						algo=-1;
					}

					valor1+=matriz1[r][k]*matriz2[k][algo+1];
				}
				matrizr[r][valor2]=valor1;
				valor1=0;
				if(valor2+1>=value.getSizeColumna()){
					valor2=0;
				}else{
					valor2++;
				}
			}

			for(int r=0;r<this->sizeFila;r++){
				for(int k=0;k<value.getSizeColumna();k++){
					algo=r;
					if((r+2)>=value.getSizeColumna()){
						algo=-2;
					}

					valor1+=matriz1[r][k]*matriz2[k][algo+2];
				}
				matrizr[r][valor2]=valor1;
				valor1=0;
				if(valor2+2>=value.getSizeColumna()){
					valor2=0;
				}else{
					valor2++;
				}
			}

			matrizRetorno.setMatriz(matrizr);			
			return matrizRetorno;
		}
		
		Matriz operator--(int o){
			Matriz matrizRetorno(this->sizeFila, this->sizeColumna);
			int** matrizr=matrizRetorno.getMatriz();
			int** matriz1=this->matriz;

			if(this->sizeFila==2 && this->sizeColumna==2){
				matrizr[0][0]=matriz1[1][1];
				matrizr[1][1]=matriz1[0][0];
				matrizr[0][1]=(matriz1[0][1])*(-1);
				matrizr[1][0]=(matriz1[1][0])*(-1);
			}else if(this->sizeFila==3 && this->sizeColumna==3){
				matrizr[0][0]=(matriz[1][1]*matriz[2][2])-(matriz[2][1]*matriz[1][2]);
				matrizr[1][0]=((matriz[1][0]*matriz[2][2])-(matriz[2][0]*matriz[1][2]))*(-1);
				matrizr[2][0]=(matriz[1][0]*matriz[2][1])-(matriz[2][0]*matriz[1][1]);

				matrizr[0][1]=((matriz[0][1]*matriz[2][2])-(matriz[2][1]*matriz[0][2]))*(-1);
				matrizr[1][1]=(matriz[0][0]*matriz[2][2])-(matriz[2][0]*matriz[0][2]);
				matrizr[2][1]=((matriz[0][0]*matriz[2][1])-(matriz[2][0]*matriz[0][1]))*(-1);

				matrizr[0][2]=(matriz[0][1]*matriz[1][2])-(matriz[1][1]*matriz[0][2]);
				matrizr[1][2]=((matriz[0][0]*matriz[1][2])-(matriz[1][0]*matriz[0][2]))*(-1);
				matrizr[2][2]=(matriz[0][0]*matriz[1][1])-(matriz[1][0]*matriz[0][1]);
			}
			matrizRetorno.setMatriz(matrizr);
			return matrizRetorno;
		}


		
};
#endif
