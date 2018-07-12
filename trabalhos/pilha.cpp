// Universidade Estadual do Ceara
// Centro de Ciencias e Tecnologia
// Curso de Ciencia da Computacao
// Disciplina de Estruturas de Dados 1 2017.2 - Prof. Bruno Lima
// Alunas:	Jessica Cristina Cacau Patricio (1388627)
//			Camila Alves Barbosa (1394330)

// Pilha
// Metodos: criarPilha, clear, isEmpty, isFull, push, pop, top, size, print,
// search

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

class Pilha {
	private:
	Nodo *topo;	// Nodo mais a esquerda da lista
	
	public:
	Nodo* getTopo() {
		return topo;
	}
	
	void setTopo(Nodo *topo) {
		this->topo = topo;
	}
	
	// Inicializa a pilha vazia
	void criarPilha() {
		topo = nullptr;
	}
	
	// Remove todos os nodos da pilha
	void clear() {
		Nodo *aux;
		while (topo != nullptr) {
			aux = topo;
			topo = topo->getProx();
			aux->setProx(aux);
			delete aux;
		}
	}
	
	// Verifica se a pilha esta vazia ao checar se o topo tem valor nulo.
	bool isEmpty() {
		if (topo == nullptr)
			return true;
		return false;
	}
 
	// Verifica se a pilha esta cheia. 
	void isFull() {
		// Como a pilha foi implementada dinamicamente, ela nunca estara cheia.
		cout << endl << "Pilha nao cheia." << endl;
	}
	
	// Insere novo elemento no topo da pilha
	// Cria um nodo para o novo elemento e faz ele apontar para o topo atual,
	// Depois o topo e atualizado e sera o novo nodo.
	void push(int info) {
		Nodo *novo = new Nodo();
		novo->setInfo(info);
		novo->setProx(topo);
		topo = novo;
	}
	
	// Remove elemento do topo e retorna seu valor
	// Retorna -1 se pilha esta vazia.
	// Primeiro checa se existe elementos na pilha, e cria uma pilha auxiliar
	// se existir. Se a pilha conter elementos, a pilha auxiliar ira armazenar o
	// topo, o topo sera atualizado com o proximo elemento da pilha. Assim
	// faremos o auxiliar apontar para si mesmo, eliminando o valor da pilha, e
	// retornara o elemento que foi eliminado.
	int pop() {
		if (topo != nullptr) {
			Nodo *aux = topo;
			int auxInfo = topo->getInfo();
			topo = topo->getProx();
			aux->setProx(aux);
			delete aux;
			return auxInfo;
		}
		return -1;
	}
	
	// Retorna valor do topo da pilha
	// Retorna -1 se pilha esta vazia
	int top() {
		if (topo != nullptr)
			return topo->getInfo();
		return -1;
	}
	
	// Retorna tamanho da pilha
	// Cria uma pilha auxiliar que armazenara os elementos da pilha original. E
	// criado um contador que sera incrementado sempre um novo elemento for
	// inserido na pilha auxiliar. Sera retornado o valor do contador, mostrando
	// a quantidade de elementos existentes na pilha.
	int size() {
		Pilha *p = new Pilha();
		p->criarPilha();
		int cont = 0;
		
		// Empilha os valores da pilha original na pilha auxiliar
		while (topo != nullptr) {
			p->push(pop());
			cont++;
		}
		
		// Empilha de volta na pilha original os valores da pilha auxiliar
		while (p->getTopo() != nullptr)
			push(p->pop());
			
		return cont;
	}
	
	// Imprime os valores da pilha
	// Cria-se uma pilha auxiliar que armazenara os valores da pilha original e
	// imprimira seus valores a medida do processo. 
	void print() {
		Pilha *p = new Pilha();
		p->criarPilha();
	
		// Empilha os valores da pilha original na pilha auxiliar
		while (topo != nullptr) {
			cout << top() << " ";
			p->push(pop());
		}
		cout << endl;
		
		// Empilha de volta na pilha original os valores da pilha auxiliar
		while (p->getTopo() != nullptr)
			push(p->pop());
	}
	
