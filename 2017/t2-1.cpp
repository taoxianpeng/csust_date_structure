#include <iostream>
using namespace std;
struct LNode{
    char data;
    LNode *next;
};

//此函数为输入链表
LNode* Read(){
    //一行输入多个元素，用空格分隔开
    char r;
    LNode *res=new LNode();
    LNode *k=res;

    while(cin>>r){
        k->next = new LNode();
        k->next->next=NULL;
        k=k->next;
        k->data=r;

        if(cin.get()=='\n') break;
    }
    return res->next;
}

//此函数为打印链表
void Print(LNode *l){
    LNode *s=l;
    while(s){
        cout<< s->data<<" ";
        s=s->next;
    }
}
void merge(LNode *a,LNode *b,LNode *c){
    LNode *ar,*br,*cr;
    ar=a;
    br=b;
    cr=c;
    bool k; //b集合里面是否与此时a的数 相等false 不等true
    while (ar)
    {
        br=b;
        while (br)
        {
            if(ar->data ==br->data){
                k=false;
                break;
            }else{
                k=true;
            }

            br=br->next;
        }
        //当b里一个循环都没有找到与a中的此时元素相等 即k=true,就将此元素加入c的尾部
        if(k){
            cr->next=ar;
            cr=cr->next;
        }
        ar=ar->next;
    }
    //在a中而不在b中的元素都已经加入，最后在c的尾部加入所有b的集合
    cr->next=b;
}
int main()
{
    LNode *a,*b,*c;
    c=new LNode();
    a=Read();
    b=Read();

    merge(a,b,c);
    Print(c->next);
    return 0;
}
