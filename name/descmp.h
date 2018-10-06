//
// Created by zhaojiangcheng on 2018/10/4.
//

#ifndef NAME_DESCMP_H
#define NAME_DESCMP_H

#include <array>
const int length = 4;
const int width = 4;
using multiarr = std::array<std::array<double,length>,width>;

void LU_descomposed(multiarr &a, multiarr &l, multiarr &u);
void print_matrix(multiarr, const int);

#endif //NAME_DESCMP_H
