#include <stdio.h>
#include <time.h>

int main()
{
    struct timespec ts;
    int ret;

    // monotonic clock
    ret = clock_gettime(CLOCK_MONOTONIC, &ts);
    if (ret)
        return -1;

    printf("The monotonic clock is %u.%09us.\n", ts.tv_sec, ts.tv_nsec);

    // faster but less precise version of monotonic time
    ret = clock_gettime(CLOCK_MONOTONIC_COARSE, &ts);
    if (ret)
        return -1;

    printf("The monotonic coarse clock is %u.%09us.\n", ts.tv_sec, ts.tv_nsec);

    // raw hardware-based time
    ret = clock_gettime(CLOCK_MONOTONIC_RAW, &ts);
    if (ret)
        return -1;

    printf("The monotonic raw clock is %u.%09us.\n", ts.tv_sec, ts.tv_nsec);

    // boot time, includes any time that the system is suspended
    ret = clock_gettime(CLOCK_BOOTTIME, &ts);
    if (ret)
        return -1;

    printf("The boottime clock is %u.%09us.\n", ts.tv_sec, ts.tv_nsec);

    // real time
    ret = clock_gettime(CLOCK_REALTIME, &ts);
    if (ret)
        return -1;

    printf("The realtime clock is %u.%09us.\n", ts.tv_sec, ts.tv_nsec);

    // faster but less precise version of real time
    ret = clock_gettime(CLOCK_REALTIME_COARSE, &ts);
    if (ret)
        return -1;

    printf("The realtime coarse clock is %u.%09us.\n", ts.tv_sec, ts.tv_nsec);

    // High-resolution per-process timer from the CPU
    ret = clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &ts);
    if (ret)
        return -1;

    printf("The process cpu-time clock is %u.%09us.\n", ts.tv_sec, ts.tv_nsec);

    // Thread-specific CPU-time clock.
    ret = clock_gettime(CLOCK_THREAD_CPUTIME_ID, &ts);
    if (ret)
        return -1;

    printf("The thread cpu-time clock is %u.%09us.\n", ts.tv_sec, ts.tv_nsec);

    return 0;
}
