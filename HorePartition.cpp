//Hoare partition
#include <bits/stdc++.h>
using namespace std;
void HoarePartition(vector<int> &arr){
    int n=arr.size();
    int pivot=arr[0];
    int low=-1,high=n;
    while(true){
        do{
            low++;
        }while(arr[low]<pivot);
        do{
            high--;
        }while(arr[high]>pivot)
        if(low>=high)
        return;
        swap(a[low],a[high]);
    }
    
}
int main(){
    int n;//number of elements;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    HoarePartition(arr);
    for(auto i:arr)
    cout<<i<<" ";
}