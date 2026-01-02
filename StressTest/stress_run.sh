#!/bin/bash
# Run stress test in kitty

cd "$(dirname "$0")"

KITTY_TITLE="StressTest"
SOCKET="unix:/tmp/kitty"

if ! kitty @ --to $SOCKET ls | grep -q "$KITTY_TITLE"; then
    kitty --title "$KITTY_TITLE" \
          --listen-on $SOCKET \
          bash -c "cd bag && ./stress.sh; exec bash" &
else
    kitty @ --to $SOCKET send-text \
          --match title:"$KITTY_TITLE" \
          "cd bag && ./stress.sh\n"
fi
