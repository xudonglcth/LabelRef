//
//  synchronous_composition.h
//  sync
//
//  Created by 梁旭东 on 2020-01-27.
//  Copyright © 2020 xudongl. All rights reserved.
//

#ifndef synchronous_composition_h
#define synchronous_composition_h
#include <vector>
#include <set>
#include <map>
class Synchronization{
public:
    std::set<size_t > sigma_1, sigma_2;
    std::map<size_t ,std::set<size_t> > sigma_f1, sigma_f2;
    std::set<size_t > sigma_sb;
    std::map <std::vector<size_t>, std::set<size_t>> sigma_f;
    std::map<std::vector<size_t>, std::set<size_t> > delta1, delta2;
    std::map<std::vector<size_t>, std::set<std::vector<size_t > > > delta;
    std::set<size_t> init_1, init_2;
    std::set<std::vector<size_t> > X;

    void sync(){
        int k = 0;
        std::vector<std::set<std::vector<size_t >>> delta_X;
        std::set<size_t > sigma_il = sigma_1;
        std::set<size_t> set1, set2, set3, res;
        std::set<std::vector<size_t > > delta_val;
        std::vector<size_t > delta_key;
        for(auto ele : sigma_2){
            sigma_il.insert(ele);
        }
        for (auto ele : sigma_sb){
            sigma_il.erase(ele);
        }
        setCrossProduct(init_1, init_2, X);
        delta_X.push_back(X);
        do{
            ++k;
            delta_X.emplace_back();
            for (const auto& i : delta_X[k - 1]){
                set1.clear();set2.clear();set3.clear();
                sigma_f[i] = {};

                //first for loop
                res.clear();
                std::set_intersection(sigma_f1[i[0]].begin(), sigma_f1[i[0]].end(),
                                      sigma_f2[i[1]].begin(), sigma_f2[i[1]].end(),
                                      std::inserter(set1, set1.begin()));
                std::set_intersection(set1.begin(), set1.end(),
                                      sigma_sb.begin(), sigma_sb.end(),
                                      std::inserter(res, res.begin()));
                set1 = res;
                for (auto a : set1){
                    sigma_f[i].insert(a);
                    delta_key = {i[0], i[1], a};
                    delta_val.clear();
                    setCrossProduct(delta1[{i[0], a}], delta2[{i[1], a}], delta_val);
                    for (auto ele : delta_key){
                        std::cout << ele << " ";
                    }
                    //std::cout << std::endl;
                    if (delta[delta_key].empty()){
                        delta[delta_key] = delta_val;
                    }
                    else{
                        for (auto ele : delta_val){
                            delta[delta_key].insert(ele);
                        }
                    }
                    for (const auto& val:delta_val){
                        std::cout << std::endl;
                        for (auto ele: val){
                            std::cout << ele << " ";
                        }
                        std::cout << '\n'<<std::endl;
                        delta_X[k].insert(val);
                    }
                }

                //second for loop
                res.clear();
                std::set_intersection(sigma_f1[i[0]].begin(), sigma_f1[i[0]].end(),
                                      sigma_il.begin(), sigma_il.end(),
                                      std::inserter(res, res.end()));
                set2 = res;
                for (auto a : set2){
                    sigma_f[i].insert(a);
                    delta_key = {i[0], i[1], a};
                    delta_val.clear();
                    setCrossProduct(delta1[{i[0], a}], {i[1]}, delta_val);
                    if (delta[delta_key].empty()){
                        delta[delta_key] = delta_val;
                    }
                    else{
                        for (auto ele : delta_val){
                            delta[delta_key].insert(ele);
                        }
                    }
                    for (auto ele : delta_key){
                        std::cout << ele << " ";
                    }
                    //std::cout << std::endl;
                    for (const auto& val:delta_val){
                        std::cout << std::endl;
                        for (auto ele: val){
                            std::cout << ele << " ";
                        }
                        std::cout << '\n'<<std::endl;
                        delta_X[k].insert(val);
                    }
                }

                //third for loop
                res.clear();
                std::set_intersection(sigma_f2[i[1]].begin(), sigma_f2[i[1]].end(),
                                      sigma_il.begin(), sigma_il.end(),
                                      std::inserter(res, res.end()));
                set3 = res;
                for (auto a : set3){
                    sigma_f[i].insert(a);
                    delta_key = {i[0], i[1], a};
                    delta_val.clear();
                    setCrossProduct({i[0]}, delta2[{i[1], a}], delta_val);
                    if (delta[delta_key].empty()){
                        delta[delta_key] = delta_val;
                    }
                    else{
                        for (auto ele : delta_val){
                            delta[delta_key].insert(ele);
                        }
                    }
                    for (auto ele : delta_key){
                        std::cout << ele << " ";
                    }
                    //std::cout << std::endl;
                    for (const auto& val:delta_val){
                        std::cout << std::endl;
                        for (auto ele: val){
                            std::cout << ele << " ";
                        }
                        std::cout << '\n'<<std::endl;
                        delta_X[k].insert(val);
                    }
                }
            }
            for (const auto& ele: X){
                delta_X[k].erase(ele);
            }
            for (auto ele : delta_X[k]){
                X.insert(ele);
            }
        }while(! delta_X[k].empty());
        int a = 1;
        std::cout<< "Finished!\n" << std::endl;
    }

    static void setCrossProduct(const std::set<size_t>& s1, const std::set<size_t>& s2, std::set<std::vector<size_t> > &s){
        for (auto i : s1){
            for (auto j : s2){
                std::vector<size_t> v = {i, j};
                s.insert(v);
            }
        }
    }

};

#endif /* synchronous_composition_h */
