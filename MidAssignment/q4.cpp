#include <bits/stdc++.h>
using namespace std;

pair<int, vector<int>> mcsa(vector<int> &arr, int l, int r)
{
    int crossSum = INT_MIN;
    vector<int> crossArr;
    int mid = (l + r) / 2;
    // 1. mid-2, mid-1, mid
    if (mid - 2 >= l)
    {
        int sum = arr[mid - 2] + arr[mid - 1] + arr[mid];
        if (sum > crossSum)
        {
            crossSum = sum;
            crossArr = {arr[mid - 2], arr[mid - 1], arr[mid]};
        }
    }

    // 2. mid-1, mid, mid+1
    if (mid - 1 >= l && mid + 1 <= r)
    {
        int sum = arr[mid - 1] + arr[mid] + arr[mid + 1];
        if (sum > crossSum)
        {
            crossSum = sum;
            crossArr = {arr[mid - 1], arr[mid], arr[mid + 1]};
        }
    }

    // 3. mid, mid+1, mid+2
    if (mid + 2 <= r)
    {
        int sum = arr[mid] + arr[mid + 1] + arr[mid + 2];
        if (sum > crossSum)
        {
            crossSum = sum;
            crossArr = {arr[mid], arr[mid + 1], arr[mid + 2]};
        }
    }
    return {crossSum, crossArr};
}

pair<int, vector<int>> maxSub(vector<int> &arr, int l, int r)
{
    if (r - l + 1 < 3)
        return {0, {}};

    if (r - l + 1 == 3)
    {
        return {arr[l] + arr[l + 1] + arr[l + 2], {arr[l], arr[l + 1], arr[l + 2]}};
    }

    int mid = (l + r) / 2;

    pair<int, vector<int>> leftMax = maxSub(arr, l, mid);
    pair<int, vector<int>> rightMax = maxSub(arr, mid + 1, r);
    pair<int, vector<int>> cross = mcsa(arr, l, r);

    if (leftMax.first >= rightMax.first && leftMax.first >= cross.first)
        return leftMax;
    else if (rightMax.first >= leftMax.first && rightMax.first >= cross.first)
        return rightMax;
    else
        return cross;
}

int main()
{
    vector<int> temperatures = {28, 31, 29, 34, 30, 33, 27, 35, 32};

    pair<int, vector<int>> result = maxSub(temperatures, 0, temperatures.size() - 1);

    cout << "The 3-day subarray with the maximum total temperature is [";
    for (int i = 0; i < 3; i++)
    {
        cout << result.second[i];
        if (i < 2)
            cout << ", ";
    }
    cout << "] (total = " << result.first << ")" << endl;

    return 0;
}
