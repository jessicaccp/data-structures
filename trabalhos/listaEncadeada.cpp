// Universidade Estadual do Ceará
// Centro de Ciências e Tecnologia
// Curso de Ciência da Computação
// Disciplina de Estruturas de Dados 1 2017.2 - Prof. Bruno Lima
// Alunas:	Jessica Cristina Cacau Patrício - 1388627
//		Camila Alves Barbosa - 1394330 

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

class Lista {
        int info;
		private:
		Lista *prim= prim;
		
		public:
		Lista* getPrim() {
			return prim;
		}
		
		public:
    	int getInfo() {
    		return info;
    	}
    	
    	void setInfo(int info) {
    		this->info = info;
    	}
    	
    	Lista* getProx() {
    		return prim;
    	}
    	
    	void setProx(Lista *prim) {
    		this->prim = prim;
    	}
		
		void setPrim(Lista *prim) {
			this->prim = prim;
		}
		
		// Inicializa a lista vazia.
		void criarLista() {
			prim = nullptr;
		}
		// Remove todos os elementos da lista.
		void liberarLista() {
		while (prim != nullptr) {
			Lista *aux = prim->getProx();
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
	
	// Retorna a quantidade de elementos criando uma lista auxiliar.
	int getSize() {
		Lista *aux = prim;
		int numeroElementos = 0;
		
		while (aux != nullptr) {
			numeroElementos++;
			aux = aux->getProx();
		}
		
		return numeroElementos;
	}
	
	// Insercao no inicio da lista setando o novo nodo ao primeiro da lista e fazendo o inicio apontar para o novo.
	void addInicio(int element) {
		Lista *novo = new Lista();
		novo->setInfo(element);
		novo->setProx(prim);
		prim = novo;
	}
	
	// Insercao no meio da lista.
	// Primeiro verifica se a posicao onde o elemento sera adicionado existe.
	// Se existir, o elemento sera adicionado, fazendo o novo nodo apontar para o proximo nodo de onde ele sera inserido
	// e o antigo nodo daquela posicao apontara para o novo nodo.
	void addMeio(int element, int pos) {		
		if (pos > getSize()+1) {
			cout << "Impossível adicionar na posição " << pos << "." << endl;
			return;
		}
		int cont = 0;
		Lista *aux = prim;
		Lista *novo = new Lista();
		novo->setInfo(element);
		while (pos--){
			aux = aux->getProx();
			cont++;
		}
		novo->setProx(aux->getProx());
		aux->setProx(novo);
	}
	
	// Insercao no final da lista.
	// Primeiro acha qual o nodo que aponta para o nulo, logo apos faz o novo nodo apontar para o nulo,
	// e o "ex" ultimo da lista apontara para o novo nodo.
	void addFim(int element) {
		Lista *novo = new Lista(), *aux = prim;
		novo->setInfo(element);
		novo->setProx(nullptr);
		
		while (aux->getProx() != nullptr)
			aux = aux->getProx();
		
		aux->setProx(novo);
	}
	// Insercao ordenada na lista.
	// Cria-se um novo nodo que contem o valor a ser inserido.
	// Cria-se um nodo auxiliar que aponta para o comeco da lista.
	// Se o novo nodo for menor que o auxiliar, ele será inserido no começo da lista.
	// Se não for, sera feito uma busca na lista ate achar o nodo que tem a menor diferenca de valor e o novo sera inserido antes dele.
	void addOrdenado(int element) {
		Lista *novo = new Lista(), *aux = prim;
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
	// Primeiro verifica se o elemento existe, ao achar faz o nodo anterior dele apontar para seu sucessor
	// Logo depois faz com que o nodo que sera eliminado aponte para si mesmo, podendo assim ser excluido.
	bool remove(int element) {
		if (search(element) == nullptr)
			return false;
		Lista *aux = prim;
		while (aux->getProx() != nullptr) {
			if ((aux->getProx())->getInfo() == element) {
				Lista *rm = aux->getProx();
				aux->setProx(rm->getProx());
				rm->setProx(rm);
				delete rm;
				return true;
			}
			aux = aux->getProx();
		}
	}
	
	// Imprime todos os elementos da lista enquanto percorre ate o ultimo elemento com a ajuda de uma lista auxiliar.
	void print() {
		Lista *aux = prim;
		while (aux != nullptr) {
			cout << aux->getInfo() << " ";
			aux = aux->getProx();
		}
		cout << endl;
	}
	
	// Busca um elemento percorrendo a lista com uma lista auxiliar.
	Lista* search(int element) {
		Lista *aux = prim;
		while (aux != nullptr)
			if (aux->getInfo() == element)
				return aux;
		return nullptr;
	}
	
	/* com recursao */
	
	// Imprime os elementos da lista de uma forma recursiva.
	// Enquanto nao chegar no final da lista, o argumento da funcao sera o proximo nodo.
	void printRec(Lista *n) {
		if (n != nullptr) {
			cout << n->getInfo() << endl;
			printRec(n->getProx());
		}
	}
	
	// Remove um elemento de uma forma recursiva.
	// Primeiro encontra-se o no que contem o elemento.
	// Ao encontrar, cria-se um no auxiliar que apontara para o proximo no do elemento que sera removido.
	// Com isso, o elemento do no auxiliar sera um argumento para a exclusao de outro no.
	Lista* removeRec(Lista *n, int element) {
		if (n->getInfo() == element) {
			Lista *aux = n->getProx();
			delete n;
			return aux;
		}
		Lista *aux = prim;
		aux->setProx(removeRec(n->getProx(), element));
		return n;
	}
	
	// Checar se duas listas sao iguais.
	// Cria-se duas listas auxiliares, se ambas contiverem elementos, sera checado seus valores.
	bool listasIguais(Lista *n1, Lista *n2){
		Lista *aux1 = n1;
		Lista *aux2 = n2;
		for (aux1 != nullptr && aux2 != nullptr; aux1 = aux1->getProx(); aux2 = aux2->getProx()){
			if (aux1->getInfo() != aux2->getInfo())
				return false;
		}
			return true;
	}
	
	// Checar se duas listas sao iguais de uma forma recursiva.
	// Se ambas nao contiverem elementos, sao iguais.
	// Se somente uma for nula, elas nao serao iguais.
	// Se elas contiverem elementos, sera checado se esses elementos sao iguais e como argumento da funcao sera usado seus proximos nos.
	bool listasIguaisRec(Lista *n1, Lista *n2) {
		if ( n1 == nullptr && n2 == nullptr ){
			return true;
		}else if ( n1 == nullptr || n2 == nullptr){
			return false;
		}else
			return (( n1->getInfo() == n2->getInfo() && listasIguaisRec(n1->getProx(), n2->getProx())));
	}
};

// Metodos: criarLista, isEmpty, insert(element), insert(pos), insertOrd(element),
// getSize, search(element), remove(index), print(Node n), eqlist(Node l1, Node l2). 
	
	int main() {
		Lista *lista = new Lista();
		lista->criarLista();
		int op = 0; 
		int element =0;
		int pos = 0;
		
		Lista *l1 = new Lista();
		Lista *l2 = new Lista();
		l1->criarLista();
		l2->criarLista();
		
		// Menu
		while (true) {
		// Opcoes
		op = 0;
		cout	<< endl
				<< " 1. isEmpty"											<< endl
				<< " 2. getSize"											<< endl
				<< " 3. insercao no inicio"									<< endl
				<< " 4. insercao no meio"									<< endl
				<< " 5. insercao no fim"									<< endl
				<< " 6. insercao ordenada"									<< endl
				<< " 7. remocao normal"										<< endl
				<< " 8. imprimir os elementos"								<< endl
				<< " 9. busca de um elemento"								<< endl
				<< " 10. impressao recursiva"								<< endl
				<< " 11. remocao recursiva"									<< endl
				<< " 12. checa se duas listas sao iguais"					<< endl
				<< " 13. checa se duas listas sao iguais recursiva"			<< endl
				<< " 14. sair" 												<<endl;
		
		// Faz a leitura da opcao
		while (op < 1 or op > 14) {
			cout << endl << "Opcao: ";
			cin >> op;
			if (op < 1 or op > 14)
				cout << endl << "Opcao invalida." << endl;
		}
		
		// Realiza o comando de acordo com a opcao.
		switch(op) {
			// Verifica se a lista esta vazia.
			case 1:
				if(lista->isEmpty())
					cout << endl << "Lista esta vazia." << endl;
				else 
					cout << endl << "Lista nao vazia." << endl;
				break;
				
			// Imprime o tamanho da lista.
			case 2:
				cout << endl << "Numero de elementos: " << lista->getSize() << "." << endl;
				
			// Insere o valor desejado no inicio da lista.
			case 3:
				cout << endl << "Insira o valor a ser inserido: " << endl;
				cin >> element;
				lista->addInicio(element);
				cout << endl << "Valor inserido." << endl;
				break;
				
			// Insere o valor desejado no meio da lista.
			case 4: 
				cout << endl << "Insira o valor a ser inserido na lista: " << endl;
				cin >> element;
				cout << endl << "Insira a posicao onde voce quer inserir o valor: " << endl;
				cin >> pos;
				lista->addMeio(element,pos);
				cout << endl << "Valor inserido na posicao desejada." << endl;
				break;
				
			// Insere o valor no final da lista
			case 5:
				cout << endl << "Insira o valor a ser inserido na lista: " << endl;
				cin >> element;
				lista->addFim(element);
				cout << endl << "Valor inserido no final da lista." << endl;
				break;
				
			// Insere o valor ordenadamente.
			case 6:
				cout << endl << "Insira o valor a ser inserido na lista: " << endl;
				cin >> element;
				lista->addOrdenado(element);
				cout << endl << "Valor inserido ordenadamente." << endl;
				break;
				
			// Remove o elemento da lista.
			case 7:
				cout << endl << "Insira o valor a ser removido: " << endl;
				cin >> element;
				lista->remove(element);
				cout << endl << "Valor removido." << endl;
				break;
				
			// Imprime os elementos da lista.
			case 8:
				cout << endl << "Elementos da fila: ";
				lista->print();
				break;
			
			// Busca um elemento na lista.
			case 9:
				cout << endl << "Insira o valor a ser buscado na lista: " << endl;
				cin >> element;
				if (lista->search(element))
					cout << endl << "Valor contido a lista." << endl;
				else
					cout << endl << "Valor nao contido na lista." << endl;
				break;
			
			// Imprime os elementos da lista recursivamente.
			case 10:
				cout << endl << "Elementos da fila: ";
				lista->printRec(lista);
				break;
				
			// Remove um elemento recursivamente.
			case 11:
				cout << endl << "Insira o valor a ser removido da lista: " << endl;
				cin >> element;
				lista->removeRec(lista, element);
				cout << endl << "Valor removido da lista.";
				break;
				
			// Verifica se duas listas sao iguais.
			case 12:
				if (lista->listasIguais(l1, l2)) 
					cout << endl << "Listas iguais." << endl;
				else
					cout << endl << "Listas nao iguais." << endl;
				break;
				
			// Verifica se duas listas sao iguais recursivamente.
			case 13: 
				if (lista->listasIguaisRec(l1, l2))
					cout << endl << "Listas iguais." << endl;
				else
					cout << endl << "Listas nao iguais." << endl;
				break;
			
			// Sair do programa.
			case 14:
				exit(0);
			
			default:
				cout << endl << "Opcao invalida." << endl;
				break;
		}
		
		
	}
	return 0;
}
