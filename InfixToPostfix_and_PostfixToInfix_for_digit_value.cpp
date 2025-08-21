#include<iostream>
using namespace std;
#include<stack>
#include<math.h>


int precedence(char ch)
{
    if(ch == '+' || ch == '-') return 0;
    else if(ch == '*' || ch == '/') return 1;
    else if(ch == '^') return 2;
    else return -1;
}

string InfixToPostfix(string infix)
{
    stack<char> Stack;
    string postfix;
    for(char ch : infix)
    {
        if(ch == '(')
        {
            Stack.push(ch);
        }

        else if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
        {
            postfix += ch;
        }

        else if(ch == ')')
        {
            while(Stack.top() != '(')
            {
                postfix += Stack.top();
                Stack.pop();
            }
            Stack.pop();
        }

        else
        {
            while(!Stack.empty() && precedence(ch) <= precedence(Stack.top()))
            {
                postfix += Stack.top();
                Stack.pop();
            }

            Stack.push(ch);
        }
    }
    
    while(!Stack.empty())
    {
        postfix += Stack.top();
        Stack.pop();
    }
    return postfix;
}

int operation(int operand1, int operand2, char op)
{
    switch (op)
    {
    case '*':
        return operand2 * operand1;
        break;
    case '/':
        return operand2 / operand1;
        break;
    
    case '+':
        return operand2 + operand1;
        break;

    case '-':
        return operand2 - operand1;
        break;

    case '^':
        return pow(operand2,operand1);
        break;
    
    default:
        return 0;
    }
}

int PostfixToInfix(string postfix)
{
    stack<int> Stack;
    int result = 0;
    for(char ch : postfix)
    {
        if(ch >= '0' && ch <= '9')
        {
            Stack.push(int(ch - '0'));
        }
        else
        {
            int operand1 = Stack.top();
            Stack.pop();
            int operand2 = Stack.top();
            Stack.pop();
            Stack.push(operation(operand1, operand2, ch));
            
        }
    }
    return Stack.top();
}

int main()
{

    string infix = "2+4-6*7+(2^5-7)"; //"K+L-M*N+(O^P)*W/U/V*T+Q"; // KL+MN*-OP^W*U/V/T*+Q+
    // string exp =  //"a+b*(c^d-e)^(f+g*h)-i"; // abcd^e-fgh*+^*+i-
    string postfix = InfixToPostfix(infix);
    cout << postfix;
    cout << endl << PostfixToInfix(postfix);
    
    // cout << endl << operation('4', '5', '^');
    return 0;
}