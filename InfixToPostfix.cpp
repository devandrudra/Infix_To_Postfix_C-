#include<iostream>
using namespace std;
#include<stack>


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

int main()
{

    string infix = "K+L-M*N+(O^P)*W/U/V*T+Q"; // KL+MN*-OP^W*U/V/T*+Q+
    string exp = "a+b*(c^d-e)^(f+g*h)-i"; // abcd^e-fgh*+^*+i-
    string postfix = InfixToPostfix(infix);
    cout << postfix;
    return 0;
}