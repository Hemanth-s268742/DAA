#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Bubble Sort
void bubble(vector<int> &a)
{
    int size = a.size();

    for(int i = 0; i < size - 1; i++)
    {
        bool swapped = false;

        for(int j = 0; j < size - i - 1; j++)
        {
            if(a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
                swapped = true;
            }
        }

        if(!swapped)
            break;
    }
}

// Selection Sort
void selectSort(vector<int> &a)
{
    int size = a.size();

    for(int i = 0; i < size - 1; i++)
    {
        int smallest = i;

        for(int j = i + 1; j < size; j++)
        {
            if(a[j] < a[smallest])
                smallest = j;
        }

        if(smallest != i)
            swap(a[i], a[smallest]);
    }
}

// Insertion Sort
void insertSort(vector<int> &a)
{
    int size = a.size();

    for(int i = 1; i < size; i++)
    {
        int current = a[i];
        int j = i - 1;

        while(j >= 0 && a[j] > current)
        {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = current;
    }
}

// Merge Sort
void mergeArray(vector<int> &a, int left, int mid, int right)
{
    vector<int> temp;

    int i = left;
    int j = mid + 1;

    while(i <= mid && j <= right)
    {
        if(a[i] <= a[j])
            temp.push_back(a[i++]);
        else
            temp.push_back(a[j++]);
    }

    while(i <= mid)
        temp.push_back(a[i++]);

    while(j <= right)
        temp.push_back(a[j++]);

    for(int k = 0; k < temp.size(); k++)
        a[left + k] = temp[k];
}

void mergeDivide(vector<int> &a, int left, int right)
{
    if(left >= right)
        return;

    int mid = left + (right - left) / 2;

    mergeDivide(a, left, mid);
    mergeDivide(a, mid + 1, right);

    mergeArray(a, left, mid, right);
}

// Quick Sort
int partitionArray(vector<int> &a, int low, int high)
{
    int pivot = a[low];
    int i = low + 1;
    int j = high;

    while(true)
    {
        while(i <= high && a[i] <= pivot)
            i++;

        while(a[j] > pivot)
            j--;

        if(i >= j)
            break;

        swap(a[i], a[j]);
    }

    swap(a[low], a[j]);

    return j;
}

void quickArrange(vector<int> &a, int low, int high)
{
    if(low < high)
    {
        int p = partitionArray(a, low, high);

        quickArrange(a, low, p - 1);
        quickArrange(a, p + 1, high);
    }
}

int main()
{
    const int SIZE = 100;

    vector<int> numbers(SIZE);
    vector<int> sample;

    srand((unsigned)time(NULL));

    for(int i = 0; i < SIZE; i++)
        numbers[i] = rand() % 1000;

    cout << "Total Elements : " << SIZE << "\n\n";

    auto start = high_resolution_clock::now();
    sample = numbers;
    bubble(sample);
    auto end = high_resolution_clock::now();
    cout << "Bubble Sort Time    : "
         << duration_cast<microseconds>(end - start).count()
         << " microseconds\n";

    start = high_resolution_clock::now();
    sample = numbers;
    selectSort(sample);
    end = high_resolution_clock::now();
    cout << "Selection Sort Time : "
         << duration_cast<microseconds>(end - start).count()
         << " microseconds\n";

    start = high_resolution_clock::now();
    sample = numbers;
    insertSort(sample);
    end = high_resolution_clock::now();
    cout << "Insertion Sort Time : "
         << duration_cast<microseconds>(end - start).count()
         << " microseconds\n";

    start = high_resolution_clock::now();
    sample = numbers;
    mergeDivide(sample, 0, SIZE - 1);
    end = high_resolution_clock::now();
    cout << "Merge Sort Time     : "
         << duration_cast<microseconds>(end - start).count()
         << " microseconds\n";

    start = high_resolution_clock::now();
    sample = numbers;
    quickArrange(sample, 0, SIZE - 1);
    end = high_resolution_clock::now();
    cout << "Quick Sort Time     : "
         << duration_cast<microseconds>(end - start).count()
         << " microseconds\n";

    return 0;
}