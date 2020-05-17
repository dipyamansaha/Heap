// BASIC MAX-HEAP OPERATIONS

#include<iostream>

using namespace std;

void MaxHeapify(int Arr[], int n, int i);

void HeapIncreaseKey(int Arr[], int i, int key)
{
    if (key < Arr[i])
    {
        cout << "\nThat's NOT an increase!";
        return;
    }

    Arr[i] = key;

    while ((i > 0) && (Arr[i/2] < Arr[i]))
    {
        int temp = Arr[i];
        Arr[i] = Arr[i/2];
        Arr[i/2] = temp;

        i/=2;
    }
}

int HeapExtractMax(int Arr[], int n)
{
    if(n < 1)
    {
        cout << "\nHeap underflow!";
        return -1;
    }

    int max = Arr[1];
    Arr[1] = Arr[n];
    n--;

    MaxHeapify(Arr, n, 1);

    return max;
}

void MaxHeapify(int Arr[], int n, int i)
{
    int l = 2*i;
    int r = (2*i + 1);

    int largest;

    if((l <= n) && (Arr[l] > Arr[i]))
        largest = l;
    else
        largest = i;

    if((r <= n) && (Arr[r] > Arr[largest]))
        largest = r;

    if(largest != i)
    {
        int temp = Arr[i];
        Arr[i] = Arr[largest];
        Arr[largest] = temp;

        MaxHeapify(Arr, n, largest);
    }
}

void BuildMaxHeap(int Arr[], int n)
{
    for(int i = n/2; i >= 1; i--)
        MaxHeapify(Arr, n, i);
}

int main()
{
    int n;

    cout << "How many elements do you wanna insert? ";
    cin >> n;

    int Arr[n];

    cout << "\nEnter the elements: " << endl;
    for(int i = 1; i <= n; i++)
    {
        cin >> Arr[i];
    }

    cout << "\nThe entered array: " << endl;
    for(int i = 1; i <= n; i ++)
    {
        cout << Arr[i] << endl;
    }

    BuildMaxHeap(Arr, n);
    cout << "\nThe max heap: " << endl;
    for(int i = 1; i <= n; i ++)
    {
        cout << Arr[i] << endl;
    }

    int max = HeapExtractMax(Arr, n);
    cout << "\nThe maximum element in the heap: " << max << endl;
    cout << max << " is deleted from the max-heap!" << endl;

    cout << "\nThe new max heap: " << endl;
    for(int i = 1; i <= (n-1); i ++)
    {
        cout << Arr[i] << endl;
    }

    char c1;
    cout << "\nDo you want to increase the value of any element in the heap? (y/n): ";
    cin >> c1;

    char c2 = 'n';

    if(c1 == 'y')
    {
        cout << "\nDo you instead want to insert a new element at a new position? (y/n): ";
        cin >> c2;

        if(c2 == 'y')
        {
            int e;

            cout << "\nEnter the new element: ";
            cin >> e;

            HeapIncreaseKey(Arr, n, e);
        }
        else
        {
            int i, key;

            cout << "\nEnter the index (1-4) of the element and the increased value respectively: " << endl;
            cin >> i >> key;

            HeapIncreaseKey(Arr, i, key);
        }
    }
    else
        exit(0);

    if(c2 == 'y')
    {
        cout << "\nThe new max heap: " << endl;
        for(int i = 1; i <= n; i ++)
        {
            cout << Arr[i] << endl;
        }
    }
    else
    {
        cout << "\nThe new max heap: " << endl;
        for(int i = 1; i <= (n - 1); i ++)
        {
            cout << Arr[i] << endl;
        }
    }
}
