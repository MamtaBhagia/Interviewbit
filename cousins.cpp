#include <bits/stdc++.h> 
using namespace std; 

// A Binary Tree Node 
struct Node { 
	int data; 
	struct Node *left, *right; 
}; 

// A utility function to create a new 
// Binary Tree Node 
struct Node* newNode(int item) 
{ 
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node)); 
	temp->data = item; 
	temp->left = temp->right = NULL; 
	return temp; 
} 

// Function to find sum of cousins of 
// a given node. 
int findCousinSum(Node* root, int key) 
{ 
	if (root == NULL) 
		return 0; 
	int size; 
	// To perform level order traversal. 
	queue<Node*> q; 
	q.push(root); 

	// To represent that target node is 
	// found. 

	while (!q.empty()) { 

		// If target node is present at 
		// current level, then return 
		// sum of cousins stored in currSum. 

		// Find size of current level and 
		// traverse entire level. 
		size = q.size(); 

		while (size) { 
			root = q.front(); 
			q.pop(); 
			printf("%d ",root->data);
			// Check if either of the existing 
			// children of given node is target 
			// node or not. If yes then set 
			// found equal to true. 

			// If target node is not children of 
			// current node, then its childeren can be cousin 
			// of target node, so add their value to sum. 
				if (root->left) { 
					q.push(root->left); 
				} 

				if (root->right) { 
					q.push(root->right); 
				} 

			size--; 
		} 
		printf("\n");
	} 

	return 0; 
} 

// Driver Code 
int main() 
{ 
	/* 
				1 
			/ \ 
			3 7 
		/ \ / \ 
		6 5 4 13 
			/ / \ 
			10 17 15 
	*/

	struct Node* root = newNode(1); 
	root->left = newNode(3); 
	root->right = newNode(7); 
	root->left->left = newNode(6); 
	root->left->right = newNode(5); 
	root->left->right->left = newNode(10); 
	root->right->left = newNode(4); 
	root->right->right = newNode(13); 
	root->right->left->left = newNode(17); 
	root->right->left->right = newNode(15); 

	cout << findCousinSum(root, 13) << "\n"; 

	// cout << findCousinSum(root, 7) << "\n"; 
	return 0; 
} 
