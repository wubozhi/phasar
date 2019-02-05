/******************************************************************************
 * Copyright (c) 2018 Philipp Schubert.
 * All rights reserved. This program and the accompanying materials are made
 * available under the terms of LICENSE.txt.
 *
 * Contributors:
 *     Philipp Schubert and others
 *****************************************************************************/

#ifndef PHASAR_PHASARPASS_OPTIONS_H_
#define PHASAR_PHASARPASS_OPTIONS_H_

#include <string>
#include <vector>

#include  <llvm/Support/CommandLine.h>

extern llvm::cl::OptionCategory PhASARCategory;

namespace psr {

extern std::string DataFlowAnalysis;

extern std::string PointerAnalysis;

extern std::string CallGraphAnalysis;

extern std::vector<std::string> EntryPoints;

extern std::string PammOutputFile;

extern bool PrintEdgeRecorder;

} // namespace psr

#endif
