#include <iostream>
#include "pilha_dinamica.h"

using namespace std;

int main()
{
  pilhadinamica pilha;
  TipoItem item;
  int opcao;
  cout << "Programa gerador de pilha:\n";

  do
  {
    cout << "Digite 0 para parar o programa!\n";
    cout << "Digite 1 para inserir um elemento!\n";
    cout << "Digite 2 para remover um elemento!\n";
    cout << "Digite 3 para imprimir a pilha!\n";
    cin >> opcao;
    if (opcao == 1)
    {
      cout << "Digite o elemento a ser inserido:\n";
      cin >> item;
      pilha.push(item);
    }
    else if (opcao == 2)
    {
      item = pilha.pop();
      cout << "Elemento Removido: " << item << endl;
    }
    else if (opcao == 3)
    {
      pilha.print();
    }

  } while (opcao != 0);

  return 0;
}
