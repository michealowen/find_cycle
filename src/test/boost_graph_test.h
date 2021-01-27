//
// Created by OWEN on 2020/12/10.
//

#ifndef FIND_CYCLE_BOOST_GRAPH_TEST_H
#define FIND_CYCLE_BOOST_GRAPH_TEST_H

#include <string>

namespace find_cycle{
    namespace test{
        void test();

        void check_read(std::string file_name);

        /*
         * 测试 johnson 找环是否成功
         */
        void check_johnson(std::string file_name);

        /*
         * 测试 johnson 找环是否成功
         */
        void check_tiernan(std::string file_name);

    }
}

#endif //FIND_CYCLE_BOOST_GRAPH_TEST_H
