#include <iostream>
using namespace std;

typedef struct Dqueue
{
    /* data */
    char elemt;
    Dqueue *next;
}Dqueue;

//此函数为输入链表
Dqueue* Read(){
    //一行输入多个元素，用空格分隔开
    char r;
    Dqueue *res=new Dqueue();
    Dqueue *k=res;

    while(cin>>r){      
        k->next = new Dqueue();
        k=k->next;
        k->elemt=r;
    
        if(cin.get()=='\n') break;
    }
    k->next = res->next;
    //return rear point of circul queue
    return k;
}
char Dqueue_push(Dqueue *qrear){
    char data;
    Dqueue *temp;
    data = qrear->next->elemt;
    temp = qrear->next;
    qrear->next = temp->next;
    delete(temp);
    return data;
}
void Dqueue_pop(Dqueue *&qrear, char data){
    Dqueue *pnew;
    pnew = new Dqueue();
    pnew->elemt = data;
    pnew->next = qrear->next;
    qrear->next = pnew;
    qrear=qrear->next;
}
void queue_Print(Dqueue *qrear,int count){
    cout << "*********print all*********" << endl;
    for(int i = 0; i<count; i++){
        cout << Dqueue_push(qrear);
        if(i<count-1) cout<< " ";
    }
    cout<<'\n';
 
}
int main()
{
    Dqueue *queue;
    int count;
    cin >> count;
    queue = Read();

    char data;
    cin >> data;
    Dqueue_pop(queue,data);
    count++;
    queue_Print(queue,count);    
    return 0;
}