//=================================
//设计并实现一个三角形类Triangle，要求：
//（1）用三条边描述三角形；
//（2）计算面积，周长；
//（3）合理的初始化，注意检验三边长度的合法性，默认三边长都为一。
//编写测试程序。
//=================================

#include <iostream>
#include <cmath>

class Triangle{
    double side1 = 1;
    double side2 = 1;
    double side3 = 1;
public:
    Triangle(double side1, double side2, double side3){
        if(((side1 + side2) < side3) || ((side1 + side3) < side2) || ((side2 + side3) < side1)){
            //若两边之和小于第三边就退出。
            std::cout << "你干什么吃的" << std::endl;
            exit(0);
        }
        this->side1 = side1;
        this->side2 = side2;
        this->side3 = side3;
    }

    //get函数
    double get_side1(){
        return side1;
    }
    double get_side2(){
        return side2;
    }
    double get_side3(){
        return side3;
    }

    //求面积
    double S_Tri(){
        double a;
        double S;
        a = (side1+side2+ side3)/2;
        S = sqrt(a*(a-side1)*(a-side2)*(a-side3));
        return S;
    }

    //求周长
    double C_Tri(){
        double C;
        C = side1 + side2 + side3;
        return C;
    }
};

int main(){
    Triangle tri1(3,4,70);
    std::cout << "三角形的三边分别为：" << tri1.get_side1() << " ";
    std::cout << tri1.get_side2() << " ";
    std::cout << tri1.get_side3() << std::endl;

    std::cout << "三角形的面积是：" << tri1.S_Tri() <<std::endl;
    std::cout << "三角形的周长是：" << tri1.C_Tri() <<std::endl;
}