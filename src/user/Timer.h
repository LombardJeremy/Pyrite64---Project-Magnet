#ifndef MAGNET_TIMER_H
#define MAGNET_TIMER_H

namespace P64::User::Timer {
    typedef struct {
        float elapsed;
        float limit;
        bool  running;
    } Timer;

    void initTimer(Timer* timer, float limite);

    void stopTimer(Timer* timer);

    void resetTimer(Timer* timer);

    void updateTimer(Timer* timer, float delta);

    bool timer_is_finished(const Timer *t);
}

#endif //MAGNET_TIMER_H