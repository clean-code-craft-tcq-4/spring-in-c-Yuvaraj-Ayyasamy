#include "stats.h"

struct Stats compute_statistics(const float* numberset, int setlength) {
    struct Stats s;
    s.average = 0;
    s.min = 0;
    s.max = 0;
    for(int i=0; i<setlength; i++) {
        if(s.min > numberset[i])
            s.min = numberset[i];
        if(s.max < numberset[i])
            s.max = numberset[i];
        s.average += numberset[i];
    }

    return s;
}

void check_and_alert(float maxThreshold, alerter_funcptr alerters[], struct Stats computedStats) {
    if(computedStats.average > maxThreshold) {
        emailAlertCallCount = 1;
        ledAlertCallCount = 1;
    }
}
