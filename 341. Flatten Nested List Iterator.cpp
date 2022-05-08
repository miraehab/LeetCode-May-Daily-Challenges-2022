/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
    vector<int> flattened_list;
    int i = 0;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for (auto x : nestedList) {
            make_flat(x);
        }
    }
    
    void make_flat(NestedInteger x) {
        if (x.isInteger()) {
            flattened_list.push_back(x.getInteger());
        }
        else {
            for (auto y : x.getList()){
                make_flat(y);
            }
        }
    }
    
    int next() {
        return flattened_list[i++];
    }
    
    bool hasNext() {
        return i < flattened_list.size();
    }
    
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */