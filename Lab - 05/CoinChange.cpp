// minimum num of coins or notes to get maximum amount
// with inifinite number of notes supply

#include <bits/stdc++.h>
using namespace std;
void coinChange(vector<int> coins, int m)
{

    sort(coins.begin(), coins.end(), greater<int>());
    for (auto x : coins)
        cout << x << endl;

    map<int, int> selected;
    int i = 0;
    while (m > 0)
    {
        if (coins[i] <= m)
        {
            selected[coins[i]]++;
            m -= coins[i];
        }
        if (coins[i] > m)
            i++;
    }
    cout << "Selected: " << endl;
    for (auto i : selected)
    {
        cout << i.first << " : " << i.second << endl;
    }
}

int main()
{
    vector<int> coins = {1000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
    int amount = 2890;
    coinChange(coins, amount);

    return 0;
}