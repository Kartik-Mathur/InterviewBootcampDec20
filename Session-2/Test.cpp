#include <iostream>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	
	int t;
	cin>>t;
	while(t--){
		string str,pat;
		cin>>str>>pat;

		int *fstr = new int[26];
		int *fpat = new int[26];

		for(int i = 0 ; i < 26 ; i++) fpat[i] = fstr[i] = 0;

		for(int i = 0 ; i < pat.length() ; i++){
			fpat[pat[i]-'a']++;
		}

		int cnt = 0, start = 0, start_index = -1, min_len = INT_MAX;
		for(int i = 0; i < str.length() ; i++){
			fstr[str[i]-'a']++;

			if(fpat[str[i]-'a']>0 && fpat[str[i]-'a']>=fstr[str[i]-'a']){
				cnt++;
			}
			if(cnt == pat.length()){
				while(fstr[str[start]-'a'] > fpat[str[start]-'a'] || fpat[str[start]-'a'] == 0){
					if(fstr[str[start]-'a'] > fpat[str[start]-'a'])fstr[str[start]-'a']--;
					start++;
				}
				int len_window = i- start+1;
				if(min_len>len_window){
					min_len = len_window;
					start_index = start;
				}
			}
		}

		if(start_index == -1){
			cout<<"-1"<<endl;
		}
		else{
			for(int i = start_index ; i < start_index + min_len ; i++){
				cout<<str[i];
			}
			cout<<endl;
		}
	}

	return 0;
}





















