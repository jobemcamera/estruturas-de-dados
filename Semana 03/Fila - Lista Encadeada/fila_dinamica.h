// Fila Dinâmica = Dynamic Queue

typedef int TipoItem;

struct No
{
  TipoItem valor;
  No *proximo;
};

class filadinamica
{
private:
  No *primeiro;
  No *ultimo;

public:
  filadinamica();  // Construtor
  ~filadinamica(); // Destrutor
  bool isEmpty();
  bool isFull();
  void push(TipoItem item);
  TipoItem pop();
  void print();
};