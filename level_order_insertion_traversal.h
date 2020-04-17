#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

void level_order(Node* root)
{
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        Node* temp = q.front();
        q.pop();
        if(temp == NULL)
        {
            cout << "NULL" <<" ";
        }
        else 
        {
            cout << temp -> data << " ";
            q.push(temp -> left);
            q.push(temp -> right);
        }
    }
}

void insert(Node* root, int val)
{
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        Node* temp =  q.front();
        q.pop();
        if(!temp -> left)
        {
            temp -> left = new Node(val);
            break;
        }
        else if(!temp -> right)
        {
            temp -> right = new Node(val);
            break;
        }
        else
        {
            q.push(temp -> left);
            q.push(temp -> right);
        }
    }
}

int main()
{
    int i, n, val;
    Node* root;
	//Number of nodes. 
    cin >> n;
    for(i = 1; i <= n; i++)
    {
        cin >> val;
        if(i == 1)
        {
            root = new Node(val);
        }
        else
        {
            insert(root, val);
        }
    }
    level_order(root);
    return 0;
}