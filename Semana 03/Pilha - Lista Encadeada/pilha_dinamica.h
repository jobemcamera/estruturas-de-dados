// Pilha Dinâmica = Dynamic Stack

typedef int TipoItem;

struct No // Node
{
  TipoItem valor;
  No *proximo;
};

class pilhadinamica
{
private:
  No *NoTopo;

public:
  pilhadinamica();  // construtor
  ~pilhadinamica(); // destrutor
  bool isEmpty();
  bool isFull();
  void push(TipoItem item);
  TipoItem pop();
  void print();
};
