#include <iostream>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif


	string a,b;

	cin>>a>>b;
	int n = a.length(), m = b.length();
	bool isNegative = false;
	if(a[0] == '-' && b[0] != '-'){
		isNegative = true;
		a = a.substr(1); // -1234 -> 1234
		n--;
	}
	else if(a[0] != '-' && b[0] == '-'){
		isNegative = true;
		b = b.substr(1); // -1234 -> 1234
		m--;
	}
	else if(a[0] == '-' && b[0] == '-'){
		b = b.substr(1);
		a = a.substr(1);
		n--; m--;
	}

	int *ans = new int[a.length() + b.length()];
	for(int i = 0 ; i < m+n ; i++)ans[i] = 0;

	for(int i = n-1; i>=0 ; i--){
		for(int j = m- 1; j>=0 ; j--){
			int mul = (a[i]-'0')*(b[j]-'0')+ans[i+j+1];
			ans[i+j+1] = (mul)%10;
			ans[i+j] += mul/10;
		}
	}

	// for(int i = 0; i <m+n ; i++){
	// 	cout<<ans[i]<<' ';
	// }
	// cout<<endl;

	string x;
	for(int i = 0 ; i < m+n ; i++){
		if(x.length()!=0 || ans[i]!=0){
			x.push_back(ans[i]+'0');
		}
	}
	if(isNegative) x = "-"+x;
	
	cout<<x<<endl;
	return 0;
}