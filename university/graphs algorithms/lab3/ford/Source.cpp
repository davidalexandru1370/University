#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
#include <climits>
std::ifstream f("bellmanford.in");
//std::ifstream f("input.txt");
std::ofstream o("bellmanford.out");

std::vector<std::pair<int,int>>g[50005];
//std::map<std::pair<int, int>, int>costs;
int nodes, edges;
std::vector<int>distances(50005, INT_MAX);
std::vector<int>visited(50005, 0);
bool cycle = false;

void bellman_ford(int start)
{
	distances[start] = 0;
	std::queue<int>coada;
	coada.push(start);
	//for (size_t node = 1; node < nodes; node++)
	//{
	//	for (std::vector<int>::iterator n = g[node].begin(); n < g[node].end(); n++)
	//	{
	//		if (distances[node] + costs[std::make_pair(node, *n)] < distances[*n])
	//		{
	//			distances[*n] = distances[node] + costs[std::make_pair(node, *n)];
	//		}
	//	}
	//}

	//for (size_t node = 1; node < nodes; node++)
	//{
	//	for (auto& edge : costs)
	//	{
	//		if (distances[edge.first.first] + edge.second < distances[edge.first.second])
	//		{
	//			//distances[edge.first.first] + edge.second < distances[edge.first.second]
	//			cycle = true;
	//			return 0;
	//		}
	//	}
	//}
	while (!coada.empty())
	{
		int node = coada.front();
		coada.pop();
		if (visited[node] >= nodes)
		{
			//cout<<""
			o << "Ciclu negativ!\n";
			return;
		}
		visited[node]++;
		for (size_t i = 0; i < g[node].size(); i++)
		{
			int vecin = g[node][i].first;
			//int cost = costs[std::make_pair(node, vecin)];
			int cost = g[node][i].second;
			if (distances[node] + cost < distances[vecin])
			{
				distances[vecin] = distances[node] + cost;
				coada.push(vecin);
			}
		}
	}
	for (size_t i = 2; i <= nodes; i++)
	{
		//std::cout << distances[i]<<" ";
		o << distances[i] << " ";
	}

}

int main()
{
	f >> nodes >> edges;
	int i = edges;
	while (i--)
	{

		int start, to, cost;
		f >> start >> to >> cost;
		g[start].push_back(std::make_pair(to,cost));
		//costs[std::make_pair(start, to)] = cost;
	}

	bellman_ford(1);


	return 0;
}