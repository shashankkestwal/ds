#include <bits/stdc++.h> 
using namespace std;

class Graph{
  public:
    list<int> adjacecenyList;
    int vertices;
  
    void breadthFirstSearch(int start){
      cout << "Visiting order in BFS " << endl;
      queue<int> q;
      int visited[vertices] = {0};
      int j;
      q.push(j);

      while(!q.empty()){
        j = q.front();
        cout << j <<"   ";
        visited[j] = 1;

        list<int>::iterator it;
        for (it = adjacecenyList.begin(); it != adjacecenyList.end(); ++it) {
          if (visited[*it] == 0 ) {
            cout << *it <<"  ";
            visited[*it] = 1;
            q.push(*it);
          }

        }
        q.pop();

      }
    }

  
};


int main() {
  Graph g;
  cout << "Enter the adjacency matrix" << endl;
  cout << "Enter the number of vertices : ";
  cin >> g.vertices;
  for (int i = 0; i < g.vertices; ++i) {
    cout << "for vertex " << i << endl;
    for (int j = 0; j < g.vertices; ++j) {
      cout << "Is "<<i <<" adjacent to "<< j <<" (press y for yes ,else any other key)"; 

      char val;
      cin >> val;
      if (val == 'y'){
        g.adjacecenyList.push_back(j);
      }
    }
  }
  // input of the adjacenecy matrix

  cout << "Enter the starting vertex";
  int starting;
  cin >> starting;
  g.breadthFirstSearch(starting);
  // g.depthFirstSearch(starting);

  return 0;
}

