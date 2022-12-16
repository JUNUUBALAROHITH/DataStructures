#include<bits/stdc++.h>
using namespace std;
#define MAX_EDGES 100000
struct edge
{
    int vertex1,weight,vertex2;
};

edge arr[MAX_EDGES];
int parent[10001];

bool compare(edge a,edge b){  
    if(a.weight<b.weight) return true;
    return false;
}

int find(int a){  
    if(parent[a]==-1) return a;
    else return find(parent[a]);
}

void merge(int a,int b){  
    parent[a]=b;
}

int main(){
    int n,m;
    int a,b,w,sum=0;
    cout<<"Enter number of vertices: ";
    cin>>n;
    cout<<"Enter number of edges: ";
    cin>>m;
    for(int i=1;i<=n;i++) parent[i]=-1;
    cout<<"Enter vertex1 and vertex2 and weight of edge(vertex1,vertex2) respectively:\n";
    for(int i=0;i<m;i++){
        cin>>arr[i].vertex1>>arr[i].vertex2>>arr[i].weight;

    }
    sort(arr,arr+m,compare); 
    for(int i=0;i<m;i++){
        a=find(arr[i].vertex1);
        b=find(arr[i].vertex2);
        if(a!=b){
            sum=sum+arr[i].weight;
            merge(a,b);  
        }
    }
    cout<<"The cost of minimum spanning tree is: "<<sum;
}


