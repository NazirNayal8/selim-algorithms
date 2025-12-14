#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


/* 
How can we check if a number a is divisible by another number b?

if (a % b == 0){
    // a is divisible by b
} else {
    // a is not divisible by b
}

*/

bool is_prime(long long n, int x) {    
    if(x!=n){
        if(n%x!=0){
            return is_prime(n,x+1);
        } else{
            return false;
        }
    } else{
        return true;
    }
}

bool is_prime2(long long n, int x) {
    if (x == n) {
        return true;
    }
    if (n % x == 0) {
        return false;
    }
    return is_prime2(n, x + 1);
}

bool is_prime3(long long n) {

    // complexity of this is O(n)
    for (int i = 2 ; i < n ; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

bool is_prime4_sqrt(long long n) {

    // complexity of this is O(sqrt(n))
    for (int i = 2 ; i <= sqrt(n) ; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int N = 1000000; // we can give up 10^9
vector<bool> is_prime_number(N);

void compute_sieve_of_eratosthenes() {
    for (int i = 2; i < N; i++) {
        is_prime_number[i] = true;
    }
    
    // i < sqrt(N)
    // i * i < N

    for (int i = 2; i * i < N; i++) {
        if (is_prime_number[i]) {
            for (int j = 2*i ; j < N ; j += i) {
                is_prime_number[j] = false;
            }
        }
    }

}

bool is_prime_sieve(int n) {
    return is_prime_number[n];
}

// i = 3
// start from 9
// 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24 ..... N
// T  T  F  T  F  T  F  F  F   T    F   T   F   F   F   T   F   T   F   F  F    T  F *             *

// O(1)
// to obtain all primes up to N, we need O(N * sqrt(N)) time.
// sieve algorithm is an algorithm that can generate all primes up to N in O(N log(log(N))) time.

/* 
Logarithm Function

log(n) is the exponent to which a base number must be raised to produce that number n
let's assume a base 2
(log n) is the power of 2 that gives us n
2^x = n  => x = log2(n)
2^x = 8 , log2(8) = 3
log2(1024) = 10
log2(1,048,576) = 20 -> 2^20 = 1,048,576
log^2=n

log2(16) = 4
log2(log2(16)) = log2(4) = 2
log4(16)
log2(log(1,048,576)) = log2(20) = 4.3
loglog2(n)(n) = x -> log2(n)^x = n

log2(a * b) = log2(a) + log2(b)
log2(8 * 1024) = log(8) + log(1024) = 3 + 10 = 13


*/
// 36 
// 36 = 2 * 18
// 36 = 3 * 12
// 36 = 4 * 9
// 36 = 6 * 6
// 36 = 9 * 4


int main() {
  
    long long n = 11;

    if (n > 1 && is_prime(n, 2)) {
        cout << n << " is prime." << endl;
    } else {
        cout << n << " is not prime." << endl;
    }

    // Sieve of Eratosthenes
}