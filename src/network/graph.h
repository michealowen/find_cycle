//
// Created by OWEN on 2020/12/9.
//

#ifndef FIND_CIRCUIT_GRAPH_H
#define FIND_CIRCUIT_GRAPH_H

#include <utility> // for std::pair
#include <algorithm> // for std::for_each
#include <boost/graph/graph_traits.hpp>
#include <boost/graph/adjacency_list.hpp>
#include "mtype.h"

namespace find_cycle{
    namespace network{

        /**
         *  Boost graph type
         */
        typedef boost::adjacency_list <boost::vecS, boost::vecS, boost::directedS> Graph;
        /*
         * 顶点迭代器
         */
        typedef boost::graph_traits<Graph>::vertex_iterator vertex_iter;
        /*
         * 边迭代器
         */
        typedef boost::graph_traits<Graph>::edge_iterator edge_iter;
        /*
         * 出边迭代器
         */
        typedef boost::graph_traits<Graph>::out_edge_iterator out_edge_iter;
        /*
         * 邻接点迭代器
         */
        typedef boost::graph_traits<Graph>::adjacency_iterator adj_iter;
        /*
         * 图的构造器
         * 通过vector构造
         */
        Graph generate_graph(node_count nc, std::vector<std::vector<node_id>>& tmp);
        /*
         * 找出n的邻居,且邻居要大于起始点
         *
         */
        std::vector<node_id> add_adj(node_id n, Graph& G, node_id start_node);
        // 打印环
        void print_circuits(std::vector<path> circuits);
    }
}

#endif //FIND_CYCLE_GRAPH_H
