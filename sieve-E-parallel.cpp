#include <cilk/cilk.h>
#include <cilk/cilk_api.h>
#include <bits/stdc++.h>
#include <iostream>
#include <ctime>
#include <cmath>
#include "get_time.h"
using namespace std;
 
void sieveE(int n) {
    bool *prime = new bool[n + 1];
    memset(prime, true, n+1); //set all values to true
 
    for (int i = 2; i <= sqrt(n); i++) {
        if (prime[i] == true)
        {
            cilk_for (int p = pow(i,2); p <= n; p = p + i)
                prime[p] = false;
        }
    }
    
    //print prime count
    int pCount = 0;
    for (int j = 2; j <= n; j++) { 
        if (prime[j] == true) {
            pCount++;
        }
    }
    cout << pCount;
    
    delete[] prime;
}
 
// Driver Code
int main() {
    int testValue = 0;

    for (int i = 0; i <= 10; i++) {
        testValue = pow(2, 20+i);
        // cout << "2^" << 20+i << ": ";
        cout << testValue << ": ";
        for (int i = 0; i < 3; i++) {
            timer t;
            sieveE(testValue);
            t.stop();
            cout << " - " << t.get_total() << ", ";
        }
        cout << endl;
    }
    
    return 0;
}