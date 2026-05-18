#ifdef __CMS__

/* Functions that needed to be renamed for building on CMS. */

#if __CMSFNS_HDR__ == 1
/* assembler/rxas.h */
#   define RxasmAlloc                                  aRaAlloc
#   define RxasmFree                                   aRaFree
#   define RxasmTrace                                  aRaTrace
#   define promote_floats_to_decimals                  promo_fd
#endif

#if __CMSFNS_HDR__ == 2
/* assembler/rxasassm.h */
#   define rxasqmclss                                  asqmclss
#   define rxasqmattr                                  asqmattr
#   define rxasqmintf                                  asqmintf
#   define rxasqmimpl                                  asqmimpl
#   define rxasqmmemb                                  asqmmemb
#   define rxasmeclss                                  asmeclss
#   define rxasmeattr                                  asmeattr
#   define rxasmeintf                                  asmeintf
#   define rxasmeimpl                                  asmeimpl
#   define rxasmememb                                  asmememb
#endif

#if __CMSFNS_HDR__  == 3
/* compiler/rxcpmain.h */
#   define rxcp_collect_and_prune_diagnostics          ccpdiag
#   define rxcp_run_fallback_diagnostics               crundiag
#   define ast_dump_text                               adumptxt
#   define rxcp_scan_imports                           cscanimp
#   define rxcp_exit_bridge_invoke                     cexitbri
#endif

#if __CMSFNS_HDR__ == 4
/* compiler/rxcp_ast.h */
#   define ast_dup_subtree                             adupstr
#   define ast_dup_subtree_with_symbols                adupstrs
#   define ast_mark_compiler_generated_block           amcgb
#   define ast_set_primary_source_node                 aspsrcn
#   define ast_copy_source_anchor                      acsrcanc
#   define ast_enable_primary_reporting_anchor         aenpranc
#   define ast_add_reporting_source_node               aarsrcnd
#   define ast_clear_reporting_source_nodes            acrsrcns
#   define ast_grft_interpolated                       agrftint
#   define ast_interpolate_exit_fragment               aintexfr
#   define ast_apply_exit_source_map                   aapexsmp
#   define ast_free_exit_source_map                    afxsrcmp
#   define pdot_scope                                  pdotscop
#   define pdot_walker_handler                         pdotwh
#   define prnt_walker_handler                         prntwh
#   define print_error                                 prnterr
#   define mknd_err_unique                             mknderru
#   define pdot_tree                                   pdottree
#   define ast_copy_str                                acopystr
#   define ast_class                                   aclass
#   define ast_set_file_name                           asetfn
#   define rxcp_validate_ast_and_symbols               cvalast
#endif

#if __CMSFNS_HDR__ == 5
/* compiler/rxcp_ast_rewrite.h */
#   define ast_rw_new                                  arwnew
#   define ast_rw_reuse                                arwreuse
#   define ast_rw_add                                  arwadd
#   define ast_rw_move_children                        arwmvch
#   define ast_rw_move_children_replace                arwmvchr
#   define ast_rw_loc                                  arwloc
#   define ast_rw_children                             arwch
#   define ast_execute_rewrite                         aexrw
#endif

#if __CMSFNS_HDR__ == 6
/* compiler/rxcp_ctx.h */
#   define Opts_Alloc                                  optalloc
#   define Opts_Free                                   optfree
#   define Opts_Trace                                  opttrace
#   define RexxBAlloc                                  rballoc
#   define RexxBFree                                   rbfree
#   define RexxBTrace                                  rbtrace
#   define rxcp_scan_source_header                     csansrch
#   define sym_is_imfn                                 symimfn
#   define sym_is_glob_var                             sym_gvar
#   define sym_is_imcls                                symimcl1
#   define sym_imcls                                   symimcl2
#   define ensure_class_imported                       ensclimp
#   define sym_is_interface_symbol                     symiface
#   define sym_is_class_contract_symbol                symcontr
#   define symbol_names_equivalent                     symneqiv
#   define symbol_name_assignable_to                   symnasto
#   define find_unique_implementing_class              fuimpcls
#   define rxcp_debug_header                           cdbghdr
#   define rxcp_print_ast_recursive                    cprtastr
#   define rxcp_print_symbol_table                     cprtsymt
#   define mark_const_args                             _FN0001
#   define meta_narg                                   metanarg
#   define static_linked_functions                     statln_f
#   define static_linked_metadata                      statln_m
#   define free_static_linked_functions                frestlfs
#endif

