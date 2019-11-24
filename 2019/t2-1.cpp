#include <iostream>
using namespace std;


int Find(int *list,int length, int num){
    int left=0, right=length-1;
    int insert_pos;
    int mid=-1;
    while(left<=right){
        mid=left+(right-left)/2;
        if(list[mid] == num)
            return 1;
        if(list[mid] >num)
            right = mid-1;
        if(list[mid]< num)
            left = mid+1;
    }
    if(mid!=-1){
        if(list[mid]>num)
        /*若最终mid位置的数字比查找数字大
          则最终插入的位置在mid的位置上
          若是~小
          则插入到mid的后面也就是mid+1的位置
        */ 
            insert_pos=mid;
        else
            insert_pos=mid+1;                
        for(int i=length-1; i>=insert_pos; i--){
            list[i+1]=list[i];
        }
        list[insert_pos]=num;
        return 2;  
    }
    return 0;

}
int main()
{
    int list[100] = {1,2,3,4,5,6,7,9,11,12};
    int elemt = 13;
    int count = 10;
    int sign = Find(list,count,elemt);
    switch (sign)
    {
    case 0:
        cout << "list is empty!" << endl;
        break;
    case 1:
        cout << "find !" << endl;
        break;
    case 2:
        cout << "don't find,then this elemt"<<"("<< elemt << ")"<<" inserted into list!"<<endl;
        count++;
        break;
    default:
        cout << "error "+sign <<endl;
        break;
    }

    for (int i = 0; i < count; i++)
    {
        cout << list[i];
        if(i < count-1) cout << " ";
    }
    
    return 0;
}