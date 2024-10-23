#include <iostream>
#include <windows.h>
#include "Vendidos.h"
#include "Recibidos.h"
#include "Defectuosos.h"
#include "nodo.h"
#include "lista.h"
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <fstream>
#define N 7

using namespace std;


int busqueda();
int program();
void escribir();

int main(int argc, char** argv) {
	program(); //al iniciar el programa, se crea un archivo de texto con informacion del programa
	float prom;
	srand(time(0));
	Vendidos list1(N);
	Recibidos list2(N);
	Defectuosos list3(N);
	lista  *list4= new lista();
	int op, cant, bus, i, j, dat;
	string nom;
	
	do{
		system("cls");
		cout.width(25);
		cout <<  "M E N U " << endl << endl
			 << "\t 1 - Mostrar Listas" << endl
			 << "\t 2 - Ordenar Listas" << endl
			 << "\t 3 - Crear Lista" << endl
			 << "\t 4 - Buscar Cantidad" << endl
			 << "\t 5 - Dia de mayor venta" << endl
			 << "\t 6 - Mayor cantidad de articulos recibidos" << endl
			 << "\t 7 - Promedio de articulos defectuosos" << endl
			 << "\t 8 - Sobre el programa" << endl
			 << "\t 9 - Salir" << endl;
		cout << "\t Opcion ... "; cin >> op;
		switch(op){
			case 1:
				system("cls");
				cout << "  -----------------------------------------------------	" << endl;
				list1.llenarV();
				list1.llenarP();
				list1.mostrarV();
				cout << "  -----------------------------------------------------	" << endl;
				list2.llenar();
				list2.mostrar();
				cout << "  -----------------------------------------------------	" << endl;
				list3.llena();
				list3.muestra();
				system("pause");
			break;
			
			case 2:
				system("cls");
				cout << "-----------------------------------------------------" << endl;
				list1.ordenV();
				list1.mostrarV();
				cout << "-----------------------------------------------------" << endl;
				list2.orden();
				list2.mostrar();
				cout << "-----------------------------------------------------" << endl;
				list3.orden();
				list3.muestra();
				system("pause");
			break;
			
			case 3:
				system("cls");
				cout << "Nombre de la lista ";
				fflush(stdin);
				getline(cin, nom);
				for(i=0; i<N; i++){
					cout << "Cantidad Dia " << i+1 << ": "; cin >> dat;
					list4->agregar(dat);
				}
				cout << endl;
				cout.width(30);
				cout << nom << endl;
				list4->mostrar(); 
				cant = list4->suma();
				cout << endl <<"\tTotal\t" << cant << endl;
				system("pause");
			break;
			
			case 4:
				system("cls");
				bus = busqueda();
				cout << endl << endl << "Cantidad a Buscar  "; cin >> cant;
				if(bus==1){
					list1.mostrarV();
					list1.busqueda(cant);
				}else if(bus==2){
					list2.mostrar();
					list2.busqueda(cant);
				}else if(bus==3){
					list3.muestra();
					list3.busqueda(cant);
				}else if(bus==4){
					list4->mostrar();
					list4->buscar(cant);
				}
				system("pause");
			break;
			 
			case 5:
				system("cls");
				list1.mostrarV();
				cant=list1.mayor();
				fflush(stdin);
				cout << "El dia de mayor venta fue el Dia " << cant;
				cout << endl;
				system("pause");
			break;
			
			case 6:
				system("cls");
				list2.mostrar();
				cant = list2.mayor();
				cout << endl << "La mayor cantidad es: " << cant << endl;
				system("pause");
			break;
			
			case 7:
				system("cls");
				list3.muestra();
				prom=list3.promedio();
				cout << endl;
				cout << "El promedio de los articulos defectuosos es: " << prom << endl;
				system("pause");
			break;
			
			
			case 8:
				system("cls");
				escribir();
				system("pause");
			break;
			
			case 9:
				cout << "Adios!" << endl << "Hata luego..." << endl;
				exit(1);
				system("pause");
			break;
		}
	}while(op!=10);
	
	return 0;
}


int busqueda(){
	int resp, bus;
		cout << "\tEn que lista quieres hacer la busqueda?" << endl << endl;
		cout << "\t[1] Articulos Vendidos" << endl
			 << "\t[2} Articulos Recibidos" << endl
			 << "\t[3] Articulos Defectuosos" << endl
			 << "\t[4] Tu lista Creada" << endl << endl;
		cout << "\t Selecciona una opcion "; cin >> resp;
	
	return resp;
}

int program(){
	bool band=true; 
	fstream archivo;
	archivo.open("acerca.txt", ios::out|ios::app);
	if(!archivo){
		cerr<<"no se puede abrir el archivo "<<endl;
		cin.get();
		return 1;
	}
	
	while(band){
		archivo << "       Autor: Andres Noriega Villalobos"
		<< "\n" << "                  ID: 253687"
		<< "\n" << "             Semestre 3, grupo B"
		<< "\n" << "    Fecha de Entrega:  Diciembre 10 de 2021"
		<< "\n" << "            Trabajo: Proyecto Final"
		<< "\n" << "Materia/s: Estructura de Datos && Programacion II"
		<< "\n" << "  Profesora: Blanca Guadalupe Estrada Renteria \n";
		band=false;
	}
	
	archivo.close();
}

void escribir(){
	char texto[250];
	ifstream archivo("acerca.txt");
	
	while(archivo.getline(texto,250)){
		cout << endl << texto << endl;
		Sleep(200);
	}
	archivo.close();
}
