#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <cctype>
#include <stdexcept>

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

bool isParenthesis(char c) {
    return c == '(' || c == ')';
}

int evaluateInfix(const std::string& infix) {
    std::stack<int> operands;
    std::stack<char> operators;
    std::istringstream tokens(infix);
    std::string token;

    while (tokens >> token) {
        if (isdigit(token[0])) {
            operands.push(std::stoi(token));
        } else if (isOperator(token[0])) {
            while (!operators.empty() && precedence(operators.top()) >= precedence(token[0])) {
                if (operands.size() < 2) {
                    throw std::runtime_error("Invalid expression");
                }
                int right = operands.top(); operands.pop();
                int left = operands.top(); operands.pop();
                switch (operators.top()) {
                    case '+': operands.push(left + right); break;
                    case '-': operands.push(left - right); break;
                    case '*': operands.push(left * right); break;
                    case '/':
                        if (right == 0) throw std::runtime_error("Division by zero");
                        operands.push(left / right); break;
                }
                operators.pop();
            }
            operators.push(token[0]);
        } else if (token[0] == '(') {
            operators.push('(');
        } else if (token[0] == ')') {
            while (!operators.empty() && operators.top() != '(') {
                if (operands.size() < 2) {
                    throw std::runtime_error("Invalid expression");
                }
                int right = operands.top(); operands.pop();
                int left = operands.top(); operands.pop();
                switch (operators.top()) {
                    case '+': operands.push(left + right); break;
                    case '-': operands.push(left - right); break;
                    case '*': operands.push(left * right); break;
                    case '/':
                        if (right == 0) throw std::runtime_error("Division by zero");
                        operands.push(left / right); break;
                }
                operators.pop();
            }
            if (!operators.empty()) {
                operators.pop();
            } else {
                throw std::invalid_argument("Mismatched parentheses");
            }
        }
    }

    while (!operators.empty()) {
        if (operands.size() < 2) {
            throw std::runtime_error("Invalid expression");
        }
        int right = operands.top(); operands.pop();
        int left = operands.top(); operands.pop();
        switch (operators.top()) {
            case '+': operands.push(left + right); break;
            case '-': operands.push(left - right); break;
            case '*': operands.push(left * right); break;
            case '/':
                if (right == 0) throw std::runtime_error("Division by zero");
                operands.push(left / right); break;
        }
        operators.pop();
    }

    if (operands.size() != 1) {
        throw std::runtime_error("Invalid expression");
    }

    return operands.top();
}

int main() {
    std::string infix;
    std::cout << "Enter an expression: ";
    std::getline(std::cin, infix);

    try {
        int result = evaluateInfix(infix);
        std::cout << "Result: " << result << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    } catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
