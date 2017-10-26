#include <bits/stdc++.h>

using namespace std;

int LENGTH=100;
int DISTANCE=100;

std::vector<char> lz77_encode(string s){
	std::vector<char> buff;
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
			string temp;
			temp="<"+distance;
			buff.push_back('<');
			buff.push_back(distance);
			temp+=length;
			buff.push_back(length);
			temp+=",";
			buff.push_back(',');
			temp+=">";
			buff.push_back('>');
			//buff.push_back(temp);
			cout<<"<"<<distance<<","<<length<<">";
		}
		else{
			buff.push_back(s[i]);
			cout<<s[i];
		}
		i=i+length;
	}
	return buff;
}

void decode(string s){
	return;
}

/*
int main(){

	printf("input text\n");
	string s;
	getline(cin,s);

	lz77_encode(s);

	return 0;
}
*/