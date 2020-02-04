//
// Created by 梁旭东 on 2020-02-03.
//
#include <utility>
#include <vector>
#include <map>
#include <set>
#ifndef LABELREF_DINNINGPHILOSOPHERS_H
#define LABELREF_DINNINGPHILOSOPHERS_H
class System{
public:
    using state = std::vector<size_t>;
    using sigmaFSync = std::map <std::vector<size_t>, std::set<size_t>>;
    using sigmaf = std::map<size_t ,std::set<size_t> >;
    using delta = std::map<std::vector<size_t>, std::set<size_t> >;
    using deltaSync = std::map<std::vector<size_t>, std::set<std::vector<size_t > > >;
    using init = std::set<size_t>;
    using X = std::set<std::vector<size_t> >;
    using sigma = std::set<size_t >;
    System() = default;
    System(delta d1, sigmaf sigmaF1, sigma sigmaG1, init initR1)
    :
    d(std::move(d1)), sigma_f(std::move(sigmaF1)), sigmaG(std::move(sigmaG1)), init1(std::move(initR1))
    {}
    state states;
    delta d;
    init i1;
    sigmaf sigma_f;
    sigma sigmaG;
    init init1;

    static std::vector<std::vector<System> > constructG(int n){
        std::vector<size_t > r_up, r_down, eat, think;

        for (int i = 1; i <= n; ++i){
            r_up.push_back(i);
            r_down.push_back(n + i);
            eat.push_back(2*n + 1);
            think.push_back(3*n + i);
        }
        std::vector<System> GList, RList;
        System G, R;
        for (int i = 0; i != n; ++i){
            GList.push_back(G);
            RList.push_back(R);
        }
        int i = 0;
        for (auto &iter : GList){
            iter.states = {0, 1, 2, 3, 4, 5, 6};
            iter.sigmaG = {r_up[i], r_up[(i + 1 == n) ? 1 : i + 1], r_down[i], r_down[(i + 1 == n) ? 1 : i + 1], eat[i], think[i]};
            iter.sigma_f = {{0, {think[i],  r_up[i], r_up[(i + 1 == n) ? 1 : i + 1]}},
                            {1, {r_down[(i + 1 == n) ? 1 : i + 1]}},
                            {2, {r_up[(i + 1 == n) ? 1 : i + 1]}},
                            {3, {r_up[i]}},
                            {4, {r_down[i]}},
                            {5, {eat[i]}},
                            {6, {r_down[i], r_down[(i + 1 == n) ? 1 : i + 1]}}};
            iter.d = {{{0, think[i]}, {0}},
                      {{0, r_up[i]}, {2}},
                      {{0, r_up[(i + 1 == n) ? 1 : i + 1]}, {3}},
                      {{1, r_down[(i + 1 == n) ? 1 : i + 1]}, {0}},
                      {{2, r_up[(i + 1 == n) ? 1 : i + 1]}, {5}},
                      {{3, r_up[i]},{5}},
                      {{4, r_down[i]}, {0}},
                      {{5, eat[i]}, {6}},
                      {{6, r_down[i]},{1}},
                      {{6, r_down[(i + 1 == n) ? 1 : i + 1]},{4}}};
            ++i;
            iter.init1 = {0};
        }
        int j = 0;
        for (auto &iter : RList){
            iter.states = {0, 1};
            iter.sigmaG = {r_up[j], r_down[j]};
            iter.sigma_f = {{0, {r_up[j]}}, {{1}, {r_down[j]}}};
            iter.d = {{{0, r_up[j]}, {1}}, {{1, r_down[j]}, {0}}};
            ++j;
            iter.init1 = {0};
        }
        return {GList, RList};
    }
};

#endif //LABELREF_DINNINGPHILOSOPHERS_H
