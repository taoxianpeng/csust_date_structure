#include <iostream>
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

int getWeight(BTree *s){
    int result=0;
    queue<BTree *> que;
    que.push(s);
    while(!que.empty()){
        int count = que.size();
        result = max(count,result);
        while(count--){
            BTree *temp = que.front();
            que.pop();
            if(temp->lchild)
                que.push(temp->lchild);
            if(temp->rchild)
                que.push(temp->rchild);
        }
    }
    return result;
}
int count_all(BTree *k){
    //递归统计结点数
    if(k==NULL) 
        return 0;
    int Ln=count_all(k->lchild);
    int Rn=count_all(k->rchild);
    return Ln+Rn+1;
}

int count_leaf(BTree *k){
    //递归统计叶子结点
    if(k==NULL) return 0;
    if(k->lchild == NULL && k->rchild ==NULL)
        return 1;
    int Ln=count_leaf(k->lchild);
    int Rn=count_leaf(k->rchild);
    return Ln+Rn;
    
}
int main()
{
    Elemtype st[100] = {'1','2','3','4','5','6','7','8','9','x'};
    int size = 10;
    int sum = 0 ;
    BTree *s=new BTree();
    level_creatBTree(s,st,size);
    pre_visit(s);
    cout << '\n';
    int h = gethight(s);
    int w = getWeight(s);
    cout << "max hight of btree is: " << h << endl;
    cout << "max weight of btree is: " << w << endl;


    sum = count_all(s);
    cout << "sum of all elem is : " << sum << endl;
    int s2 = count_leaf(s);
    cout << "sum of leaf elem is : " << s2 << endl;
    return 0;
}