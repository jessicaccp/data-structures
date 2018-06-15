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
Pilha* questao1 (Pilha *p1, Pilha *p2) {
	Pilha *p3;
	p3->criarPilha();

	while ((not p1->isEmpty()) and (not p2->isEmpty())) {
		if (p1->isEmpty())
			p3->push(p2->pop());
		else if (p2->isEmpty())
			p3->push(p1->pop());
		else if (p1->top() < p2->top())
			p3->push(p1->pop());
		else
			p3->push(p2->pop());
	}
	
	return p3;
}

/* funcao principal */
int main () {
}
