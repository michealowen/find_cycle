//
// Created by OWEN on 2020/12/11.
//

#ifndef FIND_CYCLE_JOHNSON_H
#define FIND_CYCLE_JOHNSON_H

#define MAX_VERTICE_COUNT 1000000

#define BLOCKED 1   // 被锁
#define UNBLOCKED 0 // 未被锁

#include "network/mtype.h"
#include "network/graph.h"

#include <iostream>
#include <stack>
#include <unordered_set>
#include <unordered_map>

using namespace find_cycle::network;

namespace find_cycle{
    namespace algorithm {

        // 连环解锁
        /*
        inline void unblock(node_id v,
                            std::unordered_set<node_id>& blocked,
                            std::unordered_map<node_id,std::vector<node_id>>& B);
        */
        inline void unblocking(node_id v,
                            std::vector<bool>& blocked,
                            std::unordered_map<node_id,std::vector<node_id>>& B);
        // 连环上锁
        inline void blocking(node_id v,
                             const Graph& G,
                             std::unordered_map<node_id,std::vector<node_id>>& B);
        // 上锁
        inline void block(node_id v);

        // 去除锁
        inline void unblock(node_id v);

        // 算法主程序
        std::vector<path> johnson_main(Graph G);

        // 声明 blocked
        extern std::vector<std::vector<unsigned>> blocked;
        // 声明第一个锁下标
        extern unsigned int begin_block_idx;
        // 声明最后一个锁下标
        extern unsigned int end_block_idx;

        // 用户 unblocking 的数组,这里只能声明为数组,而不能声明为指针
        extern unsigned int node_stack[];
        // 记录 node_stack 的元素个数
        extern unsigned int num_node_stack;

    }
}

#endif //FIND_CYCLE_JOHNSON_H
