#include <bits/stdc++.h>
using namespace std;

vector<bitset<100> > b(100);
int vis[100] = {};
void F(vector<vector<int> > graph,bitset<100> par, int node);
void G(vector<pair<int, int> > adj, int e, int v);
void D(int v, int e,vector<pair<int, int> > adj);

int main()
{
	int v,e,ss;
	cout << "Enter the number of vertices : "; cin >> v;
	cout << "Enter the number of edges : "; cin >> e;
	cout << "Enter the source : "; cin >> ss;
	vector<pair<int, int> > adj;
	cout << "Enter the edges :\n";
	for(int i = 0;i<e;i++)
	{
		int x,y;
		cin >> x >> y;
		x-=ss,y-=ss;
		adj.push_back(make_pair(x,y));
	}
	D(v, e, adj);

	return 0;
}

void F(vector<vector<int> > graph,bitset<100> par, int node)
{
	if (vis[node] == 0) 
	{
		b[node] = ~b[node];
		vis[node] = 1;
	}
	b[node] &= par;
	b[node][node] = 1;
	for (int i = 0; i < (int)graph[node].size(); i++)
	{
		F(graph, b[node], graph[node][i]);
	}
}

void G(vector<pair<int, int> > adj, int e, int v)
{
	vector<vector<int> > graph(v + 1);
	for (int i = 0; i < e; i++)
	{
		int x = min(adj[i].first,adj[i].second);
		int y = max(adj[i].first,adj[i].second);
		graph[x].push_back(y);
	}
	bitset<100> g;
	g[0] = 1;
	vis[0] = 1;
	F(graph, g, 0);
}

void D(int v, int e,vector<pair<int, int> > adj)
{
	G(adj, e, v);
	for (int i = 0; i < v; i++)
	{
		cout << i+1 << " -> ";
		for (int j = 0; j < v; j++)
		{
			if (b[i][j] == 1)
				cout << j+1 << " ";
		}
		cout << endl;
	}
}

