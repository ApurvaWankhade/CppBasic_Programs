#include <iostream>
using namespace std;

struct node {
    int data;
    struct node* left;
    struct node* right;
    bool rthread;
    bool lthread;
};


struct node *insert(struct node *root, int k)
{
    node *ptr = root;
    node *par = NULL;
    while(ptr!=NULL)
    {
        if(k==(ptr->data))
        {
            return root;
        }
        par=ptr;
        if(k< ptr->data)
        {
            if(ptr->lthread == false)
            ptr = ptr->left;
            else 
            break;
        }
        else
        {
            if(ptr->rthread == false)
            ptr = ptr->right;
            else 
            break;
        }
    }
    
    node *tmp = new node;
    tmp->data =k;
    tmp->lthread=true;
    tmp->rthread=true;
    if (par == NULL) 
    { 
        root = tmp; 
        tmp -> left = NULL; 
        tmp -> right = NULL; 
    } 
    else if (k<(par ->data)) 
    { 
        tmp -> left = par -> left; 
        tmp -> right = par; 
        par -> lthread = false; 
        par -> left = tmp; 
    } 
    else
    { 
        tmp -> left = par; 
        tmp -> right = par -> right; 
        par -> rthread = false; 
        par -> right = tmp; 
    } 
  
    return root; 
}

struct node *inordersuccessor(struct node *ptr)
{
    if(ptr->rthread==true)
    return ptr->right;
    ptr=ptr->right;
    while(ptr->lthread==false)
    ptr=ptr->left;
    return ptr;
}

void inorder(struct node *root) 
{ 
    if (root == NULL) 
        printf("Tree is empty"); 
    struct node *ptr = root; 
    while (ptr->lthread == false) 
        ptr = ptr->left; 

    while (ptr != NULL) 
    { 
        printf("%d ",ptr -> data); 
        ptr = inordersuccessor(ptr); 
    } 
} 

int main() {
    int n, value;
    cin >> n;

    struct node* root = NULL;

    for (int i = 0; i < n; i++) {
        cin >> value;
        root = insert(root, value);
    }
    inorder(root);

    return 0;
}