/*

Find the max in Binary Tree.

1. Recursive Approach (T : O(n), S: O(n) )

2. Iterative Approach ( Use level order traversal.) (T : O(n), S: O(n) )
		


*/

#include<bits/stdc++.h>

using namespace std;

#include"tree.h"

int max(int a, int b){
	return a > b ? a: b;
}

//  int i = 0, ret = 0;
// int maxInBTRecursive(Node<int> *root){
// 	//cout<<i++<<endl;
// 	int left, right, rootVal, mx = INT_MIN;
// 	if(root){
// 		//cout<<++i<<endl;
// 		rootVal = root->data;
// 		cout<<"Root is now  : "<<rootVal<<endl;
// 		cout<<"calling "<<rootVal<<" ->left "<<endl;
// 		left = maxInBTRecursive(root->left);
// 		cout<<"Root is now  : "<<rootVal<<endl;
// 		cout<<"calling "<<rootVal<<" ->right "<<endl;
// 		right = maxInBTRecursive(root->right);
// 		cout<<"Root is now  : "<<rootVal<<endl;
// 		mx  =  max(rootVal,max(left,right));
// 		cout<<"mx is : "<<mx<<endl;
// 	}//cout<<"ret : "<<i--<<endl;
// 	return mx;
// }



int maxInBTRecursive(Node<int> *root){
	int left, right, rootVal, mx = INT_MIN;
	if(root){
		rootVal = root->data;
		left = maxInBTRecursive(root->left);
		right = maxInBTRecursive(root->right);
		mx  =  max(rootVal,max(left,right));
	}
		return mx;
}

//The iterative method uses level order to check for the greatest element.
int maxInBTIterative(Node<int> *root){
	if(root){
		queue<Node<int>*> q;
		int mx = INT_MIN;
		q.push(root);
		while(!q.empty()){
			Node<int>* temp = q.front();
			q.pop();
			if(mx < temp->data)
				mx = temp->data;
			if(temp->left)
				q.push(temp->left);
			if(temp->right)
				q.push(temp->right);
		}
		return mx;
	}
	else return -1;
}

int main(){
	
	freopen("input.txt","r",stdin);
	freopen("output.txt", "w", stdout);

	int arr[] = {1,2,31,4,5,6,7};

	Tree<int> tree(arr,7);
	Node<int> *temp = tree.getRoot();

	cout<<maxInBTIterative(temp);



	return 0;
}