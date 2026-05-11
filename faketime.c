#ifdef HP165X
#include <hp165x.h>

#define DATE2026 1767225600

unsigned long _systemStartTime(void) {
    static unsigned long start=0;
    if (start == 0)
        start = DATE2026 + (getSeed32() & 0xFFFFFFF);
    return start;
}

#else
char __empty_faketime;
#endif