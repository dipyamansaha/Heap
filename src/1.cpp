// MAX-HEAP - ARRAY IMPLEMENTATION

#include<iostream>

using namespace std;

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
}
