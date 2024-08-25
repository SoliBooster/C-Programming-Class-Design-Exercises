//===========================================================
//设计表示时间的Time类：
//（1）有表示时，分，秒的数据成员;
//（2）正确的初始化操作，检验数据的合法性
//（3）有时，分，秒的get和set函数;
//（4）以24小时格式或者12小时格式加上午下午的格式输出当前时间（可自己给定时间）。
//===========================================================

#include <iostream>
#include <iomanip> // 用于控制输出格式的头文件
//using namespace 能不用就不用

class Time {
private:
    int hour;    
    int minute;
    int second;

public:
    // 构造函数，可以设置默认参数，初始化为 00:00:00
    Time(int h = 0, int m = 0, int s = 0) {
        setTime(h, m, s);  //调用set函数，定义在下边
    }

    // set函数，设置时间的方法，包含参数验证
    void setTime(int h, int m, int s) {
        if (h >= 0 && h < 24 && m >= 0 && m < 60 && s >= 0 && s < 60) {
            hour = h;
            minute = m;
            second = s;
        } else {
            std::cerr << "无效的时间格式！\n";
            // 错误处理
            hour = 0;     //清除错误信息，重新初始化
            minute = 0;
            second = 0;
        }
    }

    // 获取小时
    int getHour() const {
        return hour;
    }

    // 获取分钟
    int getMinute() const {
        return minute;
    }

    // 获取秒数
    int getSecond() const {
        return second;
    }

    // 以24小时格式打印时间的方法
    void printTime() const {
        std::cout << std::setfill('0') << std::setw(2) << hour << ":"
                  << std::setw(2) << minute << ":"
                  << std::setw(2) << second << std::endl;
    }
    //std::setfill('0') 是一个流操作符，用于设置填充字符。
    //它告诉输出流在填充位数不足时使用字符 '0'。这确保了输出的时间总是以两位数字显示，
    //即使实际的值小于10（例如，9 将会显示为 09）
    
    //std::setw(2) 是一个流操作符，用于设置字段宽度为2个字符。
    //这意味着接下来的输出将占用至少两个字符的位置。
    //如果实际的输出内容少于两个字符，std::setfill 中指定的字符（在这里是 '0'）会填充前面的位置，
    //以确保输出总是占用两个字符的位置
};

int main() {
    Time t1;  // 默认构造函数，初始化为 00:00:00
    t1.printTime();

    Time t2(8, 30, 45);  // 初始化为指定时间
    t2.printTime();

    // 使用set函数
    t1.setTime(15, 45, 20);
    std::cout << "当前时间为: ";//<<t1.printTime() << std::endl;不能这么写是因为printTime()没有返回值
    t1.printTime();

    // 获取时间的各个部分
    std::cout << "小时: " << t1.getHour() << std::endl;
    std::cout << "分钟: " << t1.getMinute() << std::endl;
    std::cout << "秒数: " << t1.getSecond() << std::endl;

    return 0;
}