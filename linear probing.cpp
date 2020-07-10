/*
 --Rakesh Raj--
 linear probing
 
 let table size is a prime number = 999331
 
 let's denote empty block as INT_MAX
 and deleted block as INT_MIN;
 
 
*/

#define sz 999331
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    cin>>v[i];
    vector<int> table(sz,INT_MAX);//Initially all blocks are empty
    // Now let's take hash function as (hash(val)+i)%sz;
    
    // THis is insertion query
    for(int j=0;j<n;j++){
        int i=0;//for linear value
        while(table[(v[j]+i)%sz]!=INT_MAX){
            i++;
        }
        table[(v[j]+i)%sz]=v[j];
    }
    
    
    // Now come to search query
    
    // search until you find an empty slot  or your required element
    
    // deletion query
    // delete your elements and put that block to INT_MIN val(any special value)
    
    
    search
    
    
}