#if __CMSFNS_HDR__ == 7
/* compiler/rxcp_emit.h */
#   define emit_promotion                              _FN0002
#   define output_fs                                   outputfs
#   define output_insert_before                        _FN0003
#   define output_insert_after                         _FN0004
#   define output_concat                               _FN0005
#   define output_append_text                          _FN0006
#   define output_prepend_text                         _FN0007
#   define print_output                                _FN0008
#   define get_metaline                                _FN0009
#   define get_reporting_metalines                     _FN0010
#   define reset_metaline_source_file                  _FN0011
#   define get_metaline_range                          _FN0012
#   define get_metaline_between                        _FN0013
#   define get_metaline_token_after                    _FN0014
#   define get_metaline_clause                         _FN0015
#   define get_metaline_token_at                       _FN0016
#   define get_comment                                 _FN0017
#   define get_comment_line_number_only                _FN0018
#   define type_promotion                              _FN0019
#   define add_variable_metadata                       _FN0020
#   define clear_variable_metadata                     _FN0021
#   define clear_global_variable_metadata              _FN0022
#   define meta_set_symbol                             _FN0023
#   define add_initiator                               _FN0024
#   define add_scope_initiators                        _FN0025
#   define add_global_symbol                           _FN0026
#   define add_exposed_global_variable                 _FN0027
#   define meta_set_global_symbol                      _FN0028
#   define add_global_variable_metadata                _FN0029
#   define add_all_class_metadata                      _FN0030
#   define meta_clear_symbol                           _FN0031
#   define meta_clear_global_symbol                    _FN0032
#   define callable_effective_return_type              _FN0033
#   define emit_proc                                   _FN0034
#   define emit_expression                             _FN0035
#   define emit_flow                                   _FN0036
#   define is_constant                                 _FN0037
#   define format_constant                             _FN0038
#   define type_to_prefix                              _FN0039
#   define register_walker                             _FN0040
#   define rxcp_exit_bridge_plan_invoke                _FN0041
#   define rxcp_exit_rewrite_diagnostics               _FN0042
#endif

#if __CMSFNS_HDR__ == 8
/* compiler/rxcp_exit.h */
#   define rxcp_init_exits                             _FN0043
#   define rxcp_free_exits                             _FN0044
#   define rxcp_match_certified_exit_primary           _FN0045
#   define rxcp_is_exit_primary                        _FN0046
#   define rxcp_is_exit_additional                     _FN0047
#   define rxcp_get_exit_flags                         _FN0048
#   define rxcp_exit_bridge_invoke                     cexitbri
#endif

#if __CMSFNS_HDR__ == 9
/* compiler/rxcp_highlight_controller.h */
#   define rxc_highlight_controller_parse              _FN0049
#   define rxcp_highlight_controller_reset_cache       _FN0050
#   define rxcp_highlight_controller_get_cache_stats   _FN0051
#endif

#if __CMSFNS_HDR__ == 10
/* compiler/rxcp_source_tree.h */
#   define source_tree_build                           _FN0052
#   define source_tree_clear_diagnostics               _FN0053
#   define source_tree_record_diagnostic               _FN0054
#   define source_tree_sync_diagnostics                _FN0055
#   define source_tree_clear_semantics                 _FN0056
#   define source_tree_sync_semantics                  _FN0057
#   define source_tree_free                            _FN0058
#endif

#if __CMSFNS_HDR__ == 11
/* compiler/rxcp_sym.h */
#   define get_reg_perm                                _FN0059
#   define ret_reg_later                               _FN0060
#   define ret_reg_all_deferred                        _FN0061
#   define get_regs                                    get_regs
#   define ret_regs                                    ret_regs
#   define sym_rslv_local                              _FN0062
#   define sym_rslv_attribute                          _FN0063
#   define sym_rslv_global                             _FN0064
#   define sym_rslv_tiered                             _FN0065
#   define sym_rvfc                                    sym_rvfc
#   define sym_hoist_to_namespace                      _FN0066
#   define sym_mngd_frnm                               _FN0067
#endif

