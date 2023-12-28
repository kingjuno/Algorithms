#include <bits/stdc++.h>
using namespace std;

void debug(deque<long long int> x)
{
    cout << "#";
    for (auto i : x)
        cout << i << " ";
    cout << endl;
}
int main()
{
    vector<int> ar;
    int n, q;
    cin >> n >> q;
    long long int temp;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        ar.push_back(temp);
    }
    for (int i = 0; i < q; i++)
    {
        cin >> temp;
        deque<long long int> min_q;
        long long int max_val = -10e10;
        for (int j = 0; j < temp; j++)
        {
            while (!min_q.empty() && min_q.back() < ar[j])
                min_q.pop_back();
            min_q.push_back(ar[j]);
        }
        // debug(min_q);
        max_val = max(min_q.front(), max_val);
        for (int j = temp; j < n; j++)
        {
            while (!min_q.empty() && min_q.back() < ar[j])
                min_q.pop_back();
            min_q.push_back(ar[j]);
            if (!min_q.empty() && min_q.front() == ar[j - temp])
                min_q.pop_front();
            // debug(min_q);
            max_val = min(min_q.front(), max_val);
        }
        cout << max_val << endl;
    }
}