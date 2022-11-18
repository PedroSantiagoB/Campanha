//---------------------------------------------------------------------
// File	: campanha.hpp
// Content: functions definitions (header)
// Author	: Pedro Gomes Santiago Pires Beltrão (pedrosantiago@ufmg.br)
// Historic	: 2022-10-11 - file changes
//---------------------------------------------------------------------
#ifndef CAMPANHAHPP
#define CAMPANHAHPP

#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>

class Graph
{ // Description: represents the graph (adjacency list) and it's atributes
public:
    std::vector<int> adj;
    std::vector<int> rev_adj;
    int visited;
    int id_component;
};
//globals-------------------------------------
extern std::vector<Graph> g;
extern std::stack<int> stack_vertices;
extern int followers, proposals, num_vertices, counter;

//functions-----------------------------------
void dfs(int index);
void rev_dfs(int index, int counter);
void identify_components();
void reset_values();
void check_answer();

#endif