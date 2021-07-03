#include <bits/stdc++.h>
using namespace std;

/******************************** Number Theory (Prime and Prime Factorisation) *****************************/
/*
    1. Always set mxN
    2. Always Call once Sieve() from main function
    3. if nod or sod needed, call once SieveOfDivisors() from main
    4. if Eulers phi needed, call once SieveOfEulersPhi() from main
    5. now after initialization/build calls that you need, you can use IsPrime(n) , Nod(n), Sod(n), Phi(n)
*/
const int mxN = 1e7;     // maximum value to precomputation, the most preferable mxN <= 1e7
bool isp[mxN + 1];       // marking primes <= mxN. if isp[i] = 0, then i is prime, else it's composite 
int prime[mxN + 1];      // storing all primes <= mxN
int tot_primes = 0;      // total number of primes generating through sieve
int nod[mxN + 1];        // store nod <= mxN
long long sod[mxN + 1];  // store sod <= mxN
int phi[mxN + 1];        // store phi <= mxN
long long pf_list[100];  // it can be proven that total number of prime factors always will be less then 100 
int tot_pf = 0;          // total number of prime factors of a number

// Build Complexity : O(NloglogN) (Much faster Sieve)
void Sieve() {
    for (int i = 0; i <= mxN; i++) isp[i] = 0;            
    for (int i = 4; i <= mxN; i += 2) isp[i] = 1;         
    isp[0] = isp[1] = 1;                                  
    for (int i = 3; i * i <= mxN; i += 2) {               
        if (isp[i] == 0) {                                
            for (int j = i * i; j <= mxN; j += i + i) {   
                isp[j] = 1;                               
            }
        }
    }
    prime[tot_primes++] = 2;                               
    for (int i = 3; i <= mxN; i += 2) {
        if (isp[i] == 0) prime[tot_primes++] = i;
    }
}
// if n <= mxN, always query in O(1)
// else per query O(sqrtN)
// return 0 if prime, else return 1
bool IsPrime(long long n) {
    if (n <= mxN) return isp[n];
    if (n % 2 == 0) return 1;
    for (int i = 0; i < tot_primes; i++) {
        long long x = prime[i];
        if (x * x > n) return 0;
        if (n % x == 0) return 1;
    }
    return 0;
}
// if n <= mxN, works O(logN) per query
// if n >= mxN, most often works with O(logN) per query but sometimes goes O(sqrtN) in very rare.
// pf_list stores the prime factors and tot_pf is the number of prime factors of n
// example: n = 12 , the pf_list contains 2 , 2 , 3 and tot_pf = 3
long long PrimeFactorization(long long n) {
    tot_pf = 0;
    for (int i = 0; i < tot_primes; i++) {
        long long x = prime[i];
        if (x * x > n) break;
        if (n <= mxN && isp[n] == 0) break;
        if (n % x == 0) {
            while (n % x == 0) {
                n /= x;
            }
            pf_list[tot_pf++] = x;
        }
    }
    if (n != 1) pf_list[tot_pf++] = n;
    if (tot_pf <= 1) return -1;
    return pf_list[tot_pf - 1];
}
// Build Complexity : O(NlogN)
void SieveOfDivisors() {
    for (int i = 0; i <= mxN; i++) {
        nod[i] = 0;
        sod[i] = 0;
    }
    for (int i = 1; i <= mxN; i++) {
        for (int j = i; j <= mxN; j += i) {
            nod[j]++;
            sod[j] += i;
        }
    }
}
// if n <= 1e7, always works with O(1) per query
// if n >= 1e7, most often works with O(logN) per query but sometimes goes O(sqrtN) in very rare.
int Nod(int n) {
    if (n <= mxN) return nod[n];
    int ans = 1;
    for (int i = 0; i < tot_primes; i++) {
        if (n <= mxN && isp[n] == 0) break;
        int x = prime[i];
        if (x * x > n) break; 
        if (n % x == 0) {
            int cnt = 1;
            while (n % x == 0) {
                n /= x;
                cnt++;
            }
            ans *= cnt;
        }
    }
    if (n != 1) ans *= 2;
    return ans;
}
// if n <= 1e7, always works with O(1) per query
// if n >= 1e7, most often works with O(logN) per query but sometimes goes O(sqrtN) in very rare.
long long Sod(long long n) {
    if (n <= mxN) return sod[n];
    long long ans = 1;
    for (int i = 0; i < tot_primes; i++) {
        if (n <= mxN && isp[n] == 0) break;
        long long x = prime[i];
        if (x * x > n) break;
        if (n % x == 0) {
            long long tmpsum = 1, p = 1;
            while (n % x == 0) {
                n /= x;
                p *= x;
                tmpsum += p;
            }
            ans *= tmpsum;
        }
    }
    if (n != 1) ans *= (n + 1LL);
    return ans;
}
// Build Complexity : O(NlogN)
void SieveOfEulersPhi() {
    for (int i = 0; i <= mxN; i++) phi[i] = 0;
    phi[1] = 1;
    for (int i = 2; i <= mxN; i++) {
        if (phi[i] == 0) {
            phi[i] = i - 1;
            for (int j = i + i; j <= mxN; j += i) {
                if (phi[j] == 0) phi[j] = j;
                phi[j] -= phi[j] / i;
            } 
        }
    }
}
// if n <= 1e7, always works with O(1) per query
// if n >= 1e7, most often works with O(logN) per query but sometimes goes O(sqrtN) in very rare.
long long Phi(long long n) {
    if (n <= mxN) return phi[n];
    long long coprime = n;
    for (int i = 0; i < tot_primes; i++) {
        if (n <= mxN && isp[n] == 0) break;
        long long x = prime[i];
        if (x * x > n) break;
        if (n % x == 0) {
            while (n % x == 0) n /= x;
            coprime -= coprime / x;
        }
    }
    if (n != 1) coprime -= coprime / n;
    return coprime;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    Sieve();
    long long n;
    while (cin >> n) {
        if (n == 0) break;
        cout <<  PrimeFactorization(abs(n)) << "\n";
    }
    return 0;
}
