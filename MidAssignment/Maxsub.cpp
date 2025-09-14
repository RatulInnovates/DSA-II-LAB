#include <bits/stdc++.h>
using namespace std;
class MaxSub
{
public:
    int sum;
    int lidx;
    int ridx;
};

MaxSub mcsa(const vector<int> &arr, int l, int mid, int r)
{
    int lsum = INT_MIN, sum = 0, li = mid;
    for (int i = mid; i >= l; i--)
    {
        sum += arr[i];
        if (sum > lsum)
        {
            lsum = sum;
            li = i;
        }
    }
    int rsum = INT_MIN;
    sum = 0;
    int ri = mid + 1;
    for (int i = mid + 1; i <= r; i++)
    {
        sum += arr[i];
        if (sum > rsum)
        {
            rsum = sum;
            ri = i;
        }
    }
    MaxSub res;
    res.lidx = li;
    res.ridx = ri;
    res.sum = lsum + rsum;
    return res;
}

MaxSub maxSub(const vector<int> &arr, int l, int r)
{

    if (l == r)
    {
        MaxSub res;
        res.lidx = l;
        res.ridx = r;
        res.sum = arr[l];
        return res;
    }
    int mid = (l + r) / 2;
    MaxSub left = maxSub(arr, l, mid);
    MaxSub right = maxSub(arr, mid + 1, r);
    MaxSub cross = mcsa(arr, l, mid, r);

    if (left.sum >= right.sum && left.sum >= cross.sum)
        return left;
    else if (right.sum >= left.sum && right.sum >= cross.sum)
        return right;
    else
        return cross;
}

int main()
{
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = arr.size();
    MaxSub result = maxSub(arr, 0, n - 1);

    cout << "Maximum subarray sum: " << result.sum << endl;
    cout << "Start index: " << result.lidx << endl;
    cout << "End index: " << result.ridx << endl;

    cout << "Subarray: ";
    for (int i = result.lidx; i <= result.ridx; ++i)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}