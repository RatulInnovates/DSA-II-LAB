#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> vct = {5, 1, 21, 6, 5, 16, 21, 5, 1};
    map<int, int> mp;
    for (auto x : vct)
    {
        mp[x]++;
    }
    for (auto x : mp)
    {
        cout << x.first << "-> " << x.second << endl;
    }

    return 0;
}