	// Verifica se o valor desejado existe na pilha
	// Cria uma pilha auxiliar que armazenara os valores ate encontrar o valor
	// desejado. E setado uma flag para indicar se o elemento existe ou nao, se
	// o valor for achado, a flag sera acionada e retornara true.
	bool search(int info) {
		Pilha *p = new Pilha();
		p->criarPilha();
		bool flag = false;
		
		// Empilha os valores da pilha original na pilha auxiliar
		while (topo != nullptr) {
			if (top() == info) {
				flag = true;
				break;
			}
			p->push(pop());
		}
		
		// Empilha de volta na pilha original os valores da pilha auxiliar
		while (p->getTopo() != nullptr)
			push(p->pop());
			
		return flag;
	}
};

int main () {
	Pilha *p = new Pilha();
	p->criarPilha();
	int op = 0, info = 0;
	
	// Menu
	while (true) {
		// Opcoes
		op = 0;
		cout	<< endl
				<< "1. clear"	<< endl
				<< "2. isEmpty"	<< endl
				<< "3. isFull"  << endl
				<< "4. push"	<< endl
				<< "5. pop"		<< endl
				<< "6. top"		<< endl
				<< "7. size"	<< endl
				<< "8. print"	<< endl
				<< "9. search"	<< endl
				<< "10. sair"	<< endl;
		
		// Faz a leitura da opcao
		while (op < 1 or op > 10) {
			cout << endl << "Opcao: ";
			cin >> op;
			if (op < 1 or op > 10)
				cout << endl << "Opcao invalida." << endl;
		}
		
		// Realiza o comando de acordo com a opcao
		switch (op) {
			// Remove todos os nodos da pilha
			case 1:
				p->clear();
				cout << endl << "Pilha apagada." << endl;
				break;
				
			// Verifica se a pilha esta vazia
			case 2:
				if (p->isEmpty())
					cout << endl << "Pilha vazia." << endl;
				else
					cout << endl << "Pilha nao vazia." << endl;
				break;
			
			//Verifica se a pilha esta cheia
			case 3:
				p->isFull();
				break;
				
			// Insere valor no topo da pilha
			case 4:
				cout << endl << "Insira o valor do elemento a ser adicionado: ";
				cin >> info;
				p->push(info);
				cout << info << " adicionado na pilha." << endl;
				break;
				
			// Remove valor do topo da pilha, se existir
			case 5:
				if (p->isEmpty())
					cout << endl << "Pilha vazia." << endl;
				else
					cout << endl << p->pop() << " removido da pilha." << endl;
				break;
				
			// Exibe valor do topo da pilha, se existir
			case 6:
				if (p->isEmpty())
					cout << endl << "Pilha vazia." << endl;
				else
					cout << endl << "Topo da pilha: " << p->top() << "." << endl;
				break;
				
			// Verifica tamanho da pilha
			case 7:
				cout << endl << "Tamanho da pilha: " << p->size() << "." << endl;
				break;
				
			// Exibe os elementos da pilha, se existirem
			case 8:
				if (p->isEmpty())
					cout << endl << "Pilha vazia." << endl;
				else {
					cout << endl << "Elementos da pilha: ";
					p->print();
				}
				break;
				
			// Busca valor informado na pilha
			case 9:
				cout << endl << "Insira o valor do elemento a ser procurado: ";
				cin >> info;
				if (p->search(info))
					cout << info << " existe na pilha." << endl;
				else
					cout << info << " nao existe na pilha." << endl;
				break;
				
			// Sai do programa
			case 10:
				exit(0);
				
			default:
				cout << endl << "Opcao invalida." << endl;
				break;
		}
	}

	return 0;
}
