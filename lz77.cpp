#include <bits/stdc++.h>

using namespace std;

int LENGTH=100;
int DISTANCE=100;

void encode(string s){
	for(int i=0;i<s.length();){
		int length=1,distance=0;
		for(int j=max(0,i-DISTANCE);j<i;j++){
			int k=0;
			while(k<LENGTH && s[j+k]==s[i+k] && j<i && i<s.length())
				k++;

			if(k>length){
				length=k;
				distance=i-j;
			}
		}
		if(length>1){
			cout<<"<"<<length<<","<<distance<<">";
		}
		else
			cout<<s[i];
		i=i+length;
	}
}

void decode(string s){
	return;
}

int main(){

	printf("input text\n");
	string s;
	getline(cin,s);

	encode(s);

	return 0;
}