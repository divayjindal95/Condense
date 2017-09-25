#include <bits/stdc++.h>

using namespace std;

int char_num=256;

struct node{
	int freq;
	struct node *left;
	struct node *right;
	int val;
};

bool cmp(struct node *n1, struct node *n2){
	return n1->freq < n2->freq;
}

void inorder(node *root, std::map<char, string>){
	if(root->left==NULL && root->right==NULL)


}

std::map<char, string> make_table(node *root){

	std::map<char, string> m;
	node *n=root;
	while(m.size()!=len){
			r
	}

}

void encode(string s){

	int freq[char_num];	
	memset(freq,0,sizeof(freq));
	for(int i=0;i<char_num;i++)
		freq[s[i]]++;

	std::vector< struct node* > vec;
	for(int i=0;i<char_num;i++){
		if(freq[i]!=0){
			struct node *n;
			n->left=NULL;
			n->right=NULL;
			n->freq=freq[i];
			n->val=i;
			vec.push_back(n);
		}
	}

	make_heap(vec.begin(),vec.end(), cmp);

	while(vec.size()!=1){
		pop_heap(vec.begin(),vec.end());
		node *n1=vec[vec.size()-1];
		vec.pop_back();
		pop_heap(vec.begin(),vec.end());
		node *n2=vec[vec.size()-1];
		struct node *n;
		n->freq=n1->freq+n2->freq;
		n->left=n1;
		n->right=n2;
		n->val=-1;
		vec.push_back(n);
		push_heap(vec.begin(),vec.end());
	}
	node *root = vec[0];
	map<char, string> table = make_table(root);

}

int main(){

	printf("input text\n");
	string s;
	getline(cin,s);


	encode(s);


	return 0;
}