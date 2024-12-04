#include <iostream>
using namespace std;

int main() {
  char op;
  float num_1 , num_2;

  cout << "Enter first number: ";
  cin >> num_1;

  cout << "Input operator: +, -, *, /: ";
  cin >> op;

  cout << "Enter second number: ";
  cin >> num_2;

  switch(op) {

    case '+':
      cout << num_1 << " + " << num_2 << " = " << num_1 + num_2;
    break;

    case '-':
     cout << num_1 << " - " << num_2 << " = " << num_1 - num_2;
    break;

    case '*':
     cout << num_1 << " * " << num_2 << " = " << num_1 * num_2;
    break;

    case '/':
      cout << num_1 << " / " << num_2 << " = " << num_1 / num_2;
    break;

    default:

      cout << "Error!";
    break;
             }

   return 0;

}
