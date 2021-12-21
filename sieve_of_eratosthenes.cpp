/**
 * @file Sieve_of_eratosthenes.cpp
 * @author Ahmed Shehatah (ahmed2002.eg@gmail.com)
 * @brief this code checks if a given number is prime or not 
 * using sieve of eratothenes algorthim
 * for more info about eratothenes algorthim check: https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
 * @version 0.1
 * @date 2021-12-21
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <bits/stdc++.h>
using namespace std;

// declare a bool array that indicates if the number of the index is prime or not
const int N = 10e6 + 5;
bool isPrime[N];

void sieve()
{
    // this line assgins true to all of the elements in the array
    // i.e it suppose all elements are prime
    fill(isPrime, isPrime + N, true);
    // the exception is the numbers zero and one they are not prime
    isPrime[0] = isPrime[1] = false;

    // loop to the sqrt of N to set what prime is and what it is not
    for (int i = 2; i * i < N; i++)
    {
        if (isPrime[i])
        {
            // set all multiples of i to false
            for (int j = 2 * i; j < N; j += i)
                isPrime[j] = false;
        }
    }
}

int main()
{
    int t;
    cin >> t;
    sieve();
    while (t--)
    {
        int n;
        cin >> n;
        if (isPrime[n])
            cout << "Prime";
        else
            cout << "Not Prime";
        cout << '\n';
    }
}