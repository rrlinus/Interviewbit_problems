/*
 modulo inverse
 (a^(-1))%m;
 
 Euclid's algoritthm
 
 
 **Rakesh Raj**
*/
#include <bits/stdc++.h>
using namespace std;
int modInverse(int a,int m,int &x,int &y){
    if(m==0){
        x=1;
        y=0;
        return a;
    }
    int gcd=modInverse(m,a%m,x,y);
    int temp=x;
    x=y;
    y=temp-(a/m)*y;
    return gcd;
}
int main(){
    int a,m;
    cin>>a>>m;
    int x,y;
    cin>>x>>y;
    int gcd=modInverse(a,m,x,y);
    if(gcd==1){
        cout<<(x+m)%m;
    }
    else{
        cout<<"Not Exist";
    }
    
}