#include <iostream>

int main()
{
  int number1;
  int number2;

  std::cout << "Digite o primeiro numero: ";
  std::cin >> number1;
  std::cout << "Digite o segundo numero: ";
  std::cin >> number2;

  int sum = number1 + number2;
  int sub = number1 - number2;
  int mul = number1 * number2;

  int div = number1 / number2;
  float fdiv = static_cast<float>(number1) / number2;
  int res = number1 % number2;

  std::cout << "Soma: " << sum << std::endl;
  std::cout << "Subtração: " << sub << std::endl;
  std::cout << "Multiplicação: " << mul << std::endl;
  std::cout << "Divisão (parte inteira): " << div << std::endl;
  std::cout << "Divisão (com ponto flutuante): " << fdiv << std::endl;
  std::cout << "Resto: " << res << std::endl;

  return 0;
}
