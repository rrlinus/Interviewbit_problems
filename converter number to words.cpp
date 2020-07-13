/*
 convert number into words
 **Rakesh Raj**
*/
#include <bits/stdc++.h>
using namespace std;
// number less than 20

int one[]={"","one ","two ","three ","four ","five ","six ","seven ","eight ","nine ","ten ","eleven ","twelve ","thirteen ","fourteen ","fifteen ",
    "sixteen ","seventeen ","eighteen ","nineteen "};
int two[]={"","","twenty ","thirty ","fourty ","fifty ","sixty ","seventy ","eighty ","ninety "};

// for first digit or 2 digit

string one_two(int n,string temp){
    int op=""
    if(n<=19)
    op +=one[n];
    else{
        op +=two[n/10]+one[n%10];
    }
    if(n)
    op +=temp;
    return op;
}
int converter(int n){
    string op="";
    op +=one_two(n/10000000,"crore");
    op +=one_two(n/100000,"lakh");
    op +=one_two(n/1000,"thousand");
    op +=one_two(n/100,"hundred");
    if(n>100 and n%100)
    op +="and ";
    op +=one_two(n%100,"");
    return op;
}