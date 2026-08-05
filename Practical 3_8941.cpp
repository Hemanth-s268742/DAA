#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <algorithm>

using namespace std;
using namespace chrono;

// -------- MAX HEAPIFY --------
void maxHeapify(vector<int> &arr, int size, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && arr[left] > arr[largest])
        largest = left;

    if (right < size && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        maxHeapify(arr, size, largest);
    }
}

// -------- MAX HEAP SORT --------
void maxHeapSort(vector<int> &arr)
{
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(arr, n, i);

    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        maxHeapify(arr, i, 0);
    }
}

// -------- MIN HEAPIFY --------
void minHeapify(vector<int> &arr, int size, int i)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && arr[left] < arr[smallest])
        smallest = left;

    if (right < size && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i)
    {
        swap(arr[i], arr[smallest]);
        minHeapify(arr, size, smallest);
    }
}

// -------- MIN HEAP SORT --------
void minHeapSort(vector<int> &arr)
{
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; i--)
        minHeapify(arr, n, i);

    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        minHeapify(arr, i, 0);
    }
    reverse(arr.begin(), arr.end());
}

// -------- MAIN --------
int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);

    srand(time(0));
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 100000;

    vector<int> maxArr = arr;
    vector<int> minArr = arr;

    // MAX HEAP TIME
    auto startMax = high_resolution_clock::now();
    maxHeapSort(maxArr);
    auto endMax = high_resolution_clock::now();

    // MIN HEAP TIME
    auto startMin = high_resolution_clock::now();
    minHeapSort(minArr);
    auto endMin = high_resolution_clock::now();

    // TIME CALCULATION
    auto nanoMax = duration_cast<nanoseconds>(endMax - startMax);
    auto microMax = duration_cast<microseconds>(endMax - startMax);

    auto nanoMin = duration_cast<nanoseconds>(endMin - startMin);
    auto microMin = duration_cast<microseconds>(endMin - startMin);

    // OUTPUT
    cout << "\n========== MAX HEAP SORT ==========\n";
    cout << "Nanoseconds  : " << nanoMax.count() << " ns\n";
    cout << "Microseconds : " << microMax.count() << " us\n";

    cout << "\n========== MIN HEAP SORT ==========\n";
    cout << "Nanoseconds  : " << nanoMin.count() << " ns\n";
    cout << "Microseconds : " << microMin.count() << " us\n";

    return 0;
}