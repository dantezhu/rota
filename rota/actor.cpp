#include "actor.h"
namespace rota {

    std::string Actor::changeState(const std::string& dstState) {
        if (dstState.empty()) {
            return "";
        }

        Fsm* dstFsm = Fsm::dict[dstState];
        Fsm* curFsm = Fsm::dict[curState];

        if (isInState(dstState))
        {
            dstState = curFsm->process(0);
        }
        else
        {
            if (curFsm)
            {
                curFsm.exit(this);
            }

            self.curState = dstState;
            
            if (dstFsm)
            {
                self.fsmDuration = 0;
                dstFsm.enter(this);
            }

            dstState = dstFsm->process(0);
        }

        return processState(dstState);
    }

    std::string processState(float dt) {
        Fsm* curFsm = Fsm::dict[curState];

        this.fsmDuration += dt;

        // 之所以不用直接 ChangeState:self.curState，是因为dt只有在第一次执行process时有意义
        std::string dstState = curFsm->process(dt);

        return changeState(dstState);
    }

    bool isInState(const std::string& state) {
        return this.curState == state;
    }

}
