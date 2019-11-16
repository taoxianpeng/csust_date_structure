#include <iostream>
#include <stack>
using namespace std;


int main()
{
    string str;
    stack<char> st;
    cin >> str;
    int size = str.size();
    for(int i=0; i<size/2; i++)
       st.push(str[i]);
    int k= size/2; //str的下标是从0开始的
    if(size % 2 != 0) k++;
    for(;k<size; k++){
        char c=st.top();
        if(c!=str[k]){
            cout <<"no" << endl;
            break;
        }else{
            st.pop();
        }
    }
    if(st.empty()) cout << "yes"<<endl;
    
    return 0;
}