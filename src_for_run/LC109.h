/*
Given the head of a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution109 {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        int length = get_list_length(head);
        TreeNode* ans = nullptr;
        inorder_traverse(head, ans, 0, length - 1);
        return ans;
    }

private:
    int get_list_length(ListNode* head) {
        if (head == nullptr) return 0;
        ListNode* tracker = head;
        int ans = 0;
        while (tracker!=nullptr)
        {
            ans++;
            tracker = tracker->next;
        }
        return ans;
    }

    void inorder_traverse(ListNode*& head, TreeNode*& root, int begin, int end) {
        if (begin > end || head==nullptr){
            return;
        } 
        if (begin == end) {
            root = new TreeNode(head->val);
            head = head->next;
            return;
        }
        root = new TreeNode();
        int mid = begin + (end - begin) * 0.5;
        inorder_traverse(head, root->left, begin, mid - 1);        
        root->val = head->val;
        head = head->next;
        inorder_traverse(head, root->right, mid + 1, end);
        return;
    }
};

/*
shorter solution
    TreeNode* solve(vector<int>a,int start,int end)
    {
        if(start>end)
            return NULL;
        int mid=(start+end)/2;
        TreeNode* root=new TreeNode(a[mid]);
        root->left=solve(a,start,mid-1);
        root->right=solve(a,mid+1,end);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int>a;
        ListNode* temp=head;
        while(temp)
        {
            a.push_back(temp->val);
            temp=temp->next;
        }
        return solve(a,0,a.size()-1);
    }
*/