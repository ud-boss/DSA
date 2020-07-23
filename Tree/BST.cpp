#include<bits/stdc++.h>
using namespace std;

class BST
{
private:
    struct Node
    {
        struct Node *left,*right;
        int val;
        Node(int val)
        {
            this->left = NULL;
            this->right = NULL;
            this->val = val;
        };
    };
    Node *root;
public:
    BST()
    {
        root = NULL;
    }
    void NewLine()
    {
        cout<<endl<<"--------------------------------------------------------------------"<<endl;
    }
    void Insert(int data)
    {
        Node *temp = new Node(data);
        if(root == NULL)
        {
            root = temp;
            return;
        }
        Node *curr = root,*prev = NULL;
        bool isLeft = false;
        while(curr != NULL)
        {
            prev = curr;
            if(curr->val > data)
            {
                curr = curr->left;
                isLeft = true;
            }
            else
            {
                curr = curr->right;
                isLeft = false;
            }
        }
        if(isLeft)
        {
            prev->left = temp;
        }
        else
        {
            prev->right = temp;
        }
    }

    void Level()
    {
        if(root == NULL)
            return;
        queue<Node *> Q;
        Q.push(root);
        while(!Q.empty())
        {
            int s = Q.size();
            while(s--)
            {
                Node *curr = Q.front();
                Q.pop();
                cout<<curr->val<<" ";
                if(curr->left)
                    Q.push(curr->left);
                if(curr->right)
                    Q.push(curr->right);
            }
            cout<<endl;
        }
    }

    void InOrderMorris()
    {
        if(root == NULL)
            return;
        Node *curr = root;
        while(curr != NULL)
        {
            if(curr->left == NULL)
            {
                cout<<curr->val<<" ";
                curr = curr->right;
            }
            else
            {
                Node *inPred = curr->left;
                while(inPred->right != NULL && inPred->right != curr)
                {
                    inPred = inPred->right;
                }
                if(inPred->right == NULL)
                {
                    inPred->right = curr;
                    curr = curr->left;
                }
                else
                {
                    cout<<curr->val<<" ";
                    inPred->right = NULL;
                    curr = curr->right;
                }
            }
        }
    }

    void InorderStack()
    {
        if(root == NULL)
            return;
        stack<Node *> S;
        Node *curr = root;
        while(curr != NULL || !S.empty())
        {
            while(curr != NULL)
            {
                S.push(curr);
                curr = curr->left;
            }
            curr = S.top();
            S.pop();
            cout<<curr->val<<" ";
            curr = curr->right;
        }
    }

    void PreOrder()
    {
        if(root == NULL)
            return;
        stack<Node *> S;
        Node *curr = root;
        S.push(curr);
        while(!S.empty())
        {
            Node *temp = S.top();
            S.pop();
            cout<<temp->val<<" ";
            if(temp->right)
                S.push(temp->right);
            if(temp->left)
                S.push(temp->left);
        }
    }

    void PreOrderMorris()
    {
        if(root == NULL)
            return;
        Node *curr = root;
        while(curr != NULL)
        {
            if(curr->left == NULL)
            {
                cout<<curr->val<<" ";
                curr = curr->right;
            }
            else
            {
                Node *inPred = curr->left;
                while(inPred->right != NULL && inPred->right != curr)
                {
                    inPred = inPred->right;
                }
                if(inPred->right == NULL)
                {
                    cout<<curr->val<<" ";
                    inPred->right = curr;
                    curr = curr->left;
                }
                else
                {
                    inPred->right = NULL;
                    curr = curr->right;
                }
            }
        }
    }

    void PostOrder()
    {
        if(root == NULL)
            return;
        stack<Node *> S1,S2;
        S1.push(root);
        while(!S1.empty())
        {
            Node *curr = S1.top();
            S2.push(curr);
            S1.pop();
            if(curr->left)
                S1.push(curr->left);
            if(curr->right)
                S1.push(curr->right);
        }
        while(!S2.empty())
        {
            Node *curr = S2.top();
            cout<<curr->val<<" ";
            S2.pop();
        }
    }

     void PostOrderOneStack()
     {
         stack<Node *> S;
         Node *curr = root;
         do
         {
            while(curr)
            {
                if(curr->right)
                  S.push(curr->right);
                S.push(curr);
                curr = curr->left;
            }
            curr = S.top();
            S.pop();
            if(curr->right && (!S.empty() && S.top() == curr->right))
            {
                S.pop();
                S.push(curr);
                curr = curr->right;
            }
            else
            {
                cout<<curr->val<<" ";
                curr = NULL;
            }
         }while(!S.empty());
     }

     void LeftView()
     {
         if(root == NULL)
            return;
         Node *curr = root;
         int level = INT_MIN;
         queue<pair<Node *,int> > Q;
         Q.push({root,0});
         while(!Q.empty())
         {
             int sz = Q.size();
            while(sz--){
            pair<Node *,int> temp = Q.front();
            Q.pop();
            if(level < temp.second)
            {
                cout<<temp.first->val<<" ";
                level = temp.second;
            }
            if(temp.first->left)
              Q.push({temp.first->left,temp.second+1});
            if(temp.first->right)
              Q.push({temp.first->right,temp.second+1});
            }
            cout<<endl;
         }
     }

     void RightView()
     {
         if(root == NULL)
            return;
         Node *curr = root;
         int level = INT_MIN;
         queue<pair<Node *,int> > Q;
         Q.push({root,0});
         while(!Q.empty())
         {
             int sz = Q.size();
            while(sz--){
            pair<Node *,int> temp = Q.front();
            Q.pop();
            if(level < temp.second)
            {
                cout<<temp.first->val<<" ";
                level = temp.second;
            }
            if(temp.first->right)
              Q.push({temp.first->right,temp.second+1});
            if(temp.first->left)
              Q.push({temp.first->left,temp.second+1});
            }
            cout<<endl;
         }
     }

     void topView()
     {
        if(root == NULL)
            return;
        map<int,int> M;
        queue<pair<Node *,int> > Q;
        Q.push({root,0});
        while(!Q.empty())
        {
            int sz = Q.size();
            while(sz--)
            {
                Node *curr = Q.front().first;
                int level = Q.front().second;
                Q.pop();
                if(M.find(level) == M.end())
                    M[level] = curr->val;
                if(curr->left)
                    Q.push({curr->left,level-1});
                if(curr->right)
                    Q.push({curr->right,level+1});
            }
        }
        for(auto it=M.begin();it!=M.end();it++)
            cout<<it->second<<" ";
     }

     void zigZag()
     {
         if(root == NULL)
            return;
         queue<Node *> Q;
         Q.push(root);
         bool flag = true;
         while(!Q.empty())
         {
             int level = Q.size();
             vector<int> temp(level);
             for(int i=0;i<level;i++)
             {
                 Node *curr = Q.front();
                 Q.pop();
                 int index = flag ? i : level-i-1;
                 temp[index] = curr->val;
                 if(curr->left)
                    Q.push(curr->left);
                 if(curr->right)
                    Q.push(curr->right);
             }
             for(int i=0;i<temp.size();i++)
                cout<<temp[i]<<" ";
             cout<<endl;
             flag = !flag;
         }
     }
};

int main()
{
    BST t;
    int A[] = {50,20,60,70,65,55,10,30,40,45};
    int sz = sizeof(A)/sizeof(A[0]);
    for(int i=0;i<sz;i++)
    {
        t.Insert(A[i]);
    }
    t.Level();
    t.NewLine();
    t.zigZag();
    return 0;
}
