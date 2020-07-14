

// Rakesh Raj
string ExcelColumn(int n)
{
    // Your code goes here
   /* what we will do here?
    we know that we will represent any number in the form of ....+x1*26^2+x2*26^1+x3*26^0.
    but here value x1 ....xn lies between 1 and 26.
    but when we represent in the form of word 0-A,1-B,...
    so we will decrease by 1 and divide it recursivly by 26 and in the same way we will
    do for other indexes(like recursively)*/
    string output="";
    while(n>0){
        n-=1;
        output.push_back(n%26+'A');
        n/=26;
    }
    reverse(output.begin(),output.end());
    return output;
}