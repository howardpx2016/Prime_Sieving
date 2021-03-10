#include <bits/stdc++.h>
#include <iostream>
#include <ctime>
#include "get_time.h"
using namespace std;
 
void SieveOfEratosthenes(int n) {
    bool *prime = new bool[n + 1];
    memset(prime, true, n+1); //set all values to true
 
    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true)
        {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
 
    // Print all prime numbers
    int pCount = 0;
    for (int p = 2; p <= n; p++) { 
        if (prime[p]) {
            pCount++;
            // cout << p << " ";
        }
    }
    cout << pCount;
    
    delete[] prime;
}
 
// Driver Code
int main(int argc, char* argv[]) {
//   if (argc == 1) {
//     fprintf(stderr, "Usage: %s [num_of_elements]\n", argv[0]);
//     exit(EXIT_FAILURE);
//   }
//   int n = atoi(argv[1]);
int testValue = 0;

    for (int i = 0; i <= 10; i++) {
        testValue = pow(2, 20+i);
        cout << "2^" << 20+i << ": ";
        for (int i = 0; i < 3; i++) {
            timer t;
            SieveOfEratosthenes(testValue);
            t.stop();
            cout << " - " << t.get_total() << ", ";
        }
        cout << endl;
    }
    
    return 0;
}