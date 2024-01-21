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
int bstsize(node*root){
    if(root==NULL){
        return 0;
    }
    return bstsize(root->left)+bstsize(root->right)+1;
}


int main(){
    vector<int>arr={12,25,37,45,62,75,87};
    node*root=construct_tree(arr,0,arr.size()-1);
    cout<<bstsize(root);
    

}