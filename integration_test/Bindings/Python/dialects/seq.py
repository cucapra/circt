# REQUIRES: bindings_python
# RUN: %PYTHON% %s | FileCheck %s

import circt
from circt.dialects import rtl, seq

from mlir.ir import *

with Context() as ctx, Location.unknown():
  circt.register_dialects(ctx)

  i1 = IntegerType.get_signless(1)
  i32 = IntegerType.get_signless(32)

  m = Module.create()
  with InsertionPoint(m.body):

    @rtl.RTLModuleOp.from_py_func(i1, i1)
    def top(clk, rstn):
      # CHECK: %[[RESET_VAL:.+]] = rtl.constant 0
      reg_reset = rtl.ConstantOp(i32, IntegerAttr.get(i32, 0)).result
      # CHECK: %[[INPUT_VAL:.+]] = rtl.constant 45
      reg_input = rtl.ConstantOp(i32, IntegerAttr.get(i32, 45)).result
      # CHECK: %[[DATA_VAL:.+]] = seq.compreg %[[INPUT_VAL]], %clk, %rstn, %[[RESET_VAL]]
      reg = seq.CompRegOp(i32, reg_input, clk, rstn, reg_reset)
      # CHECK: rtl.output %[[DATA_VAL]]
      return reg.data

  print(m)