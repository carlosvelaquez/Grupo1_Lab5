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
			Matriz matrizRetorno(this->getSizeFila(), this->getSizeColumna());
			
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
			Matriz matrizRetorno(this->getSizeColumna(), this->getSizeFila());
			int** matrizr=matrizRetorno.getMatriz();
			int** matriz1=this->getMatriz();

			for(int i=0;i<this->getSizeColumna();i++){
				for(int j=0;j<this->getSizeFila();j++){
					matrizr[i][j]=matriz1[j][i];
				}
			}
			matrizRetorno.setMatriz(matrizr);
			return matrizRetorno;
		}
		
		Matriz operator-(){
			Matriz matrizRetorno(this->getSizeFila(), this->getSizeColumna());
			int** matrizr=matrizRetorno.getMatriz();
			int** matriz1=this->getMatriz();

			for(int i=0;i<this->getSizeFila();i++){
				for(int j=0;j<this->getSizeColumna();j++){
					matrizr[i][j]=(matriz1[j][i])*(-1);
				}
			}
			matrizRetorno.setMatriz(matrizr);
			return matrizRetorno;
		}

		bool operator==(Matriz& value){
			bool comparar=true;
			int** matriz1=this->getMatriz();
			int** matriz2=value.getMatriz();

			for(int i=0;i<this->getSizeFila();i++){
				for(int j=0;j<this->getSizeColumna();j++){
					if(matriz1[i][j] != matriz2[i][j]){
						comparar=false;
					}
				}
			}			
			return comparar;
		}
	
		Matriz operator*(Matriz& value){
			Matriz matrizRetorno(this->getSizeFila(), this.getSizeColumna());
			
			int** matrizr=matrizRetorno.getMatriz();
			int** matriz1=this->getMatriz();
			int** matriz2=value.getMatriz();
			int valor1=0, valor2=0, algo=0;
			
			for(int i=0;i<this->getSizeFila();i++){
				for(int j=0;j<value.getSizeColumna;j++){
					matrizr[i][j]=matriz1[i][j]*matriz2[j][i];
				}
			}


			for(int r=0;r<this->getSizeFila();r++){
				for(int k=0;k<value.getSizeColumna();k++){
					algo=r;
					if((r+1)>=value.getsizeColumna){
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

			for(int r=0;r<this->getSizeFila();r++){
				for(int k=0;k<value.getSizeColumna();k++){
					algo=r;
					if((r+2)>=value.getsizeColumna){
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
		
		Matriz operator--(){
			Matriz matrizRetorno(this->getSizeFila(), this->getSizeColumna());
			int** matrizr=matrizRetorno.getMatriz();
			int** matriz1=this->getMatriz();

			if(this->getSizeFila()==2 && this->getSizeColumna()==2){
				matrizr[0][0]=matriz1[1][1];
				matrizr[1][1]=matriz1[0][0];
				matrizr[0][1]=(matriz1[0][1])*(-1);
				matrizr[1][0]=(matriz1[1][0])*(-1);
			}else if(this->getSizeFila()==3 && this->getSizeColumna()==3){
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
