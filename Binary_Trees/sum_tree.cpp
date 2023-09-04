// T.C O(n)
// S.C O(Height of tree)

class Solution{
    public:
        pair<bool,int> isSumTreeFast(Node* root){
            // base case
            if(root == NULL){
                pair<bool,int> p = make_pair(true,0);
                return p;
            }
            // leaf Node
            if(root->left == NULL && root->right == NULL){
                pair<bool,int> p = make_pair(true,root->data);
                return p;               
            }

            pair<bool,int> leftAns = isSumTreeFast(root->left);
            pair<bool,int> rightAns = isSumTreeFast(root->right);

            bool left = leftAns.first;
            bool right = rightAns.first;

            bool condn  = root->data == (leftAns.second + rightAns.second);

            pair<bool,int> ans;

            if(left && right && condn){
                ans.first = true;
                ans.second = 2* root->data;
            }
            else {
                ans.first = false;
            }
            return ans;
            
        }

        bool isSumTree(Node* root){
            return isSumTreeFast(root).first;
        }
}