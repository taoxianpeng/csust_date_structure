#include <iostream>
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
bool isEmpty(Stack *s)
{
    if (s->top > -1)
        return false;
    return true;
}
int Pop(Stack *s)
{
    int data;
    if (isEmpty(s))
    {
        data = s->elemt[s->top];
        s->top--;
        return data;
    }
    return -1;
}
void Push(Stack *s, int data)
{
    if (s->top < MAXSIZE - 1)
    {
        s->elemt[++s->top] = data;
    }
}
void tenToEight(int num,Stack *s){
    // num表示的每次除以8后的商
    // 最后结束的条件是商为0
    // 将每次 除以8的余数 入栈
    while (num)
    {
        Push(s,num%8);
        num/=8;
    }
    
}
int main()
{
    Stack s;
    int num;
    InitStack(s);
    cin >> num;
    tenToEight(num,&s);
    while (!isEmpty(&s))
    {
        cout << Pop(&s);
    }
    cout << "\n";

    cin >> num;
    return 0;
}