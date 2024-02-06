#include<iostream>
#include<queue>
using namespace std;

class node 
{
    public:
        int data;
        node* left;
        node* right;

    node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

// Function to create the Tree using Recursion
node* BuildTree(node* root)
{
    int data;
    cout<<"Enter the data: "<<endl;
    cin>>data;

    // creating node
    root = new node(data);

    //Base Condition
    if(data == -1)
        return NULL;
    
    // create left and right child recusively
    cout<<"Enter data for left of "<<data<<": "<<endl;
    root->left = BuildTree(root->left);
    cout<<"Enter data for right of "<<data<<": "<<endl;
    root->right = BuildTree(root->right);

    return root;
}

// Traverse the tree level wise i.e BFS
void Traverse(node* root)
{
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    
    while(!q.empty())
    {
        node* temp = q.front();
        q.pop();

        if(temp == NULL){
            cout<<endl;
            if(!q.empty())
                q.push(NULL);
        }

        else{
            cout<<temp->data<<" ";
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
    }
}

// Inorder Traversal FORMULA - (Left->NODE->Right)
void inorder(node* root)
{
    if(root == NULL)
        return;

    inorder(root->left);
    cout<<root->data<< " ";
    inorder(root->right);
}

// Preorder Traversal FORMULA - (NODE->Left->Right)
void preorder(node* root)
{
    if(root == NULL)
        return;
    
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

// PostOrder Traversal FORMULA - (Left->Right->NODE)
void postorder(node* root)
{
    if(root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

int main()
{
    node* root = NULL;
    // 1 2 4 6 -1 -1 7 -1 -1 5 -1 -1 3 8 10 -1 -1 11 -1 -1 9 -1 -1
    root = BuildTree(root);
    cout<<"\n Level Wise Traversal: \n";
    Traverse(root);
    cout<<"\n Inorder Traversal: ";
    inorder(root);
    cout<<"\n Preorder Traversal: ";
    preorder(root);
    cout<<"\n Postorder Traversal: ";
    postorder(root);
    return 0;
}