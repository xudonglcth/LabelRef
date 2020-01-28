#include <iostream>
#include "ReadVLTS.h"
#include "LabelRefwithClass.h"
#include "BBSinBoolean.h"
#include "sync.h"
#include <tuple>
void testPerformance(const std::string& testCase);
void testPerformanceBool(const std::string& testCase);
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
        state state_g16b = {1, 2, 3, 4, 5};
        transition trans_g16b = {{1, 2, 2},
                                 {2, 1, 3},
                                 {3, 1, 3},
                                 {1, 1, 4},
                                 {4, 1, 5},
                                 {5, 1, 5}};
        BBSBool g16b;
        g16b.X = state_g16b;
        g16b.T = trans_g16b;
        g16b.BBSinBool();
        for (auto j : g16b.Pi) {
            std::cout << j << " ";
        }
        std::cout<<"\n"<<std::endl;
    }

    //test G23 from Matlab
    {
        std::cout<<"Test G23"<<std::endl;
        state state_g23 = {1, 2, 3, 4};
        transition trans_g23 = {{1, 1, 2},
                                {1, 1, 3},
                                {1, 2, 4},
                                {3, 2, 4},
                                {4, 1, 2},
                                {4, 1, 1},
                                {2, 2, 2}};
        BBSBool G23;
        G23.X = state_g23;
        G23.T = trans_g23;
        G23.BBSinBool();
        for (auto j : G23.Pi) {
            std::cout << j << " ";
        }
        std::cout << "\n" << std::endl;
    }

    //test G25 from Matlab
    {
        std::cout<<"Test G25"<<std::endl;
        state state_g25 = {1, 2, 3, 4, 5, 6, 7};
        transition trans_g25 = {{1, 1, 2},
                                {2, 1, 3},
                                {1, 3, 3},
                                {3, 1, 4},
                                {4, 2, 5},
                                {5, 1, 6},
                                {6, 2, 7},
                                {4, 4, 7},
                                {7, 3, 7}};
        BBSBool g25;
        g25.X = state_g25;
        g25.T = trans_g25;
        g25.BBSinBool();
        for (auto j : g25.Pi) {
            std::cout << j << " ";
        }
        std::cout << "\n" << std::endl;
    }
    */

    {
        //testPerformanceBool("vasy_0_1");
        //testPerformance("cwi_1_2");
    }

    {
        Synchronization G0;
        G0.delta1 = {{{0, 0}, {1}}, {{1, 1}, {2}}, {{2, 2}, {3}}, {{3, 3}, {4}}};
        G0.delta2 = {{{0, 4}, {1}}, {{1, 1}, {2}}, {{2, 4}, {3}}, {{3, 2}, {4}}};
        G0.sigma_f1 = {{0, {0}}, {1, {1}}, {2, {2}}, {3, {3}}, {4, {}}};
        G0.sigma_f2 = {{0, {4}}, {1, {1}}, {2, {4}}, {3, {2}}, {4, {}}};
        G0.sigma_1 = {0, 1, 2, 3};
        G0.sigma_2 = {1, 2, 4};
        G0.sigma_sb = {1, 3};
        G0.init_1 = {0};
        G0.init_2 = {0};
        std::cout << "G0\n" << std::endl;
        G0.sync();

        Synchronization G1;
        G1.delta1 = {{{1, 2}, {2}}, {{2, 3}, {2}}};
        G1.delta2 = {{{1, 3}, {2}}, {{2, 4}, {2}}};
        G1.sigma_f1 = {{1, {2}}, {2, {3}}};
        G1.sigma_f2 = {{1, {3}}, {2, {4}}};
        G1.sigma_1 = {2, 3};
        G1.sigma_2 = {3, 4};
        G1.sigma_sb = {3};
        G1.init_1 = {1};
        G1.init_2 = {1};
        std::cout << "G1\n" << std::endl;
        G1.sync();

        Synchronization G2;
        G2.delta1 = {};
        G2.delta2 = {{{1, 2}, {2}}, {{1, 3}, {2}}};
        G2.sigma_f1 = {{1, {}}, {2, {}}};
        G2.sigma_f2 = {{1, {2, 3}}, {2, {}}};
        G2.sigma_1 = {2, 3, 4};
        G2.sigma_2 = {2, 3, 4};
        G2.sigma_sb = {2, 3, 4};
        G2.init_1 = {1};
        G2.init_2 = {1};
        std::cout << "G2\n" << std::endl;
        G2.sync();

        Synchronization G4;
        G4.delta1 = {{{1, 2}, {2}}, {{1, 4}, {2}}, {{1, 3}, {3}}};
        G4.delta2 = {{{1, 2}, {2}}, {{1, 3}, {2}}};
        G4.sigma_f1 = {{1, {2, 3, 4}}, {2, {}}, {3, {}}};
        G4.sigma_f2 = {{1, {2, 3}}, {2, {}}};
        G4.sigma_1 = {2, 3, 4};
        G4.sigma_2 = {2, 3, 4};
        G4.sigma_sb = {2, 3, 4};
        G4.init_1 = {1};
        G4.init_2 = {1};
        std::cout << "G4\n" << std::endl;
        G4.sync();

        Synchronization G5;
        G5.delta1 = {{{1, 2}, {2}}, {{2, 3}, {1}}};
        G5.delta2 = {{{1, 3}, {2}}, {{2, 4}, {1}}};
        G5.sigma_f1 = {{1, {2}}, {2, {3}}};
        G5.sigma_f2 = {{1, {3}}, {2, {4}}};
        G5.sigma_1 = {2, 3};
        G5.sigma_2 = {3, 4};
        G5.sigma_sb = {3};
        G5.init_1 = {1};
        G5.init_2 = {1};
        std::cout << "G5\n" << std::endl;
        G5.sync();

        Synchronization G6;
        G6.delta1 = {{{1, 2}, {1}}, {{1, 3}, {2}}};
        G6.delta2 = {{{1, 2}, {2}}, {{2, 3}, {3}}};
        G6.sigma_f1 = {{1, {2, 3}}, {2, {}}};
        G6.sigma_f2 = {{1, {2}}, {2, {3}}, {3, {}}};
        G6.sigma_1 = {2, 3};
        G6.sigma_2 = {2, 3};
        G6.sigma_sb = {2, 3};
        G6.init_1 = {1, 2};
        G6.init_2 = {1};
        std::cout << "G6\n" << std::endl;
        G6.sync();

        Synchronization G7;
        G7.delta1 = {{{1, 5}, {2}},{{2, 6}, {3}},{{3, 3}, {3}}};
        G7.delta2 = {{{1, 6}, {2}}, {{2, 8}, {3}}, {{3, 3}, {3}}};
        G7.sigma_f1 = {{1, {5}}, {2, {6}}, {3, {3}}};
        G7.sigma_f2 = {{1, {6}}, {2, {8}}, {3, {3}}};
        G7.sigma_1 = {5, 6, 3};
        G7.sigma_2 = {6, 8, 3};
        G7.sigma_sb = {3, 6};
        G7.init_1 = {1};
        G7.init_2 = {1};
        std::cout << "G7\n" << std::endl;
        G7.sync();

        Synchronization G8;
        G8.delta1 = {{{1, 6}, {2}},{{2, 3}, {2}}};
        G8.delta2 = {{{1, 6}, {2}}, {{2, 8}, {3}}};
        G8.sigma_f1 = {{1, {6}}, {2, {3}}};
        G8.sigma_f2 = {{1, {6}}, {2, {8}}, {3, {}}};
        G8.sigma_1 = {3, 6};
        G8.sigma_2 = {6, 8};
        G8.sigma_sb = {6};
        G8.init_1 = {1};
        G8.init_2 = {1};
        std::cout << "G8\n" << std::endl;
        G8.sync();

        Synchronization G9;
        G9.delta1 = {{{1, 2}, {2}},{{2, 3}, {3}},{{3, 4}, {4}}, {{4, 5}, {5}}, {{5, 4}, {1}}};
        G9.delta2 = {{{1, 2}, {2}}, {{2, 3}, {3}}, {{3, 60}, {1, 4}}};
        G9.sigma_f1 = {{1, {2}}, {2, {3}}, {3, {4}}, {4, {5}}, {5, {4}}};
        G9.sigma_f2 = {{1, {2}}, {2, {3}}, {3, {60}}, {4, {}}};
        G9.sigma_1 = {2, 3, 4, 5};
        G9.sigma_2 = {2, 3, 60};
        G9.sigma_sb = {2, 3};
        G9.init_1 = {1};
        G9.init_2 = {1};
        std::cout << "G9\n" << std::endl;
        G9.sync();

        Synchronization G10;
        G10.delta1 = {{{1, 2}, {2}}, {{2, 3}, {3}}, {{3, 4}, {4}}, {{4, 5}, {5}},
                      {{5, 6}, {6}}, {{6, 7}, {7}}, {{7, 8}, {8}}, {{8, 9}, {9}},
                      {{9, 10}, {10}}, {{1, 12}, {2}}, {{2, 13}, {4}}};
        G10.delta2 = {{{1, 2}, {2}}, {{2, 3}, {3}}, {{3, 4}, {4}}, {{4, 5}, {5}},
                      {{5, 6}, {6}}, {{6, 7}, {7}}, {{7, 8}, {8}}, {{8, 9}, {9}},
                      {{9, 10}, {10}}};
        G10.sigma_f1 = {{1, {2, 12}}, {2, {3, 13}}, {3, {4}}, {4, {5}}, {5, {6}},
                        {6, {7}}, {7, {8}}, {8, {9}}, {9, {10}}, {10, {}}};
        G10.sigma_f2 = {{1, {2}}, {2, {3}}, {3, {4}}, {4, {5}}, {5, {6}},
                        {6, {7}}, {7, {8}}, {8, {9}}, {9, {10}}, {10, {}}};
        G10.sigma_1 = {2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 13};
        G10.sigma_2 = {2, 3, 4, 5, 6, 7, 8, 9, 10};
        G10.sigma_sb = {2, 3, 4, 5, 6, 7, 8, 9, 10};
        G10.init_1 = {1};
        G10.init_2 = {1};
        std::cout << "G10\n" << std::endl;
        G10.sync();

        Synchronization G11;
        G11.delta1 = {{{1, 6}, {3}}, {{3, 10}, {4}}};
        G11.delta2 = {{{2, 7}, {4}}, {{4, 6}, {3}}};
        G11.sigma_f1 = {{1, {6}}, {2, {}}, {3, {10}}, {4, {}}};
        G11.sigma_f2 = {{1, {}}, {2, {7}}, {3, {}}, {4, {6}}};
        G11.sigma_1 = {6, 10};
        G11.sigma_2 = {6, 7};
        G11.sigma_sb = {6};
        G11.init_1 = {1};
        G11.init_2 = {2};
        std::cout << "G11\n" << std::endl;
        G11.sync();

        Synchronization G12;
        G12.delta1 = {{{2, 14}, {1}}, {{2, 15}, {4}}, {{2, 18}, {5}}, {{3, 16}, {2}}};
        G12.delta2 = {{{2, 13}, {5}}, {{4, 19}, {5}}, {{5, 16}, {1, 7}}, {{7, 18}, {6}}};
        G12.sigma_f1 = {{1, {}}, {2, {14, 15, 18}}, {3, {16}}, {4, {0}}, {5, {0}}};
        G12.sigma_f2 = {{1, {}}, {2, {13}}, {3, {}}, {4, {19}}, {5, {16}}, {6, {}}, {7, {18}}};
        G12.sigma_1 = {16, 14, 15, 18};
        G12.sigma_2 = {13, 19, 16, 18};
        G12.sigma_sb = {16, 18};
        G12.init_1 = {3};
        G12.init_2 = {2, 4};
        std::cout << "G12\n" << std::endl;
        G12.sync();
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
    std::cout<<"Sigref: "<<std::endl;
    std::cout<<"State#: "<<*std::max_element(t.partitions.begin(), t.partitions.end()) + 1<<std::endl;
    std::cout<<"Run Time: "<<(double)(t2 - t1) / CLOCKS_PER_SEC<<"s\n"<<std::endl;
}

void testPerformanceBool(const std::string& testCase){
    BBSBool t;
    t.X = std::get<0> (BigTest(testCase));
    t.T = std::get<1> (BigTest(testCase));
    for (auto &i : t.X){
        i += 1;
    }
    for (auto &j : t.T){
        for (auto &k : j){
            k += 1;
        }
    }
    clock_t t1 = clock();
    t.BBSinBool();
    clock_t t2 = clock();
    std::cout<<"BBS in Boolean: "<<std::endl;
    std::cout<<"State#: "<<*std::max_element(t.Pi.begin(), t.Pi.end())<<std::endl;
    std::cout<<"Run Time: "<<(double)(t2 - t1) / CLOCKS_PER_SEC<<"s\n"<<std::endl;
}
