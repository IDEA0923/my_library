#include "default.hpp"
inline int fnd(string m , string d){
    int a = m .size();
    int b = d.size();
    for(int ind = 0; ind < a; ind ++){
        if(m[ind] == d[0]){
            ind++;

            for(int ind2 = 1; ind2 < b ; ind2++){
                if(m[ind] != d[ind2]){
                    goto st;
                }
                ind++;
            }
            return ind;
        }
        st:
    }
    return -1;
}