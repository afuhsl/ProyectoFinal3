#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

class Vendidos{
	private:
		int *pV, *precio;
		int sum1, sum2, N;
	public:
		Vendidos(int=0);
		void orden();
		void busqueda(int=0);
		void mostrarV();
		void llenarV();
		void llenarP();
		void ordenV();
		~Vendidos();
		int mayor();
};


int Vendidos::mayor(){
	int pos=0, may=0;
	for(int i=0; i<N; i++){
		if(pV[i] > may){
			may=pV[i];
			pos=i;
		}
	}
	
	return pos+1;
}
void Vendidos::llenarP(){
	for(int i=0; i<N; i++){
		precio[i]=rand()%(2000-300+1)+1;
		sum2+=precio[i];
	}
}

void Vendidos::llenarV(){
	srand(time(0));
	for(int i=0; i<N; i++){
		pV[i]=rand()%(300 - 60+1)+1;
		sum1+=pV[i];
	}
}

void Vendidos::mostrarV(){
	cout.width(35);
	cout << endl << "ARTICULOS VENDIDOS" << endl << endl;
	cout << "\t\tGanacia" << "\t\t" << "Cantidad" << endl;
	for(int i=0; i<N; i++)
		cout << "\tDia " << i+1 <<  "\t  $" << precio[i] << "\t\t   " << pV[i] << endl;
	
	cout << endl << "\tTotal:\t  $" << sum2 << "\t\t   " << sum1 << endl ;
}

Vendidos::Vendidos(int N){
	this->N=N;
	sum1=sum2=0;
	pV=new int[N];
	for(int i=0; i<N; i++)
		pV[i]=0;
	precio=new int[N];
	for(int j=0; j<N; j++)
		precio[j]=0;	
}

void Vendidos:: ordenV(){
	int aux, k, i;
	for(i=1; i<N;i++){
		aux = pV[i];
		k = i-1;
		while((k >= 0) && (aux < pV[k]) ){
			pV[k+1]=pV[k];
			k--;
		}
		pV[k+1] = aux;
	}
}

void Vendidos::busqueda(int x){
	bool band=false;
    for (int i=0; i<N; i++){
        if (pV[i] == x){
            band=true;
        }
    }
    if(band)
        cout << endl << "Cantidad de producto encontrado!" << endl << endl;
	else
        cout << endl << "Cantidad de producto no encontrad!" << endl << endl;
}

Vendidos::~Vendidos(){
	delete []pV;
}
