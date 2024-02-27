#include "mywidget.h"
#include "qdebug.h"
#include "subwidget.h"
MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
{
    // 初始化
    /*
     如果窗口需要依附于另一个窗口，则给该窗口指定父类
     父窗口显示的时候，子窗口也会显示！
    */
    b1 = new QPushButton("老大",this);
    b1->move(100,100);

    b2 = new QPushButton;

    b2->setParent(this);
    b2->setText("我是老二");
    b2->move(200,200);
    // 改变按钮位置 - move
    // 窗口的坐标系 原点 左上角 x：向右递增 y：向下递增

    // 内存自动回收
    // 1. 从QObject派生的类 1.直接 2.间接
    // 2. 指定父类，父类析构的时候，先析构他的孩子

    // 设置窗口的标题
//    this->setWindowTitle("明天要离开！");
//    this->resize(200,300);
    // this->setWindowIcon(QIcon(""));

    // 需求 b1 关闭窗口
    // connect(b1,this); // connect (b1,发出的信号，this,处理信号的槽函数);
    // qt 信号和槽他们都是函数
    // 1. 信号只有函数声明，不需要函数定义
    // 2. 槽函数需要声明也需要定义，回调函数！
    //connect(&b1, &QPushButton::clicked, this, &MyWidget::close);
    // b1 : 信号的发出者，此参数是一个指针
    // &QPushButton::clicked： 信号发出者，内部的一个信号
    // 格式 ： & + 信号发出者类的名字 + ：： + 信号的名字
    // this ： 信号的接收者，此参数是一个指针
    //  &MyWidget::close： 信号的处理函数，属于this
    // 自定义槽函数
    /*
     * 1. 槽函数在qt5中可以是任意成员函数，全局函数，静态函数，lambda表达式（隐式函数）
     * 2. 槽函数需要与信号对应（返回值，参数）
     * 3. 信号没有返回值，槽函数返回值：void
     * 4. void mysig(int,double,QString);
     *    void myslot(int,double,QString);
     *
     * 5. 槽函数的参数是为了接收信号传过来的数据！
     * 6. 槽函数的参数应该是不能够大于信号的参数个数，可以少于信号的参数个数
     * 7. 槽函数可以重载
    */
    connect(b1,&QPushButton::released,this,&MyWidget::slotForMianWidget);

    b3 = new QPushButton("软件园",this);
    b3->resize(100,50);
    b3->move(200,300);
    // 点击b3,显示子窗口 - subW
    connect(b3,&QPushButton::clicked,this,&MyWidget::slotHideMe);

    connect(&subW,&SubWidget::sigSub,this,&MyWidget::slotShowMe);
    
    connect(&subW,&SubWidget::sigSub,this,&MyWidget::slotSubMsg);
}

MyWidget::~MyWidget()
{

}

void MyWidget::slotForMianWidget() {
    b2->setText("我被老大改名了！");
}
void MyWidget::slotHideMe() {
    // 隐藏自己
    hide();
    // 显示软件园窗口
    subW.show();
}
void MyWidget::slotShowMe() {
    // 展示自己
    show();
    // 隐藏软件园窗口
    subW.hide();
}
void MainWidget::slotSubMsg(int num,Qstring str) {
    qDebug() << num << str;
}