#if __CMSFNS_HDR__ == 12
/* compiler/rxcp_util.h */
#   define error_and_exit                              _FN0068
#   define rx_strndup                                  _FN0069
#   define rxcp_normalize_source_symbol_name           _FN0070
#   define rxcp_source_symbol_is_qualified             _FN0071
#   define rxcp_split_internal_symbol_name             _FN0072
#   define rxcp_internal_name_to_source_qualified      _FN0073
#   define encode_comment_malloc                       _FN0074
#   define encode_line_source_malloc                   _FN0075
#   define hexchar2int                                 _FN0076
#   define binchar2int                                 _FN0077
#   define escape_character                            _FN0078
#   define token_to_string                             _FN0079
#   define node_type_to_string                         _FN0080
#endif

#if __CMSFNS_HDR__ == 13
/* compiler/rxcp_val.h */
#   define is_node_string                              _FN0081
#   define node_to_integer                             _FN0082
#   define node_to_dims                                _FN0083
#   define promote_symbol_from_target                  _FN0084
#   define validate_node_promotion                     _FN0085
#   define validate_node_promotion_for_ref             _FN0086
#   define sym_promote_type                            _FN0087
#   define sym_promote_status                          _FN0088
#   define sym_promote_symtype                         _FN0089
#   define ast_promote_type                            _FN0090
#   define ast_promote_target_type                     _FN0091
#   define ast_set_value_type                          _FN0092
#   define ast_set_target_type                         _FN0093
/* #   define validate_ast                                validate_ast */
#   define rxcp_prepare_work_ast                       _FN0094
#   define rxcp_parse_buffer                           _FN0095
#   define structure_symbols_walker                    _FN0096
#   define build_symbols_walker                        _FN0097
#   define resolve_functions_walker                    _FN0098
#   define exposed_symbols_walker                      _FN0099
#   define validate_symbols                            _FN0100
#   define ast_hoist_var                               _FN0101
#   define ast_hoist_var_typed                         _FN0102
#   define clear_node_types_walker                     _FN0103
#   define set_node_types_walker                       _FN0104
#   define type_safety_walker                          _FN0105
#   define func_type_safety_walker                     _FN0106
#   define float2decimal_walker                        flt2decw
#   define decimal2float_walker                        dec2fltw
#   define rewrite_constructor_walker                  _FN0107
#   define rewrite_exit_walker                         _FN0108
#   define rewrite_implicit_cmd_walker                 _FN0109
#   define syntax_sugar_walker                         _FN0110
#   define control_flow_rewrite_walker                 _FN0111
#   define tostring_rewrite_walker                     _FN0112
#   define needs_rxsysb_walker                         _FN0113
#   define add_rxsysb_walker                           _FN0114
#   define rxcp_fixup_walker                           cfixupw
#   define ast_source_structure_walker                 _FN0115
#   define ast_work_structure_walker                   _FN0116
#   define ast_structure_fixup_walker                  astfixw
#   define source_location_walker                      srclocw
#   define syntax_validation_walker                    synvalw
#   define decimal_parameters_walker                   decprmsw
#   define exit_dispatch_walker                        _FN0117
#   define exit_plan_walker                            _FN0118
#   define identify_inlinable_walker                   _FN0119
#   define inline_procedure_walker                     _FN0120
#   define rxcp_inline_pass                            _FN0121
#   define rxcp_inline_prune                           _FN0122
#   define rxcp_inline_export_payload                  _FN0123
#   define rxcp_inline_payload_is_supported            _FN0124
#   define rxcp_inline_attach_imported_body            _FN0125
#   define rxcp_inline_attach_imported_symbol          _FN0126
#   define set_node_ordinals_walker                    _FN0127
#endif

#if __CMSFNS_HDR__ == 14
/* disassembler/rxdadism.h */
#   define disassemble                                 _FN0128
#endif

