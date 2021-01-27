//
// Created by OWEN on 2020/12/10.
//

#include "graph.h"
#include "mtype.h"
#include "util/debug.h"

#include <iostream>

namespace find_cycle{
    namespace network {

        bool cmp(const std::vector<node_id>& a, const std::vector<node_id>& b)
        {
            if(a[0] != b[0])
                return a[0] < b[0];
            else
                return a[1] < b[1];
        }

        /*
         * 构造图
         */
        Graph generate_graph(node_count nc, std::vector<std::vector<node_id>>& tmp) {
            SPDLOG_DEBUG("tmp.size {}", tmp.size());
            std::sort(tmp.begin(), tmp.end(), cmp);
            SPDLOG_DEBUG("tmp.size {}", tmp.size());
            Graph G(nc);
            for (std::vector<node_id>& e: tmp) {
                boost::add_edge(e[0], e[1], G);
            }
            return G;
        }

        /*
         * 将邻接点加入vector
         */
        std::vector<node_id> add_adj(node_id n, Graph& G, node_id start_node){
            std::pair<adj_iter, adj_iter> avit = adjacent_vertices(n, G);
            std::vector<node_id> tmp;
            auto it = std::lower_bound(avit.first, avit.second, start_node);
            tmp.insert(tmp.end(), it, avit.second);
            return tmp;
        }

        /*
         * 输出环
         */
        void print_circuits(
                std::vector<path> circuits){
            std::cout << "环个数:" << circuits.size() << std::endl;
            for(const path& p:circuits){
                for(const node_id& n:p){
                    std::cout << n << " ";
                }
                std::cout << std::endl;
            }
        }


    }
}