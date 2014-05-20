/*=============================================================================
#
#     FileName: fsm.h
#         Desc: 
#
#       Author: dantezhu
#        Email: zny2008@gmail.com
#     HomePage: http://www.vimer.cn
#
#      Created: 2014-05-20 15:27:03
#      Version: 0.0.1
#      History:
#               0.0.1 | dantezhu | 2014-05-20 15:27:03 | init
#
#=============================================================================*/

#ifndef FSM_H_20140520152727
#define FSM_H_20140520152727

#include <iostream>
#include <map>
#include "actor.h"

namespace rota {

    class Fsm
    {
    public:
        // 所有继承的fsm，必须注册到这里来
        static std::map<int, Fsm*> dict;

    public:
        void enter(Actor* actor) {return;}
        int process(Actor* actor, float dt) {return 0;}
        void exit(Actor* actor) {return;}
    };

}

#endif /* end of include guard: FSM_H_20140520152727 */

