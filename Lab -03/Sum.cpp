#include<iostream>
#include<map>
using namespace std;




int sum(int n){
    if(n<=0) return 0;
    if(n==1) return 1;
    return sum(n-1)+n;
}
int series(int n){
    if(n<=0) return 0;
    if(n==1) return 1;
    return series(n-3)+n;

}
int ser2(int n){
    // 2,6,10,14,...
    if(n<=0) return 0;
    if(n==1) return 2;
    return ser2(n-1)+((4*n)-2);

}
int ser3(int n){
    if(n<=0) return 0;
    if(n==1) return 3;
    return ser3(n-1)+((2*n)+1);

}

int ser4(int n){
    if(n<=0) return 0;
    if(n==1) return 1;
    if(n==2) return 2;
    return ser4(n-1) + 3;
}

int numOfWays(int n){

    if(n<=0) return 0;
    if(n<=2) return n;
    return numOfWays(n-1)+numOfWays(n-2);


}
int numOFSandwich(int n,int m){

    if(n<2||m<3) return 0;
    return 1+numOFSandwich(n-2,m-3);


}
int numOfCars(int rect,int circ, int tri){
    if(rect<2|| circ<3 || tri<1) return 0;
    return 1+ numOfCars(rect-2,circ-3, tri-1);

}

int sumOfArray(int* arr,int n){
    if(n<0) return 0;
    return arr[n-1]+ sumOfArray(arr,n-1);



}

//HW: Sum of Even elements

int main(){
    //int res = sum(-3);
    //cout<<res;
    //cout<<series(10);
    int arr[]={1,12,3,4,10};
    cout<<sumOfArray(arr,5);

}
