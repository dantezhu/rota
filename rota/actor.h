/*=============================================================================
#
#     FileName: actor.h
#         Desc: 
#
#       Author: dantezhu
#        Email: zny2008@gmail.com
#     HomePage: http://www.vimer.cn
#
#      Created: 2014-05-20 15:43:14
#      Version: 0.0.1
#      History:
#               0.0.1 | dantezhu | 2014-05-20 15:43:14 | init
#
#=============================================================================*/

#ifndef ACTOR_H_20140520154302
#define ACTOR_H_20140520154302

#include <iostream>
namespace rota {

    class Actor
    {
    public:
        int changeState(int dstState);
        int processState(float dt);

        bool isInState(int state);

    public:
        int curState;
        float fsmDuration;
    };

}

#endif /* end of include guard: ACTOR_H_20140520154302 */

