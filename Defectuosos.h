#include <iostream>
#include <fstream>
using namespace std;

class Defectuosos : public Recibidos{
	private:
		int *pD;
		int N, suma;
		float prom;
	public:
		Defectuosos(int=0);
		Defectuosos(const Defectuosos&);
		float promedio();
		void reporte();
		void llena();
		void muestra();
		void busqueda(int =0);
		void grabar();
		
};


float Defectuosos::promedio(){
	for(int i=0; i<N; i++)
		suma+=pD[i];
		
	return(suma/N);
	
}

Defectuosos::Defectuosos(int N){
	this->N=N;
	suma=0;
	prom=0;
	pD=new int[N];
	for(int i=0; i<N; i++)
		pD[i]=0;
}
Defectuosos::Defectuosos(const Defectuosos &obj){
	this->N=obj.N;
	prom=obj.prom;
	suma=obj.suma;
	pD=new int[N];
	for(int i=0; i<N; i++)
		pD[i]=obj.pD[i];
}

void Defectuosos::muestra(){
	cout.width(35);
	cout << endl << "ARTICULOS DEFECTUOSOS" << endl << endl ;
	cout << "\t\t\t Cantidad " << endl;
	for(int i=0; i<N; i++)
		cout << "\tDia " << i+1 <<  "\t\t   " << pD[i] << endl;
	cout << endl << "\tTotal \t\t  " << suma << endl;
}

void Defectuosos::llena(){
	for(int i=0; i<N; i++){
		pD[i]=rand()%(35 - 1+1)+1;
		suma+=pD[i];
	}
}

void Defectuosos::busqueda(int x){
	bool band=false;
    for (int i=0; i<N; i++){
        if (pD[i] == x){
            band=true;
        }
    }
    if(band)
        cout << endl << "Cantidad de producto encontrado!" << endl << endl;
	else
        cout << endl << "Cantidad de producto no encontrad!" << endl << endl;
	/*int i=1;
	while(i<=N && pD[i])
		i++;
	if(i>N || x<pD[i])
		cout << "La Cantidad no forma parte de la lista" << endl;
	else
		cout << "La Cantidad pertence al Dia " << i << endl;*/
}


