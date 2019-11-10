#include <iostream>
#define MGragh int
using namespace std;


int count(MGragh mg[10][10], int num){
    // 横着扫描为出度
    int sum = 0;
    for(int i=0; i<num; i++){
        for(int j=0; j<10; j++){
            if(mg[i][j] > 0){
                sum+=1;
                break;
            }
        }
    }
    return sum;
}
int main()
{
    // 10*10的二维数组表示邻接矩阵
    // 0为两点之间没有边，1为两点之间有边连接
    MGragh mg[10][10] = {
        {0,1,0,0,0,0,1,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,1,0,0,0,0,1,0,0,0},
        {0,1,0,0,0,0,1,0,0,0},
        {0,1,0,0,0,0,1,0,0,0},
        {0,1,0,0,0,0,1,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,1,0,0,0,0,1,0,0,0},
        {0,0,0,0,0,0,1,0,0,0},
        {0,1,0,0,0,0,1,0,0,0}
    };

    cout <<  count(mg,10) << endl;

    int t;
    cin >> t;
    return 0;
}