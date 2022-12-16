#include <bits/stdc++.h>
using namespace std;
#define int long long
int t;
const int MAX = 100001;

void solve()
{
}

// Quick sort faster than Merge sort as quick sort is tail recursive but merge is not tail recursive
// preorder,inorder traversal --> tail recursive
// postorder traversal --> non tail recursive

void printNto1(int n){ // "TAIL RECURSION" comparitively faster than non tail recursion
    if(n==0) return;
    cout<<n<<" ";
    printNto1(n-1);
}

void printNto1(int n){ // tail call elimination
    start:
    if(n==0) return;
    cout<<n<<' ';
    n--;
    goto start;
}

void print1toN(int n){
    if(n==0) return;
    print1toN(n-1);
    cout<<n<<" ";  // just interchanging lines reverses the pattern
}
int k=1;
void print1toN(int n,int k){ // coverting to tail recursive with some auxilary space 
    if(n==0) return;
    cout<<k<<' ';
    print1toN(n-1,k+1); 
}

int k=1;
int fact(int n,int k){ // tail recursion
    if(n==1 || n==0) return k;
    return fact(n-1,k*n);
}


int start=0,end=n-1;
bool isPalindrome(string s,int start,int end){
    if(start>=end) return true;
    return (s[start]==s[end] && isPalindrome(s,start+1,end-1));
}

int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // cin >> t;
    t = 1;
    while (t--)
    {
        solve();
    }
}