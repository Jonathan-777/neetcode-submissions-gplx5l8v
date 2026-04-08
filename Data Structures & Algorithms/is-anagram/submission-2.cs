public class Solution {
    public bool IsAnagram(string s, string t) {
        char[] S = s.ToCharArray();
        Array.Sort(S);
        s = new string(S);

        char[] T = t.ToCharArray();
        Array.Sort(T);
        t= new string(T);

       return (s == t)? true : false;

    }
}
