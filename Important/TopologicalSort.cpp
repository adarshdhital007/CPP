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

void dfs(vt<vt<int>>&graph,int vertex,vt<bool>&visited,stack<int>&st){
    visited[vertex]=true;

    //visiting all adjacent vertices
    F_OR1(graph[vertex].size()){
        int adjacentVertex=graph[vertex][i];
        if(!visited[adjacentVertex]){
            dfs(graph,adjacentVertex,visited,st);
        }
    }
    st.push(vertex);
}
vt<int>topologicalsort(vt<vt<int>>&graph,int numVertices){
    vt<bool>visited(numVertices,false);
    stack<int>st;

    //performing dfs on each unvisited vertex
    F_OR1(numVertices){
        if(!visited[i]){
            dfs(graph,i,visited,st);
        }
    }
     //making topological ordering
     vt<int>result;
     while(!st.empty()){
        result.pb(st.top());
        st.pop();
     }
     reverse(result.begin(),result.end());
     return result;
}
/*
Sample I/O:
5 6
1 2
1 3
2 3
2 4
3 4
3 5
Topological Sort : 1 2 3 5 4
*/
void solve(){
    int numVertices,numEdges;
    rd(numVertices);
    rd(numEdges);

    vt<vt<int>>graph(numVertices);

    F_OR1(numEdges){
        int source, destination;
        rd(source,destination);
        graph[source-1].pb(destination-1);
    }
    vt<int>result=topologicalsort(graph,numVertices);
    wr("Topological Sort : ");
    F_OR1(result.size()){
       wr(result[result.size() - i - 1] + 1);
		wr(" ");
    }
}
  
int main(){
    solve();
    return 0;
}

