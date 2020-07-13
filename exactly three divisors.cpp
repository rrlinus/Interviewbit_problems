/*
 exactly3Divisors | GeeksforGeeks
 1.the number whose total numbers of divisor is odd must be perfect squre.
 2.so we have only three divisors it mean (1,n,x) so what is x?
    n doest not have any other divisors other than prime because if the number does not have
    prime then the divisors have some divisors which is more than one.
 
 **Rakesh Raj**
*/
void seiveMethod(){
    memset(prime,true,sizeof(prime));
    prime[0]=prime[1]=false;
    for(int i=2;i*i<100001;i++){
        if(prime[i]){
            for(int j=i*i;j<100001;j +=i){
                prime[j]=false;
            }
        }
    }
}
int exactly3Divisors(int N)
{
    //Your code here
    seiveMethod();
    int sq=sqrt(N);
    int ct=0;
    for(int i=2;i*i<=N;i++){
        if(prime[i])
        ct++;
    }
    return ct;
    
}