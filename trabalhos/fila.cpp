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
			if (inicio->getInfo() == info)
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
		// Remove os elementos das listas auxiliares
		f1->clear();
		f2->clear();
		// adiciona a maior metade dos elementos da fila em f1
		for (int i = 0; i < (size() % 2); i++)
			f1->enfileira(desenfileira());
		// adiciona o restante em f2
		while (inicio != nullptr)
			f2->enfileira(desenfileira());
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

// Metodos: criarFila, clear, isEmpty, enfileira, desenfileira, size, print,
// search, concatenar, intercalar, dividir, ordenar
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
			
			// Insere valor no fim da fila
			case 3:
				cout << endl << "Insira o valor do elemento a ser adicionado: ";
				cin >> info;
				f->enfileira(info);
				cout << info << " adicionado na fila." << endl;
				break;
				
			// Remove valor do inicio da fila
			case 4:
				if (f->isEmpty())
					cout << endl << "Fila vazia." << endl;
				else
					cout << endl << f->desenfileira() << " removido da fila." << endl;
				break;
				
			// Verifica tamanho da fila
			case 5:
				cout << endl << "Tamanho da fila: " << f->size() << "." << endl;
				break;
			
			// Exibe todos os elementos da fila, se existirem
			case 6:
				if (f->isEmpty())
					cout << endl << "Fila vazia." << endl;
				else {
					cout << endl << "Elementos da fila: ";
					f->print();
				}
				break;
				
			// Busca valor informado na fila
			case 7:
				cout << endl << "Insira o valor do elemento a ser procurado: ";
				cin >> info;
				if (f->search(info))
					cout << info << " existe na fila." << endl;
				else
					cout << info << " nao existe na fila." << endl;
				break;
			
			// Concatena duas filas recebidas em uma
			case 8:
				cout << endl << "Menu nao implementado ainda." << endl;
				break;
				// concatenar
				// recebe duas filas e exibe o final
				
			// Intercala duas filas recebidas em uma
			case 9:
				cout << endl << "Menu nao implementado ainda." << endl;
				break;
				// intercalar
				// recebe duas filas e exibe a final
				
			// Divide a fila em duas que sao passadas por parametro
			case 10:
				if (f->isEmpty())
					cout << endl << "Fila vazia." << endl;
				else {
					cout << endl << "Fila original: ";
					f->print();
					f->dividir(f1, f2);
					cout << endl << "Filas divididas:" << endl << "F1 - ";
					f1->print();
					cout << "F2 - ";
					f2->print();
				}
				break;
				
			// Ordena os valores da fila
			case 11:
				if (f->isEmpty())
					cout << endl << "Fila vazia." << endl;
				else {
					cout << endl << "Lista desordenada: ";
					f->print();
					f->ordenar();
					cout << endl << "Lista ordenada: ";
					f->print();
				}
				break;
			
			// Sai do programa
			case 12:
				exit(0);
				
			default:
				cout << endl << "Opcao invalida." << endl;
				break;
		}
	}

	return 0;
}
