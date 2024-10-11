/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        return helper(0, preorder.length-1, 0, inorder.length-1, preorder, inorder);
    }
    private TreeNode helper (int preL, int preR, int inL, int inR, int[] preorder, int[] inorder) {
        if(preL > preR || inL > inR) return null;
        int rootVal = preorder[preL], inRootIndx = inL;
        while(inorder[inRootIndx] != rootVal) inRootIndx++;
        TreeNode root = new TreeNode(rootVal);
        root.left = helper(preL+1, preL+inRootIndx-inL, inL, inRootIndx-1, preorder, inorder);
        root.right = helper(preL+inRootIndx-inL+1, preR, inRootIndx+1, inR, preorder, inorder);
        return root;
    }
}