#include <iostream>

using namespace std;

// Parametro por VALOR
void troca_por_valor(int a, int b) {
  int temp;
  temp = a;
  a = b;
  b = temp;
}

// Parametro por REFERENCIA
void troca_por_referencia(int &a, int &b) {
  int temp;
  temp = a;
  a = b;
  b = temp;
}

int main()
{
  int a=2, b=3;
  cout << "Antes: a = " << a << " b = " << b << endl;
  troca_por_valor(a,b);
  cout << "Depois: a = " << a << " b = " << b << endl;

  cout << "\n" << endl;

  cout << "Antes: a = " << a << " b = " << b << endl;
  troca_por_referencia(a,b);
  cout << "Depois: a = " << a << " b = " << b << endl;

  return 0;
}