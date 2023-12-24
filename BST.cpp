#include<iostream>
using namespace std;

struct node {
    int key;
    struct node *left;
    struct node *right;
};

struct node *newNode(int item)
{
    struct node *temp= (struct node *)malloc(sizeof(struct node));
    temp->key=item;
    temp->left=temp->right=NULL;
    return temp;
}
void preorder(struct node *root)
{
    if(root!=NULL)
    {
        cout<<root->key<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct node *root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout<<root->key<<" ";
        
    }
}
void inorder(struct node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        cout<<root->key<<" ";
        inorder(root->right);
    }
}
struct node *insert(struct node *node,int key)
{
    if (node==NULL) return newNode(key);
    
    if(key<node->key)
    node->left = insert(node->left,key);
    else
    node->right = insert(node->right,key);

    return node;
}

struct node *minValueNode(struct node *node)
{
    struct node *current = node;
    
    while(current && current->left!=NULL)
    current=current->left;

    return current;
}

struct node *deleteNode(struct node *root,int key)
{
    if(root==NULL) return root;
    
    if(key<root->key)
    root->left = deleteNode(root->left,key);
    else if(key>root->key)
    root->right = deleteNode(root->right,key);
    else
    {
        if (root->left==NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right==NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        struct node *temp = minValueNode(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right,temp->key);
    }
    return root;
}

int main()
{
    struct node *root=NULL;
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        root=insert(root,arr[i]);
    }
    inorder(root);
    cout<<endl;
    preorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
    deleteNode(root,6);
    inorder(root);
    cout<<endl;
    insert(root,8);
    inorder(root);
    cout<<endl;
    deleteNode(root,5);
    inorder(root);
    cout<<endl;
    return 0;
}