#include <iostream>
#include "arvore_avl.h"

using namespace std;

int main()
{
  ArvoreAVL ArvoreAlunos;  // objeto da arvore AVL
  int opcao, ra, imp;
  string nome;
  bool busca = false;

  do
  {
    cout << "Digite 0 para parar o algoritmo!\n";
    cout << "Digite 1 para inserir um elemento!\n";
    cout << "Digite 2 para remover um elemento!\n";
    cout << "Digite 3 para buscar um elemento!\n";
    cout << "Digite 4 para imprimir a arvore!\n";
    cin >> opcao;

    if (opcao == 1)
    {
      cout << "Digite o nome do aluno:\n";
      cin >> nome;
      cout << "Digite o RA do aluno:\n";
      cin >> ra;
      Aluno aluno(ra, nome);
      if (ArvoreAlunos.estaCheio())
      {
        cout << "A Árvore esta cheia!\n";
        cout << "Nao foi possivel inserir o elemento!\n";
      }
      else
      {
        ArvoreAlunos.inserir(aluno);
      }
    }
    else if (opcao == 2)
    {
      cout << "Digite o RA do aluno a ser removido!\n";
      cin >> ra;
      Aluno aluno(ra, " ");
      ArvoreAlunos.remover(aluno);
    }
    else if (opcao == 3)
    {
      cout << "Digite o RA do aluno a ser buscado!\n";
      cin >> ra;
      Aluno aluno(ra, " ");
      ArvoreAlunos.buscar(aluno, busca);
      if (busca)
      {
        cout << "Aluno encontrado!\n";
        cout << "Nome: " << aluno.obterNome() << endl;
        cout << "RA: " << aluno.obterRa() << endl;
      }
      else
      {
        cout << "Aluno nao encontrado!\n";
      }
    }
    else if (opcao == 4)
    {
      cout << "Digite 1 para fazer a impressao em PRE ORDEM!\n";
      cout << "Digite 2 para fazer a impressao em ORDEM!\n";
      cout << "Digite 3 para fazer a impressao em POR ORDEM!\n";
      cin >> imp;
      if (imp == 1)
      {
        ArvoreAlunos.imprimirPreOrdem(ArvoreAlunos.obterRaiz());
      }
      else if (imp == 2)
      {
        ArvoreAlunos.imprimirEmOrdem(ArvoreAlunos.obterRaiz());
      }
      else
      {
        ArvoreAlunos.imprimirPosOrdem(ArvoreAlunos.obterRaiz());
      }
    }
  } while (opcao != 0);

  return 0;
}