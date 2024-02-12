#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

class node{
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

// Create Tree
node* createTree(node* root)
{
    int data;
    cout<<"Enter the data: ";
    cin>>data;
    root = new node(data);

    if(data == -1)
        return NULL;

    cout<<"Enter data for Left of "<<data<<" : "<<endl;
    root->left = createTree(root->left);
    cout<<"Enter data for Right of "<<data<<" : "<<endl;
    root->right = createTree(root->right);

    return root;
}

//Traverse
void traverse(node* root)
{
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        node* temp = q.front();
        q.pop();
        if(temp == NULL)
        {
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

// func to return pair of bool and height
pair<bool, int> check(node* root)
{
    //base case
    if(root == NULL)
    {
        pair<bool,int>p = make_pair(true,0);
        return p;
    }

    pair<bool, int> left = check(root->left);
    pair<bool, int> right = check(root->right);

    bool leftAns = left.first;
    bool rightAns = right.first;
    bool diff = abs(left.second - right.second) <= 1;

    pair<bool,int>ans;
    ans.second = max(left.second, right.second) +1;
    if(leftAns && rightAns && diff)
        ans.first = true;
    else    
        ans.first = false;

    return ans;
}


//Check that tree is balanced or not
bool isBalanced(node* root)
{
    return check(root).first;
}

int main()
{
    node* root = NULL;
    root = createTree (root);
    traverse(root);
    if(isBalanced(root))
        cout<<"Tree is Balanced...";
    else
        cout<<"Tree is not Balanced...";
    return 0;
}