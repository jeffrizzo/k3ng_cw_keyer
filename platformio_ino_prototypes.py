# PlatformIO pre-build script: let .ino prototype generation see indented function definitions.
#
# Like the Arduino IDE, PlatformIO turns the .ino files into one .cpp and auto-generates prototypes for
# the functions defined in them.  Its prototype regex only matches definitions that start in column 0,
# but k3ng_keyer.ino indents some definitions that sit inside #ifdef blocks (e.g. sidetone_adj(),
# lcd_center_print_timed_wpm()), so with those features enabled the build fails with
# "'...' was not declared in this scope".  This allows leading whitespace before a definition.
#
# Matches ending in ';' are treated by PlatformIO as existing declarations and never emitted, so
# indented statements inside function bodies (e.g. "return foo(x);") can't produce bogus prototypes.

import re

Import("env")  # noqa: F821  (provided by SCons)

# SCons loads the tool as its own "pioino" module, separate from platformio.builder.tools.pioino, so reach
# the converter class through the function the build actually calls.
InoToCPPConverter = env.ConvertInoToCpp.method.__globals__["InoToCPPConverter"]  # noqa: F821

pattern = InoToCPPConverter.PROTOTYPE_RE.pattern
if not pattern.startswith("^("):
    raise RuntimeError(
        "platformio_ino_prototypes.py: PlatformIO's InoToCPPConverter.PROTOTYPE_RE has changed; "
        "this workaround needs updating"
    )

InoToCPPConverter.PROTOTYPE_RE = re.compile(
    "^[ \\t]*" + pattern[1:], InoToCPPConverter.PROTOTYPE_RE.flags
)
