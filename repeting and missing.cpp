/*
 Given an array of integers of size n and all the value in the range  1 to n.
 find the missing and repeating number.
 **Rakesh Raj**
*/
#include <bits/stdc++.h>
using namespace std;
int solve(int a[],int n){
    int repeating;
    for(int i=0;i<n;i++){
        if(a[abs(a[i])-1]<0){
            repeating=abs(a[i]);
            break;
        }
        a[abs(a[i])-1]=-a[i];
    }
    for(int i=0;i<n;i++){
        if(a[i]>0){
            missing=i+1;
            break;
        }
    }
    cout<<repeating<<" "<<missing;
}
