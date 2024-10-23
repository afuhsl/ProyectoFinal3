class lista{
		nodo *raiz;
		int acum; 
	public:
		lista(){
			raiz=NULL;
		};
		void agregar(int x){
			nodo *l = new nodo(x);
			l->ant = NULL;
			if(raiz == NULL){
				l->sig=NULL;
				raiz=l;
			}else{
				l->sig=raiz;
				raiz->ant=raiz;
				raiz=l;
			}
		}
		void mostrar(){
			nodo *r=raiz;
			cout << "\t\tCantidad" << endl;
			for(int i=0; i<7; i++){
				while(r!=NULL){
					cout << "\tDia " << i+1 <<"\t " <<  r->dato << endl;
					r = r->sig;
				}
			}
		}
		int suma(){
			nodo *sum=raiz;
			int s=0;
			while(sum!=NULL){
				s+=sum->dato;
				sum=sum->sig;
			}
			return s;
		}
		
		void buscar(int dat){
			if(raiz==NULL){
			cout << "El dato NO se encuentra dentro de la lista" << endl;
			}else{
				if(raiz->dato==dat){
					cout << "El dato se encuentra dentro de la lista!" << endl;
				}else{
					cout << "El dato NO se encuentra dentro de la lista" << endl;
				}
			}
		}
		 
};
