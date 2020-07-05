// https://practice.geeksforgeeks.org/problems/huffman-encoding/0


***Rakesh Raj ****

#include <bits/stdc++.h>
using namespace std;
class Node{
public:
  int ct;
  char ch;
  Node *left,*right;
  Node(){
      this->left=this->right=NULL;
  }
  Node(char ch,int ct){
      this->ch=ch;
      this->ct=ct;
      this->left=this->right=NULL;
  }
};
class comp{
 public:
  bool operator()(Node *first,Node *second){
      return first->ct>second->ct;
  }  
};


void solve(Node *head,string ans){
    if(head==NULL){
        return ;
    }
    // cout<<"x";
    if(!head->left and !head->right){
        if(ans.length()>0)
        cout<<ans<<" ";
        return;
    }
    solve(head->left,ans+"0");
    solve(head->right,ans+"1");
}
int main(){
    int t;
    cin>>t;
    while(t--){
        string inp;
        cin>>inp;
        int n=inp.length();
        vector<int> freq(n);
        for(int i=0;i<n;i++){
            cin>>freq[i];
        }
        priority_queue<Node*,vector<Node*>,comp> pq;
        for(int i=0;i<n;i++){
            Node *temp=new Node(inp[i],freq[i]);
            pq.push(temp);
        }
        while(pq.size()>1){
            Node *temp1=pq.top();
            pq.pop();
            Node *temp2=pq.top();
            pq.pop();
            Node *temp=new Node('X',temp1->ct+temp2->ct);
            temp->left=temp1;
            temp->right=temp2;
            // cout<<temp->left->ct<<" "<<temp->right->ct<<" ";
            pq.push(temp);
        }
        Node *head=pq.top();
        
        solve(head,"");
        pq.pop();
        cout<<endl;
        
    }
}