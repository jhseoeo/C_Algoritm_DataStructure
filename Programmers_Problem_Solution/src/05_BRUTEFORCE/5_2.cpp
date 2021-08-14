#include "Problems5.h"

#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

static const int MAXPRIME = 3163;
static bool numbers[MAXPRIME] = { false, };
static vector<int> primes;
static vector<int> foundPrime;

static void initialize() {
    foundPrime.clear();
    for (int i = 2; i < MAXPRIME; i++) {
        if (!numbers[i]) {
            primes.push_back(i);
            for (int j = i * 2; j < MAXPRIME; j += i)
                numbers[j] = true;
        }
    }
}

static bool isPrime(const int n) {
    if (n == 2) return true;

    for (size_t i = 0; i < primes.size(); i++) {
        if (n % primes[i] == 0)         return false;
        else if (primes[i] * primes[i] >= n)   return true;
    }

    return true;
}

static void divide(const string& numbers, const int n) {
    if (numbers.size() == 0) {
        
        if (find(foundPrime.begin(), foundPrime.end(), n) != foundPrime.end()) return;
        else if (n <= 1)        return;
        
        else if (!isPrime(n))   return;
        else { foundPrime.push_back(n); cout << n << " ";
        }
    }

    for (size_t i = 0; i < numbers.size(); i++) {
        int c = numbers[i] - '0';

        divide(numbers.substr(0, i) + numbers.substr(i + 1), n * 10 + c);
        divide(numbers.substr(0, i) + numbers.substr(i + 1), n);
    }
}

static int solution(string numbers) {
    divide(numbers, 0);
    return foundPrime.size();
}

void solution_5_2() {
    initialize();

    cout << isPrime(2) << endl;

    AutomatedInput Input;
    Input.set(
        "1 "
        //"17 "
        //"011 "
        "1234 "
    );

    int T;
    Input >> T;

    initialize();
    
    for (int trial = 0; trial < T; trial++) {
        string numbers;
        Input >> numbers;

        cout << solution(numbers) << endl;
    }
}