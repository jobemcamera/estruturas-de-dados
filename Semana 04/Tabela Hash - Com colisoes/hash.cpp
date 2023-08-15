#include <iostream>
#include "hash.h"
using namespace std;

int Hash::FuncaoHash(Aluno aluno)
{
  return (aluno.obterRa() % max_posicoes); // resto da divisao do RA do aluno pela maxima posicoes do vetor
}

Hash::Hash(int tam_vetor, int max)
{
  quant_itens = 0;
  max_itens = max;
  max_posicoes = tam_vetor;
  estrutura = new Aluno[tam_vetor]; // construtor padrao do aluno (-1, " ")
}

Hash::~Hash()
{
  delete[] estrutura;
}

bool Hash::estaCheio()
{
  return (quant_itens == max_itens);
}

int Hash::obterTamanhoAtual()
{
  return (quant_itens);
}

void Hash::inserir(Aluno aluno)
{
  if (estaCheio())
  {
    cout << "A tabela Hash esta cheia!\n";
    cout << "O aluno nao pode ser inserido.\n";
  }
  else
  {
    int local = FuncaoHash(aluno);

    // se for > 0 signifca que já adicionei nesse local, se for < 0 (-1 ou -2) está vazio ou disponível, então posso inserir
    while (estrutura[local].obterRa() > 0)
    {
      local = (local + 1) % max_posicoes;
    }

    estrutura[local] = aluno;
    quant_itens++;
  }
}

void Hash::deletar(Aluno aluno)
{
  int local = FuncaoHash(aluno);
  bool encontrado = false;

  // procura posicões que não são -1 (vazio)
  while (estrutura[local].obterRa() != -1)
  {
    if (estrutura[local].obterRa() == aluno.obterRa())
    {
      cout << "Aluno removido!\n";
      estrutura[local] = Aluno(-2, " "); // (-2) = removido = disponível
      quant_itens--;
      encontrado = true;
      break;
    }
    local = (local + 1) % max_posicoes;
  }

  if (!encontrado)
  {
    cout << "Aluno nao encontrado!\n";
    cout << "Nenhum aluno foi removido.\n";
  }

  if (estrutura[local].obterRa() != -1)
  {
    estrutura[local] = Aluno(-1, " ");
    quant_itens--;
  }
}

void Hash::buscar(Aluno &aluno, bool &busca)
{
  int local = FuncaoHash(aluno);
  busca = false;

  // procura posicões que não são -1 (vazio)
  while (estrutura[local].obterRa() != -1)
  {
    if (estrutura[local].obterRa() == aluno.obterRa())
    {
      busca = true;
      aluno = estrutura[local];
      break;
    }
    local = (local + 1) % max_posicoes;
  }
}

void Hash::imprimir()
{
  cout << "Tabela Hash: " << endl;

  for (int i = 0; i < max_posicoes; i++)
  {
    // só imprime os itens que existem. Disponíveis e vazios são ignorados (-2 e -1)
    if (estrutura[i].obterRa() > 0)
    {
      cout << "Indice " << i << ":" << estrutura[i].obterRa() << " " << estrutura[i].obterNome() << endl;
    }
  }
}