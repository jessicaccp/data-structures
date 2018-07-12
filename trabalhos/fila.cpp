// Universidade Estadual do Ceara
// Centro de Ciencias e Tecnologia
// Curso de Ciencia da Computacao
// Disciplina de Estruturas de Dados 1 2017.2 - Prof. Bruno Lima
// Aluna: Jessica Cristina Cacau Patricio (1388627)
//	  	  Camila Alves Barbosa (1394330)

// Fila
// Metodos: criarFila, clear, isEmpty, enfileira, desenfileira, size, print,
// search.

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

class Fila {
	private:
	Nodo *inicio;	// Nodo mais a esquerda
	Nodo *fim;		// Nodo mais a direita
	
	public:
	Nodo* getInicio() {
		return inicio;
	}
	
	void setInicio(Nodo *inicio) {
		this->inicio = inicio;
	}
	
	Nodo* getFim() {
		return fim;
	}
	
	void setFim(Nodo *fim) {
		this->fim = fim;
	}
	
	// Inicializa a fila
	void criarFila() {
		inicio = fim = nullptr;
	}
	
	// Remove todos os nodos da fila
	void clear() {
		Nodo *aux;
		while (inicio != nullptr) {
			aux = inicio;
			// Altera ponteiro do final ao remover ultimo nodo
			if (inicio == fim)
				fim = nullptr;
			inicio = inicio->getProx();
			aux->setProx(aux);
			delete aux;
		}
	}
	
	// Verifica se a fila esta vazia
	bool isEmpty() {
		if (inicio == nullptr)
			return true;
		return false;
	}
	// Verifica se a fila esta cheia
	void isFull() {
		//Como a fila e dinamica, ela nunca estara cheia.
		cout << endl << "Fila nao vazia." << endl;
	}
	
	
	// Insere novo elemento no fim da fila
	// Faz o novo nodo apontar para o nulo. Se o antigo "fim" da fila for o
	// inicio, faz o inicio apontar para o novo, que sera o novo final. Se não,
	// o antigo final apontara para o novo, assim, o novo elemento sera o novo
	// final.
	void enfileira(int info) {
		Nodo *novo = new Nodo();
		novo->setInfo(info);
		novo->setProx(nullptr);
		if (inicio == nullptr)
			inicio = fim = novo;
		else {
			fim->setProx(novo);
			fim = novo;
		}
	}
	
	// Remove elemento do inicio da fila e retorna seu valor
	// Retorna -1 se a fila estiver vazia	
	// Cria um no auxiliar que guardara o valor do inicio da fila. Se o inicio
	// for o final da lista, a lista ficara vazia. Se não, o inicio será o
	// proximo elemento da fila. O no auxiliar apontara para ele mesmo e sera
	// removido. Sera retornado o elemento que foi removido.
	int desenfileira() {
		if (inicio != nullptr) {
			Nodo *aux = inicio;
			int auxInfo = inicio->getInfo();
			// Altera ponteiro do final ao remover ultimo nodo
			if (inicio == fim)
				fim = nullptr;
			inicio = inicio->getProx();
			aux->setProx(aux);
			delete aux;
			return auxInfo;
		}
		return -1;
	}
	
	// Retorna tamanho da fila
	// Cria-se uma fila auxiliar para receber os elementos da fila original. E
	// criado um contador que e incrementado a medida que um novo elemento e
	// inserido na fila auxiliar.
	int size() {
		Fila *f = new Fila();
		f->criarFila();
		int cont = 0;
		
		// Enfileira os valores da fila original na fila auxiliar
		while (inicio != nullptr) {
			f->enfileira(desenfileira());
			cont++;
		}
		
		// Enfileira de volta na fila original os valores da fila auxiliar
		while (f->getInicio() != nullptr)
			enfileira(f->desenfileira());
			
		return cont;
	}
	
	// Imprime os valores da fila
	// E criado uma fila auxiliar que recebe a fila original. A medida que os
	// elementos sao inseridos na filha auxiliar, eles sao imprimidos na tela.
	void print() {
		Fila *f = new Fila();
		f->criarFila();
		
		// Enfileira os valores da fila original na fila auxiliar
		while (inicio != nullptr) {
			cout << inicio->getInfo() << " ";
			f->enfileira(desenfileira());
		}
		cout << endl;
		
		// Enfileira de volta na fila original os valores da fila auxiliar
		while (f->getInicio() != nullptr)
			enfileira(f->desenfileira());
	}
	
	// Verifica se valor existe na fila
	bool search(int info) {
		Fila *f = new Fila();
		f->criarFila();
		bool flag = false;
		
		// Enfileira os valores da fila original na fila auxiliar
		// Nao para o loop quando encontra o valor, senao eles nao serao
		// reinseridos na mesma posicao
		while (inicio != nullptr) {
			if (inicio->getInfo() == info)
				flag = true;
			f->enfileira(desenfileira());
		}
		
		// Enfileira de volta na fila original os valores da fila auxiliar
		while (f->getInicio() != nullptr)
			enfileira(f->desenfileira());
			
		return flag;
	}
	
