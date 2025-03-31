#include <bits/stdc++.h>
using namespace std;

// HARD
class Solution
{
public:
    int MOD = 1e9 + 7;

    // optimally handling the power through binary exponentiation
    long long BinaryExpo(long long a, long long b)
    {
        if (b == 0)
            return 1;

        if (b < 0) // in negative case, suppose 2^-4 so it would be 1/2^4 which would be (1/2)^4
            return BinaryExpo(1 / a, -b);

        else if (b % 2 == 0) // means power is even,so power would be half and a+a
            return (BinaryExpo((a % MOD * a % MOD) % MOD, b / 2)) % MOD;

        else // means power is odd
            return (a % MOD * BinaryExpo((a % MOD * a % MOD) % MOD, b / 2)) % MOD;
    }

    // calculating prime scores of each element by using Seive of Eratosthenes
    vector<int> Seive(int limit)
    {
        // limit is uptill which number we want the prime numbers
        // no matter what the limit is we will always start from 2

        // intially marking all as true
        vector<bool> isPrime(limit + 1, true);
        vector<int> primes;
        isPrime[0] = false;
        isPrime[1] = false;

        for (int i = 2; i * i <= limit; i++) // O(N)
        {
            if (isPrime[i]) // means prime as it is true
            {
                // mark all the multiples of that numbers in the vector as false;
                for (int j = 2; i * j <= limit; j++)
                {
                    isPrime[i * j] = false;
                }
            }
        }

        for (int i = 2; i <= limit; i++)
        {
            if (isPrime[i])
                primes.push_back(i);
        }
        return primes;
    }

    vector<int> findNextGreater(vector<int> &primeScores)
    {
        int n = primeScores.size();
        vector<int> nextGreater(n, n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && primeScores[st.top()] <= primeScores[i])
            {
                st.pop();
            }
            nextGreater[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        return nextGreater;
    }

    vector<int> findPreviousGreaterOrEqual(vector<int> &primeScores)
    {
        int n = primeScores.size();
        vector<int> prevGreaterOrEqual(n, -1);
        stack<int> st;

        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && primeScores[st.top()] < primeScores[i])
            {
                st.pop();
            }
            prevGreaterOrEqual[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        return prevGreaterOrEqual;
    }

    vector<int> findPrimeScores(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> primeScores(n, 0); // would be consiting of unique primeScores

        int maxElement = *max_element(nums.begin(), nums.end());
        vector<int> primes = Seive(maxElement);

        for (int index = 0; index < n; index++)
        {
            int num = nums[index];

            for (int prime : primes)
            {
                if (prime * prime > num) // we would only have to go till the sqrt of num to find its prime factors
                    break;
                if (num % prime != 0)
                    continue; // go and check the divisibility with next prime number

                primeScores[index]++; // updating the count of primeScore of that isx
                while (num % prime == 0)
                    num /= prime;
            }

            if (num > 1)
            { // if any value remains lastly so means it is a prime number just increment once
                primeScores[index]++;
            }
        }

        return primeScores;
    }

    int maximumScore(vector<int> &nums, int k)
    {
        // Referred codestory with mik

        vector<int> primeScores = findPrimeScores(nums);
        // getting the prime scores each element in nums

        vector<int> nextGreater = findNextGreater(primeScores);
        // since we can take the right side elements uptill it is not greater
        // than the current primeScore, because as given in the problem if
        // in the range we have to take the element with higher PrimeScore and if equal
        // then we have to choose the one with smallest idx so we are greedily choosing
        // the current element as it is the max

        vector<int> previousGreaterOrEqual = findPreviousGreaterOrEqual(primeScores);
        // if we consider the left side then we can go uptill the element is not greater or
        // equal to even if it is equal then too we cannot consider that because in the question its been
        // said that if equalPrime Score then consider the one with lowest idx and unfortunately we would have
        // to take the smaller one which is not our motive as we are choosing greedily the maximum Value

        int n = nums.size();
        vector<long long> subarrays(n, 0); // here we would eb counting how many subarrays we can create
        // considering the elements at that particular idx

        for (int i = 0; i < n; i++)
        {
            subarrays[i] = (nextGreater[i] - i) * 1LL * (i - previousGreaterOrEqual[i]);
            // we multiply number of elements possible on the left side * possible on right side to get the
            // number of total subarrays possible
        }

        vector<pair<int, int>> sortedArray(n); // sorting the array to be greedy by choosing the maximum and storing
        // the original idx as pair
        for (int i = 0; i < n; i++)
        {
            sortedArray[i] = {nums[i], i};
        }

        sort(sortedArray.begin(), sortedArray.end(), greater<>());

        long long score = 1;
        int processingIndex = 0; // iterating on the sorted array

        while (k > 0)
        {
            auto [num, index] = sortedArray[processingIndex];           // choosing the index
            long long operations = min((long long)k, subarrays[index]); // taking the min so as we can multiply
            // that many times the same element
            score = (score * BinaryExpo(num, operations)) % MOD;
            k -= operations;

            processingIndex++;
        }

        return score;
    }
};
int main()
{

    return 0;
}