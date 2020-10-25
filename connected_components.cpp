#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <memory>
#include <utility>
#include <vector>

using namespace std;

struct ConnectedComponent {
  list<int> vertices;
  bool visited;
};

int main() {
  // ========================== INPUT BEGIN =================================
  const int vertex_cnt = 17;
  vector< pair<int, int> > edges;
  edges.push_back(make_pair(1, 9));
  edges.push_back(make_pair(5, 11));
  edges.push_back(make_pair(8, 10));
  edges.push_back(make_pair(10, 4));
  edges.push_back(make_pair(6, 5));
  edges.push_back(make_pair(2, 14));
  edges.push_back(make_pair(2, 0));
  edges.push_back(make_pair(0, 8));
  edges.push_back(make_pair(9, 3));
  // ========================== INPUT END ==================================

  // ======================== ALGORITHM BEGIN ==============================
  // Initialization. Every vertex is itself a connected component.
  vector< shared_ptr<ConnectedComponent> > conn_comps;
  conn_comps.reserve(vertex_cnt);
  for (int i = 0; i < vertex_cnt; ++i) {
    shared_ptr<ConnectedComponent> comp(new ConnectedComponent);
    comp->visited = false;
    comp->vertices.push_back(i);
    conn_comps.push_back(comp);
  }

  for (const auto edge : edges) {
    auto comp_large = conn_comps[edge.first];
    auto comp_small = conn_comps[edge.second];
    if (comp_large->vertices.size() < comp_small->vertices.size()) {
      comp_large = conn_comps[edge.second];
      comp_small = conn_comps[edge.first];
    }
    if (comp_large.get() != comp_small.get()) {
      for (auto vertex : comp_small->vertices) {
        conn_comps[vertex] = comp_large;
      }
      comp_large->vertices.splice(
        comp_large->vertices.end(), comp_small->vertices);
    }
  }
  // ======================== ALGORITHM END ================================

  // ======================== OUTPUT BEGIN =================================
  cout << "Vertices of each connected components:" << endl;
  int comp_idx = 0;
  for (auto comp : conn_comps) {
    if (!comp->visited) {
      auto &vertices = comp->vertices;
      vertices.sort();
      cout << "Component " << comp_idx++ << ":";
      for (auto vertex : vertices) {
        cout << " " << vertex;
      }
      cout << endl;
      comp->visited = true;
    }
  }
  // ======================== OUTPUT END ===================================

  return 0;
}

/**
 * Relevant coding test questions:
 * 
 * https://atcoder.jp/contests/arc106/tasks/arc106_b
 */
