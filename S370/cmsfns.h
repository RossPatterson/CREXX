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
#   define mark_const_args                             mark_const_args
#   define meta_narg                                   metanarg
#   define static_linked_functions                     statln_f
#   define static_linked_metadata                      statln_m
#   define free_static_linked_functions                frestlfs
#endif

#if __CMSFNS_HDR__ == 7
/* compiler/rxcp_emit.h */
#   define emit_promotion                              emit_promotion
#   define output_fs                                   outputfs
#   define output_insert_before                        output_insert_before
#   define output_insert_after                         output_insert_after
#   define output_concat                               output_concat
#   define output_append_text                          output_append_text
#   define output_prepend_text                         output_prepend_text
#   define print_output                                print_output
#   define get_metaline                                get_metaline
#   define get_reporting_metalines                     get_reporting_metalines
#   define reset_metaline_source_file                  reset_metaline_source_file
#   define get_metaline_range                          get_metaline_range
#   define get_metaline_between                        get_metaline_between
#   define get_metaline_token_after                    get_metaline_token_after
#   define get_metaline_clause                         get_metaline_clause
#   define get_metaline_token_at                       get_metaline_token_at
#   define get_comment                                 get_comment
#   define get_comment_line_number_only                get_comment_line_number_only
#   define type_promotion                              type_promotion
#   define add_variable_metadata                       add_variable_metadata
#   define clear_variable_metadata                     clear_variable_metadata
#   define clear_global_variable_metadata              clear_global_variable_metadata
#   define meta_set_symbol                             meta_set_symbol
#   define add_initiator                               add_initiator
#   define add_scope_initiators                        add_scope_initiators
#   define add_global_symbol                           add_global_symbol
#   define add_exposed_global_variable                 add_exposed_global_variable
#   define meta_set_global_symbol                      meta_set_global_symbol
#   define add_global_variable_metadata                add_global_variable_metadata
#   define add_all_class_metadata                      add_all_class_metadata
#   define meta_clear_symbol                           meta_clear_symbol
#   define meta_clear_global_symbol                    meta_clear_global_symbol
#   define callable_effective_return_type              callable_effective_return_type
#   define emit_proc                                   emit_proc
#   define emit_expression                             emit_expression
#   define emit_flow                                   emit_flow
#   define is_constant                                 is_constant
#   define format_constant                             format_constant
#   define type_to_prefix                              type_to_prefix
#   define register_walker                             register_walker
#   define rxcp_exit_bridge_plan_invoke                rxcp_exit_bridge_plan_invoke
#   define rxcp_exit_rewrite_diagnostics               rxcp_exit_rewrite_diagnostics
#endif

#if __CMSFNS_HDR__ == 8
/* compiler/rxcp_exit.h */
#   define rxcp_init_exits                             rxcp_init_exits
#   define rxcp_free_exits                             rxcp_free_exits
#   define rxcp_match_certified_exit_primary           rxcp_match_certified_exit_primary
#   define rxcp_is_exit_primary                        rxcp_is_exit_primary
#   define rxcp_is_exit_additional                     rxcp_is_exit_additional
#   define rxcp_get_exit_flags                         rxcp_get_exit_flags
#   define rxcp_exit_bridge_invoke                     cexitbri
#endif

#if __CMSFNS_HDR__ == 9
/* compiler/rxcp_highlight_controller.h */
#   define rxc_highlight_controller_parse              rxc_highlight_controller_parse
#   define rxcp_highlight_controller_reset_cache       rxcp_highlight_controller_reset_cache
#   define rxcp_highlight_controller_get_cache_stats   rxcp_highlight_controller_get_cache_stats
#endif

#if __CMSFNS_HDR__ == 10
/* compiler/rxcp_source_tree.h */
#   define source_tree_build                           source_tree_build
#   define source_tree_clear_diagnostics               source_tree_clear_diagnostics
#   define source_tree_record_diagnostic               source_tree_record_diagnostic
#   define source_tree_sync_diagnostics                source_tree_sync_diagnostics
#   define source_tree_clear_semantics                 source_tree_clear_semantics
#   define source_tree_sync_semantics                  source_tree_sync_semantics
#   define source_tree_free                            source_tree_free
#endif

