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
        // 直接用静态变量保存就行了
        static map<std::string, Fsm*> dict;

    public:
        std::string name() const=0;

        void enter(Actor* actor) {return;}
        std::string process(Actor* actor, float dt) {return "";}
        void exit(Actor* actor) {return;}
    };

}

#endif /* end of include guard: FSM_H_20140520152727 */

