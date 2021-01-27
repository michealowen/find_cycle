//
// Created by OWEN on 2020/12/11.
//

#include "Tiernan.h"
#include "util/debug.h"
#include "util/util.h"

#include <algorithm>
#include <iostream>

using namespace find_cycle::util;

namespace find_cycle{
    namespace algorithm{

        std::vector<bool> blocked_tier(MAX_VERTICE_COUNT, false);

        /*
         * Tiernan算法主程序
         * 未使用 scc(strongly connected conponent)
         */
        std::vector<path> tiernan_main(Graph G){

            // DPS深度记录
            depth_log d_l;
            SPDLOG_INFO("tiernan main process");
            std::pair<vertex_iter, vertex_iter> vip;
            vip = vertices(G);
            std::vector<path> circuits;             // 环集合
            for(auto vi = vip.first;vi != vip.second; ++vi){
                //if((vi-vip.first)%((vip.second-vip.first)/20)==0)
                //    SPDLOG_INFO("进度 {}%", (vi-vip.first)/(vip.second-vip.first)*100);
                // 当前路径
                path node_path;
                // 起点
                node_id start_node = *vi;
                node_path.push_back(start_node);
                blocked_tier[start_node] = true;
                std::vector<std::pair<node_id, std::vector<node_id>>> path_stack;
                path_stack.emplace_back(
                        std::pair<node_id,
                                std::vector<node_id>>(
                                start_node,
                                add_adj(start_node, G, start_node
                                )));
                /* 深度记录 */
                d_l.depth_inc(path_stack.size()-1);
                while(!path_stack.empty()) {
                    // 取出当前点
                    std::pair<node_id, std::vector<node_id>> &this_pair = path_stack.back();
                    node_id this_node = this_pair.first;
                    std::vector<node_id> &nbrs = this_pair.second;
                    if (!nbrs.empty()) {
                        node_id next_node = nbrs.back();
                        nbrs.pop_back();
                        // 若形成环
                        if (next_node == start_node) {
                            circuits.push_back(node_path);
                        }
                        // 若 next_node 位于路线上
                        //else if (std::find(node_path.begin(), node_path.end(), next_node) == node_path.end()) {
                        else if(blocked_tier[next_node] == false){
                            node_path.push_back(next_node);
                            blocked_tier[next_node] = true;
                            path_stack.emplace_back(
                                    std::pair<node_id, std::vector<node_id>>(
                                            next_node,
                                            add_adj(next_node, G, start_node
                                            )));
                            /* 深度记录 */
                            d_l.depth_inc(path_stack.size()-1);
                            continue;
                        }
                    }
                    // no more nbrs
                    if (nbrs.empty()) {
                        path_stack.pop_back();
                        blocked_tier[node_path.back()] = false;
                        node_path.pop_back();
                    }
                }
            }
            //print_circuits(circuits);
            std::cout << "环个数:" << circuits.size() << std::endl;
            /* 输出深度记录 */
            d_l.print_depth_log();
            return circuits;
        }
    }
}