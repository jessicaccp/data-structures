#include<iostream>
#include<string>
using namespace std;

/* estrutura e metodos do nodo */
class Nodo {
	private:
	int info;
	Nodo *ant, *prox;
	
	public:
	int getInfo() {
		return info;
	}
	
	void setInfo(int info) {
		this->info = info;
	}
	
	Nodo* getAnt() {
		return ant;
	}
	
	void setAnt(Nodo *ant) {
		this->ant = ant;
	}
	
	Nodo *getProx () {
		return prox;
	}
	
	void setProx(Nodo *prox) {
		this->prox = prox;
	}
};

/* estrutura e metodos da lista encadeada */
class Lista {
	private:
	Nodo *head;
	
	public:
	Nodo* getHead() {
		return head;
	}
	
	void setHead(Nodo *head) {
		this->head = head;
	}
	
	/* insere novo elemento no final da lista */
	void insert(int info) {
		Nodo *novo = new Nodo();
		novo->setInfo(info);
		novo->setProx(nullptr);
		
		Nodo *aux = head;
		if (not isEmpty()) {
			while (aux->getProx() != nullptr)
				aux = aux->getProx();
			aux->setProx(novo);
			novo->setAnt(aux);
		}
		else {
			novo->setAnt(nullptr);
			head = novo;
		}
	
	}
	
	/* remove elemento com determinada info da lista */
	bool remove(int info) {
		Nodo *aux = head;
		
		if (not isEmpty()) {
			while (aux != nullptr) {
				if (aux->getInfo() == info) {
					Nodo *toDelete = aux;
					if (toDelete->getProx() != nullptr)
						toDelete->getProx()->setAnt(toDelete->getAnt());
					if (toDelete->getAnt() != nullptr)
						toDelete->getAnt()->setProx(toDelete->getProx());
					else
						head = toDelete->getProx();
					toDelete->setProx(toDelete);
					toDelete->setAnt(toDelete);
					delete toDelete;
					return true;
				}
				aux = aux->getProx();
			}
		}
		
		return false;
	}
	
	/* checa se a lista esta vazia */
	bool isEmpty() {
		if (head == nullptr)
			return true;
		return false;
	}
	
	/* exibe os valores presentes na lista */
	void print() {
		Nodo *aux = head;
		while (aux != nullptr) {
			cout << aux->getInfo() <<  " ";
			aux = aux->getProx();
		}
		cout << endl;
	}
	// busca
	// liberar lista
	// inserir ordenado
	// getSize
	
};

/* estrutura e metodos da pilha */
class Pilha {
	private:
	Nodo *topo;
	
	public:
	Nodo* getTopo() {
		return topo;
	}
	
	void setTopo(Nodo *topo) {
		this->topo = topo;
	}
	
	/* inicializa o ponteiro do topo da pilha */
	void criarPilha() {
		topo = nullptr;
	}
	
	/* remove todos os elementos da pilha */
	void clear() {
		// enquanto o topo nao for nulo, remove da pilha
		while (topo != nullptr)
			pop();
	}
	
	/* verifica se a pilha esta vazia ou nao */
	bool isEmpty() {
		// se o topo for nulo, pilha esta vazia
		if (topo == nullptr)
			return true;
		// se nao, pilha nao esta vazia
		return false;
	}
	
	/* insere novo elemento no topo da pilha */
	void push(int info) {
		// cria novo no e seta valor e ponteiros
		Nodo *novo = new Nodo();
		novo->setInfo(info);
		novo->setProx(nullptr);
		novo->setAnt(topo);
		
		// se esse nao for o primeiro elemento da pilha,
		// altera o ponteiro de prox do topo
		if (topo != nullptr)
			topo->setProx(novo);
		
		// atualiza o topo
		topo = novo;
	}
	
	/* remove e retorna topo da pilha */
	int pop() {
		// se a pilha estiver vazia, retorna um ponteiro nulo
		if (topo == nullptr)
			return EXIT_FAILURE;
		
		// se nao, cria-se um nodo auxiliar que recebe o topo
		Nodo *aux = topo;
		
		// atualiza-se o valor da topo para o anterior
		topo = topo->getAnt();
		
		// se o novo topo nao for um nodo nulo, altera-se seu ponteiro prox
		if (topo != nullptr)
			topo->setProx(nullptr);
		
		// faz-se aux apontar para si mesmo, salva sua info e deleta da memoria
		aux->setAnt(aux);
		aux->setProx(aux);
		int auxInfo = aux->getInfo();
		delete aux;
		
		// retorna o info do topo antigo
		return auxInfo;
	}
	
