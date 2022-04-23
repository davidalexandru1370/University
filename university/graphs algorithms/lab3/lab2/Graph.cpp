#include "Graph.h"
#include <queue>
#include <string>
#include <sstream>
#include <climits>
Graph::Graph()
{
	number_of_nodes = 0;
	number_of_edges = 0;
	deleted_nodes = 0;
}

Graph::Graph(const Graph& graph) : number_of_nodes{ graph.number_of_nodes }, number_of_edges{ graph.number_of_edges }
{
	edges_in = graph.edges_in;
	edges_out = graph.edges_out;
	costs = graph.costs;
	nodes = graph.nodes;
	deleted_nodes = graph.deleted_nodes;
	/*this->number_of_nodes = graph.number_of_nodes;*/
}

void Graph::add_edge(int node_from, int node_to, int cost)
{
	if (check_if_node_exists(node_from) == false || check_if_node_exists(node_to) == false)
	{
		throw std::exception("One of the nodes does not exists\n");
	}
	if (is_edge(node_from, node_to) == true)
	{
		throw std::exception("There is already an edge between those two nodes\n");
		//throw std::runtime_error("there already exists an edge between these 2 nodes");
	}
	//edges_out
	//edges_in
	edges_in[node_to].push_back(node_from);
	edges_out[node_from].push_back(node_to);
	costs[std::make_pair(node_from, node_to)] = cost;
	number_of_edges++;
}

void Graph::add_node(int node)
{
	if (check_if_node_exists(node) == true)
	{
		throw std::exception();
	}
	number_of_nodes++;
	edges_in[node] = std::vector<int>();
	edges_out[node] = std::vector<int>();
	nodes.push_back(node);
}

void Graph::delete_edge(int node_from, int node_to)
{
	if (check_if_node_exists(node_from) == false || check_if_node_exists(node_to) == false)
	{
		throw std::exception("One of the nodes does not exists!\n");
	}

	if (is_edge(node_from, node_to) == false)
	{
		throw std::exception("The edge between those two nodes does not exist!\n");
	}
	//edges_in
	edges_out[node_from].erase(std::find(edges_out[node_from].begin(), edges_out[node_from].end(), node_to));
	edges_in[node_to].erase(std::find(edges_in[node_to].begin(), edges_in[node_to].end(), node_from));
	//costs[std::make_pair(node_from, node_to)];
	costs.erase(std::make_pair(node_from, node_to));
}

bool Graph::is_edge(int node_from, int node_to)
{
	if (edges_out.find(node_from) == edges_out.end() || edges_in.find(node_to) == edges_in.end())
	{
		return false;
	}

	if (find(edges_out[node_from].begin(), edges_out[node_from].end(), node_to) == edges_out[node_from].end())
	{
		return false;
	}
	return true;
}

int Graph::get_out_degree_of_node(int node)
{
	//if (edges_out.find(node) == edges_out.end() || edges_out[node][0] == -1)
	if (check_if_node_exists(node) == false)
	{
		//return exception
		//if node does not exists
		throw std::exception();
	}

	return edges_out[node].size();
}

int Graph::get_in_degree_of_node(int node)
{
	if (check_if_node_exists(node) == false)
	{
		throw std::exception();
	}
	return edges_in[node].size();
}

int Graph::get_number_of_nodes()
{
	return number_of_nodes;
}

void Graph::remove_node(int node)
{
	if (check_if_node_exists(node) == false)
	{
		throw std::exception();
	}
	//parse the succesrs and predecessors of the node
	//take the values from oout dict and look in edges in array
	number_of_nodes--;
	//deleted_nodes++;
	/*edges_in.erase(node);
	edges_out.erase(node);
	nodes.erase(find(nodes.begin(), nodes.end(), node));*/
	for (int& vertex : edges_out[node])
	{
		edges_in[vertex].erase(find(edges_in[vertex].begin(), edges_in[vertex].end(), node));
		costs.erase(costs.find(std::make_pair(node, vertex)));
	}

	for (int& vertex : edges_in[node])
	{
		edges_out[vertex].erase(find(edges_out[vertex].begin(), edges_out[vertex].end(), node));
		costs.erase(costs.find(std::make_pair(vertex, node)));
	}
	//edges_out[node] = std::vector<int>();
	edges_in.erase(edges_in.find(node));
	edges_out.erase(edges_out.find(node));
	nodes.erase(find(nodes.begin(), nodes.end(), node));
}

int Graph::get_the_cost_between_two_nodes(int node_from, int node_to) {

	if (check_if_node_exists(node_from) == false || check_if_node_exists(node_to) == false)
	{
		throw std::exception("One of the nodes does not exist!\n");
	}

	if (is_edge(node_from, node_to) == false)
	{
		throw std::exception("There is no edge between those two nodes!\n");
	}

	return costs[std::make_pair(node_from, node_to)];
}

