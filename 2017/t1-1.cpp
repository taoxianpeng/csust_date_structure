#include <iostream>
#include <cstdio>   
using namespace std;
// 1.设计判断单链表中结点是否关于中心对称算法。例如，某链表的各个节点数据分别 
// 为c、s、U、 s、T、s、U、s、c即为中心对称。 

typedef struct LNode
{
    /* data */
    char elemt;
    LNode *next;
}LNode;

//此函数为输入链表
LNode* Read(){
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

//此函数为打印链表
void Print(LNode *l){
    LNode *s=l;
    while(s->next){
        cout<< s->next->elemt<<" ";
        s=s->next;
    }
}

bool is_Centrosymmetric(LNode *lnode){
    LNode *p= lnode;
    // 前指针f指向p所在位置，后指针r指向头节点，
    // 然后前后指针同时移动，直到前指针到末尾，
    // 判断后指针是否与p相同。
    //诺后指针位置与p重合则结束。
    LNode *f,*r;
     
    while(p){
        f=lnode;
        r=p;
        while (r->next)
        {
            f=f->next;
            r=r->next;
        }
        if(f->elemt != p->elemt) return false;
        if (p!=lnode && (f==p || f==p+1)) break;
        p=p->next;
    }
    return true;
}
int main(){
    LNode *lnode;
    lnode = Read();

    /*code*/
    if (is_Centrosymmetric(lnode))
        cout<<"yes"<<endl;
    else
        cout<<"no"<<endl;
    
    
    /*code*/
    
    return 0;
}
