//======================================================
//设计一个名为Fan的类表示风扇，要求包括：
//（1）3个名为SLOW,MEDIUM和FAST的常量，值分别为1,2,3,表示风速
//（2）int类型的私有数据成员speed,表示风扇的速度，
//(3)bool类型的私有数据成员on，表示风扇是否打开，默认值为false;
//(4) double 类型的私有数据成员radius，表示风扇的半径，创建后不可修改，默认值为5;
//(5) string类型的私有数据成员color，表示风扇的颜色，默认值为white;
//(6)4个数据成员的访问器，非const成员的修改器;
//(7)创建默认风扇的构造函数;
//(8)根据参数值创建风扇的构造函数;→初始化列表
//(9)成员函数 status()，返回风扇的状态字符串:如果风扇是打开的，字符串中包括风扇的速度、颜色和半径;否则，返回的字符串中包括风扇关闭、颜色和半径。
//编写测试程序，创建三个不同颜色和大小的风扇，进行改变速度开、关等操作，输出这些风扇的状态
//======================================================

#include <iostream>
using namespace std;

class Fan
{
private:
    enum {SLOW=1,MEDIUM=2,FAST=3}; //枚举，声明常量
    int speed = SLOW;              //风速，默认值为SLOW
    bool on = false;               //表示风扇是否打开，默认值为false
    const double radius = 5;       //表示风扇半径，默认为5,不可修改
    string color = "white";        //表示风扇的颜色，默认为white
public:
    //speed的访问器（get函数）
    int getSpeed(){
        return speed;
    }
    //speed的修改器（set函数）
    void setSpeed(int speed){
        this->speed = speed;
    }
    //on的访问器
    bool getOn(){
        return on;
    }
    //on的修改器
    void setOn(bool on){
        this->on = on;
    }
    //radius的访问器，防止不经意修改，使用const
    double getRadius()const{
        return radius;
    }
    //radius不能修改，没有修改器
    //color的访问器
    string getColor(){
        return color;
    }
    //color的修改器
    void setColor(string color){
        this->color = color;
    }

    //创建默认风扇的构造函数（默认构造函数）
    Fan(){} 

    //根据参数值创建风扇的构造函数（初始化列表）
    Fan(int speed, bool on , string color):speed(speed),on(on),color(color){} 

    void status(){
        if(on == true){
            cout << "风扇已经打开" << endl;
            cout << "风速为" << speed << endl;
            cout << "颜色为" << color << endl;
            cout << "半径为" << radius << endl;
            cout << "=====**输出完成**=====" << endl << endl; //多输出一空行
        }
        else{
            cout << "风扇为关闭状态！" << endl;
            cout << "颜色为" << color << endl;
            cout << "半径为" << radius << endl;
            cout << "=====**输出完成**=====" << endl << endl;
        }
    }
};

int main(){
    Fan a;    //默认创建风扇对象a
    a.status();  //调用status，

    Fan b = Fan(1, true, "red"); //创建风扇对象b,并赋初始值，下同
    b.status();

    Fan c = Fan(3, true, "black");
    c.status();
}
