//
// Created by OWEN on 2020/12/9.
// Johnson-1997 algorithm
//
#define MAX_VERTICE_COUNT 1000000

#include "Johnson.h"
#include "util/debug.h"
#include "util/util.h"

#include <algorithm>

using namespace find_cycle::network;
using namespace find_cycle::util;

namespace find_cycle{
    namespace algorithm{

        std::vector<std::vector<unsigned int>> blocked(3, std::vector<unsigned int>(MAX_VERTICE_COUNT, UNBLOCKED));
        unsigned int begin_block_idx;
        unsigned int end_block_idx;
        unsigned int node_stack[MAX_VERTICE_COUNT];
        unsigned int num_node_stack = 0;

        // 上锁
        inline void block(node_id v){
            blocked[0][v] = BLOCKED;
            blocked[2][end_block_idx] = v;
            blocked[1][v] = end_block_idx;
            blocked[2][v] = -1;
            end_block_idx = v;
        }

        // 去除锁
        inline void unblock(node_id v){
            int prev = blocked[1][v];
            int next = blocked[2][v];
            blocked[0][v] = UNBLOCKED;
            // 若v的前驱后继都为空
            if (prev == -1 && next == -1) {
                begin_block_idx = -1;
            }
            // 若v前驱为空
            else if (prev == -1) {
                begin_block_idx = next;
            }
            // 若v后继为空
            else if (next == -1) {
                blocked[2][prev] = -1;
                end_block_idx = prev;
            }
            // 若v前驱后继都不为空
            else {
                blocked[2][prev] = next;
                blocked[1][next] = prev;
            }
        }

        /*
         * unblock procedure
         */
        inline void unblocking(const node_id v,
                               std::unordered_map<node_id,std::vector<node_id>>& B
        )
        {
            /*
            std::vector<node_id> node_stack({v});
            while(!node_stack.empty()){
                node_id w = node_stack.back();
                node_stack.pop_back();
                // 循环解锁
                if(blocked[0][w] == BLOCKED){
                    unblock(w);
                    node_stack.insert(node_stack.end(), B[w].begin(), B[w].end());
                    B[w].clear();
                }
            }*/

            node_stack[num_node_stack++] = v;
            while(num_node_stack){
                node_id w = node_stack[--num_node_stack];
                if(blocked[0][w] == BLOCKED){
                    unblock(w);
                    for(node_id ww:B[w]){
                        node_stack[num_node_stack++] = ww;
                    }
                    B[w].clear();
                }
            }
        }

        /*
         * block procedure
         */
        inline void blocking(const node_id v,
                             const Graph& G,
                             std::unordered_map<node_id,std::vector<node_id>>& B){
            std::pair<adj_iter, adj_iter> adjip = adjacent_vertices(v, G);
            for(auto it=adjip.first; it != adjip.second; ++it){
                if(std::find(B[*it].begin(), B[*it].end(), v) == B[*it].end()){
                    B[*it].push_back(v);
                    //std::cout << "锁链:" << *it << "->" << v << std::endl;
                }
            }
        }


        /*
         * Johnson算法的主程序,不使用强连通分量(strongly connected)
         */
        std::vector<path> johnson_main(Graph G){

            // DPS深度记录
            depth_log d_l;

            SPDLOG_INFO("johnson main process");
            std::pair<vertex_iter, vertex_iter> vip;
            // 图的顶点迭代器
            vip = vertices(G);
            // 环集合
            std::vector<path> circuits;

            SPDLOG_INFO("图顶点个数{}", G.vertex_set().size());

            std::vector<bool> closed(G.vertex_set().size(), false);  //经过这个点可以找到回到起点的路径
            // 当前路径
            path node_path;
            // 工作栈
            std::vector<std::pair<node_id, std::vector<node_id>>> path_stack;
            for(auto vi = vip.first;vi != vip.second; ++vi){
                // 起点
                node_id start_node = *vi;
                // 当前路径加入起点
                node_path.push_back(start_node);
                // 初始化首尾锁位
                begin_block_idx = start_node, end_block_idx = start_node;
                block(start_node);
                // 初始化工作栈
                path_stack.emplace_back(
                        std::pair<node_id,std::vector<node_id>>(
                                start_node,
                                add_adj(start_node, G, start_node
                                )));
                /* 深度记录 */
                d_l.depth_inc(path_stack.size()-1);

                std::unordered_map<node_id, std::vector<node_id>> B;          // 锁信息
                while(!path_stack.empty()){
                    // 取工作栈中最后一点为当前点
                    /* 这里要使用引用！！！ */
                    std::pair<node_id, std::vector<node_id>>& this_pair = path_stack.back();
                    node_id this_node = this_pair.first;
                    std::vector<node_id>& nbrs = this_pair.second;
                    // 若当前点还有邻居
                    if(!nbrs.empty()) {
                        node_id next_node = nbrs.back();
                        nbrs.pop_back();
                        // 若形成环
                        if (next_node == start_node) {
                            circuits.push_back(node_path);
                            for(node_id& v:node_path){
                                closed[v] = true;
                            }
                        }

                        // 若 next_node 未上锁,入栈,上锁
                        else if(blocked[0][next_node] == UNBLOCKED){
                            node_path.push_back(next_node);
                            path_stack.emplace_back(
                                    std::pair<node_id, std::vector<node_id>>(
                                            next_node,
                                            add_adj(next_node, G, start_node
                                            )));
                            /* 深度记录 */
                            d_l.depth_inc(path_stack.size()-1);
                            closed[next_node] = false;
                            block(next_node);
                            continue;
                        }
                    }
                    // 若无更多邻居
                    if(nbrs.empty()){
                        // 若通过这一点可以回到起点,则可以进行连环解锁unblocking
                        if(closed[this_node] == true){
                            unblocking(this_node, B);
                        }
                        // 通过 this_node 没有一条路能回到起点,因此他要收到相邻点的限制,相邻点unblock,this_node才能unblock
                        else{
                            blocking(this_node, G, B);
                        }
                        path_stack.pop_back();
                        node_path.pop_back();
                    }
                }
                /* 将blocked的所有点清除 */
                int i = begin_block_idx;
                while(i!=-1){
                    blocked[0][i] = UNBLOCKED;
                    i = blocked[2][i];
                }
                //for(int i=0;i<MAX_VERTICE_COUNT;++i){
                //    blocked[0][i] = UNBLOCKED;
                //}
            }
            //print_circuits(circuits);
            std::cout << "环个数:" << circuits.size() << std::endl;
            /* 输出深度记录 */
            d_l.print_depth_log();
            return circuits;
        }
    }
}