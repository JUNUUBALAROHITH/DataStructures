#include <bits/stdc++.h>
#define int long long
using namespace std;
int arr[1000];
int top = -1;
int rear = -1;
bool isempty();

bool isempty()
{
    if(top==-1 && rear==-1) return true;
    else return false;
}

void enqueue(int x)
{
    if (isempty())
    {
        top++;
        rear++;
        arr[rear] = x;
    }
    else
    {
        rear++;
        arr[rear] = x;
    }
}

int dequeue()
{
    int temp;
    if (isempty())
    {
        return 0;
    }
    else if (top == rear)
    {
        temp = arr[top];
        top--;
        return temp;
    }
    else
    {
        temp = arr[top];
        top++;
        return temp;
    }
}

int front()
{
    if (isempty())
    {

        return 0;
    }
    else
    {
        return arr[top];
    }
}
void display()
{
    if (isempty())
    {
        cout << "Queue is empty"
             << "\n";
    }
    else if (top == rear)
    {
        cout << "The element of the queue is: " << arr[top] << "\n";
    }
    else
    {
        cout << "The elements of queue are: ";
        int x, y;
        x = top;
        y = rear;
        while (x <= y)
        {
            cout << arr[x] << " ";
            x++;
        }
        cout << "\n";
    }
}
int32_t main()
{
    cout << "1.Create queue"
         << "\n";
    cout << "2.Delete an element"
         << "\n";
    cout << "3.Check if the queue is empty or not"
         << "\n";
    cout << "4.Print the element at the head of the queue"
         << "\n";
    cout << "5.Exit"
         << "\n";
    while (true)
    {
        cout << "Enter your choice: ";
        int c;
        cin >> c;
        if (c == 1)
        {
            cout << "Enter the number of elements u want to enter in queue: ";
            int k;
            cin >> k;
            cout << "Enter the elements: ";
            for (int i = 0; i < k; i++)
            {
                int p;
                cin >> p;
                enqueue(p);
            }
            cout << "Queue is created"
                 << "\n";
            display();
        }
        else if (c == 2)
        {
            int k;
            k = dequeue();
            if (k == 0)
            {
                cout << "Queue is empty,you can't delete an element from an empty queue"
                     << "\n";
            }
            else
            {
                cout << "The dequeued element is: " << k << "\n";
            }
            display();
        }
        else if (c == 3)
        {
            if (isempty())
            {
                cout << "The queue is empty"
                     << "\n";
            }
            else
            {
                cout << "The queue is not empty"
                     << "\n";
            }
        }
        else if (c == 4)
        {
            int k;
            k = front();
            if (k == 0)
            {
                cout << "Queue is empty"
                     << "\n";
            }
            else
            {
                cout << "The element at the head is: " << k << "\n";
            }
        }
        else
        {
            break;
        }
    }
    return 0;
}
