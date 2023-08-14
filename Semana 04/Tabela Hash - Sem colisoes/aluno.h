#include <iostream>
using namespace std;

class Aluno
{
private:
  int ra;
  string nome;

public:
  Aluno();                  // construtor padrao para criar a hash
  Aluno(int r, string n);
  int obterRa();
  string obterNome();
};