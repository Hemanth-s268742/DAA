#include <iostream>
#include <chrono>
using namespace std;

// Function to find factorial using loop (Iterative)
long long factorialLoop(int n) {
    long long result = 1;

    for(int i = 1; i <= n; i++) {
        result = result * i;
    }

    return result;
}

// Function to find factorial using recursion
long long factorialRec(int n) {
    if(n == 0 || n == 1)
        return 1;

    return n * factorialRec(n - 1);
}

int main() {
    int n;

    cout << "Enter a non-negative number: ";
    cin >> n;

    // Check for invalid input
    if(n < 0) {
        cout << "Invalid input! Please enter a non-negative number." << endl;
        return 0;
    }

    // Measure time for Iterative method
    auto start1 = chrono::steady_clock::now();
    long long iterResult = factorialLoop(n);
    auto end1 = chrono::steady_clock::now();

    auto iterTime = chrono::duration_cast<chrono::nanoseconds>(end1 - start1);

    // Measure time for Recursive method
    auto start2 = chrono::steady_clock::now();
    long long recResult = factorialRec(n);
    auto end2 = chrono::steady_clock::now();

    auto recTime = chrono::duration_cast<chrono::nanoseconds>(end2 - start2);

    // Display Results
    cout << "\n--- Factorial Results ---" << endl;

    cout << "Iterative Method Result : " << iterResult << endl;
    cout << "Time Taken (Iterative)  : " << iterTime.count() << " ns" << endl;

    cout << "----------------------------------" << endl;

    cout << "Recursive Method Result : " << recResult << endl;
    cout << "Time Taken (Recursive)  : " << recTime.count() << " ns" << endl;

    return 0;
}