#if __CMSFNS_HDR__ == 11
/* compiler/rxcp_sym.h */
#   define get_reg_perm                                get_reg_perm
#   define ret_reg_later                               ret_reg_later
#   define ret_reg_all_deferred                        ret_reg_all_deferred
#   define get_regs                                    get_regs
#   define ret_regs                                    ret_regs
#   define sym_rslv_local                              sym_rslv_local
#   define sym_rslv_attribute                          sym_rslv_attribute
#   define sym_rslv_global                             sym_rslv_global
#   define sym_rslv_tiered                             sym_rslv_tiered
#   define sym_rvfc                                    sym_rvfc
#   define sym_hoist_to_namespace                      sym_hoist_to_namespace
#   define sym_mngd_frnm                               sym_mngd_frnm
#endif

#if __CMSFNS_HDR__ == 12
/* compiler/rxcp_util.h */
#   define error_and_exit                              error_and_exit
#   define rx_strndup                                  rx_strndup
#   define rxcp_normalize_source_symbol_name           rxcp_normalize_source_symbol_name
#   define rxcp_source_symbol_is_qualified             rxcp_source_symbol_is_qualified
#   define rxcp_split_internal_symbol_name             rxcp_split_internal_symbol_name
#   define rxcp_internal_name_to_source_qualified      rxcp_internal_name_to_source_qualified
#   define encode_comment_malloc                       encode_comment_malloc
#   define encode_line_source_malloc                   encode_line_source_malloc
#   define hexchar2int                                 hexchar2int
#   define binchar2int                                 binchar2int
#   define escape_character                            escape_character
#   define token_to_string                             token_to_string
#   define node_type_to_string                         node_type_to_string
#endif

#if __CMSFNS_HDR__ == 13
/* compiler/rxcp_val.h */
#   define is_node_string                              is_node_string
#   define node_to_integer                             node_to_integer
#   define node_to_dims                                node_to_dims
#   define promote_symbol_from_target                  promote_symbol_from_target
#   define validate_node_promotion                     validate_node_promotion
#   define validate_node_promotion_for_ref             validate_node_promotion_for_ref
#   define sym_promote_type                            sym_promote_type
#   define sym_promote_status                          sym_promote_status
#   define sym_promote_symtype                         sym_promote_symtype
#   define ast_promote_type                            ast_promote_type
#   define ast_promote_target_type                     ast_promote_target_type
#   define ast_set_value_type                          ast_set_value_type
#   define ast_set_target_type                         ast_set_target_type
/* #   define validate_ast                                validate_ast */
#   define rxcp_prepare_work_ast                       rxcp_prepare_work_ast
#   define rxcp_parse_buffer                           rxcp_parse_buffer
#   define structure_symbols_walker                    structure_symbols_walker
#   define build_symbols_walker                        build_symbols_walker
#   define resolve_functions_walker                    resolve_functions_walker
#   define exposed_symbols_walker                      exposed_symbols_walker
#   define validate_symbols                            validate_symbols
#   define ast_hoist_var                               ast_hoist_var
#   define ast_hoist_var_typed                         ast_hoist_var_typed
#   define clear_node_types_walker                     clear_node_types_walker
#   define set_node_types_walker                       set_node_types_walker
#   define type_safety_walker                          type_safety_walker
#   define func_type_safety_walker                     func_type_safety_walker
#   define float2decimal_walker                        flt2decw
#   define decimal2float_walker                        dec2fltw
#   define rewrite_constructor_walker                  rewrite_constructor_walker
#   define rewrite_exit_walker                         rewrite_exit_walker
#   define rewrite_implicit_cmd_walker                 rewrite_implicit_cmd_walker
#   define syntax_sugar_walker                         syntax_sugar_walker
#   define control_flow_rewrite_walker                 control_flow_rewrite_walker
#   define tostring_rewrite_walker                     tostring_rewrite_walker
#   define needs_rxsysb_walker                         needs_rxsysb_walker
#   define add_rxsysb_walker                           add_rxsysb_walker
#   define rxcp_fixup_walker                           cfixupw
#   define ast_source_structure_walker                 ast_source_structure_walker
#   define ast_work_structure_walker                   ast_work_structure_walker
#   define ast_structure_fixup_walker                  astfixw
#   define source_location_walker                      srclocw
#   define syntax_validation_walker                    synvalw
#   define decimal_parameters_walker                   decprmsw
#   define exit_dispatch_walker                        exit_dispatch_walker
#   define exit_plan_walker                            exit_plan_walker
#   define identify_inlinable_walker                   identify_inlinable_walker
#   define inline_procedure_walker                     inline_procedure_walker
#   define rxcp_inline_pass                            rxcp_inline_pass
#   define rxcp_inline_prune                           rxcp_inline_prune
#   define rxcp_inline_export_payload                  rxcp_inline_export_payload
#   define rxcp_inline_payload_is_supported            rxcp_inline_payload_is_supported
#   define rxcp_inline_attach_imported_body            rxcp_inline_attach_imported_body
#   define rxcp_inline_attach_imported_symbol          rxcp_inline_attach_imported_symbol
#   define set_node_ordinals_walker                    set_node_ordinals_walker
#endif

