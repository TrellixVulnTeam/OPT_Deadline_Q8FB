
/*
Copyright 2017 Biagio Festa <info@biagiofesta.it>

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#include "Algorithm1.hpp"
#include "FineGrain.hpp"
#include "InitialSolution_SA.hpp"

bool Algorithm1::process(const Configuration& configuration, Process* process,
                         std::ostream* log, std::ostream* result_log) {
  try {
    // Initialization deadlines (first algorithm initialization)
    InitialSolution_SA initial_deadline_solution;
    initial_deadline_solution.process(process, log);

    // Dump with initial solution
    process->dump_process(result_log, "Input Solution SA");

    // Fine Grain
    FineGrain fine_grain_algorithm(configuration);
    fine_grain_algorithm.process(process, log, result_log);
  } catch (const std::exception& err) {
    *log << err.what() << '\n';
    return false;
  }
  return true;
}
