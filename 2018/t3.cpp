#include <iostream>
#include <stdlib.h>
#include <queue>
#define Elemtype char
using namespace std;

struct BTree
{
    Elemtype data;
    struct BTree *lchild;
    struct BTree *rchild;
};

void level_creatBTree(BTree *bt,Elemtype data[],int size){
    //层次遍历建树
    queue<BTree*> que;
    BTree *p;
    que.push(bt);
    if(data[0]){
        p=que.front();
        que.pop();
        p->data=data[0];
        for(int i=1; i<size; i++){
            if(p->lchild == NULL){
                p->lchild = new BTree();
                p->lchild->data = data[i];
                que.push(p->lchild);
                continue;
            }
            if(p->rchild == NULL){
                p->rchild = new BTree();
                p->rchild->data = data[i];
                que.push(p->rchild);
                p=que.front();
                que.pop();
            }
        }
    }
    
}

void pre_visit(BTree *p){

    if(p!=NULL){
        cout << p->data << " ";
        pre_visit(p->lchild);
        pre_visit(p->rchild);
    }
}

int gethight(BTree *s){
    if(s==NULL)
        return 0;
    int Lh = gethight(s->lchild);
    int Rh = gethight(s->rchild);
    return Lh>Rh?Lh+1:Rh+1;
}
int main()
{
    Elemtype st[100] = {'1','2','3','4','5','6','7','8'};
    int size = 8;
    BTree *s=new BTree();
    level_creatBTree(s,st,size);
    pre_visit(s);
    cout << '\n';
    int h = gethight(s);
    cout << "max hight of btree is: " << h << endl;

    return 0;
}