#if __CMSFNS_HDR__ == 15
/* inc/rxvm.h */
#   define rxvm_create                                 vmcreate
#   define rxvm_destroy                                _FN0129
#   define rxvm_load                                   vmload
#   define rxvm_load_file                              _FN0130
#   define rxvm_link                                   vmlink
#   define rxvm_prepare                                _FN0131
#   define rxvm_call                                   vmcall
#endif

#if __CMSFNS_HDR__ == 16
/* interpreter/crexxsaa.h */
#   define crexxsaa_create                             _FN0132
#   define crexxsaa_destroy                            _FN0133
#   define crexxsaa_register_address_environment       _FN0134
#   define crexxsaa_set_address_environment            _FN0135
#   define crexxsaa_set_compiler                       _FN0136
#   define crexxsaa_set_cache_dir                      _FN0137
#   define crexxsaa_address_variable_set               _FN0138
#   define crexxsaa_address_variable_get_alloc         _FN0139
#   define crexxsaa_free                               csafree
#   define crexxsaa_run_rxbin                          _FN0140
#   define crexxsaa_run_source                         _FN0141
#   define crexxsaa_invalidate_source                  _FN0142
#   define crexxsaa_invalidate_all                     _FN0143
#   define crexxsaa_get_cache_dir                      _FN0144
#   define crexxsaa_clear_cache                        _FN0145
#   define crexxsaa_last_error                         _FN0146
#endif

#if __CMSFNS_HDR__ == 17
/* interpreter/rxvmintp.h */
#   define rxvm_getsignaltext                          _FN0147
#   define rxvm_getsignalcode                          _FN0148
#   define completely_free_frame                       _FN0149
#   define rxvm_link_module                            _FN0150
#   define rxvm_rebuild_interface_factory_registry     _FN0151
#   define rxvm_rebuild_interface_method_registry      _FN0152
#   define rxvm_callfunc                               _FN0153
#   define getEnvVal                                   _FN0154
#   define shellspawn                                  _FN0155
#   define redrwriteclose                              _FN0156
#   define rxvm_setsayexit                             risetsay
#   define rxvm_resetsayexit                           rirstsay
#   define rxvm_mprintf                                _FN0157
#   define enable_interrupt                            _FN0158
#   define ignore_interrupt                            _FN0159
#   define restore_interrupt                           _FN0160
#   define initialize_vm_signals                       _FN0161
#   define cleanup_vm_signals                          _FN0162
#   define raise_signal                                _FN0163
#   define clear_signal                                _FN0164
#endif

#if __CMSFNS_HDR__ == 18
/* interpreter/rxvml.h */
#   define rxvml_create                                vlcreate
#   define rxvml_destroy                               _FN0165
#   define rxvml_load_module_file                      _FN0166
#   define rxvml_load_module_buffer                    _FN0167
#   define rxvml_value_new                             _FN0168
#   define rxvml_set_int                               _FN0169
#   define rxvml_set_str                               _FN0170
#   define rxvml_set_native_payload                    _FN0171
#   define rxvml_get_native_payload                    _FN0172
#   define rxvml_value_free                            _FN0173
#   define rxvml_object_new                            _FN0174
#   define rxvml_set_attribute                         _FN0175
#   define rxvml_get_attribute                         _FN0176
#   define rxvml_array_new                             _FN0177
#   define rxvml_array_set                             _FN0178
#   define rxvml_to_int                                vlto_int
#   define rxvml_to_str                                vlto_str
#   define rxvml_num_attributes                        _FN0179
#   define rxvml_call_procedure                        _FN0180
#   define rxvml_run                                   vlrun
#   define rxvml_call_factory                          _FN0181
#   define rxvml_address_register_environment          _FN0182
#   define rxvml_address_register_callback_environment _FN0183
#   define rxvml_address_create_environment            _FN0184
#   define rxvml_address_set_environment               _FN0185
#   define rxvml_address_sandbox_get                   _FN0186
#   define rxvml_address_sandbox_set                   _FN0187
#   define rxvml_address_emit_output                   _FN0188
#   define rxvml_address_emit_error                    _FN0189
#   define rxvml_address_binding_get                   _FN0190
#   define rxvml_address_stem_get                      _FN0191
#   define rxvml_address_stem_set                      _FN0192
#   define rxvml_address_binding_stem_get              _FN0193
#   define rxvml_address_binding_stem_set              _FN0194
#   define rxvml_reg_alloc                             _FN0195
#   define rxvml_reg_free                              _FN0196
#   define rxvml_reg_get                               _FN0197
#   define rxvml_discover_classes                      _FN0198
#   define rxvml_call_method                           _FN0199
#   define rxvml_set_say_exit                          _FN0200
#   define rxvml_last_error                            _FN0201
#   define rxvml_get_debug_mode                        _FN0202
#endif