	// Ordena os elementos da fila
	void ordenar() {
		Fila *f1 = new Fila();
		Fila *f2 = new Fila();
		f1->criarFila();
		f2->criarFila();
		
		// Usa as duas filas auxiliares na ordenacao, deixando sempre ao menos
		// uma delas vazia
		while (inicio != nullptr) {
			// Se ambas estiverem vazias, desenfileira em f1
			if (f1->isEmpty() and f2->isEmpty())
				f1->enfileira(desenfileira());
			// Se f1 estiver vazia e f2 nao, desenfileira de f2 os valores
			// menores que o inicio da fila original, desenfileira o inicio e
			// desenfileira de f2 os valores restantes
			else if (f1->isEmpty()) {
				while (f2->getInicio()->getInfo() < inicio->getInfo())
					f1->enfileira(f2->desenfileira());
				f1->enfileira(desenfileira());
				while (f2->getInicio() != nullptr)
					f1->enfileira(f2->desenfileira());
			}
			// Se f2 estiver vazia e f1 nao, desenfileira de f1 os valores
			// menores que o inicio da fila original, desenfileira o inicio e
			// desenfileira de f1 os valores restantes
			else if (f2->isEmpty()) {
				while (f1->getInicio()->getInfo() < inicio->getInfo())
					f2->enfileira(f1->desenfileira());
				f2->enfileira(desenfileira());
				while (f1->getInicio() != nullptr)
					f2->enfileira(f1->desenfileira());
			}
			else
				cout << "Ops" << endl;
		}
		
		// Enfileira os valores da fila auxiliar de volta na fila original
		if (not f1->isEmpty())
			while (f1->getInicio() != nullptr)
				enfileira(f1->desenfileira());
		else
			while (f2->getInicio() != nullptr)
				enfileira(f2->desenfileira());
	}
};

int main () {
	Fila *f = new Fila();
	f->criarFila();
	int op = 0, info = 0;
	
	Fila *f1 = new Fila();
	Fila *f2 = new Fila();
	f1->criarFila();
	f2->criarFila();
	
	// Menu
	while (true) {
		// Opcoes
		op = 0;
		cout	<< endl
				<< " 1. clear"			<< endl
				<< " 2. isEmpty"		<< endl
				<< " 3. isFull"			<< endl
				<< " 4. enfileira"		<< endl
				<< " 5. desenfileira"	<< endl
				<< " 6. size"			<< endl
				<< " 7. print"			<< endl
				<< " 8. search"			<< endl
				<< " 9. sair"			<< endl;
		
		// Faz a leitura da opcao
		while (op < 1 or op > 9) {
			cout << endl << "Opcao: ";
			cin >> op;
			if (op < 1 or op > 10	)
				cout << endl << "Opcao invalida." << endl;
		}
		
		// Realiza o comando de acordo com a opcao
		switch (op) {
			// Remove todos os nodos da fila
			case 1:
				f->clear();
				cout << endl << "Fila apagada." << endl;
				break;
			
			// Verifica se a fila esta vazia
			case 2:
				if (f->isEmpty())
					cout << endl << "Fila vazia." << endl;
				else
					cout << endl << "Fila nao vazia." << endl;
				break;
			
			//Verifica se a fila esta cheia
			case 3:
				f->isFull();
				break;
				
			// Insere valor no fim da fila
			case 4:
				cout << endl << "Insira o valor do elemento a ser adicionado: ";
				cin >> info;
				f->enfileira(info);
				cout << info << " adicionado na fila." << endl;
				break;
				
			// Remove valor do inicio da fila
			case 5:
				if (f->isEmpty())
					cout << endl << "Fila vazia." << endl;
				else
					cout << endl << f->desenfileira() << " removido da fila." << endl;
				break;
				
			// Verifica tamanho da fila
			case 6:
				cout << endl << "Tamanho da fila: " << f->size() << "." << endl;
				break;
			
			// Exibe todos os elementos da fila, se existirem
			case 7:
				if (f->isEmpty())
					cout << endl << "Fila vazia." << endl;
				else {
					cout << endl << "Elementos da fila: ";
					f->print();
				}
				break;
				
			// Busca valor informado na fila
			case 8:
				cout << endl << "Insira o valor do elemento a ser procurado: ";
				cin >> info;
				if (f->search(info))
					cout << info << " existe na fila." << endl;
				else
					cout << info << " nao existe na fila." << endl;
				break;
			
			// Sai do programa
			case 9:
				exit(0);
				
			default:
				cout << endl << "Opcao invalida." << endl;
				break;
		}
	}

	return 0;
}
