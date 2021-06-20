//===- CalyxDialect.h - Calyx dialect declaration ---------------*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file defines the Calyx MLIR dialect.
//
//===----------------------------------------------------------------------===//

#ifndef CIRCT_DIALECT_CALYX_CALYXDIALECT_H
#define CIRCT_DIALECT_CALYX_CALYXDIALECT_H

#include "circt/Support/LLVM.h"
#include "mlir/IR/Attributes.h"
#include "mlir/IR/BuiltinAttributes.h"
#include "mlir/IR/Types.h"
#include "mlir/IR/Dialect.h"
#include "mlir/IR/BuiltinOps.h"

// Pull in the Dialect definition.
#include "circt/Dialect/Calyx/CalyxDialect.h.inc"

// Pull in all enum type definitions.
#include "circt/Dialect/Calyx/CalyxEnums.h.inc"

#endif // CIRCT_DIALECT_CALYX_CALYXDIALECT_H