#if __CMSFNS_HDR__ == 19
/* interpreter/rxvmsock.h */
#   define rxvm_socket_new                             sknew
#   define rxvm_socket_close                           skclose
#   define rxvm_socket_connect                         _FN0203
#   define rxvm_socket_connect_tls                     _FN0204
#   define rxvm_socket_bind                            skbind
#   define rxvm_socket_listen                          sklisten
#   define rxvm_socket_accept                          skaccept
#   define rxvm_socket_shutdown                        _FN0205
#   define rxvm_socket_starttls                        _FN0206
#   define rxvm_socket_send_string                     _FN0207
#   define rxvm_socket_send_binary                     _FN0208
#   define rxvm_socket_recv_string                     _FN0209
#   define rxvm_socket_recv_binary                     _FN0210
#   define rxvm_socket_pending                         _FN0211
#   define rxvm_socket_timeout                         _FN0212
#   define rxvm_socket_blocking                        _FN0213
#   define rxvm_socket_nodelay                         _FN0214
#   define rxvm_socket_keepalive                       _FN0215
#   define rxvm_socket_peer                            skpeer
#   define rxvm_socket_local                           sklocal
#   define rxvm_socket_status                          skstatus
#   define rxvm_socket_error                           skerror
#endif

#if __CMSFNS_HDR__ == 20
/* interpreter/rxvmvars.h */
#   define clear_binary_payload                        _FN0216
#   define value_zero                                  _FN0217
#   define value_init                                  _FN0218
#   define power_of_two_size                           _FN0219
#   define set_num_attributes                          _FN0220
#   define buffer_size                                 _FN0221
#   define prep_string_buffer                          _FN0222
#   define extend_string_buffer                        _FN0223
#   define null_terminate_string_buffer                _FN0224
#   define clear_value                                 _FN0225
#   define set_float                                   _FN0226
#   define set_string                                  _FN0227
#   define set_null_string                             _FN0228
#   define set_const_string                            _FN0229
#   define set_value_string                            _FN0230
#   define set_buffer_string                           _FN0231
#   define set_native_payload                          _FN0232
#   define get_native_payload                          _FN0233
#   define copy_value                                  _FN0234
#   define move_value                                  _FN0235
#   define copy_string_value                           _FN0236
#   define string_set_byte_pos                         _FN0237
#   define string_reset_cursor                         _FN0238
#   define string_set_lengths                          _FN0239
#   define string_set_ascii_length                     _FN0240
#   define string_chars_remaining                      _FN0241
#   define string_slice_from_cursor                    _FN0242
#   define string_truncate_chars                       _FN0243
#   define string_cmp                                  str_cmp
#   define string_cmp_value                            str_cmpv
#   define string_cmp_const                            str_cmpc
#   define string_append                               _FN0244
#   define string_append_chars                         _FN0245
#   define string_sappend                              _FN0246
#   define string_concat                               _FN0247
#   define string_sconcat                              _FN0248
#   define string_concat_var_const                     _FN0249
#   define string_sconcat_var_const                    _FN0250
#   define string_concat_const_var                     _FN0251
#   define string_sconcat_const_var                    _FN0252
#   define string_step_forward                         _FN0253
#   define string_step_backward                        _FN0254
#   define string_concat_char                          _FN0255
#   define int_to_string                               _FN0256
#   define float_to_string                             _FN0257
#   define int_from_float                              _FN0258
#   define reg2nullstring                              _FN0259
#   define string2integer                              _FN0260
#   define string2float                                _FN0261
#   define stringtodecimal                             _FN0262
#   define trim_numeric_trailing_zeros                 _FN0263
#   define extract_double_decimal                      _FN0264
#   define number_of_digits                            _FN0265
#   define RexxDecimalFormat                           _FN0266
#   define extract_integer_decimal                     _FN0267
#endif

