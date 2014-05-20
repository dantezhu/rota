#include "fsm.h"
#include "actor.h"

namespace rota {

    int Actor::changeState(int dstState) {
        if (dstState <= 0) {
            return 0;
        }

        // 这样写确实可能会增加内容，但是一般情况下不会故意用错
        Fsm* dstFsm = Fsm::dict[dstState];
        Fsm* curFsm = Fsm::dict[curState];

        if (isInState(dstState))
        {
            dstState = curFsm->process(this, 0);
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
                fsmDuration = 0;
                dstFsm->enter(this);
            }

            dstState = dstFsm->process(this, 0);
        }

        return processState(dstState);
    }

    int Actor::processState(float dt) {
        Fsm* curFsm = Fsm::dict[curState];

        fsmDuration += dt;

        // 之所以不用直接 ChangeState:self.curState，是因为dt只有在第一次执行process时有意义
        int dstState = curFsm->process(this, dt);

        return changeState(dstState);
    }

    bool Actor::isInState(int state) {
        return curState == state;
    }

}
