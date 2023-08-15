#include "aluno.h"

class Hash
{
private:
  int FuncaoHash(Aluno aluno); // recebe o objeto Aluno
  int max_itens;               // maximo de itens a colocar
  int max_posicoes;            // tamanho do vetor
  int quant_itens;             // quantos itens eu ja coloquei no vetor
  Aluno *estrutura;            // vetor para guardar a Hash que tem os itens da classe Aluno

public:
  Hash(int tam_vetor, int max);
  ~Hash();
  bool estaCheio();
  int obterTamanhoAtual();
  void inserir(Aluno aluno);
  void deletar(Aluno aluno);
  void buscar(Aluno &aluno, bool &busca); // por referencia, mudando aqui tambem muda na main
  void imprimir();
};