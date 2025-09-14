#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<string> drinks = {"Glaxose-D", "GlucoMax", "Sting"};
    vector<int> bottleSize = {3, 4, 5};
    vector<int> totalGlucose = {75, 80, 150};
    vector<float> glucosePerLitre;
    for (int i = 0; i < bottleSize.size(); i++)
    {

        glucosePerLitre.push_back((float)totalGlucose[i] / bottleSize[i]);
    }

    map<float, pair<string, float>> data;
    for (int i = 0; i < drinks.size(); i++)
    {
        data[glucosePerLitre[i]] = {drinks[i], bottleSize[i]};
    }

    int capacity = 6;
    float consm = 0;
    map<string, float> consumption;
    for (auto it = data.begin(); it != data.end() && capacity >= 0; it++)
    {

        if (it->second.second < capacity)
        {
            float glcsCnsm = it->first * it->second.second;
            consm += glcsCnsm;
            capacity -= it->second.second;
            consumption[it->second.first] += glcsCnsm;
        }
        else
        {
            float glcsCnsm = capacity * it->first;
            consm += glcsCnsm;
            capacity -= capacity;
            consumption[it->second.first] += glcsCnsm;
        }
    }
    cout << "Total Minimum Glucose consume: " << consm << endl;
    for (auto x : consumption)
    {
        cout << x.first << ": " << x.second << endl;
    }

    return 0;
}