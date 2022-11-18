
//---------------------------------------------------------------------
// File	: campanha.cpp
// Content: functions implementations
// Author	: Pedro Gomes Santiago Pires Beltrão (pedrosantiago@ufmg.br)
// Historic	: 2022-10-11 - file changes
//---------------------------------------------------------------------
#include "campanha.hpp" 
void dfs(int index)
{ // Description: depth first search, assembling the stack
    g[index].visited = 1;
    int test = 0;
    for (unsigned int i = 0; i < g[index].adj.size(); i++)
        if (!g[g[index].adj[i]].visited)
        {
            dfs(g[index].adj[i]);
            test++;
        }

    stack_vertices.push(index);
}

void rev_dfs(int index, int counter)
{ // Description: depth first search reversed, identifying SCC indexs
    g[index].visited = 1;
    g[index].id_component = counter;
    int test_rev = 0;
    for (unsigned int i = 0; i < g[index].rev_adj.size(); i++)
        if (!g[g[index].rev_adj[i]].visited)
        {
            rev_dfs(g[index].rev_adj[i], counter);
            test_rev++;
        }
}

void identify_components()
{ // Description: Kosaraju's calls dfs, resets the visited atributes, unstack the vertices and calls reverse dfs to get SCCs
    int aux_vertice = 0;
    for (int i = 1; i <= num_vertices; i++)
        if (!g[i].visited)
            dfs(i);
    for (int i = 1; i <= num_vertices; i++)
        g[i].visited = 0;
    while (!stack_vertices.empty())
    {
        aux_vertice = stack_vertices.top();
        stack_vertices.pop();
        if (!g[aux_vertice].visited)
            rev_dfs(aux_vertice, counter++);
    }
}
void reset_values()
{ // Description: update the graph for another input block
    for (int i = 1; i <= num_vertices; i++)
    {
        g[i].adj.clear();
        g[i].rev_adj.clear();
        g[i].visited = 0;
        g[i].id_component = -1;
        counter = 0;
    }
}
void check_answer()
{ // Description:  check if all the proposals pleases the deputy and prints the answer
    std::string answer = "sim";
    for (int i = 1; i <= proposals; i++)
        if (g[i].id_component == g[i + proposals].id_component)
            answer = "nao";
    std::cout << answer << std::endl;
}
