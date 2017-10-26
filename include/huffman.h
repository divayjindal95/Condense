#include <bits/stdc++.h>

using namespace std;

int char_num=256;

std::map<char, string> lookup_table;

struct node{
	int freq;
	struct node *left;
	struct node *right;
	int val;
};

// HEAP


/* Generic Print function
template <typename T>
void print(T arr){
	T::iterator it;
	for(it=arr.begin();it!=arr.end();it++)
		return;
}
*/

void inorder(node *root){
	//cout<<root<<"\n";
	if(root==NULL)	return;
	inorder(root->left);
	cout<<root->freq;
	inorder(root->right);
}

bool cmp(struct node *n1, struct node *n2){
	return n1->freq > n2->freq;
}

void make_table(node *root, string code){

	if(root->left==NULL && root->right==NULL){
		lookup_table[root->val]=code;
		cout<<root->val<<" "<<code<<endl;
		return;
	}

	if (root->left!=NULL) make_table(root->left,code+'0');
	if (root->right!=NULL) make_table(root->right,code+'1');

}

std::vector<char> huffman_encode(std::vector<char> s){

	int freq[char_num];	
	memset(freq,0,sizeof(freq));
	for(int i=0;i<s.size();i++)
		freq[s[i]]++;

	std::vector< struct node* > vec;
	for(int i=0;i<char_num;i++){
		if(freq[i]!=0){
			struct node *n = new struct node;
			n->left=NULL;
			n->right=NULL;
			n->freq=freq[i];
			n->val=i;
			vec.push_back(n);
		}
	}

	make_heap(vec.begin(),vec.end(), cmp);
	while(vec.size()!=1){
		for(int i=0;i<vec.size();i++){
			cout<<vec[i]->val<<" "<<vec[i]->freq<<" "<<vec[i]->left<<" "<<vec[i]->right<<" "<<vec[i]<<endl;
		}
		cout<<"\n";
		pop_heap(vec.begin(),vec.end(),cmp);

		node *n1 =vec[vec.size()-1];

		vec.pop_back();

		pop_heap(vec.begin(),vec.end(),cmp);
		node *n2=vec[vec.size()-1];
		vec.pop_back();

		struct node *n=new struct node;
		n->freq=n1->freq+n2->freq;
		n->left=n1;
		n->right=n2;
		n->val=-1;
		vec.push_back(n);
		push_heap(vec.begin(),vec.end(),cmp);
	}

	for(int i=0;i<vec.size();i++){
		cout<<vec[i]->val<<" "<<vec[i]->freq<<" "<<vec[i]->left<<" "<<vec[i]->right<<" "<<vec[i]<<endl;
	}
	cout<<"\n";

	node *root = vec[0];
	//cout<<root->left<<" "<<root->left->freq<<endl;
	//cout<<root->right<<" "<<root->right->freq<<endl;
	//cout<<root->left->left->left;
	//inorder(root);
	make_table(root,"");

	for(std::map<char, string>::iterator it=lookup_table.begin();it!=lookup_table.end();it++)
		cout<<it->first<<" " <<it->second<<"\n";

	vector<char> buff;
	for(int i=0;i<s.size();i++)
		for(int j=0;j<lookup_table[s[i]].length();j++)
			buff.push_back(lookup_table[s[i]][j]);

	for(int i=0;i<buff.size();i++)
		cout<<buff[i];

	return buff;

}

/*
int main(){

	printf("input text\n");
	string s;
	getline(cin,s);

	encode(s);

	return 0;
}
*/