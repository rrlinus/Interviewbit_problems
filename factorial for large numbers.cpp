/*
 factorial for large numbers;
 **Rakesh Raj**
*/
#include <bits/stdc++.h>
using namespace std;
string fact(int n){
    string res="1";
    int rem=0;
    for(int i=2;i<=n;i++){
        for(int j=0;j<res.length();j++){
            int temp=((res[j]-'0')*i+rem);
            res[j]=temp%10 + '0';
            rem=temp/10;
        }
        while(rem){
            res.push_back(rem%10+'0');
            rem/=10;
        }
    }
    reverse(res.begin(),res.end());
    return res;
}
int main(){
    int n;
    cin>>n;
    cout<<fact(n);
}