void Graph::set_the_cost_between_two_nodes(int node_from, int node_to, int new_value)
{
	if (check_if_node_exists(node_from) == false || check_if_node_exists(node_to) == false)
	{
		throw std::exception("One of the nodes does not exist!\n");
	}
	if (is_edge(node_from, node_to) == false)
	{
		throw std::exception("There is no edge between those two nodes!\n");
	}
	costs[std::make_pair(node_from, node_to)] = new_value;
}

std::pair<std::vector<int>::iterator, std::vector<int>::iterator> Graph::get_iterator_for_nodes()
{
	//return std::pair<std::vector<int>::iterator, std::vector<int>::iterator>();
	return std::make_pair(nodes.begin(), nodes.end());
}

std::pair<std::vector<int>::iterator, std::vector<int>::iterator> Graph::get_iterator_for_outbounds_of_a_node(int node)
{
	if (check_if_node_exists(node) == false)
	{
		throw std::exception();
	}
	return(std::make_pair(edges_out[node].begin(), edges_out[node].end()));
}

std::pair<std::vector<int>::iterator, std::vector<int>::iterator> Graph::get_iterator_for_inbounds_of_a_node(int node)
{
	//return std::pair<std::vector<int>::iterator, std::vector<int>::iterator>();
	if (check_if_node_exists(node) == false)
	{
		throw std::exception();
	}
	return std::make_pair(edges_in[node].begin(), edges_in[node].end());
}

bool Graph::check_for_same_extension(char* name1, const char* extension)
{
	if (strlen(name1) < strlen(extension))
	{
		return false;
	}
	int index = 1;
	for (int i = strlen(extension) - 1; i >= 0; i--)
	{
		if (extension[i] != name1[strlen(name1) - index])
		{
			return false;
		}
		index++;
		//std::cout << name1[strlen(name1) - 1 - i];
		//std::cout << extension[i];
	}
	return true;
}

void Graph::read_graph_from_file(char file_name[])
{
	std::ifstream file(file_name);
	std::vector<std::string>lines;
	std::string line;

	if (check_for_same_extension(file_name, ".other"))
	{
		while (std::getline(file, line))
		{
			lines.push_back(line);
		}
		std::istringstream ss(lines[0]);
		ss >> number_of_nodes >> number_of_edges;
		ss = std::istringstream(lines[1]);
		for (size_t i = 0; i < number_of_nodes; i++)
		{
			std::string node;
			ss >> node;
			nodes.push_back(atoi(node.c_str()));

		}
		for (size_t index = 0; index < number_of_edges; index++)
		{
			std::string node1, node2, cost;
			ss = std::istringstream(lines[index + 2]);
			ss >> node1 >> node2 >> cost;
			edges_out[atoi(node1.c_str())].push_back(atoi(node2.c_str()));
			edges_in[atoi(node2.c_str())].push_back(atoi(node1.c_str()));
			costs[std::make_pair(atoi(node1.c_str()), atoi(node2.c_str()))] = atoi(cost.c_str());
		}

	}
	else if (check_for_same_extension(file_name, ".txt") == true) {
		file >> number_of_nodes >> number_of_edges;
		for (size_t index = 0; index < number_of_nodes; index++)
		{
			edges_in[index] = std::vector<int>();
			edges_out[index] = std::vector<int>();
			nodes.push_back(index);
		}

		for (size_t index = 0; index < number_of_edges; index++)
		{
			int node1, node2, cost = 0;
			file >> node1 >> node2 >> cost;
			edges_out[node1].push_back(node2);
			edges_in[node2].push_back(node1);
			costs[std::make_pair(node1, node2)] = cost;
		}
	}
}

int Graph::get_the_number_of_edges()
{
	//return costs.size();
	return costs.size();
}

int Graph::get_the_number_of_deleted_nodes()
{
	return deleted_nodes;
}

bool Graph::check_if_node_exists(int node) {
	if (edges_out.find(node) != edges_out.end())
	{
		if (edges_out[node].size() > 0 && edges_out[node][0] == -1)
		{
			return false;
		}
	}
	std::vector<int>::iterator it = std::find(nodes.begin(), nodes.end(), node);
	if (it == nodes.end())
	{
		return false;
	}

	return true;
	//return (edges_in.find(node) != edges_in.end() || edges_out.find(node) != edges_out.end());
}

void Graph::build_random_graph(int vertices, int edges)
{
	if (edges > vertices * (vertices - 1) || edges < 0)
	{
		throw std::exception("Edges number outside boundaries\n");
	}
	//generate vertices;
	int total_generated_edges = 0;
	for (size_t index = 0; index < vertices; index++)
	{
		if (check_if_node_exists(index) == false)
		{
			add_node(index);
		}
		else
		{
			total_generated_edges += get_out_degree_of_node(index) + get_in_degree_of_node(index);
		}
		//works for bigger graphs i.e generate a random graph inside a graph
	}
	while (total_generated_edges < edges)
	{
		int node1 = rand() % vertices;
		int node2 = rand() % vertices;
		int cost = rand() % 100;
		if (is_edge(node1, node2) == false)
		{
			add_edge(node1, node2, cost);
			total_generated_edges++;
		}
	}
}

