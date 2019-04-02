//
//  Bank.cpp
//  模拟银行排队
//
//  Created by 蓝猫 on 2019/3/18.
//  Copyright © 2019年 蓝猫. All rights reserved.
//

#include "Bank.hpp"

void Bank::Main()
{
    Create_Customer();
    Customer_into();
}

void Bank::print_time(int time)//time是分钟
{
    int hour=time/60+open_time;
    int min=time%60;
    cout<<hour<<":"<<min<<" ";
};
void Bank::Create_Customer()//产生用户放入队列
{
    while (1)
    {
        int arrive=rand()%10+1+arr_time;//随机产生一个用户进入队列 1-30内来一个
        if(arrive>close_time2)
        {
            print_time(arrive);
            cout<<"已经关门了 明个再来"<<endl;
            break;
        }
        /*
        if(arrive>last)
        {
            cout<<"准备关门了 明个再来"<<endl;
            break;
        }
         */
        int process=rand()%20+1+5;//业务办理时间  5-25min
        arr_time=arrive;
        Customer cust(num_customer,arrive,process);
        que.push(cust);
        num_customer++;

    }
}
void Bank::Customer_into()//顾客处理函数
{
    /*
    for(auto x:win_v)
    {
        cout<<x.get_num()<<" "<<x.get_last_time()<<endl;
    }*/
    while (!que.empty())
    {
        Customer c=que.front();
        que.pop();
        if(c.get_arrive_time()>last)
        {
            cout<<c.get_id()<<"号 到达:";
            print_time(c.get_arrive_time());
            cout<<"准备关门了 明个再来"<<endl;
        }
        else
        {
            //Win w=win_v[0];
            int pos=0;// pos和窗口编号不一样！！！！
            int min_wait=INT_MAX;
            
            for(auto x:win_v)
            {
                //cout<<x.get_num()<<" "<<x.get_last_time()<<endl;
                if(x.get_last_time()<c.get_arrive_time())//不用等
                {
                    //cout<<"no wait"<<x.get_last_time()<<" "<<c.get_arrive_time()<<endl;
                    pos=x.get_num();
                    break;//记住加break
                    //cout<<w.get_num()<<endl;
                }
                else//那个窗口等的时间最短
                {
                    if(min_wait>(x.get_last_time()-c.get_arrive_time()))
                    {
                        //cout<<"wait"<<endl;
                        pos=x.get_num();
                        min_wait=x.get_last_time()-c.get_arrive_time();
                    }
                }
            }
            Win_Customer(pos,c);
            cout<<endl;
        }
    }
}
void Bank::Win_Customer(int pos,Customer c)//顾客办理业务  这个w必须传实参 因为窗口会变的
{
    win_v[pos].set_busy();
    c.set_wait_time(win_v[pos].get_last_time());
    cout<<"窗口:"<<win_v[pos].get_num()+1<<" ";
    print_cust(c);
    win_v[pos].set_last_time(c.get_leave_time());//窗口更新时间
    cout<<endl;
    /*
    for(int i=0;i<win_v.size();i++)
    {
        cout<<win_v[i].get_num()<<" "<<win_v[i].get_last_time()<<endl;
    }
     */
    win_v[pos].set_nobusy();
    
}

void Bank:: print_cust(Customer c)
{
    cout<<c.get_id()<<"号 到达:";
    print_time(c.get_arrive_time());
    cout<<" 离开:";
    print_time(c.get_leave_time());
    cout<<" 等待:"<<c.get_wait_time();
    
    //print_time(c.get_wait_time());
    cout<<" 开始办理:";
    print_time(c.get_start_time());
    cout<<" 业务时间:"<<c.get_process_time();
    //print_time(c.get_process_time());
    cout<<" 总时间:"<<c.get_total_time();
    //print_time(c.get_total_time());
}
