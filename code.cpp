#include<iostream>
#include<stdio.h>
#include<math.h>
#include<bits/stdc++.h>
using namespace std;

unsigned int Logn(unsigned int n,
                  unsigned int r)
{
    return (n > r - 1) ? 1 +
       Logn(n / r, r) : 0;
}
 

bool isPower(int x, int y)
{
    // logarithm function to calculate value
    int res1 = log(y) / log(x);
    double res2 = log(y) /log(x); // Note : this is double
 
    // compare to the result1 or result2 both are equal
    return (res1 == res2);
}
// Driver code

//step 2:

int step2(unsigned long long int n){
    unsigned long long int maxk=log2(n)*log2(n);
    double a=pow(log2(n),5);
    unsigned long long int b=pow(log2(n),5);
    unsigned long long int c;
    if(a==b){
        c=a;
    }
    else{
        c=b+1;
    }
    int r;
    int k;
    //unsigned long long int maxr=max((unsigned long long int)3, c);

    //cout<<"maxr is "<<maxr<<endl;
    bool nextR=true;
    for(r=2; nextR && r<n;r++){
        nextR=false;
        for(k=1; (!nextR) && k<=maxk;k++){
            unsigned long long int p=pow(n,k);
            nextR=(p%r==1 || p%r==0);
        }
    }
    r--;
    return r;
}


//step 3
int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);    
}

bool step3(int n, int r){
    int a=2;
    for(a=2;a<=r;a++){
        int g=gcd(a,n);
        if(g>1 && g<n){
            return false;
        }
    }
    return true;
}


//step 5

int phi(int n)
{
    float result = n;
    for(int p = 2; p * p <= n; ++p)
    {
        if (n % p == 0)
        {
            while (n % p == 0)
                n /= p;
                 
            result *= (1.0 - (1.0 / (float)p));
        }
    }
  
    if (n > 1)
        result *= (1.0 - (1.0 / (float)n));
  
    return (int)result;
}


int main()
{
    unsigned long long int n = 31;
    unsigned int r = 2;
     
    cout << log2(n)/log2(r)<<endl;
    cout << isPower(27, 729) << endl;

    int answer2=step2(n);

    bool answer3=step3(n,answer2);
    cout<<answer2<<endl;
    if(answer3==false)
        cout<<"composite";
    //step4:
    if(n<=r)
        cout<<"prime";

    int answer5=phi(answer2);
    int ans5=sqrt(answer5)*log(n);


    int st5=sqrt(answer2)*log(n);
    int a;
    // for(a=1;a<ans5;a++){

    // }

    // for(a=1;a<st5;a++){

    // }

    
    
    return 0;
}