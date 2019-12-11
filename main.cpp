#include <iostream>
#include "ReadVLTS.h"
#include "LabelRefwithClass.h"

void testPerformance(const std::string& testCase);

int main() {
    /*
    //test 5
    {
        std::cout<<"Test 5"<<std::endl;
        state state_5 = {0, 1, 2, 3, 4, 5, 6};
        transition trans_5 = {{0, 1, 1},
                              {0, 1, 2},
                              {1, 0, 3},
                              {1, 3, 4},
                              {2, 2, 6},
                              {3, 2, 5}};
        partition res_5 = ts_reduce(state_5, trans_5);
        for (auto j : res_5) {
            std::cout << j << " ";
        }
        std::cout << "\n" << std::endl;
    }

    //test 5a
    {
        std::cout<<"Test 5a"<<std::endl;
        state state_5a = {0, 1, 2, 3, 4, 5, 6};
        transition trans_5a = {{0, 4, 1},
                               {0, 4, 2},
                               {1, 1, 3},
                               {2, 1, 4},
                               {2, 1, 5},
                               {3, 2, 6},
                               {3, 0, 4},
                               {4, 3, 6},
                               {5, 2, 6},
                               {5, 0, 4}};
        partition res_5a = ts_reduce(state_5a, trans_5a);
        for (auto j : res_5a) {
            std::cout << j << " ";
        }
        std::cout << "\n" << std::endl;
    }

    //test 7
    {
        std::cout << "Test 7" << std::endl;
        state state_7 = {0, 1, 2, 3, 4, 5, 6};
        transition trans_7 = {{0, 0, 4},
                              {2, 0, 1},
                              {3, 0, 2},
                              {4, 0, 3},
                              {1, 0, 5},
                              {5, 0, 6},
                              {6, 1, 3}};
        partition res_7 = ts_reduce(state_7, trans_7);
        for (auto j : res_7) {
            std::cout << j << " ";
        }
        std::cout << "\n" << std::endl;
    }

    //test 8
    {
        std::cout << "Test 8" << std::endl;
        state state_8 = {0, 1, 2, 3, 4};
        transition trans_8 = {{0, 0, 1},
                              {0, 0, 2},
                              {0, 0, 3},
                              {0, 0, 4},
                              {3, 0, 3},
                              {4, 0, 4},};
        partition res_8 = ts_reduce(state_8, trans_8);
        for (auto j : res_8) {
            std::cout << j << " ";
        }
        std::cout << "\n" << std::endl;
    }

    //test 9
    {
        std::cout << "Test 9" << std::endl;
        state state_9 = {0, 1, 2, 3};
        transition trans_9 = {{0, 1, 1},
                              {1, 0, 2},
                              {2, 0, 3},
                              {3, 0, 1},};
        partition res_9 = ts_reduce(state_9, trans_9);
        for (auto j : res_9) {
            std::cout << j << " ";
        }
        std::cout << "\n" << std::endl;
    }

    //test 10
    {
        std::cout << "Test 10" << std::endl;
        state state_10 = {0, 1, 2, 3, 4, 5, 6, 7};
        transition trans_10 = {{0, 2, 1},
                              {0, 2, 2},
                              {1, 1, 3},
                              {1, 0, 4},
                              {2, 1, 5},
                              {2, 0, 6},
                              {6, 1, 7}};
        partition res_10 = ts_reduce(state_10, trans_10);
        for (auto j : res_10) {
            std::cout << j << " ";
        }
        std::cout << "\n" << std::endl;
    }

    //test 12
    {
        std::cout<<"Test 12"<<std::endl;
        state state_12 = {0, 1, 2, 3, 4, 5};
        transition trans_12 = {{0, 0, 1},
                               {0, 0, 2},
                               {1, 0, 3},
                               {2, 0, 4},
                               {2, 1, 5},
                               {3, 3, 5},
                               {4, 2, 5}};
        partition res_12 = ts_reduce(state_12, trans_12);
        for (auto j : res_12) {
            std::cout << j << " ";
        }
        std::cout << "\n" << std::endl;
    }

    //test G15 from Matlab
    {
        std::cout << "Test G15" << std::endl;
        state state_g15 = {0, 1, 2, 3};
        transition trans_g15 = {{0, 1, 1},
                                {1, 0, 3},
                                {0, 0, 3},
                                {2, 0, 3}};
        partition res_g15 = ts_reduce(state_g15, trans_g15);
        for (auto j : res_g15) {
            std::cout << j << " ";
        }
        std::cout << "\n" << std::endl;
    }
    //test G16b from Matlab
    {
        std::cout<<"Test G16b"<<std::endl;
        state state_g16b = {0, 1, 2, 3, 4};
        transition trans_g16b = {{0, 1, 1},
                                 {1, 0, 2},
                                 {2, 0, 2},
                                 {0, 0, 3},
                                 {3, 0, 4},
                                 {4, 0, 4}};
        partition res_g16b = ts_reduce(state_g16b, trans_g16b);
        for (auto j : res_g16b) {
            std::cout << j << " ";
        }
        std::cout<<"\n"<<std::endl;
    }

    //test G23 from Matlab
    {
        std::cout<<"Test G23"<<std::endl;
        state state_g23 = {0, 1, 2, 3};
        transition trans_g23 = {{0, 0, 1},
                                {0, 0, 2},
                                {0, 9, 3},
                                {2, 9, 3},
                                {3, 0, 1},
                                {3, 0, 0},
                                {1, 9, 1}};
        partition res_g23 = ts_reduce(state_g23, trans_g23);
        for (auto j : res_g23) {
            std::cout << j << " ";
        }
        std::cout << "\n" << std::endl;
    }

    //test G25 from Matlab
    {
        std::cout<<"Test G25"<<std::endl;
        state state_g25 = {0, 1, 2, 3, 4, 5, 6};
        transition trans_g25 = {{0, 0, 1},
                                {1, 0, 2},
                                {0, 2, 2},
                                {2, 0, 3},
                                {3, 1, 4},
                                {4, 0, 5},
                                {5, 1, 6},
                                {3, 3, 6},
                                {6, 2, 6}};
        partition res_g25 = ts_reduce(state_g25, trans_g25);
        for (auto j : res_g25) {
            std::cout << j << " ";
        }
        std::cout << "\n" << std::endl;
    }
*/
    {
        testPerformance("vasy_25_25");
    }
    return 0;
}

void testPerformance(const std::string& testCase){
    LabelRef t;
    t.states = std::get<0> (BigTest(testCase));
    t.transitions = std::get<1> (BigTest(testCase));
    clock_t t1 = clock();
    t.transSystemReduce();
    clock_t t2 = clock();
    std::cout<<"State#: "<<*std::max_element(t.partitions.begin(), t.partitions.end()) + 1<<std::endl;
    std::cout<<"Run Time: "<<(double)(t2 - t1) / CLOCKS_PER_SEC<<"s\n"<<std::endl;
}
