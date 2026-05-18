#!/usr/bin/bash
# Fix up long or colliding filenames for building in CMS.

# Exit if there is an error
set -euo pipefail

# Show the commands
set -x

cd src

mv avl_tree.c                  avltree.c
mv crexxsaa_tool.c             csaatool.c
mv interrupt.c                 interrup.c
mv levelbfunc.exec             lvlbfunc.exec
mv rxas_test_flatten.c         rastsflt.c
mv rxas_dsl.c                  rxasdsl.c
mv rxas_opt.c                  rxasopt.c
mv rxcp_ast_core.c             rcacore.c
mv rxcp_ast_print.c            rcaprt.c
mv rxcp_ast_rewrite.c          rcarewrt.c
mv rxcp_ast_val.c              rcasval.c
mv rxcp_ast_walk.c             rcawalk.c
mv rxcp_diag_fallback.c        rcdiagfb.c
mv rxcp_dsl.c                  rxcpdsl.c
mv rxcp_emit_core.c            rcecore.c
mv rxcp_emit_expr.c            rceexpr.c
mv rxcp_emit_flow.c            rceflow.c
mv rxcp_emit_meta.c            rcemeta.c
mv rxcp_emit_proc.c            rceproc.c
mv rxcp_emit_reg.c             rcereg.c
mv rxcp_exit.c                 rcexit.c
mv rxcp_fixup.c                rcfixup.c
mv rxcp_highlight_controller.c rchictl.c
mv rxcp_inline.c               rcinline.c
mv rxcp_instr.c                rcinstr.c
mv rxcp_opt.c                  rxcpopt.c
mv rxcp_source_tree.c          rcsrctr.c
mv rxcp_util.c                 rcutil.c
mv rxcp_val_check.c            rcvcheck.c
mv rxcp_val_orch.c             rcvorch.c
mv rxcp_val_plugin.c           rcvplgin.c
mv rxcp_val_sym.c              rcvsym.c
mv rxcp_val_trans.c            rcvtrans.c
mv rxcp_val_type.c             rcvtype.c
mv rxlinkmain.c                rxlkmain.c
mv rxpafuncs.c                 rxpafunc.c
mv rxvm_run.c                  rxvmrun.c
mv rxvmplugin_framework.c      rxplfr.c