#if __CMSFNS_HDR__ == 21
/* platform/platform.h */
#   define fileexists                                  filexist
#   define exefqname                                   exefqn
#   define has_any_extension                           hasext
#   define strip_rightmost_extension_if                strpext
#   define platform_term_save                          ptsave
#   define platform_term_restore                       ptrest
#   define platform_install_signal_handlers            pisighnd
#endif

#if __CMSFNS_HDR__ == 22
/* rxpa/rxpa.h */
#   define load_plugin                                 _FN0268
#endif

#if __CMSFNS_HDR__ == 23
/* interpreter/rxpashim.c */
#   define rxvm_addfunc                                _FN0269
#   define rxvm_addclass                               _FN0270
#   define rxvm_addinterface                           _FN0271
#   define rxvm_addimplements                          _FN0272
#   define rxvm_addmember                              _FN0273
#   define rxvm_getstring                              _FN0274
#   define rxvm_setstring                              _FN0275
#   define rxvm_setint                                 _FN0276
#   define rxvm_getint                                 _FN0277
#   define rxvm_setfloat                               _FN0278
#   define rxvm_getfloat                               _FN0279
#   define rxvm_setnativepayload                       _FN0280
#   define rxvm_getnativepayload                       _FN0281
#   define rxvm_getnumattrs                            _FN0282
#   define rxvm_setnumattrs                            _FN0283
#   define rxvm_getattr                                _FN0284
#   define rxvm_insertattr                             _FN0285
#   define rxvm_removeattr                             _FN0286
#   define rxvm_swapattrs                              _FN0287
#   define rxvm_setsayexit                             risetsay
#   define rxvm_resetsayexit                           rirstsay
#   define rxpa_addfunc                                _FN0288
#   define rxpa_addclass                               _FN0289
#   define rxpa_addinterface                           _FN0290
#   define rxpa_addimplements                          _FN0291
#   define rxpa_addmember                              _FN0292
#   define rxpa_getstring                              _FN0293
#   define rxpa_setstring                              _FN0294
#   define rxpa_setint                                 _FN0295
#   define rxpa_getint                                 _FN0296
#   define rxpa_setfloat                               _FN0297
#   define rxpa_getfloat                               _FN0298
#   define rxpa_setnativepayload                       _FN0299
#   define rxpa_getnativepayload                       _FN0300
#   define rxpa_getnumattrs                            _FN0301
#   define rxpa_setnumattrs                            _FN0302
#   define rxpa_getattr                                _FN0303
#   define rxpa_insertattr                             _FN0304
#   define rxpa_removeattr                             _FN0305
#   define rxpa_swapattrs                              _FN0306
#   define rxpa_setsayexit                             _FN0307
#   define rxpa_resetsayexit                           _FN0308
#endif

#if __CMSFNS_HDR__ == 24
/* interpreter/rxvmload.c */
#   define rxvm_addfunc                                _FN0309
#   define rxvm_addclass                               _FN0310
#   define rxvm_addinterface                           _FN0311
#   define rxvm_addimplements                          _FN0312
#   define rxvm_addmember                              _FN0313
#   define rxvm_getstring                              _FN0314
#   define rxvm_setstring                              _FN0315
#   define rxvm_setint                                 _FN0316
#   define rxvm_getint                                 _FN0317
#   define rxvm_setfloat                               _FN0318
#   define rxvm_getfloat                               _FN0319
#   define rxvm_setnativepayload                       _FN0320
#   define rxvm_getnativepayload                       _FN0321
#   define rxpa_getnumattrs                            _FN0322
#   define rxpa_setnumattrs                            _FN0323
#   define rxpa_getattr                                _FN0324
#   define rxpa_insertattr                             _FN0325
#   define rxpa_removeattr                             _FN0326
#   define rxpa_swapattrs                              _FN0327
#   define rxpa_setsayexit                             _FN0328
#   define rxpa_resetsayexit                           _FN0329
#endif

