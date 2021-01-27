#include "test/boost_graph_test.h"
#include "util/debug.h"

#include <iostream>
#include <string>
#include <cstring>

int main(int argc, char* argv[]){
    std::cout << "project find_cycle" << std::endl;

    if(argc!=3){
        std::cout << "参数个数不对" << std::endl;
        exit(0);
    }

    std::cout << "方法" << ":" << argv[1] << std::endl;
    std::cout << "数据" << ":" << argv[2] << std::endl;

    // 第一个参数 执行的算法
    if(strcmp(argv[1], "john") == 0){
        // johnson找环
        std::string file_name(argv[2]);
        find_cycle::test::check_johnson(file_name);
    }
    else if(strcmp(argv[1], "tier") == 0){
        // tiernan找环
        std::string file_name(argv[2]);
        find_cycle::test::check_tiernan(file_name);
    }

    return 0;
}