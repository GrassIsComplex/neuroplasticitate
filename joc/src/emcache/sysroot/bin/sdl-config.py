#!/nix/store/h097imm3w6dpx10qynrd2sz9fks2wbq8-python3-3.12.11/bin/python3

import sys

print('emscripten sdl-config called with', ' '.join(sys.argv), file=sys.stderr)

args = sys.argv[1:]

if args[0] == '--cflags':
  print('')
elif '--version' in args:
  print('1.3.0')

