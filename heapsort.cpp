#include <iostream>
#define ElemType int
using namespace std;


void AdjustDown(ElemType A[], int k, int len){
    int i;
    A[0] = A[k]; //A[0]存储最一开始(进入这个函数时A[k])要调整的节点
    for(i=k*2; i<=len; i*=2){
        //若k的左孩子小于右孩子 则i指向右孩子
        if(A[i]<A[i+1]) i++;
        //若此时最大的孩子节点都小于父节点，则说明这一段已经调整好
        if(A[i]<=A[0]) break;
        else{
            //子节点大于父节点 子节点覆盖父节点
            A[k]=A[i];
            //继续往下判断，即k要移动到调整后的那个节点
            k=i;
        }
    }
    //最后将一开始要调整的节点赋值给最后一个节点 注：k指向调整好的最后一个节点
    A[k]=A[0];
}

void BulidMaxHeap(ElemType A[],int len){
    //完全二叉树的最后一个节点的父节点为 len/2 (len - 所有节点的总数)
    for (int i = len/2; i > 0; i--)
    {
        AdjustDown(A,i,len);
    }
    
}

void Swap(ElemType n1, ElemType n2){
    ElemType temp = n1;
    n1 = n2;
    n2 = temp;
}

void HeapSort(ElemType A[], int len){
    BulidMaxHeap(A,len);
    //将每次堆顶的根节点的值移到最后一位(最后一位是不断缩小一位的！)
    for (int i = len; i > 1; i--)
    {
        Swap(A[i],A[1]);
        //AdjustDown 第二个参数取1, 因为只有根节点动了，其他节点不需要调整
        AdjustDown(A,1,i-1);
    }
    
    
}

int main()
{
    ElemType A[100] = {0,5,2,7,9,0,2,5,7,1,10};
    int len =10;

    HeapSort(A,len);

    for (int i = 1; i <= len; i++)
    {
        cout << A[i];
        if(i<len-1) cout <<" ";
    }
        

    return 0;
}