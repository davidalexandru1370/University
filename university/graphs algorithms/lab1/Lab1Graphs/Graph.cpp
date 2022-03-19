#include "Graph.h"
Graph::Graph()
{
	number_of_nodes = 0;
	number_of_edges = 0;
}

void Graph::add_edge(int node_from, int node_to, int cost)
{
	if (is_edge(node_from, node_to) == true)
	{
		throw std::exception();
		//throw std::runtime_error("there already exists an edge between these 2 nodes");
	}
	//edges_out
	//edges_in
	edges_in[node_from].push_back(node_to);
	costs[std::make_pair(node_from, node_to)] = cost;
}

void Graph::add_node(int node)
{
	if (edges_in.find(node) != edges_in.end() && edges_out.find(node) != edges_out.end())
	{
		throw std::exception();
	}
	number_of_nodes++;
	edges_in[node] = std::vector<int>();
	edges_out[node] = std::vector<int>();
}

void Graph::delete_edge(int node_from, int node_to)
{
	if (is_edge(node_from, node_to) == false)
	{
		throw std::exception();
	}
	//edges_in
	edges_out[node_from].erase(std::find(edges_out[node_from].begin(), edges_out[node_from].end(), node_to));
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
	if (edges_out.find(node) == edges_out.end())
	{
		//return exception
		//if node does not exists
		return 0;
	}
	return edges_out[node].size();
}


int Graph::get_in_degree_of_node(int node)
{
	if (edges_in.find(node) == edges_in.end())
	{
		return 0;
	}
	return edges_in[node].size();
}

int Graph::get_number_of_nodes()
{
	return number_of_nodes;
}

void Graph::remove_node(int node)
{
	if (!check_if_node_exists(node))
	{
		throw std::exception();
	}
	//parse the succesrs and predecessors of the node
	//take the values from oout dict and look in edges in array
	number_of_nodes--;
	edges_in.erase(node);
	edges_out.erase(node);
	nodes.erase(find(nodes.begin(), nodes.end(), node));
}

int Graph::get_the_cost_between_two_nodes(int node_from, int node_to) {
	if (is_edge(node_from, node_to) == false)
	{
		throw std::exception();
	}
	return costs[std::make_pair(node_from, node_to)];
}

void Graph::set_the_cost_between_two_nodes(int node_from, int node_to, int new_value)
{
	if (is_edge(node_from, node_to) == false)
	{
		throw std::exception();
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
	if (!check_if_node_exists(node))
	{
		throw std::exception();
	}
	return std::make_pair(edges_in[node].begin(), edges_in[node].end());
}

void Graph::read_graph_from_file(char file_name[])
{
	std::ifstream file(file_name);
	file >> number_of_nodes >> number_of_edges;
	for (size_t index = 0; index < number_of_nodes; index++)
	{
		nodes.push_back(index);
		edges_in[index] = std::vector<int>();
		edges_out[index] = std::vector<int>();
		//add_node(index);
	}

	for (size_t index = 0; index < number_of_edges; index++)
	{
		int node1, node2, cost = 0;
		file >> node1 >> node2 >> cost;
		edges_out[node1].push_back(node2);
		costs[std::make_pair(node1, node2)] = cost;
		//add_edge(node1, node2, cost);

	}
}

bool Graph::check_if_node_exists(int node) {
	return std::find(nodes.begin(), nodes.end(), node) == nodes.end() ? false : true;
}