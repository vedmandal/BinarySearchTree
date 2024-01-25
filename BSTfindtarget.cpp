


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


bool bstfind(node*root,int data){
    if(root==NULL){
        return false;
    }
    if(data>root->val){
        return bstfind(root->right, data);
    }else if(data<root->val){
        return bstfind(root->left, data);
    }else{
        return true;
    }
}


int main(){
    vector<int>arr={12,25,37,45,62,75,87};
    node*root=construct_tree(arr,0,arr.size()-1);
    cout<<bstfind(root,45);
   

}