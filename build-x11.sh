#!/bin/sh
BINARY=src/client/x11/bloodspilot-client-x11
if test -e "$BINARY"; then
    mv "$BINARY" "$BINARY".old
fi
bash configure  --disable-sdl-client --disable-454-client --disable-replay --disable-ng-x11-client $@
make
echo ""
if test -e "$BINARY"; then
    echo "Built $BINARY successfully."
else
    echo "Failed to build $BINARY !!!"
fi
echo ""
