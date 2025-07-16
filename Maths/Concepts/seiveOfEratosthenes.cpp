#include <bits/stdc++.h>
using namespace std;

/*
Primality Check :
Just loop till sqrt(n) and u would be good to find whether a number is prime or not


//CODE to check whether a number is prime or not
bool checkPrime(int n)
{ // loop form 2 as 0 and 1 are not prime and stop just before the n as it would divide the number itself
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

//CODE to print all the divisors of a number
void divisors(int n)
{
    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0) //means divisible
        {
            cout << i << " ";
            if ((n / i) != i)
                cout << n / i << " ";
        }
    }
}

//CODE to check all the prime numbers between a specific range
  bool checkPrime(int n)
    {   
        if(n==1)
        return false;

        for (int i = 2; i * i <= n; i++)
         {
             if (n % i == 0)
             return false;
        }
         return true;
    }

    vector<int> givePrimes(int left,int right)
    {
        vector<int> primes;

        for(int i=left;i<=right;i++) //O(N)
        {
            if(checkPrime(i))
            primes.push_back(i);
        }

        return primes;
    }
*/

/*
Seive of Eratothenes

CODE
    vector<bool> seive(int right)
    {   
        //intially marking all as true
        vector<bool> isPrime(right+1,true);
        isPrime[0]=false;
        isPrime[1]=false;

        for(int i=2;i*i<=right;i++) 
        {
            if(isPrime[i]) //means prime as it is true
            {
                //mark all the multiples of that numbers in the vector as false;
                for(int j=2;i*j<=right;j++)
                {
                    isPrime[i*j]=false;
                }
            }
        }
        return isPrime;
    }

    vector<int> closestPrimes(int left, int right) {

        vector<bool> isPrime = seive(right); 
        vector<int> primes;

        //iterate over the isPrime to check which are the primes
        //move from left as the range start from there
        for(int i=left;i<isPrime.size();i++)
        {
            if(isPrime[i]) //if true then push
            primes.push_back(i);
        }

        int num1 = -1;
        int num2 = -1;

        if(primes.size()<2)
        return {num1,num2};

        //now iterate over the primes to check the nums with minimum difference and if the difference is 
        //same then choose the one with less number 
        
        int diff=INT_MAX;
        for(int i=0;i<primes.size()-1;i++)
        {   
            int currDiff=primes[i+1]- primes[i];
            if(currDiff<diff)
            {   
                diff=currDiff; //update the diff
                num1 = primes[i];
                num2 = primes[i+1];
            }
        }

        return {num1,num2};


        //doing it with seive of eratosthenes which takes a complexity of O(N*log(log(n)))
        //how this T.C came
        /*
            Suppose if we have to find the primes till 30
            the loop would be going till 5 as the sqrt(30) is rounded off to 5
            now at 2 as it is prime-->30/2 --> n/2 it would mark these elements
            now at 3 --> n/3
            now at 4-->wouldnt run as it would be marked false
            now at 5 -->n/5 

            so n/2+n/3+n/5
            n(1/2+1/3+1/5)
            this is harmonic series on primes and its values grows very slowly even slower than log
            
            O(n(log(log n)))

        */
    
    


int main()
{

    int n;
    cout << "enter the number to be checked" << '\n';
    cin >> n;

    // cout << (checkPrime(n) ? "Prime" : "Not a Prime");
    // return 0;
}