#include <iostream>
#include <algorithm>

using namespace std;

//1)bubble sort
void bubbleSort(int arr[], int n)
{
    bool sorted = true;
    int co = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j < n-i; j++)
        {
            if(arr[j] > arr[j+1])
            {
                swap(arr[j], arr[j+1]);
                sorted = false;
            }
            co++;
        }
        if(sorted)
            break;
    }
    cout << co << endl;
}

//2)selection sort
void seletionSort(int arr[], int n)
{
    int steps = 0;
    //bool sorted = true;

    int minIndex;
    for(int i = 0; i < n-1; i++)
    {
        minIndex = i;
        for(int j = i+1; j < n; j++)
        {
            if(arr[minIndex] > arr[j])
            {
                minIndex = j;
            }
            steps++;
        }
        swap(arr[minIndex], arr[i]);
    }
    cout << steps << endl;
}

//3)insertion sort
void insertionSort(int arr[], int n) //i 1  //r 1 //
{
    int r, key;
    int co = 0;
    int co1 = 0;

    for(int i = 1; i < n; i++)
    {
        r = i-1;
        key = i;

        while(r >= 0 && arr[key] < arr[r])
        {
            swap(arr[key], arr[r]);
            r--;
            key--;

            co++;
        }
        co1++;
    }
    cout << co+co1 << endl;
}

//4)merge sort
void divideAndSort(int arr[], int s, int m, int e)
{
    int n1 = m - s + 1;
    int n2 = e - m;

    int* leftArray = new int[n1];
    int* rightArray = new int[n2];

    //distribute items on left and right arrays
    for(int i = 0; i < n1; i++)
        leftArray[i] = arr[s+i];

    for(int j = 0; j < n2; j++)
        rightArray[j] = arr[m+1+j];

    //merging right and left arrays in sorted order
    int i, j, k;
    i = j = 0;
    k = s;

    while(i < n1 && j < n2)
    {
        if(leftArray[i] <= rightArray[j])
        {
            arr[k] = leftArray[i];
            i++;
        }
        else
        {
            arr[k] = rightArray[j];
            j++;
        }
        k++;
    }

    while(i < n1)
    {
        arr[k] = leftArray[i];
        i++;
        k++;
    }

    while(j < n2)
    {
        arr[k] = rightArray[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int s, int e)
{
    if(s < e)
    {
        int m = (s + e) / 2;
        mergeSort(arr, s, m);
        mergeSort(arr, m+1, e);
        divideAndSort(arr, s, m, e);
    }
}

//5)quick sort
int divideByPivot(int arr[], int s, int e)
{
    int i, j, p;
    i = s;
    j = e;
    p = arr[s];

    while(i < j)
    {
        do
        {
            i++;
        }while(arr[i] <= p);

        do
        {
            j--;
        }while(arr[j] > p);

        if(i < j)
            swap(arr[i], arr[j]);
    }
    swap(arr[s], arr[j]);

    return j;
}
int co = 0;
void quickSort(int arr[], int s, int e)
{
    if(s < e)
    {
        co++;
        int piv = divideByPivot(arr, s, e);
        quickSort(arr, s, piv);
        quickSort(arr, piv+1, e);
    }
}

//6)heap sort
void heapify(int arr[], int n, int i)
{
    int l = 2*i+1;
    int r = 2*i+2;
    int mx = i;

    if(l < n && arr[l] > arr[mx])
        mx = l;

    if(r < n && arr[r] > arr[mx])
        mx = r;

    if(mx != i)
    {
        swap(arr[i], arr[mx]);
        heapify(arr, n, mx);
    }
}

void buildHeap(int arr[], int s)
{
    for(int i = s / 2 -1; i >= 0; i--)
        heapify(arr, s, i);
}

void heapSort(int arr[], int n)
{
    buildHeap(arr, n);
    for(int i = n-1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main()
{
    int arr[] = {1, 6, 3, 2, -1, 12, 10, 9, 35, 100};

    heapSort(arr, 10);

    cout << co << endl;
    for(int i = 0; i < 10; i++)
        cout << arr[i] << " ";


    return 0;
}
