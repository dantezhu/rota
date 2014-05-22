#include "fsm.h"
namespace rota {
    std::map<int, Fsm*> Fsm::mapFsms;

    void Fsm::addFsm(int state, Fsm* fsm) {
        mapFsms[state] = fsm;
    }

    void Fsm::delFsm(int state) {
        mapFsms.erase(state);
    }

    Fsm* Fsm::getFsm(int state) {
        typeof(mapFsms.begin()) it = mapFsms.find(state);
        if (it == mapFsms.end())
        {
            return NULL;
        }

        return it->second;
    }

    void Fsm::enter(Actor* actor) {
        return;
    }

    int Fsm::execute(Actor* actor, float dt) {
        return 0;
    }

    void Fsm::exit(Actor* actor) {
        return;
    }

}
