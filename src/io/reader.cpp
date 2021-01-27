//
// Created by OWEN on 2020/12/10.
//

#include "reader.h"
#include "network/mtype.h"
#include "util/debug.h"

using namespace find_cycle::network;

namespace find_cycle {
    namespace io {

        /*
         * 从文件中读出数据
         *
         */
        std::pair<std::pair<node_count, edge_cout>, std::vector<std::vector<node_id>>>
                read_data(const std::string file_name) {
            SPDLOG_INFO("read data begin");
            std::pair<std::pair<node_count, edge_cout>, std::vector<std::vector<node_id>>> data;
            // 判断文件是否存在
            FILE *fp;
            fp = fopen(file_name.c_str(), "r");
            if (fp == nullptr) {
                std::cout << "文件打开失败" << std::endl;
            }
            // 按字符读数据
            std::vector<std::vector<node_id>> tmp;
            // 点个数nc,边个数ec
            node_count nc;
            edge_cout ec;
            node_id source, target;
            fscanf(fp, "%d,%d", &nc, &ec);
            tmp.reserve(ec);
            for (int i = 0; i < ec; ++i) {
                fscanf(fp, "%d,%d", &source, &target);
                tmp.push_back({source, target});
            }
            fclose(fp);
            data.first.first = nc;
            data.first.second = ec;
            data.second = tmp;
            return data;
        }
    }
}



