#!/usr/bin/bash
# Split a Lemon parser for building in CMS.

# Exit if there is an error
set -euo pipefail

# Show the commands
set -x

INFILE=$1

sed \
	-e "s/MAYBE_STATIC const YYCODETYPE yy_lookahead/#endif\n\n#if __SPLIT_RXCPBGMR__ == 0 || __SPLIT_RXCPBGMR__ == 4\nMAYBE_STATIC const YYCODETYPE yy_lookahead/" \
	-e "s/MAYBE_STATIC const unsigned short int yy_shift_ofst/#endif\n\n#if __SPLIT_RXCPBGMR__ == 0 || __SPLIT_RXCPBGMR__ == 5\nMAYBE_STATIC const unsigned short int yy_shift_ofst/" \
	-e "s/MAYBE_STATIC const YYACTIONTYPE yy_default/#endif\n\n#if __SPLIT_RXCPBGMR__ == 0 || __SPLIT_RXCPBGMR__ == 6\nMAYBE_STATIC const YYACTIONTYPE yy_default/" \
	--in-place \
	$INFILE