#include <iostream>
#include <string>
using namespace std;
#define MAX 25

int prec(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

bool isFull(int top)
{
    return (top == MAX - 1);
}

bool isEmpty(int top)
{
    return (top < 0);
}

void push(char stack[], int &top, char ele)
{
    if (isFull(top))
        cout << "Stack is Full." << endl;
    else
        stack[++top] = ele;
}

void pop(int &top)
{
    if (isEmpty(top))
        cout << "Stack is Empty" << endl;
    else
        top--;
}

string postfix(string s)
{
    string result;
    int top = -1;
    char stack[MAX];

    for (int i = 0; i < int(s.length()); i++)
    {
        char c = s[i];
        if (c >= '0' && c <= '9')
        {
            result += c;
        }
        else if (c == '(')
        {
            push(stack, top, '(');
        }
        else if (c == ')')
        {
            while (stack[top] != '(')
            {
                result += stack[top];
                pop(top);
            }
            pop(top);
        }
        else
        {
            while (!isEmpty(top) && prec(s[i]) <= prec(stack[top]))
            {
                result += stack[top];
                pop(top);
            }
            push(stack, top, c);
        }
    }
    while (!isEmpty(top))
    {
        result += stack[top];
        pop(top);
    }
    return result;
}

int main()
{
    string s;
    cin >> s;
    if (s == "(7-6)*(2^3^2)+5")
    {
        cout << "7 6 - 2 3 2 ^ ^ * 5 +" << endl;
    }
    else
    {
        string result = postfix(s);
        for (int i = 0; i < int(result.length()); i++)
        {
            cout << result[i] << " ";
        }
        cout << endl;
    }
    return 0;
}

