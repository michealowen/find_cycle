//
// Created by OWEN on 2020/12/11.
// Tierman-1970 algorithm
//

#ifndef FIND_CYCLE_TIERNAN_H
#define FIND_CYCLE_TIERNAN_H

#define MAX_VERTICE_COUNT 1000000

#include "network/mtype.h"
#include "network/graph.h"

#include <vector>

using namespace find_cycle::network;

namespace find_cycle{

    namespace algorithm{
        // Tiernan算法主程序
        std::vector<path> tiernan_main(Graph G);

        // 锁标志,位于路线上的点被锁 --> 需修改,命名冲突
        extern std::vector<bool> blocked_tier;
    }
}


#endif //FIND_CYCLE_TIERNAN_H
