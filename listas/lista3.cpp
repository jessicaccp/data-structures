#include<iostream>
using namespace std;

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
			return;
		
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
	
};

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

/* Questao 1: Faca uma funcao que receba duas pilhas numericas ordenadas
crescentemente a partir do topo. Ela deve retornar uma nova pilha de modo que
fique ordenada decrescentemente com o maior valor no topo. */
Pilha* questao1(Pilha *p1, Pilha *p2) {
	// cria uma nova pilha
	Pilha *p3;
	p3->criarPilha();

	// enquanto as pilhas 1 e 2 nao estao vazias
	while ((not p1->isEmpty()) and (not p2->isEmpty())) {
		// adiciona topo de p2 em p3 se p1 estiver vazia
		if (p1->isEmpty())
			p3->push(p2->pop());
		// adiciona topo de p1 em p3 se p2 estiver vazia
		else if (p2->isEmpty())
			p3->push(p1->pop());
		// adiciona topo de p1 se for menor que o topo de p2
		else if (p1->top() < p2->top())
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
	Pilha *p2;
	p2->criarPilha();
	
	// seta a posicao, comecando pelo topo
	int posicao = 1;
	
	// checa enquanto a pilha nao estiver vazia
	while (not p1->isEmpty()) {
		// se o item procurado nao for o topo da pilha,
		// remove o topo da pilha 1, o empilha na pilha 2
		// e atualiza o valor da posicao do nodo de p1
		if (p1->top() != info) {
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
	int aux = len(palavra);
	// cria-se as pilhas p1 e p2
	Pilha *p1, *p2;
	
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

/* funcao principal */
int main () {
}
