# Intel (R) QuickAssist Hardware 1.5 Driver/Software
This repository contains a refactoring of Intel's QuickAssist Technology Driver
for Linux - HW Version 1.5. It is an entirely unsupported effort by Intel; you
can find their driver, [here](https://www.intel.com/content/www/us/en/download/708765/intel-quickassist-technology-driver-for-linux-hw-version-1-5.html),
if you are seeking support from Intel.

## Why?
Intel's latest release of the driver no longer compiles against recent kernels.
Futhermore, the module cannot be compiled in-tree, which precludes it from
recent optimizations like LTO and enhancements, such as CFI. There are also
one or two bug fixes to the code found via Clang static analysis that are
addressed at the time of writing.

Mostly for fun. The ciphers supported by Gen2 QAT hardware are becoming less
useful. Though, at the same time, such hardware is now becoming very
affordable ("Rangley" C2xx8 SoCs with integrated QAT can be found for as low
as $50 USD or less at the time of writing, etc.) and thus of interest to
hobbyist homelabbers.

HW1.5 supports 2048-bit RSA and 256-bit ECDSA, so there is still a lot of
cryptographic life left in the hardware, so to speak.
