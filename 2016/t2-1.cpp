#include <iostream>
#define ElemType int
using namespace std;


typedef struct BTreeNode{
    ElemType data;
    BTreeNode *lchild;
    BTreeNode *rchild;
};

BTreeNode* createNode(ElemType data){
    BTreeNode *res;
    res = new BTreeNode();
    res->lchild=NULL;
    res->rchild=NULL;
    res->data = data;
    return res;
}

void In_order_traversal(BTreeNode *root){
    if(root != NULL){
        In_order_traversal(root->lchild);
        cout << root->data;
        In_order_traversal(root->rchild);
    }
}

BTreeNode* CreatBTree(ElemType list[],int size){
    BTreeNode *head,*p;
    BTreeNode *queue[100];
    int front,rear;
    front=rear=0;
    head = createNode(list[0]);
    queue[front++] = head;
    p=queue[rear];
    for(int i=1; front != rear && i<size; i++){
        cout << p->data <<" - front : "<<front<<" rear : "<<rear <<endl;
        if(p->lchild == NULL) {
            p->lchild=createNode(list[i]);
            queue[front++] = p->lchild;
            continue;
        }
        if(p->rchild == NULL) {
            p->rchild=createNode(list[i]);
            queue[front++] = p->rchild;
            continue;

        }
        p=queue[++rear];
    }
    return head;
}

void Read(ElemType *l){
    int num;
    int i=0;
    while(cin >> num){
        l[i++] = num;
        if(cin.get() == '\n') break;
    }
}
int main()
{
    int size;
    BTreeNode *btree;
    ElemType A[100];
    cin >> size;
    Read(A);
    btree = CreatBTree(A, size);
    In_order_traversal(btree);
    return 0;
}