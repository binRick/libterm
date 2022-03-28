#!/bin/bash
set -eou pipefail
CMD="${@:-make all test}"
cmd="reap reap nodemon -i bin -w . --signal SIGKILL -e sh,c,h -V -x sh -- -c \"$CMD||true\""

ansi --yellow --bg-black --italic "$cmd"
eval "$cmd"
