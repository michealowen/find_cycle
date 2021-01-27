#include "algorithm/Johnson.h"
#include "algorithm/Tiernan.h"
#include "io/reader.h"
#include "network/graph.h"
#include "util/debug.h"

#include <iostream> // for std::cout
#include <string>
#include <ctime>

using namespace find_cycle::network;

namespace find_cycle{
    namespace test{

        void test(){
            node_count nc = 10;
            edge_cout ec = 8;
            //图中的边
            //
            // 0 -> 1
            // 0 -> 3
            // 2 -> 0
            // 3 -> 2
            // 2 -> 4
            // 1 -> 3
            // 3 -> 4
            // 2 -> 1
            std::vector<std::vector<node_id>> edge_array({{0,1},{0,3},{2,0},{3,2},{2,4},{1,3},{3,4},{2,1}});
            Graph G = generate_graph(5, edge_array);
            // 遍历点
            std::cout << "遍历点" << std::endl;
            std::pair<vertex_iter, vertex_iter> vip;
            vip = vertices(G);
            for(vertex_iter vi = vip.first; vi != vip.second; ++vi){
                std::cout << *vi << std::endl;
            }
            // 通过G的顶点集合遍历
            std::cout << "通过顶点集合遍历点" << std::endl;
            for(node_id v:G.vertex_set()) {
                std::cout << v << std::endl;
            }
            // 通过边迭代器遍历边
            std::cout << "通过边迭代器遍历边" << std::endl;
            std::pair<edge_iter, edge_iter> eip;
            eip = edges(G);
            for(edge_iter ei = eip.first; ei != eip.second; ++ei){
                std::cout << source(*ei, G) << "->" << target(*ei, G) << std::endl;
            }
            // 通过出边迭代器遍历边
            std::cout << "通过出边迭代器遍历边" << std::endl;
            std::pair<out_edge_iter, out_edge_iter> oeip;
            for(vertex_iter vi = vip.first; vi != vip.second; ++vi){
                oeip = out_edges(*vi, G);
                for(out_edge_iter oei = oeip.first; oei != oeip.second; ++oei){
                    std::cout << source(*oei, G) << "->" << target(*oei, G) << std::endl;
                }
            }
            // 通过点的邻接点遍历边
            std::cout << "通过点的邻接点遍历边" << std::endl;
            //std::pair<vertex_iter, vertex_iter> vip;
            for(vertex_iter vi = vip.first; vi != vip.second; ++vi) {\
                std::pair<adj_iter, adj_iter> it;
                it = adjacent_vertices(*vi, G);
                for(auto iit=it.first; iit != it.second; ++iit){
                    std::cout << *iit << std::endl;
                }
            }
            // 邻接点 lower_bound
            std::cout << "邻接点 lower_bound" << std::endl;
            std::pair<adj_iter, adj_iter> avit = adjacent_vertices(2, G);
            auto it = std::lower_bound(avit.first, avit.second, 1);
            std::vector<int> tmp;
            tmp.insert(tmp.end(), it, avit.second);
            for(auto &d:tmp){
                std::cout << d << std::endl;
            }

        }


        void check_read(std::string file_name){
            auto data = find_cycle::io::read_data(file_name);
            Graph G = generate_graph(data.first.first, data.second);
            // 遍历点
            std::cout << "遍历点" << std::endl;
            std::pair<vertex_iter, vertex_iter> vip;
            vip = vertices(G);
            for(vertex_iter vi = vip.first; vi != vip.second; ++vi){
                std::cout << *vi << std::endl;
            }
            // 通过出边迭代器遍历边
            std::cout << "通过出边迭代器遍历边" << std::endl;
            std::pair<out_edge_iter, out_edge_iter> oeip;
            for(vertex_iter vi = vip.first; vi != vip.second; ++vi){
                oeip = out_edges(*vi, G);
                for(out_edge_iter oei = oeip.first; oei != oeip.second; ++oei){
                    std::cout << source(*oei, G) << "->" << target(*oei, G) << std::endl;
                }
            }
        }

        void check_johnson(std::string file_name){
            auto data = find_cycle::io::read_data(file_name);
            Graph G = generate_graph(data.first.first, data.second);
            clock_t startTime = clock();
            find_cycle::algorithm::johnson_main(G);
            std::cout << "消耗时间" << clock() - startTime << std::endl;
        }

        void check_tiernan(std::string file_name){
            auto data = find_cycle::io::read_data(file_name);
            Graph G = generate_graph(data.first.first, data.second);
            clock_t startTime = clock();
            find_cycle::algorithm::tiernan_main(G);
            std::cout << "消耗时间" << clock() - startTime << std::endl;
        }
    }
}