#if __CMSFNS_HDR__ == 14
/* disassembler/rxdadism.h */
#   define disassemble                                 disassemble
#endif

#if __CMSFNS_HDR__ == 15
/* inc/rxvm.h */
#   define rxvm_create                                 vmcreate
#   define rxvm_destroy                                rxvm_destroy
#   define rxvm_load                                   vmload
#   define rxvm_load_file                              rxvm_load_file
#   define rxvm_link                                   vmlink
#   define rxvm_prepare                                rxvm_prepare
#   define rxvm_call                                   vmcall
#endif

#if __CMSFNS_HDR__ == 16
/* interpreter/crexxsaa.h */
#   define crexxsaa_create                             crexxsaa_create
#   define crexxsaa_destroy                            crexxsaa_destroy
#   define crexxsaa_register_address_environment       crexxsaa_register_address_environment
#   define crexxsaa_set_address_environment            crexxsaa_set_address_environment
#   define crexxsaa_set_compiler                       crexxsaa_set_compiler
#   define crexxsaa_set_cache_dir                      crexxsaa_set_cache_dir
#   define crexxsaa_address_variable_set               crexxsaa_address_variable_set
#   define crexxsaa_address_variable_get_alloc         crexxsaa_address_variable_get_alloc
#   define crexxsaa_free                               csafree
#   define crexxsaa_run_rxbin                          crexxsaa_run_rxbin
#   define crexxsaa_run_source                         crexxsaa_run_source
#   define crexxsaa_invalidate_source                  crexxsaa_invalidate_source
#   define crexxsaa_invalidate_all                     crexxsaa_invalidate_all
#   define crexxsaa_get_cache_dir                      crexxsaa_get_cache_dir
#   define crexxsaa_clear_cache                        crexxsaa_clear_cache
#   define crexxsaa_last_error                         crexxsaa_last_error
#endif

#if __CMSFNS_HDR__ == 17
/* interpreter/rxvmintp.h */
#   define rxvm_getsignaltext                          rxvm_getsignaltext
#   define rxvm_getsignalcode                          rxvm_getsignalcode
#   define completely_free_frame                       completely_free_frame
#   define rxvm_link_module                            rxvm_link_module
#   define rxvm_rebuild_interface_factory_registry     rxvm_rebuild_interface_factory_registry
#   define rxvm_rebuild_interface_method_registry      rxvm_rebuild_interface_method_registry
#   define rxvm_callfunc                               rxvm_callfunc
#   define getEnvVal                                   getEnvVal
#   define shellspawn                                  shellspawn
#   define redrwriteclose                              redrwriteclose
#   define rxvm_setsayexit                             risetsay
#   define rxvm_resetsayexit                           rirstsay
#   define rxvm_mprintf                                rxvm_mprintf
#   define enable_interrupt                            enable_interrupt
#   define ignore_interrupt                            ignore_interrupt
#   define restore_interrupt                           restore_interrupt
#   define initialize_vm_signals                       initialize_vm_signals
#   define cleanup_vm_signals                          cleanup_vm_signals
#   define raise_signal                                raise_signal
#   define clear_signal                                clear_signal
#endif