	/* retorna topo da pilha */
	Nodo* top() {
		return topo;
	}
	
	/* verifica o numero de elementos presentes na pilha */
	int size() {
		Nodo *aux = topo;
		int num = 0;
		
		// cria-se uma pilha auxiliar
		Pilha *pAux;
		pAux->criarPilha();
		
		// remove o topo da pilha ate a mesma estar vazia
		// enquanto isso, adiciona cada um dos nodos na pilha auxiliar
		// e conta quantos nodos existem
		while (topo != nullptr) {
			pAux->push(pop());
			num++;
		}
		
		// adiciona os nodos da pilha auxiliar de volta para a pilha
		while (pAux->getTopo() != nullptr)
			push(pAux->pop());
		
		// retorna o numero de nodos
		return num;
	}
	
	void print() {
		Nodo *aux = topo;
		while (aux != nullptr) {
			cout << aux->getInfo() << " ";
			aux = aux->getAnt();
		}
		cout << endl;
	}
};

/* estrutura e metodos da fila */
class Fila {
	private:
	Nodo *inicio, *fim;
	
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
	
	// criacao
	void criarFila() {
		inicio = fim = nullptr;
	}
	
	// destruicao
	
	// insercao de um elemento (insere no fim) - cabeca da lista
	void enfileira(int info) {
		Nodo *novo = new Nodo();
		novo->setInfo(info);
		novo->setProx(fim);
		novo->setAnt(nullptr);
		
		if (fim != nullptr)
			fim->setAnt(novo);
			
		fim = novo;
	}
	
	// remocao de um elemento (remove no comeco) - rabo da lista
	int desenfileira() {
		Nodo *aux = inicio;
		int auxInfo = aux->getInfo();
		
		inicio = inicio->getAnt();
		inicio->setProx(nullptr);
		
		aux->setProx(aux);
		aux->setAnt(aux);
		delete aux;
		
		return auxInfo;
	}
	
	void print() {
		Nodo *aux = inicio;
		while (aux != nullptr) {
			cout << aux->getInfo() << " ";
			aux = aux->getAnt();
		}
		cout << endl;
	}
	
	// localizacao de um elemento para consulta ou alteracao
	
	// ordenacao de uma lista
	// ?
	
	// intercalacao de duas listas
	void intercalar(Lista *l1, Lista *l2) {
		while ((not l1->isEmpty()) and (not l2->isEmpty())) {
			// incompleto
		}
	}
	// concatenacao de duas listas
	// divisao de uma lista em duas	
	
};



/* Questao 1: Faca uma funcao que receba duas pilhas numericas ordenadas
crescentemente a partir do topo. Ela deve retornar uma nova pilha de modo que
fique ordenada decrescentemente com o maior valor no topo. */
Pilha* questao1(Pilha *p1, Pilha *p2) {
	// cria uma nova pilha
	Pilha *p3 = new Pilha();
	p3->criarPilha();

	// enquanto as pilhas 1 e 2 nao estao vazias
	while ((not p1->isEmpty()) or (not p2->isEmpty())) {
		// adiciona topo de p2 em p3 se p1 estiver vazia
		if (p1->isEmpty())
			p3->push(p2->pop());
		// adiciona topo de p1 em p3 se p2 estiver vazia
		else if (p2->isEmpty())
			p3->push(p1->pop());
		// adiciona topo de p1 se for menor que o topo de p2
		else if (p1->top()->getInfo() < p2->top()->getInfo())
			p3->push(p1->pop());
		// adiciona topo de p2 se for menor ou igual que o topo de p1
		else
			p3->push(p2->pop());
	}
	
	// retorna a nova pilha
	return p3;
}

