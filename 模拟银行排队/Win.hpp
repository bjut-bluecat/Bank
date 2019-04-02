//
//  Win.hpp
//  模拟银行排队
//
//  Created by 蓝猫 on 2019/3/18.
//  Copyright © 2019年 蓝猫. All rights reserved.
//

#ifndef Win_hpp
#define Win_hpp

#include <stdio.h>
class Win
{
private:
    int num;//窗口号码
    bool isbusy;
    int last_time;//上一个刚结束的时间 
public:
    Win()
    {
        isbusy=false;
        last_time=0;
    };
    void set_num(int n)
    {
        num=n;
    }

    void set_busy()
    {
        isbusy=true;
    }
    void set_nobusy()
    {
        isbusy=false;
    }
    void set_last_time(int time)
    {
        last_time=time;
    }
    inline int get_last_time()
    {
        return last_time;
    }
    inline int get_num()
    {
        return num;
    }

};
#endif /* Win_hpp */
