#include <bits/stdc++.h>
int main()
{
    // will only store whatever is important and nothing else
    std::deque<int> q;
    // adding an element
    int new_element = 10, remove_element = 10;
    while (!q.empty() && q.back() > new_element)
        q.pop_back();
    q.push_back(new_element);
    new_element = 30;
    while (!q.empty() && q.back() > new_element)
        q.pop_back();
    q.push_back(new_element);
    for(auto i: q){
        std::cout<<i<<std::endl;
    }
    std::cout<<"Second round\n";
    new_element = 20;
    while (!q.empty() && q.back() > new_element)
        q.pop_back();
    q.push_back(new_element);
    for(auto i: q){
        std::cout<<i<<std::endl;
    }
    std::cout<<"Remove element\n";
    // removing and element
    if (!q.empty() && q.front() == remove_element)
        q.pop_front();
    for(auto i: q){
        std::cout<<i<<std::endl;
    }
    // minium
    int min = q.front();
}