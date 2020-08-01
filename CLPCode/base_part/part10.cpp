//
//  part10.cpp
//  CLPCode
//
//  Created by 陈俊 on 2020/4/16.
//  Copyright © 2020 陈俊. All rights reserved.
//

// C++ STL的使用
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

// 使用sort函数
int a[105];
void part10_test0()
{
    int n;
    scanf("%d",&n);
    
    for (int i=0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    sort(a, a+n);
    
    for (int i=0; i<n; i++) {
        printf("%d ",a[i]);
    }
}


void part10_test1()
{
    priority_queue<int> queue;
    queue.push(1);
    queue.push(2);
    queue.push(5);
    
    while (!queue.empty()) {
        printf("%d ", queue.top());
        queue.pop();
    }
}


void part10_test2()
{
    vector<int> v;
    for (int i=1; i<=9; i++) {
        v.push_back(i*i); // 加入vector中
    }
    
    for (int i=1; i<=9; i++) {
        cout << v[i] << " "; // 访问vector的元素
    }
}

void part10_test3()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(7);
    
    while (!q.empty()) {
        cout << q.front() << " "; // 取队首元素
        q.pop(); // 出队
    }
    
    cout << endl;
}

void part10_test4()
{
    stack<int> s;
    s.push(3);
    s.push(6);
    s.push(8);
    
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

void part10_test5()
{
    map<string,int> dict; // 定义一个map
    dict["tom"] = 1;
    dict["Jone"] = 2;
    dict["Mary"] = 1;
    
    if(dict.count("Mary")) {
        cout << "Mary is in class " << dict["Mary"] << endl;
    }
    
    for (map<string,int>::iterator it = dict.begin(); it != dict.end(); it++) {
        cout << it->first << " is in class " << it->second << endl;
    }
    dict.clear(); // 清空map
}


void part10_test6()
{
    set<string> country;
    country.insert("china");
    country.insert("French");
    country.insert("America");
    country.insert("Itali");
    
    set<string>::iterator it;
    for (it = country.begin(); it != country.end(); it++) {
        cout << *it << " ";
    }
    
    cout << endl;
    
    country.erase("America");
    
    if (country.count("china")) {
        cout << "china is number " << country.count("china") << endl;
    }
    
    country.clear();
}

int main_cp_part10()
{
    part10_test6();
    return 0;
}
