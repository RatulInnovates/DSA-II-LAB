#include <bits/stdc++.h>
using namespace std;
class Activity
{
public:
    int start_time, finish_time;
    Activity(int s, int f) : start_time(s), finish_time(f) {}
    void display()
    {
        cout << "Start time:" << start_time << " finish time:" << finish_time << endl;
    }
};
bool Compare(Activity a1, Activity a2)
{
    return a1.finish_time < a2.finish_time;
}
void activitySelection(vector<Activity> alist)
{
    sort(alist.begin(), alist.end(), Compare);
    for (auto a : alist)
        a.display();

    vector<Activity> selected;
    int l = 0;
    selected.push_back(alist[0]);
    int cnt = 1;
    for (int m = 1; m < alist.size(); m++)
    {
        if (alist[m].start_time >= alist[l].finish_time)
        {
            selected.push_back(alist[m]);
            l = m;
            cnt++;
        }
    }
    cout << "maximum num of activities: " << cnt << endl;
    cout << "Selected ones: " << endl;
    for (auto a : selected)
    {
        a.display();
    }
}

int main()
{
    vector<Activity> activities = {Activity(8, 12), Activity(9, 10), Activity(14, 16), Activity(11, 13), Activity(9, 11), Activity(10, 12)};
    activitySelection(activities);

    return 0;
}