#include<iostream>
using namespace std;

void increment(int &x){
x++;
}

void max(int a,int b, int &m){
if(a>b) m = a;
else m = b;
}


int main(){
    int y = 10;
    increment(y);
    //cout<<y;
    int maxnum;
    max(1,3,maxnum);
    cout<<maxnum;
}
