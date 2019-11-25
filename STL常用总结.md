# C++ STL常用总结

[TOC]


## Vector 向量

### push_back

> 将元素添加到容器末尾

```c++
#include <vector>
#include <iostream>
using namespace stl; 
int main()
{
    vector<string> numbers;
 
    numbers.push_back("abc");
    string s = "def";
    numbers.push_back(move(s));
 
    cout << "vector holds: ";
    for (auto&& i : numbers) cout << quoted(i) << ' ';
    cout << "\nMoved-from string holds " << quoted(s) << '\n';
}
```
```
输出：
vector holds: "abc" "def" 
Moved-from string holds ""
```
### erase
> 指定删除某个位置上的元素，或时一个范围的元素

```C++ 
    vector<int> vr {1,2,3,4,5,6,7};
    //删除向量下标为2位置上的元素
    vr.erase(2);
    //删除下标2到4位置上的元素
    vr.erase(2,4);
``` 

### insert 
> 指定插入

```
    //在向量下标为2的位置插入
    vr.insert(2)
```

### size

> 返回向量的大小

```c++
#include <vector>
#include <iostream>
 
int main()
{ 
    vector<int> nums {1, 3, 5, 7};
 
    cout << "nums contains " << nums.size() << " elements.\n";
}

输出：
nums contains 4 elements.
```

### pop_back
>移除容器的最末元素。

```c++
#include <vector>
#include <iostream>
 
template<class T>
void print(T const & xs)
{
    std::cout << "[ ";
    for(auto && x : xs) {
        std::cout << x << ' ';
    }
    std::cout << "]\n";
}
 
int main()
{
    std::vector<int> numbers;
 
    print(numbers); 
 
    numbers.push_back(5);
    numbers.push_back(3);
    numbers.push_back(4);
 
    print(numbers); 
 
    numbers.pop_back();
 
    print(numbers); 
}

输出：
[ ]
[ 5 3 4 ]
[ 5 3 ]
```
### empty
> 检查容器是否无元素，即是否 begin() == end()
> 若容器为空则为 true ，否则为 false

```c++
#include <vector>
#include <iostream>
 
int main()
{
    std::cout << std::boolalpha;
    std::vector<int> numbers;
    std::cout << "Initially, numbers.empty(): " << numbers.empty() << '\n';
 
    numbers.push_back(42);
    std::cout << "After adding elements, numbers.empty(): " << numbers.empty() << '\n';
}

输出：
Initially, numbers.empty(): true
After adding elements, numbers.empty(): false
```
## stack 栈

### push

> 将元素压入栈中

```c++
    stack<int> st;
    st.push(1);
```

### top 和 pop

> .top() 访问栈顶端的元素，但是并不会删除栈顶的元素

```c++
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    // 访问栈顶
    cout << st.top() << endl;
```

> .pop() 删除栈顶元素

```c++
    stack<int> st;
    st.push(1);
    if(st.empty()){
        st.pop();
        cout << "栈顶元素删除" << endl;
    }
    else
        cout << "栈为空" << endl;
```

### empty

> 栈是否为空，为空返回true，不为空返回false

```c++
    stack<int> st.;
    st.push(1);
    if(st.empty())
        cout << "栈不为空" << endl;
    else 
        cout << "栈为空" << endl;
```

## queue 队列

### push

> 往队列尾部添加元素

```c++
    queue<int> que;
    que.push(11);
```
### front 及 pop
> .front() 访问第一个元素
> .pop() 从 queue 移除前端元素。等效地调用 c.pop_front()

```c++
    queue<int> que;
    cout << que.front() << endl;
    que.pop();
```
### size

> 返回队列当前长度

### empty

> 判断队列是否为空，为空返回true，不为空返回false

