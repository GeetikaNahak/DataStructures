// Given two BSTs, return elements of merged BSTs in sorted form.

void inorder(Node* r,vector<int>&s){
    if(!r)return;
    inorder(r->left,s);
    s.push_back(r->data);
    inorder(r->right,s);
}

vector<int> merge(Node *root1, Node *root2) {
        // Your code here
    vector<int>s1,s2,res;
    inorder(root1,s1);
    inorder(root2,s2);
    int i=0,j=0;
    while(i<s1.size() && j<s2.size()){
        if(s1[i]>s2[j]){
            res.push_back(s2[j++]);
        }
        else res.push_back(s1[i++]);
    }
    while(i<s1.size())res.push_back(s1[i++]);
    while(j<s2.size())res.push_back(s2[j++]);
    return res;
}
