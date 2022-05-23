#include "Road.h"
#include <iostream>
template < typename TVertex, typename TEdge>
void print(road_network<TVertex, TEdge> g)
{
	auto begin = g.begin();
	auto end = g.end();
	while (begin != end) {
		std::cout << begin->get_name() << "  (population " << begin->get_num() << ")" << std::endl;
		{
			auto b = begin->begin_edge();
			auto e = begin->end_edge();
			while (b != e) {
				std::cout << "\n\t" << b->_get_src() << " --->     " << b->_get_dst() << " Distance::: " << b->_get_edge() << std::endl;
				++b;
			}
		}
		++begin;
		std::cout << std::endl;
	}
}
void print_between() {
	std::cout << "----------------------------------------------------------------------" << std::endl;
	std::cout << "----------------------------------------------------------------------" << std::endl;
	std::cout << "----------------------------------------------------------------------" << std::endl;
	std::cout << "----------------------------------------------------------------------" << std::endl;
}
int main() {
	try
	{
		road_network<std::string, double> g;
		g.add_vertex("Novgorod", 12223);
		g.add_vertex("Pashkinistan", 1920);
		g.add_vertex("Samara", 2324);
		g.add_vertex("Cheliabinsk", 4366);
		g.add_vertex("Kazan", 100000);
		g.add_vertex("Saratov", 99821);
		g.add_vertex("Moscow", 550000);
		g.add_edge("Pashkinistan", "Samara", 1);
		g.add_edge("Samara", "Cheliabinsk", 1);
		g.add_edge("Cheliabinsk", "Kazan", 1);
		g.add_edge("Kazan", "Saratov", 1);
		g.add_edge("Pashkinistan", "Saratov", 9);
		g.add_edge("Moscow", "Saratov", 9);
		g.add_edge("Samara", "Pashkinistan", 1);
		g.add_edge("Kazan", "Moscow", 1);
		g.add_edge("Kazan", "Pashkinistan", 2);
		g.add_edge("Pashkinistan", "Moscow", 12);
		g.add_edge("Saratov", "Novgorod", 15);
		print(g);
		print_between();
		std::cout << "BFS " << std::endl;
		g.bfs("Pashkinistan");
		std::cout << std::endl;
		std::cout << "DFS " << std::endl;
		g.dfs("Pashkinistan");
		std::cout << std::endl;
		auto result = Dijkstra(g, "Pashkinistan", "Novgorod");
		std::cout << " SHORTEST DISTANCE " << result.second << std::endl;
		std::cout << " MINIMAL WAY DIJKSTRA :::::::  ";
		auto end = --result.first.end();
		auto i = result.first.begin();
		for (end; end != i; end--)
			std::cout << *end << ' ';
		std::cout << *i << std::endl;
		auto result2 = BellmanFord(g, "Pashkinistan", "Novgorod");
		std::cout << " SHORTEST DISTANCE " << result2.second << std::endl;
		std::cout << " MINIMAL WAY BELLMAN FORD :::::::  ";
		auto a = result2.first.begin();
		auto end2 = --result2.first.end();
		for (end2; end2 != a; end2--)
			std::cout << *end2 << ' ';
		std::cout << *a << std::endl;
		g.edit_edge_distance("Kazan", "Saratov", 188888);
		g.edit_edge_dst("Kazan", "Saratov", "Lugansk");
		print(g);
		print_between();
		g.erase_edge("Kazan", "Lugansk", 188888);
		print(g);
		print_between();
		g.erase_vertex("Pashkinistan");
		print(g);
		print_between();
		g.edit_vertex("Samara", "Aerokos");
		print(g);
		print_between();
		g.edit_number("Aerokos", 342235);
		print(g);
		print_between();
	}
	catch (const std::exception& ex)
	{
		std::cout << ex.what();
	}
}
