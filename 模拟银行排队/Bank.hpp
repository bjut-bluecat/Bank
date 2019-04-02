//
//  Bank.hpp
//  模拟银行排队
//
//  Created by 蓝猫 on 2019/3/18.
//  Copyright © 2019年 蓝猫. All rights reserved.
//

#ifndef Bank_hpp
#define Bank_hpp

#include <stdio.h>
#include <iostream>
#include <queue>
#include<cstdlib>
#include "Customer.hpp"
#include "Win.hpp"
class Bank
{
private:
    int open_time;//开门时间 输入多少 就是几点
    int close_time;//关门时间 输入多少 就是几点
    int close_time2;//关门时间 开门后分钟
    int last;//  转换成开门后的分钟 最后被允许取号的时间
    int arr_time;//( 上一个顾客来的时间) 通过它来随机产生顾客顺序到来
    int num_customer;//顾客数量
    int num_win;//窗口数量
    std::vector<Win> win_v;//窗口数量
    std::queue<Customer> que;//顾客队列
public:
    Bank(int t1,int t2,int num):open_time(t1),close_time(t2),num_win(num)
    {
        close_time2=(close_time-open_time)*60;
        last=(close_time-open_time)*60-20;//提前二十分钟不能取号
        arr_time=0;
        num_customer=0;
        for(int i=0;i<num_win;i++)
        {
            Win w;
            w.set_num(i);
            win_v.emplace_back(w);
        }
    };
    void Main();
    void Create_Customer();//产生用户放入队列
    void Customer_into();//顾客处理函数
    void Win_Customer(int pos,Customer);//顾客办理业务
    void print_time(int time);//打印时间为时分秒那种
    void print_cust(Customer c);//顾客离开 打印顾客信息
    
};
#endif /* Bank_hpp */
