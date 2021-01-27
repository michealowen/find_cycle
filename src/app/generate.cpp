//
// Created by OWEN on 2020/12/16.
//

#include "io/writer.h"
#include "network/graph.h"

#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <ctime> // used for srand
#include <unordered_map>

using namespace find_cycle::network;

/*
 * 两参数生成图
 */
std::vector<std::vector<node_id>> generate_graph(const node_count nc, const edge_cout ec){
    std::cout << "开始生成图" << std::endl;
    // 每次随机选取两个点组成有向边,若两个点id不能相同
    int i = 0;
    std::vector<std::vector<node_id>> data;
    std::unordered_map<node_id, std::vector<node_id>> m;
    while(i < ec){
        node_id source = rand()%nc;
        node_id target = rand()%nc;
        if(source != target && std::find(m[source].begin(), m[source].end(), target) == m[source].end()){
            ++i;
            data.push_back({source, target});
            m[source].push_back(target);
        }
    }
    return data;
}

/*
 * 三参数生成图
 */
std::vector<std::vector<node_id>> generate_graph(node_count nc, edge_cout ec, unsigned int sc){
    std::cout << "开始生成图" << std::endl;
    std::vector<std::vector<node_id>> data;
    return data;
}

int main(int argc, char* argv[]){
    std::cout << "project find_cycle" << std::endl;
    std::cout << "***************************" << std::endl;

    srand((int)time(0));  // 产生随机种子  把0换成NULL也行

    // 三个参数,第一个参数为点个数,第二个参数为边个数,第三个参数为写文件目录
    if(argc == 4){
        std::cout << "点个数:" << argv[1] << std::endl;
        std::cout << "边个数:" << argv[2] << std::endl;
        std::cout << "写文件目录" << argv[3] << std::endl;
        node_count nc = std::stoi(argv[1]);
        node_count ec = std::stoi(argv[2]);
        // 生成数据
        std::vector<std::vector<node_id>> data = generate_graph(nc, ec);
        // 文件目录
        std::string file_name(argv[3]);
        // 写数据
        find_cycle::io::write_data(nc, ec, data, file_name);
    }

    // 四个参数,第一个参数为点个数,第二个参数为边个数,第三个参数为强连通分量个数,第四个参数为写文件目录
    else if(argc == 5){
        std::cout << "点个数:" << argv[1] << std::endl;
        std::cout << "边个数:" << argv[2] << std::endl;
        std::cout << "强连通分量个数:" << argv[3] << std::endl;
        std::cout << "写文件目录" << argv[4] << std::endl;
        node_count nc = std::stoi(argv[1]);
        node_count ec = std::stoi(argv[2]);
        std::vector<std::vector<node_id>> data = generate_graph(nc, ec, std::stoi(argv[3]));
        // 文件目录
        std::string file_name(argv[4]);
        // 写数据
        find_cycle::io::write_data(nc, ec, data, file_name);
    }

    return 0;
}