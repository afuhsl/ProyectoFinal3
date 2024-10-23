class nodo{
	int dato;
	nodo *ant, *sig;
	public:
		nodo(int x){
			dato=x;
		}
		friend class lista;
};
