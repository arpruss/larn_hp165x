#ifdef HP165X
#include <hp165x.h>

#define DATE2026 1767225600

unsigned long _systemStartTime(void) {
    return DATE2026 + (getSeed32() & 0xFFFFFFF);
}

#else
char __empty_faketime;
#endif