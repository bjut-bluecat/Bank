//
//  main.cpp
//  模拟银行排队
//
//  Created by 蓝猫 on 2019/3/15.
//  Copyright © 2019年 蓝猫. All rights reserved.
//
/*
 业务逻辑：
 首先我们要分析银行提供服务的逻辑。在银行服务中，所有顾客都是通过取号排队的方式等待服务的，这和火车站买票有所不同，在火车站买票时，顾客必须在某一个窗口所排的队列下进行排队，且无法变更自己所属的窗口，否则只能从队尾重新排队。换句话说，对于银行提供的服务来说，所有用户都是位于同一个队列上的，当某个服务窗口可用时，才会从排队队列的队首取出一个新的用户来办理银行业务。即代码实现过程中，服务窗口可以创建 w 个，但只需要实现一个顾客队列即可。
 
 其次，对于顾客而言，有两个属性是能够被抽象出来的：
 
 到达银行的时间；
 需要服务的时间。
 
 感觉类似线程池，每一个顾客是任务，
 */
#include <iostream>
#include <string>
#include "Bank.hpp"
static std::string  getCurrentTimeStr()
{
    time_t t = time(NULL);
    char ch[64] = {0};
    strftime(ch, sizeof(ch) - 1, "%Y-%m-%d %H:%M:%S", localtime(&t));     //年-月-日 时-分-秒
    return ch;
}

int main(int argc, const char * argv[])
{
    const int win_num=3;
    //std::cout <<   getCurrentTimeStr()<<"\n";
    int time1,time2;
    std::cout<<"======================欢迎光临蓝猫银行======================"<<std::endl;
    std::cout <<"请输入银行开门和关门时间，9:00-17:00，请输入9 17"<<"\n";
    cin>>time1>>time2;
    Bank b(time1,time2,win_num);
    b.Main();
    return 0;
}
