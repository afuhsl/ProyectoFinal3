#include <iostream>

using namespace std;

class Recibidos{
	protected:
		int *pR;
		int N, sum;
	public:
		Recibidos(int=0);
		Recibidos(const Recibidos&);
		~Recibidos();
		void orden();
		void busqueda(int=0);
		void mostrar();
		void llenar();
		int mayor();
}; 

int Recibidos::mayor(){
	int men=0;
	for(int i=N; i>0; i--){
		if(pR[i] > men){
			men = pR[i];
		}
	}
	return men;
}

void Recibidos::llenar(){
	for(int i=0; i<N; i++){
		pR[i]=rand()%(300 - 60+1)+1;
		sum+=pR[i];
	}
}

Recibidos::Recibidos(int N){
	this->N=N;
	sum=0;
	pR=new int[N];
	for(int i=0; i<N; i++)
		pR[i]=0;
}

Recibidos::Recibidos(const Recibidos &obj){
	this->N=obj.N;
	sum=obj.sum;
	pR=new int[N];
	for(int i=0; i<N; i++)
		pR[i]=obj.pR[i];
}

Recibidos::~Recibidos(){
	delete []pR;
}

void Recibidos:: orden(){
	int aux, k, i;
	for(i=1; i<N;i++){
		aux = pR[i];
		k = i-1;
		while((k >= 0) && (aux < pR[k]) ){
			pR[k+1]=pR[k];
			k--;
		}
		pR[k+1] = aux;
	}
}

void Recibidos::mostrar(){
	cout.width(35);
	cout << endl << "ARTICULOS RECIBIDOS" << endl << endl;
	cout << "\t\t\t Cantidad " << endl;
	for(int i=0; i<N; i++)
		cout << "\tDia " << i+1 <<  "\t\t   " << pR[i] << endl;
	cout << endl << "\tTotal \t\t  " << sum << endl;
}

void Recibidos::busqueda(int x){
	bool band=false;
    for (int i=0; i<N; i++){
        if (pR[i] == x){
            band=true;
        }
    }
    if(band)
        cout << endl << "Cantidad de producto encontrado!" << endl << endl;
	else
        cout << endl << "Cantidad de producto no encontrad!" << endl << endl;
}
