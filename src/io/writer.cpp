//
// Created by OWEN on 2020/12/10.
//

#include "writer.h"

#include <iostream>

namespace find_cycle{
    namespace io{
        /*
         * 将生成的数据写入文件
         */
        void write_data(node_count nc, edge_cout ec, std::vector<std::vector<node_id>> data, const std::string file_name){
            FILE* fp = nullptr;
            fp = fopen(file_name.c_str(), "w");
            if(fp == nullptr){
                std::cout << "写数据时打开文件失败" << std::endl;
            }
            fprintf(fp, "%d,%d\n", nc, ec);
            for(auto &d:data){
                fprintf(fp, "%d,%d\n", d[0], d[1]);
            }
            fclose(fp);
        }
    }
}

