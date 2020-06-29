/*Counting sort is a sorting technique based on keys between a specific range. It works by counting the number of objects having distinct key values (kind of hashing). Then doing some arithmetic to calculate the position of each object in the output sequence.

Let us understand it with the help of an example.
For simplicity, consider the data in the range 0 to 9. 
Input data: 1, 4, 1, 2, 7, 5, 2
  1) Take a count array to store the count of each unique object.
  Index:     0  1  2  3  4  5  6  7  8  9
  Count:     0  2  2  0   1  1  0  1  0  0

  2) Modify the count array such that each element at each index 
  stores the sum of previous counts. 
  Index:     0  1  2  3  4  5  6  7  8  9
  Count:     0  2  4  4  5  6  6  7  7  7

The modified count array indicates the position of each object in 
the output sequence.
 
  3) Output each object from the input sequence followed by 
  decreasing its count by 1.
  Process the input data: 1, 4, 1, 2, 7, 5, 2. Position of 1 is 2.
  Put data 1 at index 2 in output. Decrease count by 1 to place 
  next data 1 at an index 1 smaller than this index.
 */
 
 /*Naive Approach:
 #include <bits/stdc++.h>
 using namespace std;
 
 int main(){
     int n;
     cin>>n;//number of input elements
     vector<int> input(n);
     for(int i=0;i<n;i++){
         cin>>input[i];
     }
     //let say maximum value in the input array is always less than 10^6 and greater than=0;
     vector<int> count(1000001,0);
     for(int i=0;i<n;i++){
         count[input[i]]++;
     }
     //Now again put all the elements of the array to the input array;
     int index=0;
     for(int i=0;i<1000001;i++){
         while(count[i]>0){
             input[index++]=i;
             count[i]--;
         }
     }
     for(int i=0;i<n;i++){
         cout<<input[i]<<" ";
     }
     
 }
 */
 
//  How can we handle for the negaive numbers and for large numbers like 10^18(range_--10^6)


/*#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> input(n);
    for(int i=0;i<n;i++){
        cin>>input[i];
    }
    int minimum=*min_element(input.begin(),input.end());
    int maximum=*max_element(input.begin(),input.end());
    int range=maximum-minimum+1;
    vector<int> count(range,0);
    for(int i=0;i<n;i++){
        count[input[i]-minimum]++;
    }
    int index=0;
    for(int i=0;i<range;i++){
        while(count[i]>0){
            input[index++]=i+minimum;
            count[i]--;
        }
    }
    for(auto element:input)
    cout<<element<<" ";
}
*/


//let's say how can we make this more efficient soln to all the above solns
//as well as stable counting sort.
#include <bits/stdc++.h>
using namespace std;
struct node{
    string name;
    int marks;
    node(){
        marks=0;
    }
};
int main(){
    int n;//number of students;
    cin>>n;
    vector<node> student(n);
    for(int i=0;i<n;i++){
        cin>>student[i].name>>student[i].marks;
    }
    //now sort them based on their marks if two students have same marks then as previous order.
    int max_marks=INT_MIN;
    int min_marks=INT_MAX;
    for(int i=0;i<n;i++){
        max_marks=max(max_marks,student[i].marks);
        min_marks=min(min_marks,student[i].marks);
    }
    int range=max_marks-min_marks+1;
    vector<int> count(range,0);
    for(int i=0;i<n;i++){
        count[student[i].marks-min_marks]++;
    }
    for(int i=1;i<range;i++){
        count[i] +=count[i-1];
    }
    vector<node> output(n);
    for(int i=n-1;i>=0;i--){
        output[count[student[i].marks-min_marks]-1]=student[i];
        count[student[i].marks-min_marks]--;
    }
    for(int i=0;i<n;i++){
        cout<<output[i].name<<" "<<output[i].marks<<endl;
    }
    
}
 