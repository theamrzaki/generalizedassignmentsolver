#pragma once

#include "gap/lib/instance.hpp"
#include "gap/lib/solution.hpp"

namespace gap
{

bool shiftswap_first(Solution& sol, std::vector<std::pair<ItemIdx, ItemIdx>>& alt,
        std::default_random_engine& gen, Info& info);
bool shiftswap_best(const Instance& ins, Solution& sol, Info& info);
bool doubleshift_best(const Instance& ins, Solution& sol, Info& info);
bool tripleswap_best(const Instance& ins, Solution& sol, Info& info);

Solution sol_ls_shiftswap_first(const Instance& ins, Solution& sol, std::default_random_engine& gen, Info info = Info());
Solution sol_ls_shiftswap_best(const Instance& ins, Solution& sol, std::default_random_engine& gen, Info info = Info());
Solution sol_ts_shiftswap(const Instance& ins, Solution& sol, std::default_random_engine& gen, Info info = Info());


}

