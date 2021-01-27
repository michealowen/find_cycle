//
// Created by OWEN on 2020/12/10.
//

#ifndef FIND_CYCLE_WRITER_H
#define FIND_CYCLE_WRITER_H

#include "network/mtype.h"

#include <string>

using namespace find_cycle::network;

namespace find_cycle{
    namespace io{
        /*
         * 将生成的数据写入文件
         */
        void write_data(node_count nc, edge_cout ec, std::vector<std::vector<node_id>> data, const std::string file_name);

    }
}

#endif //FIND_CYCLE_WRITER_H
