#include<iostream>
#include<vector>
using namespace std;

int countF(vector<int> a, int i, int j,int target){
    
    if(i==j){
        if(a[i]==target) return 1;
        else return 0;
    }
    int mid = (i+j)/2;
    int lcount = countF(a, i, mid, target);
    int rcount = countF(a, mid+1, j, target);
    return lcount+rcount;


}
int main(){

    vector<int> a = {3,4,5,65,3,6,3};
    cout<<countF(a, 0, a.size()-0,3);
    
}