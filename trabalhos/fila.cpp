// Universidade Estadual do Ceara
// Centro de Ciencias e Tecnologia
// Curso de Ciencia da Computacao
// Disciplina de Estruturas de Dados 1 2017.2 - Prof. Bruno Lima
// Aluna: Jessica Cristina Cacau Patricio (1388627)

// Filas
// Metodos: criarFila, clear, isEmpty, enfileira, desenfileira, size, print,
// search, concatenar, intercalar, dividir, ordenar

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
	
	// Insere novo elemento no fim da fila
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
			if (inicio->getInfo == info)
				flag = true;
			f->enfileira(desenfileira());
		}
		
		// Enfileira de volta na fila original os valores da fila auxiliar
		while (f->getInicio() != nullptr)
			enfileira(f->desenfileira());
			
		return flag;
	}
	
	// Concatena em ordem crescente a partir do inicio os elementos de duas
	// filas tambem ordenadas
	void concatenar(Fila *f1, Fila *f2) {
		// Enquanto ao menos uma das filas nao estiver vazia
		while ((not f1->isEmpty()) or (not f2->isEmpty()))
			// Se f1 estiver vazia, enfileira inicio de f2
			if (f1->isEmpty())
				enfileira(f2->desenfileira());
			// Se f2 estiver vazia, enfileira inicio de f1
			else if (f2->isEmpty())
				enfileira(f1->desenfileira());
			// Se inicio de f1 menor que de f2, enfileira inicio de f1
			else if (f1->getInicio()->getInfo() < f2->getInicio()->getInfo())
				enfileira(f1->desenfileira());
			// Se inicio de f1 maior ou igual ao de f2. enfileira inicio de f2
			else
				enfileira(f2->desenfileira());
	}
	
	// Intercala os elementos de duas listas
	void intercalar(Fila *f1, Fila *f2) {
		// Enquanto ao menos uma das filas nao estiver vazia
		while ((not f1->isEmpty()) or (not f2->isEmpty())) {
			// Se f1 nao estiver vazia, enfileira inicio de f1
			if (not f1->isEmpty())
				enfileira(f1->desenfileira());
			// Se f2 nao estiver vazia, enfileira inicio de f2
			if (not f2->isEmpty())
				enfileira(f2->desenfileira());
		}
	}
	
	// Divide fila em duas (recebidas por parametros)
	void dividir(Fila *f1, Fila *f2) {
		// implementar
	}
	
	// Ordena os elementos da fila
	void ordenar() {
		// implementar
	}
};

// Metodos: criarFila, clear, isEmpty, enfileira, desenfileira, size, print,
// search, concatenar, intercalar, dividir, ordenar
int main () {
	Fila *f = new Fila();
	f->criarFila();
	int op = 0, info = 0;
	
	// Menu
	while (true) {
		// Opcoes
		op = 0;
		cout	<< endl
				<< " 1. clear"			<< endl
				<< " 2. isEmpty"		<< endl
				<< " 3. enfileira"		<< endl
				<< " 4. desenfileira"	<< endl
				<< " 5. size"			<< endl
				<< " 6. print"			<< endl
				<< " 7. search"			<< endl
				<< " 8. concatenar"		<< endl
				<< " 9. intercalar"		<< endl
				<< "10. dividir"		<< endl
				<< "11. ordenar"		<< endl
				<< "12. sair"			<< endl;
		
		// Faz a leitura da opcao
		while (op < 1 or op > 12) {
			cout << endl << "Opcao: ";
			cin >> op;
			if (op < 1 or op > 12)
				cout << endl << "Opcao invalida." << endl;
		}
		
		// Realiza o comando de acordo com a opcao
		switch (op) {
			case 1:
			case 2:
			case 3:
			case 4:
			case 5:
			case 6:
			case 7:
			case 8:
			case 9:
			case 10:
			case 11:
			case 12:
			default:
		}
	}

	return 0;
}
