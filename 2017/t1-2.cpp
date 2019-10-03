#include <iostream>
#include <vector>   
using namespace std;

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
    vector<char> list;
    LNode *p = lnode;
    while(p){
        list.push_back(p->elemt);
        p=p->next;
    }
    
    int listSize=list.size()-1;
    
    for(int i=0; i<listSize/2; i++){
        //cout <<list[i]<<" | "<<list[listSize-i]<<endl;
        if(list[i]!=list[listSize-i])
            return false;
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