/* Elabore um algoritmo para verificar se um dado item esta presente em uma
pilha. Em caso positivo, o algoritmo deve fornecer tambem a posicao do item na
pilha, considerando o topo como posicao 1. A pilha deve permanecer a mesma apos
a execucao do procedimento. Use somente as funcoes PUSH e POP. */
int questao2(Pilha *p1, int info) {
	// cria uma nova pilha
	Pilha *p2 = new Pilha();
	p2->criarPilha();
	
	// seta a posicao, comecando pelo topo
	int posicao = 1;
	
	// checa enquanto a pilha nao estiver vazia
	while (not p1->isEmpty()) {
		// se o item procurado nao for o topo da pilha,
		// remove o topo da pilha 1, o empilha na pilha 2
		// e atualiza o valor da posicao do nodo de p1
		if (p1->top()->getInfo() != info) {
			p2->push(p1->pop());
			posicao++;
		}
		// se o item estiver no topo da pilha 1,
		// restaura a pilha p1 e retorna a posicao do item na pilha
		else {
			while (not p2->isEmpty())
				p1->push(p2->pop());
			return posicao;
		}
	}
	
	// caso nao encontre o item na pilha, restaura a pilha p1 e retorna zero
	while (not p2->isEmpty())
		p1->push(p2->pop());
	return 0;
}

/* Uma palavra eh um palindromo se tem a mesma sequencia de letras, quer seja
lida da esquerda para direita ou da direita para a esquerda (exemplo: ARARA).
Escreva um algoritmo para verificar se uma palavra eh um palindromo. Use
Pilhas(s) e/ou filas(s). */
bool questao3(string palavra) {
	// aux recebe o tamanho da palavra
	int aux = palavra.length();
	// cria-se as pilhas p1 e p2
	Pilha *p1 = new Pilha();
	Pilha *p2 = new Pilha();
	
	// p1 recebe a palavra do comeco ao final e p2 o inverso
	for (int i = 0; i < aux; i++) {
		p1->push(palavra[i]);
		p2->push(palavra[aux-i-1]);
	}
	
	// checa-se nodo a nodo de p1 e p2 se seus topos coincidem
	// se nao coincidirem, retorna false
	while (not p1->isEmpty()) {
		if (p1->pop() != p2->pop())
			return false;
	}
	
	// se sair do laco, eh porque coincidem e retorna true
	return true;
}

/* Utilizando uma pilha, escreva um metodo que receba um numero inteiro
positivo no formato decimal e converte este numero para o formato binario. O
metodo retorna uma lista encadeada com os digitos que fazem parte do numero em
binario. */
void questao4(int numero) {
	// implementar os metodos de lista
}

/* Faca um metodo que recebe como parametro uma chave c e remove o elemento
correspondente a essa chave caso exista na pilha. Ao final da execucao da
funcao, a pilha deve ser igual a original, exceto pela ausencia do item
removido. Utilize estruturas de filas ou pilhas como apoio. */
void questao5(Pilha *p1, int c) {
	// cria uma pilha auxiliar p2
	Pilha *p2;
	p2->criarPilha();
	
	// enquanto p1 nao esta vazia, checa o valor do topo
	while (not p1->isEmpty()) {
		// se a info do topo nao corresponder a c,
		// remove o topo de p1 e o adiciona em p2
		if (p1->top()->getInfo() != c)
			p2->push(p1->pop());
		// se a info do topo corresponder a c,
		// apenas remove o topo de p1, sem salvar na pilha auxiliar
		// e sai do laco
		else {
			p1->pop();
			break;
		}
	}
	
	// remove os valores de p2, adicionando-os novamente em p1
	while (not p2->isEmpty())
		p1->push(p2->pop());
}

/* Faca uma funcao para gerar uma fila a partir de duas filas ordenadas, a fila
final tambem ficara ordenada (merge). Ex:
F 1 ={5, 20, 30, 50}, F 2 ={1. 8. 25. 40} →
F r ={1, 5, 8, 20, 25, 30, 40, 50 } */
void questao6() {
	// implementar os metodos de fila
}

/* funcao principal */
int main () {
	Pilha *p1 = new Pilha();
	Pilha *p2 = new Pilha();
	p1->criarPilha();
	p2->criarPilha();
	p1->push(3);
	p2->push(6);
	p1->push(2);
	p2->push(5);
	p1->push(1);
	p2->push(4);
	p1->print();
	p2->print();
	Pilha *p3 = questao1(p1, p2);
	p3->print();
}
