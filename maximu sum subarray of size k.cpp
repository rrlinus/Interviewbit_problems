/*
 maximum sum subarray of size k.
 use sliding window technique
 a-array
 n-sizeof array
 k-as mentioned in question
 **Rakesh Raj**
*/
void solve(int a[],int n,int k){
    int sum=0;
    for(int i=0;i<k;i++){
        sum +=a[i];
    }
    int res=sum;
    for(int i=k;i<n;i++){
        sum=sum-a[i-k]+a[i];
        res=max(res,sum);
    }
    return res;
}