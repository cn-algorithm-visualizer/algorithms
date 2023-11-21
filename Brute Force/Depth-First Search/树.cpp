#include <string>
#include <iostream>
#include "algorithm-visualizer.h"

using namespace std;


int G[11][11] = { 
    // G[i][j] "表示从第i个节点到第j个节点的路径是否存在"
  {0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
};

// 定义追踪器变量 {
GraphTracer tracer("图");

LogTracer logger("日志");

// }

void DFS(int node, int parent) { // node = 当前节点, parent = 前一个节点
  // 可视化控制 {
  tracer.visit(node, parent);
  Tracer::delay();
  // }

  int length = sizeof(G[node]) / sizeof(G[node][0]);
  for (int i = 0; i < length; i++) {
    if (G[node][i]) { // 如果当前节点有第i个节点作为子节点
      DFS(i, node); // 递归调用深度优先搜索DFS
    }
  }
}

int main() {
    // 可视化控制 {
    tracer.log(logger);
    Layout::setRoot(VerticalLayout({tracer, logger}));
    tracer.set(G);
    
    tracer.layoutTree(0);
    Tracer::delay();
    // }
    DFS(0,0);
    return 0;
}