#if __CMSFNS_HDR__ == 18
/* interpreter/rxvml.h */
#   define rxvml_create                                vlcreate
#   define rxvml_destroy                               rxvml_destroy
#   define rxvml_load_module_file                      rxvml_load_module_file
#   define rxvml_load_module_buffer                    rxvml_load_module_buffer
#   define rxvml_value_new                             rxvml_value_new
#   define rxvml_set_int                               rxvml_set_int
#   define rxvml_set_str                               rxvml_set_str
#   define rxvml_set_native_payload                    rxvml_set_native_payload
#   define rxvml_get_native_payload                    rxvml_get_native_payload
#   define rxvml_value_free                            rxvml_value_free
#   define rxvml_object_new                            rxvml_object_new
#   define rxvml_set_attribute                         rxvml_set_attribute
#   define rxvml_get_attribute                         rxvml_get_attribute
#   define rxvml_array_new                             rxvml_array_new
#   define rxvml_array_set                             rxvml_array_set
#   define rxvml_to_int                                vlto_int
#   define rxvml_to_str                                vlto_str
#   define rxvml_num_attributes                        rxvml_num_attributes
#   define rxvml_call_procedure                        rxvml_call_procedure
#   define rxvml_run                                   vlrun
#   define rxvml_call_factory                          rxvml_call_factory
#   define rxvml_address_register_environment          rxvml_address_register_environment
#   define rxvml_address_register_callback_environment rxvml_address_register_callback_environment
#   define rxvml_address_create_environment            rxvml_address_create_environment
#   define rxvml_address_set_environment               rxvml_address_set_environment
#   define rxvml_address_sandbox_get                   rxvml_address_sandbox_get
#   define rxvml_address_sandbox_set                   rxvml_address_sandbox_set
#   define rxvml_address_emit_output                   rxvml_address_emit_output
#   define rxvml_address_emit_error                    rxvml_address_emit_error
#   define rxvml_address_binding_get                   rxvml_address_binding_get
#   define rxvml_address_stem_get                      rxvml_address_stem_get
#   define rxvml_address_stem_set                      rxvml_address_stem_set
#   define rxvml_address_binding_stem_get              rxvml_address_binding_stem_get
#   define rxvml_address_binding_stem_set              rxvml_address_binding_stem_set
#   define rxvml_reg_alloc                             rxvml_reg_alloc
#   define rxvml_reg_free                              rxvml_reg_free
#   define rxvml_reg_get                               rxvml_reg_get
#   define rxvml_discover_classes                      rxvml_discover_classes
#   define rxvml_call_method                           rxvml_call_method
#   define rxvml_set_say_exit                          rxvml_set_say_exit
#   define rxvml_last_error                            rxvml_last_error
#   define rxvml_get_debug_mode                        rxvml_get_debug_mode
#endif

#if __CMSFNS_HDR__ == 19
/* interpreter/rxvmsock.h */
#   define rxvm_socket_new                             sknew
#   define rxvm_socket_close                           skclose
#   define rxvm_socket_connect                         rxvm_socket_connect
#   define rxvm_socket_connect_tls                     rxvm_socket_connect_tls
#   define rxvm_socket_bind                            skbind
#   define rxvm_socket_listen                          sklisten
#   define rxvm_socket_accept                          skaccept
#   define rxvm_socket_shutdown                        rxvm_socket_shutdown
#   define rxvm_socket_starttls                        rxvm_socket_starttls
#   define rxvm_socket_send_string                     rxvm_socket_send_string
#   define rxvm_socket_send_binary                     rxvm_socket_send_binary
#   define rxvm_socket_recv_string                     rxvm_socket_recv_string
#   define rxvm_socket_recv_binary                     rxvm_socket_recv_binary
#   define rxvm_socket_pending                         rxvm_socket_pending
#   define rxvm_socket_timeout                         rxvm_socket_timeout
#   define rxvm_socket_blocking                        rxvm_socket_blocking
#   define rxvm_socket_nodelay                         rxvm_socket_nodelay
#   define rxvm_socket_keepalive                       rxvm_socket_keepalive
#   define rxvm_socket_peer                            skpeer
#   define rxvm_socket_local                           sklocal
#   define rxvm_socket_status                          skstatus
#   define rxvm_socket_error                           skerror
#endif

