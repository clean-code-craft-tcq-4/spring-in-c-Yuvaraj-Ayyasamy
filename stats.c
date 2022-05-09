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

void emailAlerter() {
    emailAlertCallCount = 1;
}

void ledAlerter() {
    ledAlertCallCount = 1; 
}

void check_and_alert(float maxThreshold, alerter_funcptr alerters[], struct Stats computedStats) {
    if(computedStats.average > maxThreshold) {
        (*alerters[0])();
        (*alerters[1])();
    }
}
