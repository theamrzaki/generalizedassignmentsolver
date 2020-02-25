#pragma once

#include "generalizedassignmentsolver/solution.hpp"

#include "knapsacksolver/algorithms/minknap.hpp"
#include "knapsacksolver/algorithms/bellman.hpp"

namespace generalizedassignmentsolver
{

struct ColGenOptionalParameters
{
    Info info = Info();

    std::string solver = "clp"; // "clp", "cplex"
    std::vector<std::vector<std::vector<ItemIdx>>>* columns = NULL;
    std::vector<int>* fixed_alt = NULL; // -1: unfixed, 0: fixed to 0, 1: fixed to 1.
    std::vector<int>* fixed_agents = NULL; // 0: unfixed, 1: fixed.

    ColGenOptionalParameters& set_params(const std::vector<std::string>& argv)
    {
        for (auto it = argv.begin() + 1; it != argv.end(); ++it) {
            if (*it == "solver") { solver = *(++it); }
        }
        return *this;
    }
};

struct ColGenOutput: Output
{
    ColGenOutput(const Instance& ins, Info& info): Output(ins, info) { }
    ColGenOutput& algorithm_end(Info& info);

    std::vector<std::vector<std::vector<ItemIdx>>> columns;
    std::vector<std::pair<AgentIdx, ColIdx>> column_indices;
    std::vector<double> solution;
    std::vector<double> x;
    Counter it = 0;
    Counter added_column_number = 0;
};

ColGenOutput columngeneration(const Instance& ins, ColGenOptionalParameters p = {});

}

