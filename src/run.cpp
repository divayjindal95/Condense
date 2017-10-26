#include <bits/stdc++.h>
#include "../include/huffman.h"
#include "../include/lz77.h"

using namespace std;

int main(){

	printf("input text\n");
	string s;
	getline(cin,s);
	
	vector<char> lz77_encoded=lz77_encode(s);

	cout<<endl<<s.length()<<" "<<lz77_encoded.size()<<endl;

	vector<char> huff_encoded=huffman_encode(lz77_encoded);
	cout<<huff_encoded.size();
	int len = huff_encoded.size();
	bitset<25> b1;
	return 0;
}

