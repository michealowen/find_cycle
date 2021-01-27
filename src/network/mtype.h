//
// Created by OWEN on 2020/12/9.
//
#ifndef FIND_CYCLE_MTYPE_H
#define FIND_CYCLE_MTYPE_H

#include <vector>

namespace find_cycle{
    namespace network{
        /* 节点个数 */
        typedef unsigned int node_count;
        /* 边个数 */
        typedef unsigned int edge_cout;
        /* 节点ID 范围[0,node_count] */
        typedef unsigned int node_id;
        /* 边ID 范围[0, edge_cout] */
        //typedef unsigned int edge_id;
        /* 边 */
        typedef std::pair<node_id ,node_id> edge;
        /* 路线 */
        typedef std::vector<node_id> path;
    }
}

#endif //FIND_CYCLE_MTYPE_H
