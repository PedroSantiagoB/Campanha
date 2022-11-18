//---------------------------------------------------------------------
// File	: main.cpp
// Content: main implementation 
// Author	: Pedro Gomes Santiago Pires Beltrão (pedrosantiago@ufmg.br)
// Historic	: 2022-10-11 - file changes
//---------------------------------------------------------------------
#include "campanha.hpp"

using namespace std;
//globals-------------------------------------
std::vector<Graph> g;
std::stack<int> stack_vertices;
int followers, proposals, num_vertices, counter;

int main()
{
  int p1, p2, p3, p4;
  while (1)
  {
    cin >> followers >> proposals;
    if (followers == 0 && proposals == 0) // stop condition
      break;
    num_vertices = 2 * proposals; // each proposal generate two diferent vertices v and v'
    g.resize(num_vertices + 1);   // sets graph size

    reset_values();
    // scan input and normalize zero case ------------------------------------------------
    for (int i = 0; i < followers; i++)
    {
      cin >> p1 >> p2 >> p3 >> p4;
      if (!p1)
        p1 = p2;
      else if (!p2)
        p2 = p1;
      if (p1 && p2)
      {
        g[proposals + p1].adj.push_back(p2);
        g[proposals + p2].adj.push_back(p1);
        g[p2].rev_adj.push_back(proposals + p1);
        g[p1].rev_adj.push_back(proposals + p2);
      }

      if (!p3)
        p3 = p4;
      else if (!p4)
        p4 = p3;
      if (p3 && p4 )
      {
        g[p3].adj.push_back(proposals + p4);
        g[p4].adj.push_back(proposals + p3);
        g[proposals + p4].rev_adj.push_back(p3);
        g[proposals + p3].rev_adj.push_back(p4);
      }
    }
    identify_components();
    check_answer();
  }
  return (0);
}
