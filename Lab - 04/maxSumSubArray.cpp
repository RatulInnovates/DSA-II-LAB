#include<iostream>
#include<vector>
using namespace std;
struct SubArray
{
    int sum, low, high;
};


SubArray mcsa(vector<int> a, int i,int j){

int mid = (i + j) / 2;

    // Left of mid
    int lsum = 0, lmax = INT_MIN;
    int sum = 0, low = mid;
    for (int x = mid; x >= i; x--) {
        sum += a[x];
        if (sum > lmax) {
            lmax = sum;
            low = x;
        }
    }

    // running on same loop might cause one side to end before actual end point

    // Right of mid
    int rsum = 0, rmax = INT_MIN;
    sum = 0;
    int high = mid + 1;
    for (int y = mid + 1; y <= j; y++) {
        sum += a[y];
        if (sum > rmax) {
            rmax = sum;
            high = y;
        }
    }

    SubArray msub;
    msub.sum = lmax + rmax;
    msub.low = low;
    msub.high = high;
    return msub;

    
}

SubArray maxSubArray(vector<int> a,int i,int j){
    SubArray res;
    if(i==j){
        res.sum = a[i];
        res.low = i;
        res.high = j;
        return res;
    }
    


    int mid = (i+j)/2;
    SubArray lsub = maxSubArray(a,i,mid);
    SubArray rsub = maxSubArray(a,mid+1,j);
    SubArray mcsub = mcsa(a,i,j);
    
    if(lsub.sum>rsub.sum&&lsub.sum>mcsub.sum) 
    {
        res.sum = lsub.sum;
        res.low = lsub.low;
        res.high = lsub.high;
        

    }
    else if(rsub.sum>lsub.sum&&rsub.sum>mcsub.sum)
    {
        res.sum = rsub.sum;
        res.low = rsub.low;
        res.high = rsub.high;

    }
    else{
        res.sum = mcsub.sum;
        res.low = mcsub.low;
        res.high = mcsub.high;


    }
    return res;

    


}

int main(){
    vector<int> a={2, 3, -8, 7, -1, 2, 3};
    SubArray s = maxSubArray(a, 0, a.size()-1);
    cout<<"Sum: "<<s.sum<<endl;
    cout<<"Max Sub Array: ";
    for(int i= s.low;i<=s.high;i++) cout<<a[i]<<" ";
    
  



}