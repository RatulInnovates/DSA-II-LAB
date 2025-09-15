#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<string> product = {"Rice", "Sugar", "Wheat", "Onion"};
    vector<int> weight = {100, 200, 350, 250};
    vector<int> wsalePrice = {4000, 9000, 7000, 12000};
    vector<int> retailPrice = {55, 62, 30, 80};
    int size = product.size();

    vector<float> profit;
    for (int i = 0; i < size; i++)
    {
        profit.push_back((retailPrice[i] * weight[i]) - wsalePrice[i]);
    }
    vector<float> profitPerUnit;
    for (int i = 0; i < size; i++)
    {
        profitPerUnit.push_back(profit[i] / weight[i]);
    }

    // profit, {product, weight}

    map<float, pair<string, int>, greater<float>> data;

    for (int i = 0; i < size; i++)
    {
        data[profitPerUnit[i]] = make_pair(product[i], weight[i]);
    }

    for (auto x : data)
    {
        cout << x.first << " " << x.second.first << " " << x.second.second << endl;
    }

    int capacity = 600;
    float maxProfit = 0;
    // product, weight taken
    map<string, float> taken;
    // it->first=profitPerunit
    // it->second.first = product
    // it->second.second = weight
    for (auto it = data.begin(); it != data.end(); it++)
    {
        if (capacity == 0)
            break;
        if (it->second.second == 0)
            continue;
        if (it->second.second < capacity)
        {
            maxProfit += it->first * it->second.second;
            capacity -= it->second.second;
            taken[it->second.first] = it->second.second;
            it->second.second = 0;
        }

        else
        {
            // profitPerunit*capacity
            maxProfit += it->first * capacity;
            taken[it->second.first] = capacity;
            it->second.second = 0;
            capacity = 0;
        }
    }
    cout << "Total Profit: " << maxProfit << endl;
    cout << "Choosen Items: " << endl;
    for (auto x : taken)
    {
        cout << x.first << " " << x.second << endl;
    }

    return 0;
}
