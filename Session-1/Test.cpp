#include <iostream>
using namespace std;

int main(){
	string s;
	cin>>s;

	int n = s.length(),ans = 0;
	for(int i = 0 ; i < n ; i++){
		int l = s.substr(i).find("bear");
		if(l!=-1){
			ans += s.size()-(i+l+3);
		}
	}
	cout<<ans<<endl;
	return 0;
}