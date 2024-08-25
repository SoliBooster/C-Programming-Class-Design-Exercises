//=================================================================
//设计一个Account类：
//（1）static数据成员annual表示每个存款人的年利率;
//（2）private数据成员saving表示当前存款额;
//（3）成员函数calculate()用于计算月利息，并将利息加进savings;
//（4）static成员函数modify()改变annual;
//在主程序中实例化两个不同的Account对象saver1和saver2,账户余额分别为2000.00和3000.00
//将annual设置为3%，计算每个人的月息并打印结果，再将annual设置为4%，重新计算每个存款人的月息并
//打印新的结果。
//==================================================================


#include <iostream>
#include <iomanip> 


class Account {
private:
    double savings;  //当前存款额
    
public:
    static double annual; // 年利率

    //构造函数，初始化存款额
    Account(double savings) : savings(savings) {}

    //成员函数calculate()用于计算月利息，并将利息加进savings
    double calculate() {
        double month_rate = annual / 12.0;  // 月利率 = 年利率 / 12
        double month_profit = savings * month_rate;
        savings += month_profit;  // 将利息加进savings
        return month_profit;  // 返回的是月利息
    }

    // 静态成员函数modify()改变annual
    static void modify(double new_annual) {
        annual = new_annual;
    }
};

//静态数据成员的定义和初始化，类外定义静态成员变量;
double Account::annual = 0.0;

int main() {
    Account saver1(2000.00);
    Account saver2(3000.00);

    //设置年利率为3%
    Account::modify(0.03);

    //计算每个人的月利息
    std::cout << std::fixed << std::setprecision(2); // 设置输出为保留两位小数
    std::cout << "当月利率为：" << Account::annual << "时" << std::endl;
    std::cout << "Saver1的月利息为：" << saver1.calculate() <<std::endl;
    std::cout << "Saver2的月利息为：" << saver2.calculate() <<std::endl <<std::endl;

    //将年利率设置为4%
    Account::modify(0.04);

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "当月利率为：" << Account::annual << "时" << std::endl;
    std::cout << "Saver1的新月利息为：" << saver1.calculate() <<std::endl;
    std::cout << "Saver2的新月利息为：" << saver2.calculate() <<std::endl <<std::endl;

    return 0;
}