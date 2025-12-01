#include <iostream>
#include <list>
using namespace std;
struct graph {
    int vertices;
    list<int> *l;

    graph(int v){
        vertices = v;
        this->l = new list<int>[v];
    }

    void add_edge(int u, int v) {
        l[u].push_back(v);
        l[v].push_back(u);
    }
};
int main(){
    
    return 0;
}