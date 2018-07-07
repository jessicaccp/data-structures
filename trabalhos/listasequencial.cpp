// Universidade Estadual do Ceara
// Centro de Ciencias e Tecnologia
// Curso de Ciencia da Computacao
// Disciplina de Estruturas de Dados 1 2017.2 - Prof. Bruno Lima
// Aluna: Jessica Cristina Cacau Patricio (1388627)
//		  Camila Alves Barbosa (1394330)
// Listas sequenciais
// Metodos: criarLista, isEmpty, isFull, getSize, insert (fim), insert (pos), insert(ord), remove(index), print.

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
	
	// Verifica se a lista esta vazia.
	bool isEmpty() {
		if (lista[0] == -1)
			return true;
		return false;
	}
	
	// Verifica se a lista esta cheia.
	bool isFull() {
		if (lista[getTamanho() - 1] != -1)
			return true;
		return false;
	}
	
	// Retorna o numero de elementos na lista.
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
	// Checa se o lugar onde o usuario que inserir e valido, se não for entra no primeiro if.
	// Se for valido e se a lista nao estiver cheia, entra no primeiro else if.
	// Se ela estiver cheia, 
	void insert(int element, int pos) {
		if (pos>tamanho or pos>getSize()) 
			cout << "Impossível inserir nessa posição." << endl;
		else if (pos == tamanho)
			insert(element);
		else { 
			if (isFull())
				insert(lista[tamanho-1]);
			for (int i=getSize()-1; i>=pos; i--)
				lista[i+1] = lista[i];
			lista[pos] = element;
		}
	}
	
	// Funcao de ordenacao para ordenar o vetor.
	 void ordenar() {
	 	for (int i=0; i<getSize()-1; i++)
	 		for (int j=i; j<getSize(); j++)
	 			if (lista[i] > lista[j])
	 				swap(lista[i], lista[j]);
	 }
	
	// Insere um novo elemento de forma ordenada
	// Primeiro ordena-se a lista para depois realizar a insercao.
	void insertOrd(int element) {
		ordenar();
		for (int i=0; i<getSize(); i++)
			if (element<lista[i])
				insert(element, i);
	}
	
	// Remove um elemento da posicao index da lista
	// Primeiro checa-se se na posicao existe um elemento ou se a posicao que sera eliminada existe.
	// Se ele existir, o elemento sera removido e o tamanho da lista diminuira.
	bool remove(int index) {
		if (index >= tamanho or lista[index] == -1)
			return false;
		for (int i=index; i<getSize()-1; i++)
			lista[i] = lista[i+1];
		lista[getSize()-1] = -1;
		tamanho--;
	}
	
	// Imprime todos os elementos da lista
	void print() {
		if (isEmpty())
			cout << "Lista vazia." << endl;
		else {
			for (int i=0; i<getSize(); i++)
				cout << lista[i] << " ";
			cout << endl;
		}
	}
	
};
// Metodos: criarFila, isEmpty, getSize, insert(info), insert(element, pos), insertOrd(element), remove(index), print.
int main () {
	Lista *l = new Lista();
	l->criarLista();
	
	// Menu
	while (true) {
		// Opcoes
		op = 0;
		cout	<< endl
				<< " 1. isEmpty"						<< endl
				<< " 2. isFull"							<< endl
				<< " 3. getSize"						<< endl
				<< " 4. insercao no final"				<< endl
				<< " 5. insercao com detalhamentos"		<< endl
				<< " 6. insercao ordenada"				<< endl
				<< " 7. remocao de um elemento"			<< endl
				<< " 8. imprimir todos os elementos"	<< endl
				<< " 9. sair"							<< endl;
		
		// Faz a leitura da opcao
		while (op < 1 or op > 7) {
			cout << endl << "Opcao: ";
			cin >> op;
			if (op < 1 or op > 7)
				cout << endl << "Opcao invalida." << endl;
		}
		
		// Realiza o comando de acordo com a opcao.
		switch (op) {
			// Verifica se a lista esta vazia.
			case 1:
				if (l->isEmpty())
					cout << endl << "Lista vazia." << endl;
				else
					cout << endl << "Lista nao vazia." << endl;
				break;
			
			// Verifica se a lista esta cheia.
			case 2:
				if (l->isFull())
					cout << endl << "Lista cheia." << endl;
				else
					cout << endl << "Lista nao vazia." << endl;
				break;
			
			// Imprime o tamanho da lista.
			case 3:
				cout << endl << "Numero de elementos: " << l->getSize() << "." << endl;
			
			// Insere o valor no final da lista
			case 4:
				ccout << endl << "Insira o valor do elemento a ser adicionado na lista: ";
				cin >> info;
				l->insert(info);
				cout << info << "Elemento adicionado na lista." << endl;
				break;
			
			// Insere valor desejado na posicao desejada.
			case 5:
				cout << endl << "Insira o elemento que voce quer inserir: ";
				cin >> element;
				cout << endl << "Insira a posicao a qual voce quer inserir o elemento: ";
				cin >> pos;
				l->insert(element, pos);
				cout << endl << "Elemento adicionado na lista." << endl;
				break;
				
			// Insere o valor desejdao de uma forma ordenada.
			case 6:
				cout << endl << "Insira o elemento que voce quer inserir: ";
				cin >> element;
				l->insertOrd(element);
				cout << endl << "Elemento adicionado na lista." << endl;
				break;
				
			// Remove o elemento desejado da lista.
			case 7:
				cout << endl << "Insira a posicao que voce quer remover: ";
				cin << index;
				l->remove(index);
				cout << "Elemento removido." << endl;
				break;
			
			// Exibe todos os elementos da lista, se existirem.
			case 8:
				cout << endl << "Elementos da fila: ";
				l->print();
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
