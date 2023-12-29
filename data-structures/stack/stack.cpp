#include <iostream>
using namespace std;
class stack
{
private:
    int arr[100];
    int ptr = -1;

public:
    void push(int ele)
    {
        if (ptr == 100)
        {
            cout << "Maximum size reached!\n";
        }
        arr[++ptr] = ele;
    }

    int pop()
    {
        if (ptr == -1)
        {
            "No elements to Pop!\n";
        }
        return arr[ptr--];
    }

    int top()
    {
        return arr[ptr];
    }

    bool isEmpty()
    {
        return ptr == -1;
    }

    int size()
    {
        return ptr;
    }
    void traverse()
    {
        if (ptr == -1)
            return;
        for (int i = 0; i <= ptr; i++)
            cout << arr[i] << " ";
        cout << "\n";
    }
};
int main()
{
    stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.traverse();
    cout<<s.isEmpty()<<" "<<s.top();
    cout<<"\n"<<s.pop();
    cout<<"\n";
    s.traverse();
}