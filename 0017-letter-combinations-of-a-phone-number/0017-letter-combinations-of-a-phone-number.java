class Solution {
    List<String> ans = new LinkedList<String>();
    String[] mp = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    private void foo (int i, String temp, String digits) {
        if(i == digits.length()){
            if(temp.length() > 0) ans.add(temp);
            return;
        }
        for(int k=0; k<mp[digits.charAt(i) - '0'].length(); k++)
            foo(i+1, temp + mp[digits.charAt(i) - '0'].charAt(k), digits);
    }

    public List<String> letterCombinations(String digits) {
        foo(0, "", digits);
        return ans;
    }
}