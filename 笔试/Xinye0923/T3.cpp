/**
 * @file T3.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-23
 * 
 * @copyright Copyright (c) 2022
 * 
 * SQL编程题
 * 已知网站访问日志表visit_table
 * (date访问日期，time访问时间，user用户)
 * 想要获取8月1日至8月3日，3天内至少有2天访问次数
 * 都大于2(包含2)的用户，正确的sql为
 * 

示例1：
create table visit_table
( visit_date varchar(20) comment '访问日期' ,
 visit_time varchar(20)  comment '访问时间', 
 user_id bigint comment '用户');
 insert into visit_table values ( '2022-08-02' , '2022-08-02 00:02:05',  111 );
insert into visit_table values ( '2022-08-02' , '2022-08-02 00:04:02' , 111   );
insert into visit_table values ( '2022-08-02' , '2022-08-02 00:05:32' , 111  );
insert into visit_table values ( '2022-08-02' , '2022-08-02 00:24:59' , 222   );
insert into visit_table values ( '2022-08-02' , '2022-08-02 00:26:56' , 222  );
insert into visit_table values ( '2022-08-02' , '2022-08-02 00:31:41' , 111 );
insert into visit_table values ( '2022-08-01' , '2022-08-01 00:32:29' , 111   );
insert into visit_table values ( '2022-08-01' , '2022-08-01 00:41:40' , 111  );
insert into visit_table values ( '2022-08-03' , '2022-08-03 00:45:47' , 111    );
insert into visit_table values ( '2022-08-03' , '2022-08-03 00:49:29' , 111  );

user_id
111

示例2：

select user_id
from visit_table
where visit_date between '2022-08-01' and '2022-08-03'
group by user_id having count(*) >=2;
 */


/*
2022-09-23复盘
看起来很简单的一个SQL语句，但是确实做不出来。
想了半天😂

不服不行，搜了半天，也没有找到参考办法和思路

3天内访问次数大于2天：
select user_id
from visit_table
where visit_date between '2022-08-01' and '2022-08-03'
group by user_id having count(*) >=2;

user_id
111
222

问题在于222用户，的访问次数全部出现第2天

我们希望剔除掉访问次数出现在1天的情况

3天内至少访问2天：
select visit_date
from visit_table
where visit_date between '2022-08-01' and '2022-08-03'
group by visit_date having count(*) >=2;

visit_date
2022-08-01
2022-08-02
2022-08-03

放弃了，明天还要复习深信服呢
*/
