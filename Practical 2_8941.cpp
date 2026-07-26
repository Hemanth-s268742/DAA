#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace chrono;

// Linear Search
int linearSearch(const vector<int>& arr, int key)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == key)
            return i;
    }
    return -1;
}

// Binary Search
int binarySearch(const vector<int>& arr,int key)
{
    int left = 0, right = arr.size()-1;

    while (left <= right)
    {
        int mid = left + (right - left)/2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int main()
{
    int n = 200000;
    vector<int> arr(n);

    // Fill sorted array
    for (int i = 0; i < n; i++)
        arr[i] = i + 1;

    int key;
    cout << "Enter element to search: ";
    cin >> key;

    int result;

    // -------- Linear Search Timing --------
    auto start1 = high_resolution_clock::now();
    result = linearSearch(arr, key);
    auto end1 = high_resolution_clock::now();

    auto time1 = duration_cast<microseconds>(end1 - start1);

    cout << "\nLinear Search:\n";
    if (result != -1)
        cout << "Found at index: " << result << endl;
    else
        cout << "Not found\n";

    cout << "Time Taken: " << time1.count() << " microseconds\n";

    // -------- Binary Search Timing --------
    auto start2 = high_resolution_clock::now();
    result = binarySearch(arr, key);
    auto end2 = high_resolution_clock::now();

    auto time2 = duration_cast<microseconds>(end2 - start2);

    cout << "\nBinary Search:\n";
    if (result != -1)
        cout << "Found at index: " << result << endl;
    else
        cout << "Not found\n";

    cout << "Time Taken: " << time2.count() << " microseconds\n";

    return 0;
}