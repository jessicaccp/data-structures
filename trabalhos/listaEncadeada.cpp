// Universidade Estadual do Ceará
// Centro de Ciências e Tecnologia
// Curso de Ciência da Computação
// Disciplina de Estruturas de Dados 1 2017.2 - Prof. Bruno Lima
// Alunas:	Jessica Cristina Cacau Patrício - 1388627
//			Camila Alves Barbosa - 1394330 
//*Metodos: criarLista, isEmpty, insert(element), insert(pos), insertOrd(element), getSize, search(element), remove(index), print(Node n), eqlist(Node l1, Node l2). 

/*
public bool isEmpty() - retorna se a lista está vazia ou não.
public void insert(int element) - insere um novo elemento no final da lista.
public void insert(int element, int pos) - insere um novo elemento em uma determinada posição passada por parâmetro (3 casos).
public void insertOrd(int element) - insere um novo elemento de forma ordenada, ou seja, ao inserir um novo elemento a lista deve continuar ordenada em ordem crescente.
public int getSize() - retorna o número de elementos da lista
public int search(int element) - Busca um elemento na lista, caso exista retorna a posição, caso contrário retorna NULL.
public bool remove(int index) - remove o elemento da posição index, caso exista na lista.
public void print(Node n) - imprime a lista de forma recursiva.
public bool eqlist(Node l1, Node l2) - verifica se duas listas são iguais.
*/

#include<iostream>
using namespace std;

class Nodo {
	private:
	int info;
	Nodo *prox;
	
	public:
	int getInfo() {
		return info;
	}
	
	void setInfo(int info) {
		this->info = info;
	}
	
	Nodo* getProx() {
		return prox;
	}
	
	void setProx(Nodo *prox) {
		this->prox = prox;
	}
};

class Lista {
		private:
		Nodo *prim= prim;
		
		public:
		Nodo* getPrim() {
			return prim;
		}
		
		void setPrim(Nodo *prim) {
			this->prim = prim;
		}
		
		// Inicializa a lista vazia.
		void criarLista() {
			prim = nullptr;
		}
		// Remove todos os elementos da lista.
		void liberarLista() {
		while (prim != nullptr) {
			Nodo *aux = prim->getProx();
			delete prim;
			prim = aux;
		}
	}
	
	/* sem recursao */
	
	// Verifica se a lista esta vazia.
	bool isEmpty() {
		if (prim == nullptr)
			return true;
		return false;
	}
	
	// Retorna a quantidade de elementos.
	int getSize() {
		Nodo *aux = prim;
		int numeroElementos = 0;
		
		while (aux != nullptr) {
			numeroElementos++;
			aux = aux->getProx();
		}
		
		return numeroElementos;
	}
	
	// Insercao no inicio da lista.
	void addInicio(int element) {
		Nodo *novo = new Nodo();
		novo->setInfo(element);
		novo->setProx(prim);
		prim = novo;
	}
	
	// Insercao no meio da lista.
	// Primeiro verifica se a posicao onde o elemento sera adicionado existe.
	// Se existir, o elemento sera adicionado.
	void addMeio(int element, int pos) {		
		if (pos > getSize()+1) {
			cout << "Impossível adicionar na posição " << pos << "." << endl;
			return;
		}
		int cont = 0;
		Nodo *aux = prim;
		Nodo *novo = new Nodo();
		novo->setInfo(element);
		while (pos--){
			aux = aux->getProx();
			cont++;
		}
		novo->setProx(aux->getProx());
		aux->setProx(novo);
	}
	
	// Insercao no final da lista.
	// 
	void addFim(int element) {
		Nodo *novo = new Nodo(), *aux = prim;
		novo->setInfo(element);
		novo->setProx(nullptr);
		
		while (aux->getProx() != nullptr)
			aux = aux->getProx();
		
		aux->setProx(novo);
	}
	
	// Insercao na posicao desejada.
	void addOrdenado(int element) {
		Nodo *novo = new Nodo(), *aux = prim;
		novo->setInfo(element);
		
		if (aux->getInfo() > element) {
			novo->setProx(prim);
			prim = novo;
		}
		else {
			while (aux->getProx() != nullptr) {
				if ((aux->getProx())->getInfo() > element)
					break;
				aux = aux->getProx();
			}
			novo->setProx(aux->getProx());
			aux->setProx(novo);
		}
	}
	
	// Remocao de um elemento da lista.
	bool remove(int element) {
		if (search(element) == nullptr)
			return false;
		Nodo *aux = prim;
		while (aux->getProx() != nullptr) {
			if ((aux->getProx())->getInfo() == element) {
				Nodo *rm = aux->getProx();
				aux->setProx(rm->getProx());
				rm->setProx(rm);
				delete rm;
				return true;
			}
			aux = aux->getProx();
		}
	}
	
	// Imprime todos os elementos da lista enquanto percorre ate o ultimo elemento.
	void print() {
		Nodo *aux = prim;
		while (aux != nullptr) {
			cout << aux->getInfo() << " ";
			aux = aux->getProx();
		}
		cout << endl;
	}
	
	// Busca um elemento percorrendo a lista. 
	Nodo* search(int element) {
		Nodo *aux = prim;
		while (aux != nullptr)
			if (aux->getInfo() == element)
				return aux;
		return nullptr;
	}
	
	void sort();
	
	/* com recursao */
	void printRec(Nodo *n) {
		if (n != nullptr) {
			cout << n->getInfo() << endl;
			printRec(n->getProx());
		}
	}
	
	Nodo* removeRec(Nodo *n, int element) {
		if (n->getInfo() == element) {
			Nodo *aux = n->getProx();
			delete n;
			return aux;
		}
		Nodo *aux = prim;
		aux->setProx(removeRec(n->getProx(), element));
		return n;
	}

	bool listasIguais(Nodo *n1, Nodo *n2){
		Nodo *aux1 = n1;
		Nodo *aux2 = n2;
		for (aux1 != nullptr && aux2 != nullptr; aux1 = aux1->getProx(); aux2 = aux2->getProx()){
			if (aux1->getInfo() != aux2->getInfo())
				return false;
		}
			return true;
	}
	
	bool listasIguaisRec(Nodo *n1, Nodo *n2) {
		if ( n1 == nullptr && n2 == nullptr ){
			return true;
		}else if ( n1 == nullptr || n2 == nullptr){
			return false;
		}else
			return (( n1->getInfo() == n2->getInfo() && listasIguaisRec(n1->getProx(), n2->getProx())));
	}
};

	int main() {
		Lista *lista = new Lista();
		lista->criarLista();

		return 0;
	}
