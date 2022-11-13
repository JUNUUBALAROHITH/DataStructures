#include <bits/stdc++.h>
using namespace std;

struct node
{
    int key;
    node *next;
};

typedef struct node node;

node *createNode(int n)
{
    node *temp = new node;
    temp->key = n;
    temp->next = NULL;
    return temp;
}

node *append(node *head, int n)
{
    node *temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }
    temp->next = createNode(n);
    return head;
}

void bucketSort(int arr[], int k, int n)
{
    node *count[k + 1];
    for (int i = 0; i <= k; i++)
    {
        count[i] = NULL;
    }
    for (int i = 0; i < n; i++)
    {
        count[arr[i]]=append(count[arr[i]], arr[i]);
    }
    for (int i = 0; i <= k; i++)
    {
        node *temp = count[i];
        while (temp)
        {
            cout << temp->key << " ";
            temp=temp->next;
        }
    }
    cout << '\n';
}
void swap(int &a, int &b)
{
    int c = a;
    a = b;
    b = c;
}

void merge(int arr[], int l, int mid, int h)
{
    int temp[h - l + 1], k = 0;
    int i = l, j = mid + 1;
    while (i <= mid && j <= h)
    {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }
    while (i <= mid)
        temp[k++] = arr[i++];
    while (j <= h)
        temp[k++] = arr[j++];
    for (i = l; i <= h; i++)
        arr[i] = temp[i - l];
}

void mergeSort(int a[], int l, int r)
{
    if (r > l)
    {
        int m = l + (r - l) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

void maxHeapify(int arr[], int n, int i)
{
    int l = (2 * i) + 1, r = (2 * i) + 2;
    int largest = i;
    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        maxHeapify(arr, n, largest);
    }
}

void buildHeap(int arr[], int n)
{
    for (int i = (n - 2) / 2; i >= 0; i--)
    {
        maxHeapify(arr, n, i);
    }
}
void countingSort(int arr[], int exp, int n)
{
    int count[10] = {0}, output[n] = {0};
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];
    for (int i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSort(int arr[], int n)
{
    int m = 0;
    for (int i = 0; i < n; i++)
        m = max(m, arr[i]);
    for (int exp = 1; m / exp > 0; exp *= 10)
    {
        countingSort(arr, exp, n);
    }
}

void heapSort(int arr[], int n)
{
    buildHeap(arr, n);
    for (int i = n - 1; i >= 1; i--)
    {
        swap(arr[0], arr[i]);
        maxHeapify(arr, i, 0);
    }
}

void bubbleSort(int arr[], int n)
{
    for (int i = n - 1; i >= 0; i--)
    {
        int max = 0;
        for (int j = 0; j <= i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[index])
            {
                index = j;
            }
        }
        if (index != i)
            swap(arr[i], arr[index]);
    }
}

int main()
{
    int i, n;
    cin >> n;
    int arr[n];
    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int k = 0;
    for (i = 0; i < n; i++)
        k = max(k, arr[i]);
    // selectionSort(arr,n);
    // for(i=0;i<n;i++) cout<<arr[i]<<" ";
    bucketSort(arr, k, n);
    // for (i = 0; i < n; i++)
    //     cout << arr[i] << " ";
    // cout << '\n';
}
