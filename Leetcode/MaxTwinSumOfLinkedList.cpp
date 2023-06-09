#include <bits/stdc++.h>
using namespace std;
/*adarshdhital007*/
#define ll long long
#define ld long double
#define ar array
#define vt vector
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
    
#define F_OR(i, a, b, s) for (int i=(a); (s)>0?i<(b):i>(b); i+=(s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)
#define EACH(x, a) for (auto& x: a)
    
template<class T> bool umin(T& a, const T& b) {
    return b<a?a=b, 1:0;
}
template<class T> bool umax(T& a, const T& b) { 
    return a<b?a=b, 1:0;
} 
    
ll FT(function<bool(ll)> f, ll lb, ll rb) {
    while(lb<rb) {
        ll mb=(lb+rb)/2;
        f(mb)?rb=mb:lb=mb+1; 
    } 
    return lb;
}
ll LT(function<bool(ll)> f, ll lb, ll rb) {
    while(lb<rb) {
        ll mb=(lb+rb+1)/2;
        f(mb)?lb=mb:rb=mb-1; 
    } 
    return lb;
}
    
template<class A> void rd(vt<A>& v);
template<class A, size_t S> void rd(ar<A, S>& a);
template<class T> void rd(T& x) {
    cin >> x;
}
void rd(double& d) {
    string t;
    rd(t);
    d=stod(t);
}
void rd(long double& d) {
    string t;
    rd(t);
    d=stold(t);
}
template<class H, class... T> void rd(H& h, T&... t) {
    rd(h);
    rd(t...);
}
template<class A> void rd(vt<A>& x) {
    EACH(a, x)
        rd(a);
}
template<class A, size_t S> void rd(array<A, S>& x) {
    EACH(a, x)
        rd(a);
}
    
string to_string(char c) {
    return string(1, c);
}
string to_string(bool b) {
    return b?"true":"false";
}
string to_string(const char* s) {
    return string(s);
}
string to_string(string s) {
    return s;
}
string to_string(vt<bool> v) {
    string res;
    FOR(sz(v))
        res+=char('0'+v[i]);
    return res;
}
    
template<size_t S> string to_string(bitset<S> b) {
    string res;
    FOR(S)
        res+=char('0'+b[i]);
    return res;
}
template<class T> string to_string(T v) {
    bool f=1;
    string res;
    EACH(x, v) {
        if(!f)
            res+=' ';
        f=0;
        res+=to_string(x);
    }
    return res;
}
    
template<class A> void wr(A x) {
    cout << to_string(x);
}
template<class H, class... T> void wr(const H& h, const T&... t) { 
    wr(h);
    wr(t...);
}
void print() {
    wr("\n");
}
template<class H, class... T> void print(const H& h, const T&... t) { 
    wr(h);
    if(sizeof...(t))
        wr(' ');
    print(t...);
}
const int d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const int d8i[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]={0, 1, 1, 1, 0, -1, -1, -1}; 


struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    int pairSum(ListNode* head) {
        int sum = INT_MIN;
        vt<int> demo;
        while (head != NULL) {
            demo.push_back(head->val);
            head = head->next;
        }
        int n = demo.size();
        //just doing the loop till n/2 as given 
        F_OR3(i,0,n/2) {
            sum = max(sum, demo[i] + demo[n - 1 - i]);
        }
        return sum;
    }
};

void solve() {
   
    ListNode* head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);

    Solution solution;
    int result = solution.pairSum(head);
    cout << "Maximum twin sum: " << result << endl;


    delete head->next->next->next;
    delete head->next->next;
    delete head->next;
    delete head;
}

int main() {
    solve();
    return 0;
}


//Using stack

 /*
Create a ListNode pointer current and initialize it to head.
Initialize an integer stack st to store the node values in the linked list.
Iterate while current is not null:
      -->Push current->val into st.
      -->Update current to current->next.
Set current back to head to iterate the list again from the start.
Initialize size as st.size() and count as 1 to count the number of twin pairs.
Create an integer variable maximumSum and initialize it to 0 to track the maximum sum of a node and its twin.
While count is less than or equal to size/2:
    -->Update maximumSum if the current twin sum is greater than the previous one:
     maximumSum = max(maximumSum, current->val + st.top()).
    -->Update current to current->next.
    -->Pop the top element from the stack st.
    -->Increment count by 1.
Return maximumSum.
*/

 /*
class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode* current = head;
        stack<int> st;

        while (current) {
            st.push(current->val);
            current = current->next;
        }

        current = head;
        int size = st.size(), count = 1;
        int maximumSum = 0;
        while (count <= size / 2) {
            maximumSum = max(maximumSum, current->val + st.top());
            current = current->next;
            st.pop();
            count++;
        }

        return maximumSum;
    }
};
*/