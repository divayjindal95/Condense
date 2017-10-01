#include <bits/stdc++.h>
#include "huffman.h"
#include "lz77.h"

using namespace std;

int main(){

	printf("input text\n");
	string s;
	getline(cin,s);
	
	vector<string> encoded=lz77_encode(s);

	cout<<endl<<s.length()<<endl;
	cout<<sizeof(encoded);
	return 0;
}

