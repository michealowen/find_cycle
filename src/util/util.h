//
// Created by OWEN on 2020/12/17.
//

#ifndef FIND_CYCLE_UTIL_H
#define FIND_CYCLE_UTIL_H

#include <map>

namespace find_cycle{
    namespace util{

        /*
         * 记录DFS信息
         */
        class depth_log{
        public:
            /*
             * DFS深度增加
             */
            void depth_inc(const int depth);
            /*
             * 格式化输出深度记录
             */
            const void print_depth_log();
        private:
            // 记录各个深度的次数
            std::map<int, int> dl;
        };

    }
}

#endif //FIND_CYCLE_UTIL_H
