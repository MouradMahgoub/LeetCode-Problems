class Solution {
    List<String> ans = new LinkedList<String>();
    String[] mp = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    private void foo (int i, String temp, String digits) {
        if(temp.length() > 0 && temp.length() == digits.length()){
            ans.add(temp);
            return;
        }
        for(int j=i+1; j<digits.length(); j++){
                for(int k=0; k<mp[digits.charAt(j) - '0'].length(); k++){
                    foo(j, temp + mp[digits.charAt(j) - '0'].charAt(k), digits);
                }
        }
    }

    public List<String> letterCombinations(String digits) {
        foo(-1, "", digits);
        return ans;
    }
}