#include "fsm.h"
#include "actor.h"

namespace rota {
    Actor::Actor() {
        curState = 0;
        stateAge = 0;
    }

    int Actor::changeState(int dstState) {
        if (dstState <= 0) {
            return 0;
        }

        Fsm* dstFsm = Fsm::getFsm(dstState);
        Fsm* curFsm = Fsm::getFsm(curState);

        if (curState == dstState)
        {
            dstState = curFsm->execute(this, 0);
        }
        else
        {
            if (curFsm)
            {
                curFsm->exit(this);
            }

            curState = dstState;
            
            if (dstFsm)
            {
                stateAge = 0;
                dstFsm->enter(this);
            }

            dstState = dstFsm->execute(this, 0);
        }

        return changeState(dstState);
    }

    int Actor::updateState(float dt) {
        Fsm* curFsm = Fsm::getFsm(curState);
        if (!curFsm) {
            return 0;
        }

        stateAge += dt;

        // 之所以不用直接 changeState:self.curState，是因为dt只有在第一次执行process时有意义
        int dstState = curFsm->execute(this, dt);

        return changeState(dstState);
    }

    int Actor::getState() {
        return curState;
    }

    float Actor::getStateAge() {
        return stateAge;
    }

}
