//
// Created by 梁旭东 on 2019-12-16.
//
#include "LabelRefwithClass.h"
#ifndef LABELREF_BBSINBOOLEAN_H
#define LABELREF_BBSINBOOLEAN_H
typedef std::vector<bool> boolVec;
class BBSBool{
public:
    state X, nDeltaC;
    boolVec B, BF, BT, BTiv, BD;
    size_t n;
    transition T, Tv, deltaC;
    size_t tau = 1;
    state Pi, Pi0;

    void BBSinBool(){
        n = X.size();
        size_t m = T.size();
        state X1;
        boolVec BivTarget (n, false);
        boolVec BivTarF = BivTarget;
        boolVec BD1;
        std::vector<size_t > zero3(n, 0);
        for (size_t i = 0; i < n; ++i){
            BF.push_back(false);
            nDeltaC.push_back(0);
            deltaC.push_back(zero3);
            Pi.push_back(3);
            Pi0.push_back(3);
        }
        for (size_t i = 0; i < m; ++i){
            BT.push_back(T[i][1] == tau);
        }
        if (!T.empty()){
            for (auto & i : T){
                if (i[1] == tau){
                    size_t q = i[2];
                    nDeltaC[q - 1] += 1;
                    deltaC[nDeltaC[q - 1] - 1][q - 1] = i[0];
                }
            }
        }
        size_t iter = 0;
        do{
            boolVec subGamma(n, false);
            std::vector<std::vector<bool> > gamma (n*T.size() + X.size(), subGamma);
            BivTarget = BivTarF;
            BTiv.clear(); Tv.clear();
            iter += 1;
            for (size_t i = 0; i < m; ++i){
                BTiv.push_back(BT[i] && Pi[T[i][0] - 1] == Pi[T[i][2] - 1]);
            }
            for (size_t i = 0; i < m; ++i){
                if (!BTiv[i]){
                    Tv.push_back(T[i]);
                }
            }
            for (size_t i = 0; i < m; ++i){
                if (BTiv[i]){
                    BivTarget[T[i][2] - 1] = true;
                }
            }
            for (auto & k : Tv){
                B = BF;
                B[k[0] - 1] = true;
                BD = B;
                do{
                    BD1 = BF;
                    for (size_t i = 0; i < n; i++){
                        if (BD[i] && BivTarget[i]){
                            size_t q = X[i];
                            for (size_t j = 0; j < nDeltaC[q - 1]; ++j){
                                if (Pi[deltaC[j][q - 1] - 1] == Pi[q - 1]){
                                    BD1[deltaC[j][q - 1] - 1] = true;
                                }
                            }
                        }
                    }
                    for (size_t l = 0; l < n; ++l){
                        BD[l] = BD1[l] && !B[l];
                    }
                    for (size_t l = 0; l < n; ++l){
                        B[l] = B[l] || BD[l];
                    }
                }while(*max_element(BD.begin(), BD.end()));

                size_t aPi = n*k[1] + Pi[k[2] - 1];
                for (size_t i = 0; i < n; ++i){
                    if(B[i]){
                        gamma[aPi - 1][i] = true;
                    }
                }
            }


            gamma.erase(std::remove(gamma.begin(), gamma.end(), subGamma), gamma.end());
            std::map<std::vector<bool>, size_t> gamma_map;
            std::vector<bool> subGammaT;
            std::vector<std::vector<bool> > hashKey;
            size_t count = 0;
            for(size_t i = 0; i < n; ++i){
                for(auto & j : gamma){
                    subGammaT.push_back(j[i]);
                }
                if (gamma_map.find(subGammaT) == gamma_map.end()){
                    count += 1;
                    gamma_map[subGammaT] = count;
                }
                hashKey.push_back(subGammaT);
                subGammaT.clear();
            }
            Pi0 = Pi;
            for (size_t i = 0; i < n; ++i){
                Pi[i] = gamma_map[hashKey[i]];
            }
        }while(Pi != Pi0);
    }
};
#endif //LABELREF_BBSINBOOLEAN_H
