#include <iostream>
using namespace std;

int main()
{
  int count;
  int number;
  int sum;

  do
  {
    cout << "Insira um novo número: " << endl;
    cin >> number;

    sum += number;
    count++;
  } while (number != 0);

  return 0;
}