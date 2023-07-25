/*
医院挂号问题（测试编程题）
时间限制： 3000MS
内存限制： 589824KB
题目描述：
某医院为了简化病人的看病流程，提高接诊效率，将医院接诊的流程转移至线上由病人及家属用手机办理，实现“互联网+医院”的便利接诊模式。

具体流程如下：病人及家属于就诊前在手机上预约抽号，待到达医院后，在自助机上输入号码，自助机自动显示等待人数。需要判断用户在自助机上输入的号码格式是否正确。在手机上抽取的号码一共有9位，具体含义为：

第1位可取的值为p/c，意为病人选择的是专家号p(professor)还是普通号c(common)；

第2、3位意为接诊的专家编号，每个科室有3位专家号医生和10位普通号医生，可见看出如果选择的是专家号，那么第2、3位的取值为01~03，如果选择的是普通号，那么第2、3位的取值为01~10。值得注意的是，专家号的专家医生只在周一至周五工作，普通号医生则一周七天都有人在岗。

第4位可取值为w/m，意为病人的性别，w：女性(women)，m：男性(man)。

第5、6、7位意为病人年龄。

第8、9位记录当天为周几。

比如，一个60岁的女病人周三挂了3号专家号。则预约号码为p03w06003。

现根据该场景，该医院欲开发一软件，请设计相应功能测试用例。（如提交用例达到上限，请尽可能精简常规用例）

说明：本题目中，已经给出了Java语言的标准代码，
请使用右下方的“自测数据”功能，保存若干组测试用例，
并逐一点击“调试”按钮进行调试，
您提交的测试用例应尽可能覆盖全面，
如果您觉得默认代码不够完善，也可自行调整。 
最终评分将根据测试用例的质量进行评判。

输入描述
输入1个9位的字符串，即预约的挂号号码。
要求第1位为p/c，第2、3位取值范围：01~03或者01~10，
第4位取值为w/m，第5、6、7位取值大于0，
第8、9位取值范围01~07。
值得注意的是，专家号在周六和周天不工作。

输出描述
判读号码输入格式是否正确，如果正确输出“号码输入正确”；如果错误输出“Error：号码输入错误”。

样例输入
p03w06002
样例输出
号码输入正确

提示
输入样例2
s03w06025

输出样例2
Error：号码输入错误

*
/

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);

        //输入
        //System.out.println("请输入预约挂号号码n:");
        String n = input.next();

        if(n.length() == 9)
        {
            //获取字符串的第一位字母
            char n1 = n.charAt(0);
            String n2 = String.valueOf(n.charAt(1));
            String n3 = String.valueOf(n.charAt(2));
            int flag1 = Integer.parseInt(n2)*10 +Integer.parseInt(n3) ;
            if(n1 == 'p' )
            {
                if(flag1>=01&&flag1<=03)
                {
                    char n4 = n.charAt(3);
                    if(n4 == 'w'|| n4 == 'm')
                    {
                        String n5 = String.valueOf(n.charAt(4));
                        String n6 = String.valueOf(n.charAt(5));
                        String n7 = String.valueOf(n.charAt(6));

                        if(isNumber(n5)&& isNumber(n6) && isNumber(n7))
                        {
                            int flag2 = Integer.parseInt(n5)*100 +Integer.parseInt(n6)*10 + Integer.parseInt(n7) ;

                            if(flag2 > 0) {
                                String n8 = String.valueOf(n.charAt(7));
                                String n9 = String.valueOf(n.charAt(8));

                                if(isNumber(n8)&&isNumber(n9)) {

                                    int flag3 = Integer.parseInt(n8)*10 + Integer.parseInt(n9) ;

                                    if(flag3>=1 && flag3 <=5)
                                    {
                                        System.out.println("号码输入正确");
                                    }
                                    else
                                    {
                                        System.out.println("Error:号码输入错误");
                                    }
                                }
                                else {
                                    System.out.println("Error:号码输入错误");

                                }

                            }
                            else {
                                System.out.println("Error:号码输入错误");

                            }


                        }
                        else
                        {
                            System.out.println("Error:号码输入错误");
                        }
                    }
                    else
                    {
                        System.out.println("Error:号码输入错误");
                    }
                }
                else
                {
                    System.out.println("Error:号码输入错误");
                }

            }
            else if(n1 == 'c')
            {
                if(flag1>=01&&flag1<=10)
                {
                    char n4 = n.charAt(3);
                    if(n4 == 'w'|| n4 == 'm')
                    {
                        String n5 = String.valueOf(n.charAt(4));
                        String n6 = String.valueOf(n.charAt(5));
                        String n7 = String.valueOf(n.charAt(6));

                        int flag2 = Integer.parseInt(n5)*100 +Integer.parseInt(n6)*10 + Integer.parseInt(n7) ;
                        if(flag2 > 0)
                        {
                            String n8 = String.valueOf(n.charAt(7));
                            String n9 = String.valueOf(n.charAt(8));
                            int flag3 = Integer.parseInt(n8)*10 + Integer.parseInt(n9) ;
                            if(flag3>=1 && flag3 <=7)
                            {
                                System.out.println("号码输入正确");
                            }
                            else
                            {
                                System.out.println("Error:号码输入错误");
                            }
                        }
                        else
                        {
                            System.out.println("Error:号码输入错误");
                        }
                    }
                    else
                    {
                        System.out.println("Error:号码输入错误");
                    }
                }
                else
                {
                    System.out.println("Error:号码输入错误");
                }
            }
            else
            {
                System.out.println("Error:号码输入错误");
            }
        }
        else
        {
            System.out.println("Error:号码输入错误");
        }
    }
    public static boolean isNumber(String str) {
        // 这个代码意思是如果没有抛出异常 就证明是数字，抛出异常了那么就不是数字

        try {
            // parseInt 是将字符串转换为整数类型，返回一个int类型，如果字符串中有非数字类型字符，则会抛出一个NumberFormatException的异常
            Integer.parseInt(str);
            return true;
        } catch (NumberFormatException e) {
            return false;
        }
    }
}