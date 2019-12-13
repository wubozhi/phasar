/******************************************************************************
 * Copyright (c) 2017 Philipp Schubert.
 * All rights reserved. This program and the accompanying materials are made
 * available under the terms of LICENSE.txt.
 *
 * Contributors:
 *     Philipp Schubert and others
 *****************************************************************************/

/*
 * IDETabulationProblem.h
 *
 *  Created on: 04.08.2016
 *      Author: pdschbrt
 */

#ifndef PHASAR_PHASARLLVM_IFDSIDE_IDETABULATIONPROBLEM_H_
#define PHASAR_PHASARLLVM_IFDSIDE_IDETABULATIONPROBLEM_H_

#include <set>
#include <string>

#include <phasar/PhasarLLVM/ControlFlow/ICFG.h>
#include <phasar/PhasarLLVM/DataFlowSolver/IfdsIde/EdgeFunctions.h>
#include <phasar/PhasarLLVM/DataFlowSolver/IfdsIde/IFDSTabulationProblem.h>
#include <phasar/PhasarLLVM/DataFlowSolver/IfdsIde/JoinLattice.h>

namespace psr {

class ProjectIRDB;
template <typename T, typename M> class TypeHierarchy;
template <typename V> class PointsToInfo;

template <typename N, typename D, typename M, typename T, typename V,
          typename L, typename I>
class IDETabulationProblem : public IFDSTabulationProblem<N, D, M, T, V, I>,
                             public virtual EdgeFunctions<N, D, M, L>,
                             public virtual JoinLattice<L>,
                             public virtual EdgeFactPrinter<L> {
  static_assert(std::is_base_of_v<ICFG<N, M>, I>,
                "I must implement the ICFG interface!");

public:
  IDETabulationProblem(const ProjectIRDB *IRDB, const TypeHierarchy<T, M> *TH,
                       const I *ICF, const PointsToInfo<V> *PT,
                       std::set<std::string> EntryPoints = {})
      : IFDSTabulationProblem<N, D, M, T, V, I>(IRDB, TH, ICF, PT,
                                                EntryPoints) {}
  ~IDETabulationProblem() override = default;
  virtual EdgeFunction<L>* allTopFunction() = 0;
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winconsistent-missing-override"
  virtual void emitTextReport(std::ostream &os,
                              const SolverResults<N, D, L> &SR) {
    os << "No text report available!\n";
  }
#pragma clang diagnostic pop
private:
  using IFDSTabulationProblem<N, D, M, T, V, I>::emitTextReport;
};

} // namespace psr

#endif
