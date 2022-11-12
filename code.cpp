#include<iostream>
#include<stdio.h>
#include<math.h>
#include<bits/stdc++.h>

typedef unsigned long long int ull;
using namespace std;




//implementing n^k, using quiz1 question1, karatsuba basically



// int power(int n,int k){
//     if(k==1){
//         return n;
//     }
//     if(k%2==0){
//         int n1=power(n,k/2);
//         int n2=karatsuba(n1,n1);
//         return n2;
//     }
//     if(k%2!=0){
//         int n1=power(n,floor(k/2));
//         int n2=karatsuba(n1,n1);
//         int n3=karatsuba(n2,n);
//         return n3;
//     }
// }
// ull Logn(unsigned int n,
//                   unsigned int r)
// {
//     return (n > r - 1) ? 1 +
//        Logn(n / r, r) : 0;
// }
 

// bool isPower(int x, int y)
// {
//     // logarithm function to calculate value
//     int res1 = log(y) / log(x);
//     double res2 = log(y) /log(x); // Note : this is double
 
//     // compare to the result1 or result2 both are equal
//     return (res1 == res2);
// }
// // Driver code

//step 2:

int step2(ull n){
    
    ull maxk=log2(n)*log2(n);
    double a=pow(log2(n),5);
    ull b=pow(log2(n),5);
    ull c;
    if(a==b){
        c=a;
    }
    else{
        c=b+1;
    }
    int r;
    ull k;
    ull maxr=max((ull)3, c);
    bool nextR=true;
    for(r=2; nextR && r<maxr;r++){
        nextR=false;
        for(k=1; (!nextR) && k<=maxk;k++){
            ull modulo=n%r;
            ull p=(ull)(pow(modulo,k))%r;
            nextR=(p==1 || p==0);
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
    ull n;
    cin>>n;
    //unsigned int r = 2;
    int r=step2(n);
    bool answer3=step3(n,r);
    cout<<r<<endl;
    if(answer3==false)
    {
        cout<<"composite";
        return 0;
    }
    //step4:
    if(n<=r)
    {
        cout<<"prime";
        return 0;
    }

    int phi_val=phi(r);
    int answer5_1=sqrt(phi_val)*log(n);


    int answer5_2=sqrt(r)*log(n);
    int a;
    // for(a=1;a<answer5_1;a++){

    // }

    // for(a=1;a<answer5_2;a++){

    // }

    
    
    return 0;
}