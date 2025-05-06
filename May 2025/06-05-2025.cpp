// https://www.geeksforgeeks.org/problems/left-view-of-binary-tree/1


class Solution {
    public:
      vector<int> leftView(Node *root) {
          
          vector<int>ans;
          
          // base case
          if(root==NULL){
              return ans;
          }
          
          // create a queue for store levelorder 
          queue<pair<Node*, int >>q;
  
          
          int level =1;
          q.push({root,level});
          
          while(!q.empty()){
              
              pair<Node*, int> temp = q.front();
              q.pop();
              
              Node* node = temp.first;
              int currLevel = temp.second;
              
              if(currLevel == level){
                  ans.push_back(node->data);
                  level++;
              }
              
              if(node->left){
                  q.push({node->left, level});
              }
              if(node->right){
                  q.push({node->right, level});
              }
          }
          
          return ans;
          
      }
  };