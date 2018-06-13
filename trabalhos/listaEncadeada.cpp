/* Universidade Estadual do Ceará
Centro de Ciências e Tecnologia
Curso de Ciência da Computação
Disciplina de Estruturas de Dados 1 2017.2 - Prof. Bruno Lima
Alunas:	Jessica Cristina Cacau Patrício - 1388627
		Camila Alves Barbosa - 1394330 
*/

#include<iostream>
using namespace std;

class Lista {
	private:
	Nodo *prim;
	
	public:
	void criarLista() {
		prim = nullptr;
	}
	
	void liberarLista() {
		while (prim != nullptr) {
			Nodo *aux = prim->getProx();
			delete prim;
			prim = aux;
		}
	}
	
	/* sem recursao */
	bool isEmpty() {
		if (prim == nullptr)
			return true;
		return false;
	}
	
	int getSize() {
		Nodo *aux = prim;
		int numeroElementos = 0;
		
		while (aux != nullptr) {
			numeroElementos++;
			aux = aux->getProx();
		}
		
		return numeroElementos;
	}
	
	void addInicio(int element) {
		Nodo *novo = new Nodo();
		novo->setInfo(element);
		novo->setProx(prim);
		prim = novo;
	}
	
	void addMeio(int element, int pos) {		
		if (pos > getSize()+1) {
			cout << "Impossível adicionar na posição " << pos << "." << endl;
			return;
		}
		
		Nodo *aux = prim;
		while (pos--)
			aux = aux->getProx();
		// incompleto
	}
	
	void addFim(int element) {
		Nodo *novo = new Nodo(), *aux = prim;
		novo->setInfo(element);
		novo->setProx(nullptr);
		
		while (aux->prox != nullptr)
			aux = aux->getProx();
		
		aux->setProx(novo);
	}
	
	void addOrdenado(int element) {
		Nodo *novo = new Nodo(), *aux = prim;
		novo->setInfo(element);
		
		if (aux->getInfo() > element) {
			novo->setProx(prim);
			prim = novo;
		}
		else {
			while (aux->prox != nullptr) {
				if ((aux->getProx())->getInfo() > element)
					break;
				aux = aux->getProx();
			}
			novo->setProx(aux->getProx());
			aux->setProx(novo);
		}
	}
	
	bool remove(int element) {
		if (search(element) == nullptr)
			return false;
		
		while (aux->getProx() != nullptr) {
			if ((aux->getProx())->getInfo == element) {
				Nodo *rm = aux->getProx();
				aux->setProx(rm->getProx());
				rm->setProx(rm);
				delete rm;
				return true;
			}
			aux = aux->getProx();
		}
	}
	
	void print() {
		Nodo *aux = prim;
		while (aux != nullptr) {
			cout << aux->getInfo() << " ";
			aux = aux->getProx();
		}
		cout << endl;
	}
	
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
		aux->setProx(removeRec(n->getProx(), element));
		return n;
	}
};

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
;}

bool listasIguais(Nodo *n1, Nodo *n2);
bool listasIguaisRec(Nodo *n1, Nodo *n2);

int main() {
	Lista *lista = new Lista();
	lista->criarLista();

	return 0;
}
