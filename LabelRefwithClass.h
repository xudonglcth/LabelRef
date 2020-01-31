//
// Created by 梁旭东 on 2019-12-10.
//

#ifndef LABELREF_LABELREFWITHCLASS_H
#define LABELREF_LABELREFWITHCLASS_H

#include "ReadVLTS.h"
#include <vector>
#include <set>
#include <map>
typedef std::vector<std::vector<size_t >> trans_per_state;
typedef std::vector<size_t > bound;
using in_going_trans = std::vector<size_t >;
class LabelRef {
public:
    state states;
    transition transitions;
    std::vector<size_t> partitions_new;
    int tau = 0;
    LabelRef() = default;
    LabelRef(state &s, transition &t, std::vector<size_t > &p, int tau_)
            :
            states(s), transitions(t), partitions_new(p), tau(tau_) {}
private:
    trans_per_state inTransPerState;
    bound lower_bound, upper_bound;
    std::vector<std::set<std::pair<size_t, size_t>>> label;
    std::vector<size_t > partitions;
public:
    void transSystemReduce(){
        size_t n = states.size(), count;
        std::map<std::pair<size_t, std::set<std::pair<size_t , size_t >>>, size_t > hashtable;
        Boundaries();
        if (partitions_new.empty()){
            for(size_t i = 0; i < n; i++){
                partitions_new.push_back(0);
            }
        }

        do{
            count = 0;
            partitions = partitions_new;
            label.clear();
            hashtable.clear();
            for(size_t i = 0; i < n; i++){
                label.emplace_back();
            }

            for(auto current_trans : transitions){
                size_t source = current_trans[0], event = current_trans[1], target = current_trans[2];
                if (!(event == tau && partitions[source] == partitions[target])){
                    labelInsert(source, event, partitions[target]);
                }
            }

            for (auto current_state : states){
                if(hashtable.find(std::make_pair(partitions[current_state], label[current_state])) == hashtable.end()){
                    hashtable[std::make_pair(partitions[current_state], label[current_state])] = count;
                    count++;
                }
            }

            for (auto current_state : states){
                partitions_new[current_state] = hashtable[std::make_pair(partitions[current_state], label[current_state])];
            }
        }while(partitions_new != partitions);
        int a = 0;
        result();
        //std::cout << "Finsished!" << std::endl;
    }

private:
    void Boundaries(){
        for(size_t i = 0; i < states.size(); i++){
            lower_bound.push_back(0);
            upper_bound.push_back(0);
        }
        for(size_t j = 0; j < transitions.size(); j++){
            inTransPerState.push_back({0, 0, 0});
        }
        std::vector<size_t > indices(states.size() + 1, 0);

        for(auto i : transitions){
            indices[i[2]]++;
        }
        size_t sum = 0;
        for (auto &j : indices){
            sum += j;
            j = sum;
        }
        for(auto k : transitions){
            indices[k[2]]--;
            inTransPerState[indices[k[2]]] = {k[0], k[1], k[2]};
        }
        for(size_t i = 0; i < lower_bound.size(); i++){
            lower_bound[i] = indices[i];
            upper_bound[i] = indices[i + 1];
        }
    }

    void labelInsert(size_t target, size_t event, size_t block){
        if (label[target].insert(std::make_pair(event, block)).second){
            for(size_t i = lower_bound[target]; i < upper_bound[target]; i++){
                //in_going_trans ingoingTrans = inTransPerState[i];
                if (inTransPerState[i][1] == tau && partitions[target] == partitions[inTransPerState[i][0]]){
                    labelInsert(inTransPerState[i][0], event, block);
                }
            }
        }
    }

    void labelInsert_1(size_t target, size_t event, size_t block){
        if (label[target].insert(std::make_pair(event, block)).second){
            for(size_t i = lower_bound[target]; i < upper_bound[target]; i++){
                in_going_trans ingoingTrans = inTransPerState[i];
                if (ingoingTrans[1] == tau && partitions[target] == partitions[ingoingTrans[0]]){
                    labelInsert_1(ingoingTrans[0], event, block);
                }
            }
        }
    }

    void result(){
        transition transitions_pi;
        for (const auto& iter : transitions){
            if (!(partitions[iter[0]] == partitions[iter[2]] && iter[1] == 0)){
                transitions_pi.push_back({partitions[iter[0]], iter[1], partitions[iter[2]]});
            }
        }
        int cnt = 0;
        std::set<std::vector<size_t >> s(transitions_pi.begin(), transitions_pi.end());
        int flag = 1;
        for (auto & iter : s){
            if (iter[0] == iter[2] && iter[1] == 0){
                ++cnt;
            }
        }

        std::cout << "transitions#: " << s.size()<<std::endl;
    /*
        for (const auto &i : s){
            for (const auto &j : i){
                std::cout << j << " ";
            }
            std::cout << std::endl;
        }

        std::cout << "all zero:"<< cnt << std::endl;
*/
    }
};



#endif //LABELREF_LABELREFWITHCLASS_H

