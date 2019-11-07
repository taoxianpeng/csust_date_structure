#include <iostream>
#include <cstdio>
#define ElemType int
using namespace std;

int Partition(ElemType A[],int low, int high){
    ElemType privot = A[low];
    while (low<high)
    {
        while(low<high && A[high]>=privot) --high;
        A[low] = A[high];
        while(low<high && A[low]<=privot) ++low;
        A[high] = A[low];
    }
    A[low]=privot;
    return low;
}

void QuickSort(ElemType A[],int low, int high){
    if(low < high){
        int pivotpos=Partition(A,low,high);
        QuickSort(A,low,pivotpos-1);
        QuickSort(A,pivotpos+1,high);
    }
}

int main()
{
    ElemType list[100]={0,9,8,7,6,5,4,3,2,1};
    int n=10;
    cout <<"befor sort: ";
    for (int i = 0; i < n; i++)
    {
        cout << list[i];
        if(i<n-1) cout << " ";
    }
    cout <<"\n";

    QuickSort(list,0,n-1);
    cout <<"after sort: ";
    for (int i = 0; i < n; i++)
    {
        cout << list[i];
        if(i<n-1) cout << " ";
    }

    getchar();
        
    return 0;
}