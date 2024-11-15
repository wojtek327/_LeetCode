public class Solution {
    public bool IsValid(string s) {
        var stack = new Stack<char>();
        Dictionary<char, char> map = new Dictionary<char, char>() {
            { '(', ')'},
            { '[', ']'},
            { '{', '}'}
        };
        
        foreach (var c in s)
        {
            if (map.ContainsKey(c)) {
                stack.Push(c);
            }
            else if (stack.Count == 0 || map[stack.Pop()] != c) {
                return false;
            }
        }
        
        return stack.Count == 0 ? true : false;
    }
}