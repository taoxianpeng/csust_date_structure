#include <iostream>
#include <cstdio>
using namespace std;


typedef struct LNode
{
    /* data */
    char elemt;
    LNode *next;
}LNode;

//此函数为输入链表
LNode* Read(){
    cin.clear(); //魔性的cin
    //一行输入多个元素，用空格分隔开
    char r;
    LNode *res=new LNode();
    LNode *k=res;

    while(cin>>r){      
        k->next = new LNode();
        k=k->next;
        k->elemt=r;
    
        if(cin.get()=='\n') break;
    }
    return res->next;
}

//此函数为打印链表(带头结点)
void Print(LNode *l){
    LNode *s=l;
    while(s->next){
        cout<< s->next->elemt<<" ";
        s=s->next;
    }
}

void merge(LNode *l1, LNode *l2, LNode *res){
    LNode *p1 = l1, *p2 = l2;
    while(p1 != NULL && p2 != NULL){
        res->next = new LNode();
        res=res->next;
        if(p1->elemt<p2->elemt){
            res->elemt = p1->elemt;
            p1=p1->next;
        }else{
            res->elemt = p2->elemt;
            p2=p2->next;
        }
    }
    while (p1 != NULL){
        res->next = new LNode();
        res=res->next;
        res->elemt = p1->elemt;
        p1=p1->next;
    }
    while(p2 != NULL){
        res->next = new LNode();
        res->elemt = p2->elemt;
        p2=p2->next;
        res = res->next;
    }
}

int main()
{
    LNode *l1,*l2,*res=new LNode();
    l1=Read();
    l2=Read();
    merge(l1,l2,res);
    Print(res);
    
    
    int num;
    cin >> num;
    return 0;
}