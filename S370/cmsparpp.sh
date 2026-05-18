#!/usr/bin/bash
# Post-process a Lemon parser for building in CMS.

# Exit if there is an error
set -euo pipefail

# Show the commands
set -x

INFILE=$1

sed \
	-e "s@^\(#define YY_ACTTAB_COUNT .*\)\$@#endif\n\n\1\n#if __SPLIT_PARSER__ == 0 || __SPLIT_PARSER__ == 3@" \
	-e "s@static \(const YYCODETYPE yy_lookahead\)@\nconst int YY_NACTION = (int) (sizeof(yy_action)/sizeof(yy_action[0]));\n#endif\n\n#if __SPLIT_PARSER__ == 0 || __SPLIT_PARSER__ == 4\nMAYBE_STATIC\1@" \
	-e "s@static \(const unsigned short int yy_shift_ofst\)@\n#if __SPLIT_PARSER__ == 0 || __SPLIT_PARSER__ == 5\nMAYBE_STATIC \1@" \
	-e "s@static \(const YYACTIONTYPE yy_default\)@#endif\n\n#if __SPLIT_PARSER__ == 0 || __SPLIT_PARSER__ == 6\nMAYBE_STATIC \1@" \
	-e "s@static \(const YYACTIONTYPE yy_action\)@MAYBE_STATIC \1@" \
	-e "s@static \(const int yy_reduce_ofst\)@MAYBE_STATIC \1@" \
	-e "s@^\(#define YY_SHIFT_COUNT .*\)\$@\nconst int YY_NLOOKAHEAD = (int) (sizeof(yy_lookahead)/sizeof(yy_lookahead[0]));\n#endif\n\n\1@" \
	-e "s@^\(#define YY_REDUCE_COUNT .*\)\$@#endif\n\n\1\n\n#if __SPLIT_PARSER__ == 0 || __SPLIT_PARSER__ == 5\n@" \
	-e "s@assert( j<(int)(sizeof(yy_lookahead)/sizeof(yy_lookahead\[0])) );@assert( j<YY_NLOOKAHEAD );@" \
	-e "s@assert( i>=0 && i<(int)(sizeof(yy_action)/sizeof(yy_action\[0])) );@assert( i>=0 && i<YY_NACTION );@" \
	-e "s@assert( yyruleno<(int)(sizeof(yyRuleName)/sizeof(yyRuleName\[0])) );@assert( yyruleno<YY_NRULENAME );@" \
	-e "s@assert( yyruleno<sizeof(yyRuleInfoLhs)/sizeof(yyRuleInfoLhs\[0]) );@assert( yyruleno<YY_NRULEINFOLHS );@" \
	--in-place \
	$INFILE
