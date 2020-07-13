/*
 remove duplicates element in the sorted array.
 return size of array after removing duplicate elements. 
 **Rakesh Raj**
*/
int remove_duplicate(int A[],int N)
{
//Your code here
int prev=0;
for(int i=1;i<N;i++){
    if(A[prev]!=A[i]){
          prev++;
          A[prev]=A[i];
    }
}
return ++prev;
}