//
// Created by OWEN on 2020/12/17.
//

#include "util.h"

#include <iostream>

namespace find_cycle{
    namespace util{
        void depth_log::depth_inc(const int depth) {
            ++dl[depth];
        }
        const void depth_log::print_depth_log(){
            std::cout << "*******各层深度记录******" << std::endl;
            for(auto it = dl.begin();it != dl.end(); ++it){
                std::cout << "第" << (*it).first << "层" << (*it).second << "次" << std::endl;
            }
            std::cout << "*******记录输出结束******" << std::endl;
        }
    }
}