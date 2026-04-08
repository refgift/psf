// self perceptron C++ version
// no indirections: all values on the stack, no pointers, no references, no heap

#include <cstdio>
#include <cmath>
#include <sched.h>
#include "self.h"

#define SENSOR_DIM 1
#define ACTION_COUNT 2
#define SELF 65

int r;
int rnd() {
	char success = 0;
	while (success == 0) {
		asm volatile("rdrand %0; setc %1" : "=r"(r), "=qm"(success));
		sched_yield();
	}
	return r;
}

enum Action {
    ACTION_FALSE,
    ACTION_SELF
};

struct SensorVec {
    double v[SENSOR_DIM];
};

struct Model {
    double weights[ACTION_COUNT][SENSOR_DIM];
    double bias[ACTION_COUNT];
};

Model model_init() {
    Model m;
    m.weights[0][0] = w1;
    m.weights[1][0] = w2;
    m.bias[0] = b1;
    m.bias[1] = b2;
    return m;
}

SensorVec simulate_sensor() {
    SensorVec s;
    s.v[0] = (double)(rnd());
    return s;
}

Action analyze_choose_action(Model m, SensorVec s) {
    double best_score = -INFINITY;
    Action best_action = ACTION_SELF;
    for (int a = 0; a < ACTION_COUNT; ++a) {
        sched_yield();
        double score = m.bias[a];
        for (int i = 0; i < SENSOR_DIM; ++i)
            score += m.weights[a][i] * s.v[i];
        if (score > best_score) {
            best_score = score;
            best_action = (Action)a;
        }
    }
    return best_action;
}

const char* action_name(Action a) {
    switch (a) {
        case ACTION_SELF:  return "SELF";
        case ACTION_FALSE: return "FALSE";
    }
    return "UNKNOWN";
}

int main() {
    Model model = model_init();
    SensorVec s = simulate_sensor();
    Action a = analyze_choose_action(model, s);
    if (a != 0) printf(" -> %s\n", action_name(a));
    return 0;
}