#if __CMSFNS_HDR__ == 20
/* interpreter/rxvmvars.h */
#   define clear_binary_payload                        clear_binary_payload
#   define value_zero                                  value_zero
#   define value_init                                  value_init
#   define power_of_two_size                           power_of_two_size
#   define set_num_attributes                          set_num_attributes
#   define buffer_size                                 buffer_size
#   define prep_string_buffer                          prep_string_buffer
#   define extend_string_buffer                        extend_string_buffer
#   define null_terminate_string_buffer                null_terminate_string_buffer
#   define clear_value                                 clear_value
#   define set_float                                   set_float
#   define set_string                                  set_string
#   define set_null_string                             set_null_string
#   define set_const_string                            set_const_string
#   define set_value_string                            set_value_string
#   define set_buffer_string                           set_buffer_string
#   define set_native_payload                          set_native_payload
#   define get_native_payload                          get_native_payload
#   define copy_value                                  copy_value
#   define move_value                                  move_value
#   define copy_string_value                           copy_string_value
#   define string_set_byte_pos                         string_set_byte_pos
#   define string_reset_cursor                         string_reset_cursor
#   define string_set_lengths                          string_set_lengths
#   define string_set_ascii_length                     string_set_ascii_length
#   define string_chars_remaining                      string_chars_remaining
#   define string_slice_from_cursor                    string_slice_from_cursor
#   define string_truncate_chars                       string_truncate_chars
#   define string_cmp                                  str_cmp
#   define string_cmp_value                            str_cmpv
#   define string_cmp_const                            str_cmpc
#   define string_append                               string_append
#   define string_append_chars                         string_append_chars
#   define string_sappend                              string_sappend
#   define string_concat                               string_concat
#   define string_sconcat                              string_sconcat
#   define string_concat_var_const                     string_concat_var_const
#   define string_sconcat_var_const                    string_sconcat_var_const
#   define string_concat_const_var                     string_concat_const_var
#   define string_sconcat_const_var                    string_sconcat_const_var
#   define string_step_forward                         string_step_forward
#   define string_step_backward                        string_step_backward
#   define string_concat_char                          string_concat_char
#   define int_to_string                               int_to_string
#   define float_to_string                             float_to_string
#   define int_from_float                              int_from_float
#   define reg2nullstring                              reg2nullstring
#   define string2integer                              string2integer
#   define string2float                                string2float
#   define stringtodecimal                             stringtodecimal
#   define trim_numeric_trailing_zeros                 trim_numeric_trailing_zeros
#   define extract_double_decimal                      extract_double_decimal
#   define number_of_digits                            number_of_digits
#   define RexxDecimalFormat                           RexxDecimalFormat
#   define extract_integer_decimal                     extract_integer_decimal
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
#   define load_plugin                                 load_plugin
#endif

