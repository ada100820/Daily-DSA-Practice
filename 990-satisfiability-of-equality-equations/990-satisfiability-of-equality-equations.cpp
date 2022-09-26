class Solution {
public:
    int parent[26];
    // find the root of node x. 
    // here we are not using parent[x],
    // because it may not contain the updated value of the connected component that x belongs to. 
    // therefore, we walk the ancestors of the vertex until we reach the root.
    int find(int x) {
        // with path compression
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
        // without path compression
        // return parent[x] == x ? x : find(parent[x]);
    }
    // the idea is to put all characters in the same group if they are equal
    // in order to do that, we can use Disjoint Set Union (dsu) aka Union Find
    // for dsu tutorial, please check out https://wingkwong.github.io/leetcode-the-hard-way/tutorials/graph-theory/disjoint-set-union
    bool equationsPossible(vector<string>& equations) {
        int n = (int) equations.size();
        // at the beginning, put each character index in its own group
        // so we will have 26 groups with one character each
        // i.e. 'a' in group 0, 'b' in group 1, ..., 'z' in group 25
        for (int i = 0; i < 26; i++) parent[i] = i;
        for (auto e : equations) {
            // if two character is equal, 
            if (e[1] == '=') {
                // e.g. a == b
                // then we group them together
                // how? we use `find` function to find out the parent group of the target character index
                // then update parent. a & b would be in group 1 (i.e. a merged into the group where b belongs to)
                // or you can also do `parent[find(e[3]- 'a')] = find(e[0] - 'a');` (i.e. b merged into the group where a belongs to)
                parent[find(e[0]- 'a')] = find(e[3] - 'a');
            }
        }
        // handle != case
        for (auto e : equations) {
            // if two characters are not equal
            // then which means their parent must not be equal
            if (e[1] == '!' && find(e[0] - 'a') == find(e[3] - 'a')) {
                return false;
            }
        }
        return true;
    }
};