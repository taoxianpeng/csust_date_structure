#include <iostream>
using namespace std;

struct ElemType
{
    int key;
};

void hill_sort(ElemType A[],int n){
    int j;
    for (int dk=n/2;dk>=1; dk/=2){
        for (int i = dk+1;i<=n; i++)
        {
            if (A[i].key<A[i-dk].key)
            {
                A[0]=A[i];
                for (j=i-dk;j>0&&A[0].key<A[j].key;  j-=dk)
                {
                    A[j+dk]=A[j];
                }
                A[j+dk]=A[0];
            }
            
        }
        
    }
}

int main()
{
    ElemType list[100];
    int n=10;
    for (int j = 1; j < n+1; j++)
    {
        list[j].key= 10 - j;
    }
    
    xier_sort(list,n);
    for (int i = 1; i <n+1; i++)
    {
        cout << list[i].key;
        if(i<n) cout << " ";
    }
    
    return 0;
}