#if __CMSFNS_HDR__ == 23
/* interpreter/rxpashim.c */
#   define rxvm_addfunc                                rxvm_addfunc
#   define rxvm_addclass                               rxvm_addclass
#   define rxvm_addinterface                           rxvm_addinterface
#   define rxvm_addimplements                          rxvm_addimplements
#   define rxvm_addmember                              rxvm_addmember
#   define rxvm_getstring                              rxvm_getstring
#   define rxvm_setstring                              rxvm_setstring
#   define rxvm_setint                                 rxvm_setint
#   define rxvm_getint                                 rxvm_getint
#   define rxvm_setfloat                               rxvm_setfloat
#   define rxvm_getfloat                               rxvm_getfloat
#   define rxvm_setnativepayload                       rxvm_setnativepayload
#   define rxvm_getnativepayload                       rxvm_getnativepayload
#   define rxvm_getnumattrs                            rxvm_getnumattrs
#   define rxvm_setnumattrs                            rxvm_setnumattrs
#   define rxvm_getattr                                rxvm_getattr
#   define rxvm_insertattr                             rxvm_insertattr
#   define rxvm_removeattr                             rxvm_removeattr
#   define rxvm_swapattrs                              rxvm_swapattrs
#   define rxvm_setsayexit                             risetsay
#   define rxvm_resetsayexit                           rirstsay
#   define rxpa_addfunc                                rxpa_addfunc
#   define rxpa_addclass                               rxpa_addclass
#   define rxpa_addinterface                           rxpa_addinterface
#   define rxpa_addimplements                          rxpa_addimplements
#   define rxpa_addmember                              rxpa_addmember
#   define rxpa_getstring                              rxpa_getstring
#   define rxpa_setstring                              rxpa_setstring
#   define rxpa_setint                                 rxpa_setint
#   define rxpa_getint                                 rxpa_getint
#   define rxpa_setfloat                               rxpa_setfloat
#   define rxpa_getfloat                               rxpa_getfloat
#   define rxpa_setnativepayload                       rxpa_setnativepayload
#   define rxpa_getnativepayload                       rxpa_getnativepayload
#   define rxpa_getnumattrs                            rxpa_getnumattrs
#   define rxpa_setnumattrs                            rxpa_setnumattrs
#   define rxpa_getattr                                rxpa_getattr
#   define rxpa_insertattr                             rxpa_insertattr
#   define rxpa_removeattr                             rxpa_removeattr
#   define rxpa_swapattrs                              rxpa_swapattrs
#   define rxpa_setsayexit                             rxpa_setsayexit
#   define rxpa_resetsayexit                           rxpa_resetsayexit
#endif

#if __CMSFNS_HDR__ == 24
/* interpreter/rxvmload.c */
#   define rxvm_addfunc                                rxvm_addfunc
#   define rxvm_addclass                               rxvm_addclass
#   define rxvm_addinterface                           rxvm_addinterface
#   define rxvm_addimplements                          rxvm_addimplements
#   define rxvm_addmember                              rxvm_addmember
#   define rxvm_getstring                              rxvm_getstring
#   define rxvm_setstring                              rxvm_setstring
#   define rxvm_setint                                 rxvm_setint
#   define rxvm_getint                                 rxvm_getint
#   define rxvm_setfloat                               rxvm_setfloat
#   define rxvm_getfloat                               rxvm_getfloat
#   define rxvm_setnativepayload                       rxvm_setnativepayload
#   define rxvm_getnativepayload                       rxvm_getnativepayload
#   define rxpa_getnumattrs                            rxpa_getnumattrs
#   define rxpa_setnumattrs                            rxpa_setnumattrs
#   define rxpa_getattr                                rxpa_getattr
#   define rxpa_insertattr                             rxpa_insertattr
#   define rxpa_removeattr                             rxpa_removeattr
#   define rxpa_swapattrs                              rxpa_swapattrs
#   define rxpa_setsayexit                             rxpa_setsayexit
#   define rxpa_resetsayexit                           rxpa_resetsayexit
#endif

#if __CMSFNS_HDR__ == 25
/* interpreter/rxcpfunc.c */
#   define rxpa_getstring                              rxpa_getstring
#   define rxpa_setstring                              rxpa_setstring
#   define rxpa_setint                                 rxpa_setint
#   define rxpa_getint                                 rxpa_getint
#   define rxpa_setfloat                               rxpa_setfloat
#   define rxpa_getfloat                               rxpa_getfloat
#   define rxpa_setnativepayload                       rxpa_setnativepayload
#   define rxpa_getnativepayload                       rxpa_getnativepayload
#   define rxpa_getnumattrs                            rxpa_getnumattrs
#   define rxpa_setnumattrs                            rxpa_setnumattrs
#   define rxpa_getattr                                rxpa_getattr
#   define rxpa_insertattr                             rxpa_insertattr
#   define rxpa_removeattr                             rxpa_removeattr
#   define rxpa_swapattrs                              rxpa_swapattrs
#   define rxpa_setsayexit                             rxpa_setsayexit
#   define rxpa_resetsayexit                           rxpa_resetsayexit
#   define rxpa_addfunc                                rxpa_addfunc
#   define rxpa_addclass                               rxpa_addclass
#   define rxpa_addinterface                           rxpa_addinterface
#   define rxpa_addimplements                          rxpa_addimplements
#   define rxpa_addmember                              rxpa_addmember
#endif

