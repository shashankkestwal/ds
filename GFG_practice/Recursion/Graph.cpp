#include<bits/stdc++.h>
using namespace std;

vector<int> graph[6];
vector<vector<int>> component;
vector <int> curr;
int counter = 0;
int level[6];

bool findCycle(int vertex,int parent, bool visited[]) {
  bool hasCycle = false;
  visited[vertex] = true;
  // cout << vertex << "  ";
  // curr.push_back(vertex);
  for(auto child: graph[vertex] ) {
    if(visited[child] == true && child == parent )continue;
    if(visited[child] == true) {
      return true;
    }
    // OR operator
    hasCycle |=  findCycle(child, vertex ,visited);
  }
  return hasCycle;
}

void Bfs(int source, bool visited[]) {
  queue<int> q;
  q.push(source);
  visited[source] = 1;
  level[source] = 1;
  while(!q.empty()) {
    int curr = q.front();
    q.pop();
    cout << curr << "    ";
    cout << level[curr] << endl;
    for(int i : graph[curr]) {
      if(!visited[i]) {
        q.push(i);
        visited[i] = true;
        level[i] = level[curr] + 1;
      }
    }
  }
}


int main() {
  int vertex = 6;
  // string s = "2abcdefgh";
  // if(s[0] - '0' ==  1 ) {
  //   s =  s.substr(2,s.length()-2);
  // } else {
  //   s[0] = s[0]-'1'+'0';
  // }
  // cout << s;



  bool visited[6];
  // cout << "Number of Vertices : ";
  // cin >> vertex;
  // for(int i = 0; i < vertex; i++) {

  // }

  graph[1].push_back(2);
  graph[1].push_back(3);
  graph[3].push_back(2);
  // graph[2+1].push_back(1+1);

  // graph[1].push_back(3);
  // graph[3].push_back(1);

  // graph[3+1].push_back(2+1);
  // graph[2+1].push_back(3+1);

  // graph[4+1].push_back(3+1);
  // graph[3+1].push_back(4+1);

  // Bfs(1,visited);



  for(int i = 1; i < 6 ; i++) {
    if(visited[i]) continue;
    // curr.clear();
    cout << findCycle(i,0,visited);
    // component.push_back(curr);
    counter++;
  }

  // cout << "Number of conected components : " << component.size() << endl;  
  cout << endl;

}