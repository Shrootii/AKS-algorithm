#include<iostream>
#include<stdio.h>
#include<cmath>

typedef unsigned long long int ull;
using namespace std;




//implementing n^k, using quiz1 question1, karatsuba basically


ull*  mul(ull* arr1, ull* arr2, ull size1, ull size2)
{
    ull*  arr{new ull[size1+size2-1] {0}};

    for(int i=0;i<size1+size2-1;i++)
    {
        arr[i]=0;
    }

    for(int i=0;i<size1;i++)
    {
        for(int j=0;j<size2;j++)
        {
            arr[i+j]+=arr1[i]*arr2[j];
        }
    }
    return arr;
}

ull*  modulon(ull* arr,ull n, ull size)
{
    // if(arr.size()>=r){
    //     int n=arr.size();
    //     for(int i=0;i<n-r;i++){
    //         arr[i]=arr[i]+arr[r+i];
    //         arr.pop_back();
    //     }
    // }

    for(int i=0;i<size;i++)
    {
        arr[i]=arr[i]%n;
    }
    return arr;

}

ull*  modulor(ull* arr, ull r,ull size)
{
    if(size>=r)
    {
        for(int i=0;i<size-r;i++)
        {
            arr[i]=arr[i]+arr[r+i];
        }
    }
    return arr;
}

ull*  step5_func(ull* arr, ull n,ull r,ull power)
{
    if(n==1)
    {
        arr=modulon(arr,power,2);
        return arr;
    }
    else
    {
        if(n%2==0)
        {
            ull*  arr1=step5_func(arr,n/2,r,power);
            ull* arr2=mul(arr1,arr1,n/2+1,n/2+1);
            arr2=modulon(arr2,power,n+1);
            return arr2;
        }
        else
        {
            ull* arr1=step5_func(arr,n/2,r,power);
            ull* arr2=mul(arr1,arr1,n/2+1,n/2+1);
            ull* arr3=mul(arr2,arr,n,2);
            arr3=modulon(arr3,power,n+1);
            return arr3;
        }
    }
}



ull Logn(ull n,ull r)
{
    return (n > r - 1) ? 1 +
       Logn(n / r, r) : 0;
}
 

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

int step2(ull n, ull ln)
{
    ull maxk=ln*ln;
    int r;
    ull k;
    bool nextR=true;
    for(r=2; nextR ;r++)
    {
        nextR=false;
        for(k=1; (!nextR) && k<=maxk;k++)
        {
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

bool step3(int n, int r)
{
    int a=2;
    for(a=2;a<=r;a++)
    {
        int g=gcd(a,n);
        if(g>1 && g<n)
        {
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

    ull ln= Logn(n,2);

    ull r=step2(n,ln);

    bool answer3=step3(n,r);

    cout<<n<<" -> "<<r<<endl;

    if(answer3==false)
    {
        cout<<"composite"<<endl;
        return 0;
    }

    //step4:
    if(n<=r)
    {
        cout<<"prime"<<endl;
        return 0;
    }

    ull phi_val=phi(r);

    ull answer5_1=sqrt(phi_val)*ln;

    ull answer5_2=sqrt(r)*log(n);

    ull a;
    
    
    for(a=1;a<answer5_1;a++)
    {
        ull* arr{new ull[n+1] {0}};
        ull* arr1{ new ull[n+1] {0}};

        arr[0]=a;
        arr[1]=1;
        arr1[n]=1;
        arr1[0]=a;

        ull* step5_lhs=step5_func(arr,n,r,n);
        step5_lhs=modulor(step5_lhs,r,n+1);

        ull* step5_rhs=modulon(arr1,n,n+1);

        step5_rhs=modulor(step5_rhs,r,n+1);

       

        for(int i=0;i<r;i++)
        {
            if((step5_lhs[i]-step5_rhs[i])%n!=0)
            {
                cout<<"composite"<<endl;
                return 0;
            }
        }
       

    }

    cout<<"prime"<<endl; 
    return 0;
}