#if __CMSFNS_HDR__ == 26
/* interpreter/rxcpintp.c */
#   define add_runtime_interface_factory_entry         add_runtime_interface_factory_entry
#   define add_runtime_interface_method_entry          add_runtime_interface_method_entry
#   define ascii_back_blank                            ascii_back_blank
#   define ascii_back_nonblank                         ascii_back_nonblank
#   define ascii_fwd_blank                             ascii_fwd_blank
#   define ascii_fwd_nonblank                          ascii_fwd_nonblank
#   define build_interface_factory_error               build_interface_factory_error
#   define build_runtime_cast_error                    build_runtime_cast_error
#   define build_runtime_factory_proc_name             build_runtime_factory_proc_name
#   define build_runtime_match_proc_name               build_runtime_match_proc_name
#   define build_runtime_member_name                   build_runtime_member_name
#   define clear_frame                                 clear_frame
#   define clear_runtime_interface_factories           clear_runtime_interface_factories
#   define clear_runtime_interface_methods             clear_runtime_interface_methods
#   define compare_runtime_name                        compare_runtime_name
#   define decimal_literal_value                       decimal_literal_value
#   define dup_runtime_name                            dup_runtime_name
#   define frame_f                                     frame_f
#   define free_decimal_literal_value                  free_decimal_literal_value
#   define free_frame                                  free_frame
#   define get_runtime_string_constant                 get_runtime_string_constant
#   define interrupts                                  interrupts
#   define interrupt_to_string                         interrupt_to_string
#   define invoke_runtime_factory_match                invoke_runtime_factory_match
#   define ipow                                        ipow
#   define parse_runtime_factory_selector              parse_runtime_factory_selector
#   define print_runtime_panic_location                print_runtime_panic_location
#   define resolve_runtime_factory                     resolve_runtime_factory
#   define resolve_runtime_method                      resolve_runtime_method
#   define resolve_runtime_procedure                   resolve_runtime_procedure
#   define resolve_runtime_source_context              resolve_runtime_source_context
#   define run                                         run
#   define runtime_class_implements_interface          runtime_class_implements_interface
#   define runtime_internal_type_to_source_name        runtime_internal_type_to_source_name
#   define runtime_lookup_contract_kind                runtime_lookup_contract_kind
#   define runtime_member_kind_is_final                runtime_member_kind_is_final
#   define runtime_member_kind_is_method               runtime_member_kind_is_method
#   define runtime_normalize_type_name                 runtime_normalize_type_name
#   define runtime_type_name_is_builtin                runtime_type_name_is_builtin
#   define runtime_value_matches_object_type           runtime_value_matches_object_type
#   define rxsignal_apply_native_interrupt_mode        rxsignal_apply_native_interrupt_mode
#   define rxsignal_clear_handler_stack                rxsignal_clear_handler_stack
#   define rxsignal_handler_payload                    rxsignal_handler_payload
#   define rxsignal_pop_handler                        rxsignal_pop_handler
#   define rxsignal_populate_raw_interrupt             rxsignal_populate_raw_interrupt
#   define rxsignal_populate_runtime_signal            rxsignal_populate_runtime_signal
#   define rxsignal_push_handler                       rxsignal_push_handler
#   define rxsignal_unwind_to_frame                    rxsignal_unwind_to_frame
#   define string_to_interrupt                         string_to_interrupt
#endif

#endif  // __CMS__
