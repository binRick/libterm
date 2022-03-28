#!/bin/sh
set -eou pipefail
make test1 || { passh make test1 | bat; }

./bin/test1
