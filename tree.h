/*
Making this a header file
*/


template<class T>
 struct Node{
	T data;
	Node<T> *left;
	Node<T> *right; 
};

template<class T>
class Tree{
public:
	Node<T> *root;
	int cnt = 0;

	Tree(){
		root = NULL;
		cnt = 0;
	}
	Tree(T x){root = addNode(x);}

	//Returns the size of the tree
	int size(){
	if(root == NULL)
		return 0;
	int sz = 0;
	queue<Node<int>*> q;
	q.push(root);
	while(!q.empty()){
		Node<int> *temp = q.front();
		sz++;
		q.pop();
		if(temp->left)
				q.push(temp->left);
		if(temp->right)
			q.push(temp->right);	
	}

	return sz;
}

	Tree(T *arr, int sz){
		root = NULL;
		cnt = 0;
		for(int i=0; i<sz; i++){
			insert(arr[i]);
		}

	}

//Implement count function in the tree. Return the count of the specified element in the tree.
int count(T x){
	if(!root)
		return 0;
	queue<Node<T>*> q;
	q.push(root);
	int cnt = 0;
	while(!q.empty()){
		Node<T> *temp = q.front();
		q.pop();
		if(temp->data == x)
			cnt++;
		if(temp->left)
			q.push(temp->left);
		if(temp->right)
			q.push(temp->right);
	}

	return cnt;

}

//Implement inOrder Traversal
	void inOrder(){
	if(root){

		stack<Node<T>*> st;
		Node<T> *temp = root;
		while(temp != NULL || !st.empty()){

			//reach to the left most last node.
			while(temp != NULL){
				st.push(temp);
				temp = temp->left;
			}
			temp = st.top();
			st.pop();
			//Now the st.top() is the leftmost leaf node
			cout<<temp->data<<" ";

			//Now push this left node's 
			temp = temp->right; 

		}

	}
	else cout<<"Tree empty!"<<endl;
}

//Implement preOrder Traversal
	void preOrder(){
		if(root){
			stack<Node<T>*> st;
			st.push(root);
			while(!st.empty()){
				Node<T> *temp = st.top();
				cout<<temp->data<<" ";
				st.pop();
				if(temp->right)
					st.push(temp->right);
				if(temp->left)
					st.push(temp->left);
			}
		}
		else cout<<"Tree Empty! "<<endl;
	}

//Implement postOrder Traversal
	void postOrder(){
		if(root){
			stack<Node<T>*> st;
			Node<T> *temp = root;
			Node<T> *previous = NULL;
			do{
				while(temp){
					st.push(temp);
					temp = temp->left;
				}
				while(temp == NULL && !st.empty()){
					temp = st.top();
					if(temp->right == NULL || temp->right == previous){
						cout<<temp->data<<" ";
						previous = temp;
						temp = NULL;
						st.pop();
					}
					else temp = temp->right;
				}
			}while(!st.empty());
		}
		else cout<<"Tree Empty!"<<endl;
	}

//Implement levelOrder Traversal
	void levelOrder(){
		if(root != NULL){
			queue<Node<T>*> q;
			q.push(root);
			while(!q.empty()){
				Node<T> *temp = q.front();
				q.pop();
				cout<<temp->data<<" ";
				if(temp->left)
					q.push(temp->left);
				if(temp->right)
					q.push(temp->right);
			}
		}
		else cout<<"Tree Empty!"<<endl;

	}

//Function to create new Node for a given value of int data.
Node<T>* addNode(T x){
	Node<T> *temp = new Node<T>();
	temp->data = x;
	temp->left = temp->right = NULL;
	cnt++;
	return temp;
} 	


//Insert x in the tree at suitable position (found by level order traversal)
void insert( T x){
	if(!root){
		root = addNode(x);
		return;
	}
	queue<Node<T>*> q;
	q.push(root);
	while(!q.empty()){
		Node<T> *temp = q.front();
		q.pop();
		if(!temp->left){
			temp->left = addNode(x);
			return;
		}
		else q.push(temp->left);

		if(!temp->right){
			temp->right = addNode(x);
			return ;
		}
		else q.push(temp->right);
	}	

}
//Overload insert() to populate the tree 

//isEmpty() : Returns true if size == 0, else false
bool isEmpty(){
	return cnt == 0;
}

//Function to expose the root for use by other functions outside Tree class.

Node<T>* getRoot(){
	return root;
}

void deleteTree(){
	if(root){
		queue<Node<int>*> q;
		stack<Node<int>*> st;
		q.push(root);
		while(!q.empty()){
			Node<int> *temp = q.front();
			q.pop();
			st.push(temp);
			if(temp->right)
				q.push(temp->right);
			if(temp->left)
				q.push(temp->left);

		}

		while(!st.empty()){
			Node<int> *temp = st.top();
			free(temp);
			st.pop();
		}

		root = NULL;
	}
}


};

