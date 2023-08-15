#include <iostream>
#include "hash.h"
using namespace std;

int main()
{
  cout << "Programa gerador de Hash!\n" << endl;

  int tam_vetor, max;

  cout << "Digite o tamanho da Hash: ";
  cin >> tam_vetor;
  cout << "Digite o numero maximo de elementos: ";
  cin >> max;

  cout << "\nO fator de carga e: " << (float)max / (float)tam_vetor << "\n"<< endl;

  Hash alunoHash(tam_vetor, max);
  int opcao;
  int ra;
  string nome;
  bool busca;

  do
  { 
    cout << "\n";
    cout << "Digite 0 para parar o algoritmo." << endl;
    cout << "Digite 1 para inserir um elemento." << endl;
    cout << "Digite 2 para remover um elemento." << endl;
    cout << "Digite 3 para buscar um elemento." << endl;
    cout << "Digite 4 para imprimir a Hash." << endl;
    cin >> opcao;

    if (opcao == 1)
    {
      cout << "Qual e o RA do aluno a ser inserido? ";
      cin >> ra;
      cout << "Qual e o nome do aluno a ser inserido? ";
      cin >> nome;

      Aluno aluno(ra, nome);
      alunoHash.inserir(aluno);
    }
    else if (opcao == 2)
    {
      cout << "Qual e o RA do aluno a ser removido? ";
      cin >> ra;

      Aluno aluno(ra, " ");
      alunoHash.deletar(aluno);
    }
    else if (opcao == 3)
    {
      cout << "Qual e o RA do aluno a ser buscado? ";
      cin >> ra;

      Aluno aluno(ra, " ");
      alunoHash.buscar(aluno, busca);

      if (busca)
      {
        cout << "Aluno encontrado: " << endl;
        cout << "RA: " << aluno.obterRa() << endl;
        cout << "Nome: " << aluno.obterNome() << endl;
      }
      else
      {
        cout << "Aluno nao encontrado!" << endl;
      }
    }
    else if (opcao == 4)
    {
      alunoHash.imprimir();
    }
    else
    {
      cout << "Digite uma opcao valida: 0, 1, 2, 3 ou 4" << endl;
    }
  } while (opcao != 0);

  return 0;
}