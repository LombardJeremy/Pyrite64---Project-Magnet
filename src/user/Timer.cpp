#include "Timer.h"

namespace P64::User::Timer {
    void initTimer(Timer *timer, float limite) {
        timer->limit = limite;
        timer->running = true;
        timer->elapsed = 0;
    }

    void stopTimer(Timer *timer) {
        timer->running = false;
        timer->elapsed = 0;
    }

    void resetTimer(Timer *timer) {
        timer->elapsed = 0;
        timer->running = true;
    }

    void updateTimer(Timer *timer, float delta) {
        if (!timer->running) return;
        timer->elapsed += delta;
        if (timer->elapsed >= timer->limit) {
            timer->elapsed = timer->limit;
            timer->running = false;
        }
    }

    bool timer_is_finished(const Timer *t) {
        return t->limit > 0.0f && t->elapsed >= t->limit;
    }
}
