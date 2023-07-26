#include <iostream>
using namespace std;

void valor_alocando_memoria(int *p) // ponteiro por valor
{
  p = new int; // aponto para outra região de memória
  *p = 7; // trocando o valor localmente
}

void valor_modificando_memoria(int *p)
{
  *p = 8; // trocando o valor globalmente sem alterar a região de memória
}

void referencia(int *&p) // ponteiro por referência
{
  p = new int; // aponto para outra região de memória
  *p = 9; 
}

int main()
{
  int a = 1;
  int b = 2;
  int c = 3;
  int *p1 = &a;
  int *p2 = &b;
  int *p3 = &c;

  cout << "Antes: " << p1 << " " << p2 << " " << p3 << endl;
  cout << "Antes: " << *p1 << " " << *p2 << " " << *p3 << endl;
  cout << endl;

  valor_alocando_memoria(p1);
  valor_modificando_memoria(p2);
  referencia(p3);

  cout << "Depois: " << p1 << " " << p2 << " " << p3 << endl;
  cout << "Depois: " << *p1 << " " << *p2 << " " << *p3 << endl;
  cout << "Depois: " << a << " " << b << " " << c << endl;
  cout << endl;

  return 0;
}

// Conclusão:

// A função 'valor_alocando_memoria' NÃO ALTERA o valor da variável que estava fora da função.
// A função também não modifica o endereço para o qual o ponteiro de fora da função estava apontando.
// Isso pode ser explicado porque o parâmetro foi passado por valor. Nada do que foi feito internamente afeta as variáveis de fora.

// A função 'valor_modificando_memoria' ALTERA o valor da variável que estava fora da função.
// A passagem de parâmetro foi por valor, mas estamos modificando o endereço de memória para onde o ponteiro aponta.
// A variável 'b' usava essa região de memória e a variável 'p2' apontava para ela. Nesse caso, ambas foram afetadas. 

// A função 'referencia' ALTERA o endereço para onde aponta a variável 'p3', pois essa foi passada como referência.
// A variável 'c' não é afetada, pois continua utilizando o endereço antigo de memória.
// Nesse caso, o valor apontado por 'p3' se torna diferente do valor da variável 'c'.