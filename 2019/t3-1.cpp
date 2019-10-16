#include <iostream>
#define MAXSIZE 100
using namespace std;


typedef struct Stack{
    int top=-1;
    int elemt[MAXSIZE];
}Stack;

void InitStack(Stack *stack){
    stack = new Stack();
}
bool isEmpty(Stack s){
    if(s.top < 0) return true; else return false;
}
int Pop(Stack *s){
    int data;
    if(s->top>-1){
        data = s->elemt[s->top];
        s->top--;
        return data;
    }
    return -1;
}
int Push(Stack *s, int data){
    if(s->top<MAXSIZE-1){
        s->elemt[++s->top]=data;
        cout << s->top << endl;
        return 1;
    }
    return 0;

}
int main()
{
    Stack s;
    int num;
    int info;
    InitStack(&s);
    while(cin >> num){
        info = Push(&s,num);
        switch (info)
        {
        case 0:
            cout << "stack is full !" << endl;
            break;
        case 1:
            cout << s.elemt[s.top] <<" data was pushed !" << endl;
        default:
            break;
        }
        if(cin.get()=='\n') break;
    }
    while (s.top > -1)
    {
        cout << Pop(&s);
        if(s.top!=-1) cout << " ";
    }

    
    return 0;
}