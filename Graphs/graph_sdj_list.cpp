#include <iostream>
#include<list>
using namespace std;

class Graph{
    public:
    list<int>* adjList;
    int N;
    Graph(int n){
        adjList = new list<int> [n];
        N=n;
    }

    void addEdge(int u,int v,bool bid = true){
    adjList[u].push_back(v);
        if(bid){
            adjList[v].push_back(u);
        }
    }
    
    void print(){
        for(int i=0;i<N;i++){
            for(auto x:adjList[i]){
                cout<<x<<" ";
            }
            cout<<endl;
        }
    }


};



int main() {
    Graph g(5);

	g.addEdge(1,2);
	g.addEdge(4,2);
	g.addEdge(1,3);
	g.addEdge(4,3);
	g.addEdge(1,4);

	g.print();

	return 0;

}
