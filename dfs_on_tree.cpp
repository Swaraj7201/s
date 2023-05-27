#include<bits/stdc++.h>
using namespace std;


struct Node{
    int data;
    vector <Node* > children;

    Node(int data){
        this->data= data;
    }
};

void dfs(Node* root){
    if(root== nullptr)
    {
        return;
    }

    cout<<root->data<<" , ";

    int n = root->children.size();

    for(int i=0; i<n; i++){
        dfs(root->children[i]);
    }
}


void bfs(Node* root){
    if(root == nullptr) return;

    queue <Node*> q;
    q.push(root);

    while(!q.empty()){
        
        Node* curr = q.front();
        cout<<curr->data<<" , ";
        q.pop();

        int n = curr->children.size();

        for(int i=0; i<n; i++){
            q.push(curr->children[i]);
        }

        
    }

}
 
int main()
{

    Node* root = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    Node* node5 = new Node(5);
    Node* node6 = new Node(6);
    Node* node7 = new Node(7);
    Node* node8 = new Node(8);
    Node* node9 = new Node(9);

    root->children.push_back(node2);
    root->children.push_back(node3);
    root->children.push_back(node8);

    node2->children.push_back(node4);

    node3->children.push_back(node5);
    node3->children.push_back(node6);
    node3->children.push_back(node7);

    node7->children.push_back(node9);
    node7->children.push_back(node9);


    cout<<endl;
    bfs(root);

    return 0;
}