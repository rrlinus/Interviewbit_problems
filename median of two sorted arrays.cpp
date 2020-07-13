
//User function template for C++

// a : given array with size n 
// b : given array with size m

int findMedian(int a[], int n, int b[], int m){
    // code here
    //we know that the median of an array is that elements in the such that
    //half of the elements of the array smaller and half of the elements of the 
    //array are greater.
    
    int start=0,end=n;
    int median;
    int i,j;
    while(start<=end){
        i=start+(end-start)/2;
        j=(n+m+1)/2-i;
        if(i<n and j>0 and a[i]<b[j-1]){
            start=i+1;
        }
        else if(j<m and i>0 and b[j]<a[i-1]){
            end=i-1;
        }
        else{
            if(i==0)
            median=b[m-1];
            else if(j==0)
            median=a[n-1];
            else
            median=max(a[i-1],b[j-1]);
            break;
        }
    }
    if((n+m)%2)
    return median;
    if(i==n)
    median =(median+b[0])/2;
    else if(j==m)
    median=(median+a[0])/2;
    else 
    median=(median+min(a[i],b[j]))/2;
    return median;
    
}