#include<iostream>
#include<vector>
using namespace std;

class node{
    public:
    int val;
    node*left;
    node*right;
    node(int val,node*left,node*right){
        this->val=val;
        this->left=left;
        this->right=right;
    }
};

node*construct_tree(vector<int>arr,int s,int e){
    if(s>e){
        return NULL;
    }
    int mid=(s+e)/2;
    node*left=construct_tree(arr,s,mid-1);
    node*right=construct_tree(arr,mid+1,e);
    node*root=new node(arr[mid],left,right);
    return root;



}

int bstmax(node*root){
    if(root->right!=NULL){
        return bstmax(root->right);
    }else{
        return root->val;
    }
}
void display(node*root){
    if(root==NULL){
        return;
    }
    string str=root->left!=NULL?to_string(root->left->val):".";
    str+= "<-"+to_string(root->val)+"->";
    str+=root->right!=NULL?to_string(root->right->val):".";
    cout<<str<<endl;
    display(root->left);
    display(root->right);
}


node*removeval(node*root,int target){
    if(root==NULL){
        return NULL;
    }
    if(target>root->val){
        root->right=removeval(root->right,target);
    }else if(target<root->val){
        root->right =removeval(root->left,target);
    }else{
        if(root->left!=NULL and root->right!=NULL){
            int lmax=bstmax(root->left);
            root->val=lmax;
            root->left=removeval(root->left,lmax);
            
            
        }else if(root->left!=NULL){
            return root->left;
        }else if(root->right!=NULL){
            return root->right;
        }else{
            return NULL;
        }
    }
    return root;
}



int main(){
    vector<int>arr={12,25,37,45,62,75,87};
    node*root=construct_tree(arr,0,arr.size()-1);
    display(removeval(root,75));
   

}