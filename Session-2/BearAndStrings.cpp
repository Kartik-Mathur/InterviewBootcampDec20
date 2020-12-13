#include <iostream>
using namespace std;
#define ll long long

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	string s;
	cin>>s;
	ll ans = 0;
	for(int i = 0 ; i < s.length() ; i++){
		int j = s.substr(i).find("bear");
		if(j!=-1){
			ans += s.length()-(i+j+3);
		}
	}

	cout<<ans<<endl;
	return 0;
}