#if __CMSFNS_HDR__ == 25
/* interpreter/rxcpfunc.c */
#   define rxpa_getstring                              _FN0330
#   define rxpa_setstring                              _FN0331
#   define rxpa_setint                                 _FN0332
#   define rxpa_getint                                 _FN0333
#   define rxpa_setfloat                               _FN0334
#   define rxpa_getfloat                               _FN0335
#   define rxpa_setnativepayload                       _FN0336
#   define rxpa_getnativepayload                       _FN0337
#   define rxpa_getnumattrs                            _FN0338
#   define rxpa_setnumattrs                            _FN0339
#   define rxpa_getattr                                _FN0340
#   define rxpa_insertattr                             _FN0341
#   define rxpa_removeattr                             _FN0342
#   define rxpa_swapattrs                              _FN0343
#   define rxpa_setsayexit                             _FN0344
#   define rxpa_resetsayexit                           _FN0345
#   define rxpa_addfunc                                _FN0346
#   define rxpa_addclass                               _FN0347
#   define rxpa_addinterface                           _FN0348
#   define rxpa_addimplements                          _FN0349
#   define rxpa_addmember                              _FN0350
#endif

#if __CMSFNS_HDR__ == 26
/* interpreter/rxcpintp.c */
#   define add_runtime_interface_factory_entry         _FN0351
#   define add_runtime_interface_method_entry          _FN0352
#   define ascii_back_blank                            _FN0353
#   define ascii_back_nonblank                         _FN0354
#   define ascii_fwd_blank                             _FN0355
#   define ascii_fwd_nonblank                          _FN0356
#   define build_interface_factory_error               _FN0357
#   define build_runtime_cast_error                    _FN0358
#   define build_runtime_factory_proc_name             _FN0359
#   define build_runtime_match_proc_name               _FN0360
#   define build_runtime_member_name                   _FN0361
#   define clear_frame                                 _FN0362
#   define clear_runtime_interface_factories           _FN0363
#   define clear_runtime_interface_methods             _FN0364
#   define compare_runtime_name                        _FN0365
#   define decimal_literal_value                       _FN0366
#   define dup_runtime_name                            _FN0367
#   define frame_f                                     frame_f
#   define free_decimal_literal_value                  _FN0368
#   define free_frame                                  _FN0369
#   define get_runtime_string_constant                 _FN0370
#   define interrupts                                  _FN0371
#   define interrupt_to_string                         _FN0372
#   define invoke_runtime_factory_match                _FN0373
#   define ipow                                        ipow
#   define parse_runtime_factory_selector              _FN0374
#   define print_runtime_panic_location                _FN0375
#   define resolve_runtime_factory                     _FN0376
#   define resolve_runtime_method                      _FN0377
#   define resolve_runtime_procedure                   _FN0378
#   define resolve_runtime_source_context              _FN0379
#   define run                                         run
#   define runtime_class_implements_interface          _FN0380
#   define runtime_internal_type_to_source_name        _FN0381
#   define runtime_lookup_contract_kind                _FN0382
#   define runtime_member_kind_is_final                _FN0383
#   define runtime_member_kind_is_method               _FN0384
#   define runtime_normalize_type_name                 _FN0385
#   define runtime_type_name_is_builtin                _FN0386
#   define runtime_value_matches_object_type           _FN0387
#   define rxsignal_apply_native_interrupt_mode        _FN0388
#   define rxsignal_clear_handler_stack                _FN0389
#   define rxsignal_handler_payload                    _FN0390
#   define rxsignal_pop_handler                        _FN0391
#   define rxsignal_populate_raw_interrupt             _FN0392
#   define rxsignal_populate_runtime_signal            _FN0393
#   define rxsignal_push_handler                       _FN0394
#   define rxsignal_unwind_to_frame                    _FN0395
#   define string_to_interrupt                         _FN0396
#endif

