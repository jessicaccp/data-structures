// Universidade Estadual do Ceara
// Centro de Ciencias e Tecnologia
// Curso de Ciencia da Computacao
// Disciplina de Estruturas de Dados 1 2017.2 - Prof. Bruno Lima
// Aluna: Jessica Cristina Cacau Patricio (1388627)

// Listas sequenciais
// Metodos: criarLista, isEmpty, isFull, getSize, insert (fim), insert (pos),
//

// Metodos: criarFila, clear, isEmpty, enfileira, desenfileira, size, print,
// search, concatenar, intercalar, dividir, ordenar

/*
public void insert(int element, int pos) - insere um novo elemento em uma determinada posição passada por parâmetro
public void insertOrd(int element) - insere um novo elemento de forma ordenada, ou seja, ao inserir um novo elemento a lista deve continuar ordenada em ordem crescente
public bool remove(int index) - remove o elemento da posição index, caso exista na lista.
public void print() - imprime todos os elementos da lista 
*/

#include<iostream>
using namespace std;

class Lista {
	private:
	int *lista;	// ponteiro para o inicio do vetor
	int tamanho; // tamanho do vetor
	
	public:
	int* getLista() {
		return lista;
	}
	
	void setLista(int *lista) {
		this->lista = lista;
	}
	
	int getTamanho() {
		return tamanho;
	}
	
	void setTamanho(int tamanho) {
		this->tamanho = tamanho;
	}
	
	// Aloca espaco na memoria do tamanho desejado, atribui ao ponteiro lista
	// e seta todos os valores como -1, que seria o equivalente a nulo
	void criarLista(int tamanho) {
		setLista(new int[tamanho]);
		setTamanho(tamanho);
		for (int i = 0; i < tamanho; i++)
			lista[i] = -1;
	}
	
	// Verifica se a lista esta vazia
	bool isEmpty() {
		if (lista[0] == -1)
			return true;
		return false;
	}
	
	// Verifica se a lista esta cheia
	bool isFull() {
		if (lista[getTamanho() - 1] != -1)
			return true;
		return false;
	}
	
	// Retorna o numero de elementos na lista
	int getSize() {
		int cont = 0;
		for (int i = 0; i < getTamanho(); i++)
			if (lista[i] != -1)
				cont++;
			else
				break;
		return cont;
	}

	// Insere elemento no final da lista
	// Se lista nao estiver cheia, adiciona elemento no final. Se estiver, aloca
	// novo espaco, transfere todos os elementos, deleta lista anterior, altera
	// ponteiro da lista e adiciona elemento no final da nova lista
	void insert(int info) {
		if (not isFull())
			lista[getSize()] = info;
		else {
			setTamanho(getTamanho() + 1);
			int *aux = new int[getTamanho()];
			for (int i = 0; i < getTamanho() - 1; i++)
				aux[i] = lista[i];
			aux[getTamanho() - 1] = info;
			delete lista;
			setLista(aux);
			aux = nullptr;
			delete aux;
		}
	}
	
	// Insere elemento na posicao desejada
	void insert(int info, int pos) {

	}
	
	
	//public void insertOrd(int element) - insere um novo elemento de forma ordenada, ou seja, ao inserir um novo elemento a lista deve continuar ordenada em ordem crescente
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
