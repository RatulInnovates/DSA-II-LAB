// fractional knapsack greedy approach

#include <bits/stdc++.h>
using namespace std;
class Item
{
public:
    string name;
    float weight, value;
    float unitValue;
    Item(string s, float w, float v) : name(s), weight(w), value(v), unitValue(v / w) {}
    void display()
    {
        cout << "Name: " << name << ". Value: " << value << ". Weight: " << weight << ". Unit Value: " << unitValue << endl;
    }
};

bool compare(Item i1, Item i2)
{
    return i1.unitValue > i2.unitValue;
}
void fracKnapsack(vector<Item> itemlist, int n, int w)
{
    // find the max profit
    int profit = 0;
    sort(itemlist.begin(), itemlist.end(), compare);
    for (auto a : itemlist)
        a.display();

    for (int i = 0; i < n; i++)
    {
        if (itemlist[i].weight <= w)
        {
            profit += itemlist[i].value;
            w -= itemlist[i].weight;
        }
        else if (w > 0)
        {
            profit += (itemlist[i].unitValue * w);
            w -= itemlist[i].weight;
        }
    }

    cout << "Total Profit: " << profit << endl;
}

int main()

{
    vector<Item> Items = {Item("Rice", 5, 300), Item("Saffron", 2, 8000), Item("Salt", 10, 200), Item("Sugar", 4, 400)};
    int n = Items.size();
    int w = 8;
    fracKnapsack(Items, n, w);

    return 0;
}