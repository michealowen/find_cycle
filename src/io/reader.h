//
// Created by OWEN on 2020/12/10.
//

#ifndef FIND_CYCLE_READER_H
#define FIND_CYCLE_READER_H

#include "network/graph.h"
#include "network/mtype.h"

#include <iostream>

using namespace find_cycle::network;

namespace find_cycle{
    namespace io{
        /*
         * 从文件中读出数据
         *
         */
        std::pair<std::pair<node_count,edge_cout>, std::vector<std::vector<node_id>>> read_data(const std::string file_name);
    }
}


#endif //FIND_CYCLE_READER_H
