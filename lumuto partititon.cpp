//Lumuto partition
#include <bits/stdc++.h>
using namespace std;
void lumutoPartition(vector<int> &arr){
    int n=arr.size();
    int pivot=arr[n-1];
    int low=-1,high;
    for(high=0;high<n-1;high++){
        if(pivot>arr[high]){
            low++;
            swap(arr[high],arr[low]);
        }
    }
    swap(arr[low+1],arr[high]);
}
int main(){
    int n;//number of elements;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    lumutoPartition(arr);
    for(auto i:arr)
    cout<<i<<" ";
}