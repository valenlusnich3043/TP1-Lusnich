#include<iostream>
#include<fstream>

using namespace std;


	void cargarVec(int dimNombre, int dimTipoProdu, string vecNombre[], string vecTipoProd[], ifstream& archivoNombres){
		
		for(int i = 0; i < dimNombre && archivoNombres >> vecNombre[i]; i++);
			
		for(int i = 0; i < dimTipoProdu && archivoNombres >> vecTipoProd[i]; i++);
	}
	
	void mostrar(int dimNombre, int dimTipoProdu, string vecNombre[], string vecTipoProd[]){
	
		for(int i = 0; i < dimNombre; i++){
			cout << "Nombre: " << vecNombre[i] << endl;
		}	
		
		for(int i = 0; i < dimTipoProdu; i++){
			cout << "Tipo producto: " << vecTipoProd[i] << endl;
		}	
	}

		void ordenar(int dim, float vec[], int vec2[]){
			int imax;
			
			for(int pos = 0; pos < dim-1; pos++){
				imax = pos;
				for(int i = pos+1; i < dim; i++){
					if(vec[i] < vec[pos]){
						imax = i;
						
					swap(vec[pos], vec[imax]);
					swap(vec2[pos], vec2[imax]);

					}
				}
			}
		}

		void mostrardos(int dim, float vec[], int vec2[], string vecTipoProd[]){
		for(int i = 0; i < dim; i++){
			cout << vecTipoProd[vec2[i]] << ":" << vec[i] << endl;
		}
	}
	
	int maximo_pos(float vOrd[], int vOrd2[], int dim){
		
	float max = vOrd[0];
	int imax = 0;

	for (int i = 0; i < dim; i++)
		if (vOrd[i] > max) {
			max = vOrd[i];
			imax = vOrd2[i];
		}
	return imax;
}
	 
	
int main(){
	
	ifstream archivoNombres, archivoDatos;
	const int dimNombre = 8;
	const int dimTipoProdu = 5;
	float cliente13000[dimNombre][dimTipoProdu]{}; //matriz para calcular el >13000
	float clieDist[dimNombre][dimTipoProdu]{};// matriz para calcula la distacia de los >13000
	int prodMayCant[dimTipoProdu]; //cantidad de entregas por producto
	
	float vOrd[dimTipoProdu]{}; //vector para acomodar de forma ascendente(me guarda las distancias)
	int vOrd2[dimTipoProdu]{};	//vector para acomodar de forma ascendente(me guarda los indices)

	string vecNombre[dimNombre];
	string vecTipoProd[dimTipoProdu];

	archivoNombres.open("Nombres.txt");
	archivoDatos.open("Datos.txt");
	
	if(!archivoNombres){
		cout << "Hubo un error al abrir el archivo" << endl;
		return 1;
	}
	
	if(!archivoDatos){
		cout << "Hubo un error al abrir el archivo" << endl;
		return 1;
	}
	
	cout << "Datos:" << endl;
	cargarVec(dimNombre, dimTipoProdu, vecNombre, vecTipoProd, archivoNombres);
	mostrar(dimNombre, dimTipoProdu, vecNombre, vecTipoProd);
	
	int codCli, codProdu;
	float peso, dist;
	while(archivoDatos >> codCli >> codProdu >> peso >> dist){
		cliente13000[codCli][codProdu] += peso;
		clieDist[codCli][codProdu] += dist;
		prodMayCant[codProdu]++;
	}
		
		int cant{};
		int max{};
		int x;
		
		for(int i = 0; i < dimNombre; i++){
			cout << endl;
			cout << vecNombre[i] << ": ";
			cant = 0;
			for(int j = 0; j < dimTipoProdu; j++){
				if(cliente13000[i][j] > 13000){ 
					cout << vecTipoProd[j] << " ";
					cant++;
				}
			}
			
		if(i == 0 || cant > max){
			max = cant;
			x = i;}
		}	
		
			cout << endl;
			cout << endl;
			cout << "El cliente con mayor cantidad de productos es " << vecNombre[x] << endl;
			for(int j = 0; j < dimTipoProdu; j++){
				vOrd[j] = clieDist[x][j];
				vOrd2[j] = j;
			}
						
		ordenar(dimTipoProdu, vOrd, vOrd2);
		mostrardos(dimTipoProdu, vOrd, vOrd2, vecTipoProd);
		
		cout << endl;		
		
		int max2 = maximo_pos(vOrd, vOrd2, dimTipoProdu);
		cout << vecTipoProd[max2] << ": "<< prodMayCant[max2];

	archivoNombres.close();
	archivoDatos.close();

return 0;
}
