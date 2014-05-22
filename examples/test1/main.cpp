#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <iostream>
#include <memory>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>

#include "rota/fsm.h"
#include "rota/actor.h"

using namespace std;
using namespace rota;

#define FSM_IDLE  1
#define FSM_RUN  2
#define FSM_WALK  3

class Player: public Actor {
public:
    Player() {}
    virtual ~Player() {}
    void idle() {
        printf("player, %s\n", __func__);
    }
    void run() {
        printf("player, %s\n", __func__);
    }
    void walk() {
        printf("player, %s\n", __func__);
    }
};


class FsmIdle: public Fsm
{
public:
    FsmIdle() {}
    virtual ~FsmIdle() {}

    void enter(Actor* actor) {
        printf("FsmIdle, %s\n", __func__);
    }
    int execute(Actor* actor, float dt) {
        printf("FsmIdle, %s\n", __func__);
        ((Player*)actor)->idle();
        return FSM_RUN;
    }
    void exit(Actor* actor) {
        printf("FsmIdle, %s\n", __func__);
        return;
    }
};

class FsmRun: public Fsm
{
public:
    FsmRun() {}
    virtual ~FsmRun() {}

    void enter(Actor* actor) {
        printf("FsmRun, %s\n", __func__);
    }
    int execute(Actor* actor, float dt) {
        printf("FsmRun, %s\n", __func__);
        ((Player*)actor)->run();
        return FSM_WALK;
    }
    void exit(Actor* actor) {
        printf("FsmRun, %s\n", __func__);
        return;
    }
};

class FsmWalk: public Fsm
{
public:
    FsmWalk() {}
    virtual ~FsmWalk() {}

    void enter(Actor* actor) {
        printf("FsmWalk, %s\n", __func__);
    }
    int execute(Actor* actor, float dt) {
        printf("FsmWalk, %s\n", __func__);
        ((Player*)actor)->walk();
        return FSM_IDLE;
    }
    void exit(Actor* actor) {
        printf("FsmWalk, %s\n", __func__);
        return;
    }
};

int main(int argc, char **argv)
{
    Fsm::addFsm(FSM_IDLE, new FsmIdle());
    Fsm::addFsm(FSM_RUN, new FsmRun());
    Fsm::addFsm(FSM_WALK, new FsmWalk());
    // printf("len:%d\n", Fsm::dict().size());

    Player player;
    player.changeState(FSM_IDLE);
    return 0;
}
