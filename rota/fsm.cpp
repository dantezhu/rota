#include "fsm.h"
namespace rota {

std::map<int, Fsm*>& Fsm::dict() {
    static std::map<int, Fsm*> _dict;

    return _dict;
}

void Fsm::enter(Actor* actor) {
    return;
}

int Fsm::process(Actor* actor, float dt) {
    return 0;
}

void Fsm::exit(Actor* actor) {
    return;
}

}
