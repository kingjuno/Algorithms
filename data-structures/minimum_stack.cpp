#include<bits/stdc++.h>
int main(){
    std::stack<std::pair<int,int>> st;
    int new_elem = 10; 
    // adding an element
    int new_min = st.empty()?new_elem:std::min(new_elem, st.top().second);
    st.push({new_elem, new_min});
    // Removing an element
    int removed_element = st.top().first;
    st.pop();
    // to find the minimum
    int minimum = st.top().second;
}