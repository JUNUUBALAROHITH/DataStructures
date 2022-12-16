#include <bits/stdc++.h>
using namespace std;
int st[100], i, j, choice = 0, n, top = -1;

void push()
{
    int val;
    if (top == n)
    {
        cout << "Overflow";
    }
    else
    {
        cout << "Enter a value : ";
        cin >> val;
        top++;
        st[top] = val;
    }
}

void pop()
{
    if (top == -1)
    {
        cout << "Stack is empty" << endl;
    }
    else
    {
        top--;
    }
}

void print()
{
    for (int i = top; i >= 0; i--)
    {
        cout << st[i] << " ";
    }
    if (top == -1)
    {
        cout << "Stack is empty";
    }
    cout << endl;
}

bool IsEmpty(){
    if(top==-1) return true;
    return false;
}

int precdence(char c){
	if(c=='^'){
		return 3;
	}
	else if(c=='*' || c=='/'){
		return 2;
	}
	else if(c=='+' || c=='-'){
		return 1;
	}
	else {
		return -1;
	}
}

string Topostfix(string s){
	char c;
	stack<int> st;
	string r;
	for(int i=0;i<s.size();i++){
		c=s[i];
		if((c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9')){
			r+=c;
		}
		else if(c=='('){
			st.push(c);
		}
		else if(c==')'){
			while(st.top()!='('){
				r+=st.top();
				st.pop();
			}
			st.pop();
		}
		else{
			while(!st.empty() && precdence(c)<=precdence(st.top())){
				if(c=='^' && st.top()=='^'){
					break;
				}
				else{
					r+=st.top();
					st.pop();
				}
			}
			st.push(c);
		}
	}
	while(!st.empty()){
		r+=st.top();
		st.pop();
	}
	cout<<r<<'\n';
	return r;
}

void PostfixEval(string s){
	int n,i,f,l;
	stack<int> st;
	n=s.size();
	for(i=0;i<n;i++){
		if(s[i]>='0' && s[i]<='9'){
			st.push(s[i]-48);
		}
		else if(s[i]=='^'){
			f=st.top();
			st.pop();
			l=st.top();
			st.pop();
			st.push(pow(l,f));
		}
		else if(s[i]=='/'){
			f=st.top();
			st.pop();
			l=st.top();
			st.pop();
			st.push(l/f);
		}
		else if(s[i]=='*'){
			f=st.top();
			st.pop();
			l=st.top();
			st.pop();
			st.push(l*f);			
		}
		else if(s[i]=='+'){
			f=st.top();
			st.pop();
			l=st.top();
			st.pop();
			st.push(l+f);
		}
		else if(s[i]=='-'){
			f=st.top();
			st.pop();
			l=st.top();
			st.pop();
			st.push(l-f);
		}
	}
	cout<<"The evaluated outcome is: "<<st.top()<<'\n';
}

int main()
{
    cout << "Enter number of elements : ";
    cin >> n;
    cout << "Stack operations using array";
    cout << endl
         << endl;
    cout << "1.Push" << endl;
    cout << "2.Pop" << endl;
    cout << "3.Print" << endl;
    cout << "4.Exit" << endl;
    while (choice != 4)
    {
        cout << "Enter a choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            push();
            break;
        }
        case 2:
        {
            pop();
            break;
        }
        case 3:
        {
            print();
            break;
        }
        case 4:
        {
            return 0;
        }
        default:
        {
            cout << "Enter a valid choice" << endl;
        }
        }
    }
}
