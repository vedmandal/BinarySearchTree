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
node*addNode(node*root,int val){
    if(root==NULL){
        return new node(val,NULL,NULL);
    }
    if(val>root->val){
        root->right=addNode(root->right,val);
    }else if(val<root->val){
        root->left=addNode(root->left,val);
    }else{

    }
    return root;
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


int main(){
    vector<int>arr={12,25,37,45,62,75,87};
    node*root=construct_tree(arr,0,arr.size()-1);
    display(addNode(root,95));
   

}