#if __CMSFNS_HDR__ == 27
/* interpreter/rxpafunc.c */
#   define rxvm_callfunc                               _FN0397
#   define rxvm_getsignaltext                          _FN0398
#   define rxvm_getsignalcode                          _FN0399
#   define rxvm_getstring                              _FN0400
#   define rxvm_setstring                              _FN0401
#   define rxvm_setint                                 _FN0402
#   define rxvm_getint                                 _FN0403
#   define rxvm_setfloat                               _FN0404
#   define rxvm_getfloat                               _FN0405
#   define rxvm_setnativepayload                       _FN0406
#   define rxvm_getnativepayload                       _FN0407
#   define rxvm_getnumattrs                            _FN0408
#   define rxvm_setnumattrs                            _FN0409
#   define rxvm_getattr                                _FN0410
#   define rxvm_insertattr                             _FN0411
#   define rxvm_removeattr                             _FN0412
#   define rxvm_swapattrs                              _FN0413
#endif

#if __CMSFNS_HDR__ == 28
/* interpreter/rxvmplugin/rxvmplugin_framework.h */
#   define load_rxvmplugin                             _FN0414
#   define clear_rxvmplugin_factories                  _FN0415
#   define find_rxvmplugin                             _FN0416
#   define get_rxvmplugin                              _FN0417
#   define get_next_rxvmplugin                         _FN0418
#   define number_to_simple_format                     _FN0419
#endif

#if __CMSFNS_HDR__ == 29
/* binutils/include/rxbin.h */
#   define rxbin_file_reader_states                   _FN0420
#   define rxbin_mem_reader_states                    _FN0421
#   define init_module                                _FN0422
#   define check_header_version                       _FN0423
#   define rxbin_get_operand_types                    _FN0424
#   define rxbin_opcode_format                        _FN0425
#   define rxbin_byte_buffer_init                     _FN0426
#   define rxbin_byte_buffer_free                     _FN0427
#   define rxbin_byte_buffer_reserve                  _FN0428
#   define rxbin_byte_buffer_append_byte              _FN0429
#   define rxbin_byte_buffer_append_bytes             _FN0430
#   define rxbin_append_varuint_direct                _FN0431
#   define rxbin_var_writer_init                      _FN0432
#   define rxbin_var_writer_write                     _FN0433
#   define rxbin_var_writer_flush                     _FN0434
#   define rxbin_var_reader_init                      _FN0435
#   define rxbin_var_reader_read                      _FN0436
#   define rxbin_zigzag_encode                        _FN0437
#   define rxbin_zigzag_decode                        _FN0438
#   define rxbin_token_from_operand                   _FN0439
#   define rxbin_operand_from_token                   _FN0440
#   define rxbin_encode_instruction_stream            _FN0441
#   define rxbin_decode_instruction_stream            _FN0442
#   define rxbin_lzss_hash                            _FN9442
#   define rxbin_lzss_match_length                    _FN0443
#   define rxbin_lzss_index_position                  _FN0444
#   define rxbin_compress_constant_pool               _FN0445
#   define rxbin_decompress_constant_pool             _FN0446
#   define rxbin_duplicate_block                      _FN0447
#   define rxbin_read_file_block                      _FN0448
#   define rxbin_shared_pool_retain                   _FN0449
#   define rxbin_shared_pool_release                  _FN0450
#   define rxbin_decode_instruction_section           _FN0451
#   define rxbin_decode_constant_section              _FN0452
#   define rxbin_decode_shared_constant_pool          _FN0453
#   define rxbin_prepare_header_for_write             _FN0454
#   define write_module                               _FN0455
#   define rxbin_reader_init_file                     _FN0456
#   define rxbin_reader_init_mem                      _FN0457
#   define rxbin_reader_close                         _FN0458
#   define rxbin_reader_read_header                   _FN0459
#   define rxbin_reader_take_block                    _FN0460
#   define rxbin_reader_view_block                    _FN0461
#   define rxbin_reader_next_module                   _FN0462
#   define rxbin_close_file_reader                    _FN0463
#   define rxbin_close_mem_reader                     _FN0464
#   define read_module                                _FN0465
#   define read_module_mem                            _FN0466
#   define free_module                                _FN0467
#endif

#endif  // __CMS__
