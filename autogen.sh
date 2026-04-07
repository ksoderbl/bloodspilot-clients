#!/bin/sh

set -e

srcdir=$(dirname "$0")
test -z "$srcdir" && srcdir=.

echo "autogen.sh: source directory: $srcdir"

cd "$srcdir"

echo "autogen.sh: running autoreconf -fi"
autoreconf -fi

echo "autogen.sh: running $srcdir/configure $*"
"$srcdir"/configure "$@"

echo "autogen.sh: done"
