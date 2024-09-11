/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        int moveI[] = {0, 1, 0, -1};
        int moveJ[] = {1, 0, -1, 0};
        vector<vector<int>> ans(m, vector<int> (n, -1));
        int i=0, j=0, dir=0;
        while(head){
            ans[i][j] = head->val;
            head = head->next;
            int newI = i + moveI[dir], newJ = j + moveJ[dir];
            if(newI < 0 || newJ < 0 || newI > m-1 || newJ > n-1 || ans[newI][newJ] != -1){
                dir = (dir+1)%4;
            }
            i += moveI[dir];
            j += moveJ[dir];
        }
        return ans;
    }
};