std::vector<int> Graph::bfs(int start_node, int end_node)
{
	//validation of start_node, end_node
	if (std::find(nodes.begin(), nodes.end(), start_node) == nodes.end() || std::find(nodes.begin(), nodes.end(), end_node) == nodes.end())
	{
		throw std::exception("One of the nodes does not exist!");
	}
	std::vector<int>ans;
	ans.push_back(end_node);
	std::queue<int>next_nodes;
	std::map<int, int>visited;
	std::map<int, int>distance;
	//std::map<int, std::vector<int>> path;
	std::map<int, int>path;
	visited[start_node] = 1;
	distance[start_node] = 0;
	//path[start_node].push_back(start_node);
	next_nodes.push(start_node);
	while (next_nodes.empty() == false)
	{
		int node = next_nodes.front();
		next_nodes.pop();
		//std::pair<std::vector<int>::iterator, std::vector<int>::iterator> out = get_iterator_for_outbounds_of_a_node(node);
		std::pair<std::vector<int>::iterator, std::vector<int>::iterator> in = get_iterator_for_inbounds_of_a_node(node);
		for (std::vector<int>::iterator it = in.first; it < in.second; it++)
		{
			if (visited.find(*it) == visited.end())
			{
				next_nodes.push(*it);
				visited[*it] = 1;
				distance[*it] = distance[node] + 1;
				path[*it] = node;
				if (*it == end_node)
				{
					int vertex = path[*it];
					while (vertex != start_node)
					{
						ans.push_back(vertex);
						vertex = path[vertex];
					}
					ans.push_back(start_node);
					return ans;

				}
			}
		}
	}
	return std::vector<int>();
}

std::vector<int> Graph::ford(int start_node, int end_node)
{
	//validation of start_node, end_node
	if (std::find(nodes.begin(), nodes.end(), start_node) == nodes.end() || std::find(nodes.begin(), nodes.end(), end_node) == nodes.end())
	{
		throw std::exception("One of the nodes does not exist!");
	}

	std::map<int, int>previous;
	std::map<int, int>distances;
	std::map<int, int>freq;
	std::vector<int>ans;

	for (std::vector<int>::iterator it = this->get_iterator_for_nodes().first; it < this->get_iterator_for_nodes().second; it++)
	{
		distances[*it] = INT_MAX;
	}

	previous[start_node] = -1;
	distances[start_node] = 0;
	std::queue<int>next_node;
	next_node.push(start_node);
	freq[start_node] = 0;
	while (!next_node.empty())
	{
		int node = next_node.front();
		next_node.pop();

		freq[node]++;
		if (freq[node] >= number_of_nodes)
		{
			throw NegativeCycleException("There is a negative cost cycle inside graph!");
		}
		for (std::vector<int>::iterator it = this->get_iterator_for_outbounds_of_a_node(node).first; it < this->get_iterator_for_outbounds_of_a_node(node).second; it++)
		{
			int neighbour = *it;
			int cost = costs[std::make_pair(node, *it)];
			if (distances[node] + cost < distances[*it])
			{
				if (distances[*it] == INT_MAX)
				{
					freq[*it] = 0;
				}
				distances[*it] = distances[node] + cost;
				next_node.push(*it);
				previous[*it] = node;
			}
		}
	}

	/*for (std::vector<int>::iterator it = this->get_iterator_for_nodes().first; it < this->get_iterator_for_nodes().second-1; it++)
	{
		for (auto& edge : costs)
		{
			int cost = edge.second;
			if (distances[edge.first.first] != INT_MAX && distances[edge.first.first] + cost < distances[edge.first.second])
			{
				distances[edge.first.second] = distances[edge.first.first] + cost;
			}
		}
	}


	for (std::vector<int>::iterator it = this->get_iterator_for_nodes().first; it < this->get_iterator_for_nodes().second - 1; it++)
	{
		for (auto& edge : costs)
		{
			int cost = edge.second;
			if (distances[edge.first.first] != INT_MAX && distances[edge.first.first] + cost < distances[edge.first.second])
			{
				throw NegativeCycleException("There is a negative cycle in graph!");
			}
		}
	}*/
	int total = distances[end_node];
	ans.push_back(end_node);
	while (end_node != start_node)
	{
		ans.push_back(previous[end_node]);
		end_node = previous[end_node];
	}
	ans.push_back(total);
	return ans;

}

NegativeCycleException::NegativeCycleException(std::string mess)
{
	message = mess;
}

char const* NegativeCycleException::what() const
{
	return this->message.c_str();
}


