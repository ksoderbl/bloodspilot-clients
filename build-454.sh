#!/bin/sh
BINARY=src/client/454/bloodspilot-client-454
if test -e "$BINARY"; then
    mv "$BINARY" "$BINARY".old
fi
bash configure  --disable-sdl-client --disable-ng-x11-client --disable-replay --disable-x11-client $@
make
echo ""
if test -e "$BINARY"; then
    echo "Built $BINARY successfully."
else
    echo "Failed to build $BINARY !!!"
fi
echo ""
