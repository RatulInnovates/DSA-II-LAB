#include<iostream>
#include<vector>
using namespace std;
struct largestPair
{
    int  sum, low, high;
};


int f(vector<int> a, int i, int j){

    if(i==j-1) return a[i]+a[j];
    int mid = (i+j)/2;
    int lf = f(a, i,mid);
    int rf = f(a, mid+1, j);
    int cf = a[mid]+a[mid+1];
    largestPair lsub ;
    // .... hw
    
    
}