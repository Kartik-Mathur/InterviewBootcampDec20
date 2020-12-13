#include <iostream>
using namespace std;

void Paranthesis(char *a,int i,int n,int open,int close){
	// base case
	if(i == 2*n){
		a[i] = '\0';
		cout<<a<<endl;
		return;
	}
	// recursive case
	if(open<n){
		// add '('
		a[i] = '(';
		Paranthesis(a,i+1,n,open+1,close);
	}
	if(close<open){
		// add ')'
		a[i] = ')';
		Paranthesis(a,i+1,n,open,close+1);
	}
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int n;
	cin>>n;
	char a[100];
	Paranthesis(a,0,n,0,0);

	cout<<endl;
	return 0;
}