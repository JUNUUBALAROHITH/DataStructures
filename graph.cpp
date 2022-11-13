#include <bits/stdc++.h>
using namespace std;
#define MAX_SIZE 10000
#define MAX_ARRAY 100
struct node
{
    char data;
    struct node *link;
};
bool visited[MAX_SIZE];
node *graph[MAX_SIZE];
// int arr[MAX_ARRAY][MAX_ARRAY];

node *insertatlast(node *head, char c)
{
    node *p, *temp;
    if (!head)
    {
        temp = new node;
        temp->data = c;
        temp->link = NULL;
        return temp;
    }
    else
    {
        temp = head;
        while (temp->link)
        {
            temp = temp->link;
        }
        p = new node();
        p->data = c;
        p->link = NULL;
        temp->link = p;
        return head;
    }
}

void traversal(struct node *head)
{
    if (!head)
        return;
    struct node *p = head;
    while (p != NULL)
    {
        cout << p->data;
        if (p->link)
            cout << "->";
        p = p->link;
    }
    cout << endl;
}

node *addEdge(char c1, char c2)
{
    if (graph[c1 - 64] == NULL)
    {
        graph[c1 - 64] = insertatlast(graph[c1 - 64], c1);
        graph[c1 - 64] = insertatlast(graph[c1 - 64], c2);
    }
    else
    {
        graph[c1 - 64] = insertatlast(graph[c1 - 64], c2);
    }
    return graph[c1 - 64];
}
stack<char> s;
void topoLogicalSort(int i)
{
    if (visited[i] == true)
        return;
    visited[i] = true;
    node *temp = graph[i]->link;
    for (; temp; temp = temp->link)
    {
        if (!visited[temp->data - 64])
        {
            topoLogicalSort(temp->data - 64);
        }
    }
    s.push(i + 64);
}

void dfs(char c)
{
    node *temp;
    visited[c - 64] = true;
    cout << c << " ";
    for (temp = graph[c - 64]; temp; temp = temp->link)
    {
        if (!visited[temp->data - 64])
            dfs(temp->data);
    }
}

void bfs(char c)
{
    node *temp;
    queue<char> q;
    cout << c << " ";
    q.push(c);
    visited[c - 64] = true;
    while (q.empty() == false)
    {
        c = q.front();
        q.pop();
        for (temp = graph[c - 64]; temp; temp = temp->link)
        {
            if (!visited[temp->data - 64])
            {
                cout << temp->data << " ";
                q.push(temp->data);
                visited[temp->data - 64] = true;
            }
        }
    }
}

void dfsTopoSort(char c, stack<char> st)
{
    visited[c] = true;
    for (node *temp = graph[c - 64]; temp; temp = temp->link)
    {
        if (!visited[temp->data])
            dfsTopoSort(temp->data, st);
    }
    st.push(c);
}

void topoSort(int n, int m)
{
    stack<char> st;
    for (char c = 'A'; c <= 'G'; c++)
    {
        if (!visited[c])
        {
            dfsTopoSort(c, st);
        }
    }
    while (st.empty() == false)
    {
        cout << st.top() << " ";
        st.pop();
    }
}

int main()
{
    int n, m, i, j;
    char c1, c2;
    // for(i=0;i<MAX_ARRAY;i++){
    // 	for(j=0;j<MAX_ARRAY;j++){
    // 		arr[i][j]=0;
    // 	}
    // }
    // Adjacency List
    cout << "m=";
    cin >> m;
    cout << "n=";
    cin >> n;
    cout << "Enter " << n << " pair of vertices, each of which is representing an edge:\n";
    for (i = 1; i <= n; i++)
    {
        cin >> c1 >> c2;
        graph[c1 - 64] = addEdge(c1, c2);
        // arr[c1-64][c2-64]=1;
    }
    cout << "Adjacency List :\n";
    for (i = 1; i <= m; i++)
    {
        traversal(graph[i]);
    }
    // // Adjacency Matrix
    // cout<<"Adjacency Matrix :\n";
    // char c='A';
    // cout<<"  ";
    // for(i=1;i<=m;i++){
    // 	cout<<c<<" ";
    // 	c++;
    // }
    // c='A';cout<<'\n';
    // for(i=1;i<=m;i++){
    // 	cout<<c<<" ";
    // 	for(j=1;j<=m;j++){
    // 		cout<<arr[i][j]<<" ";
    // 	}
    // 	cout<<'\n';c++;
    // }
    // dfs('A);
    // bfs('A');
    // topoSort(n,m);
}
