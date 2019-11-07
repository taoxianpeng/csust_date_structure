#include <iostream>
#include <cstdio>
#define MAXSIZE 100
using namespace std;

typedef struct Stack
{
    int top;
    int elemt[MAXSIZE];
} Stack;

void InitStack(Stack &stack)
{
    stack.top = -1;
}
bool isEmpty(Stack s)
{
    if (s.top > -1)
        return false;
    return true;
}
int Pop(Stack *s)
{
    int data;
    if (s->top > -1)
    {
        data = s->elemt[s->top];
        s->top--;
        return data;
    }
    return -1;
}
int Push(Stack *s, int data)
{
    if (s->top < MAXSIZE - 1)
    {
        s->elemt[++s->top] = data;
        return 1;
    }
    return 0;
}
int main()
{
    Stack s;
    int num;
    int res;
    const int EOS = 8;
    InitStack(s);
    cin >> num;
    while (num)
    {
        Push(&s, num % EOS);
        num /= EOS;
    }
    while (!isEmpty(s))
    {
        cout << Pop(&s);
    }
    cout << "\n";

    getchar();
    return 0;
}