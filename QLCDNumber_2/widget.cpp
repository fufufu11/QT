#include "widget.h"
#include "ui_widget.h"
#include <thread>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // while(true)
    // {
    //     int value = ui->lcdNumber->intValue();
    //     std::this_thread::sleep_for(std::chrono::seconds(1));
    //     if(value <= 0)
    //     {
    //         break;
    //     }
    //     ui->lcdNumber->display(value - 1);
    // }
    std::thread t([this](){
        int value = this->ui->lcdNumber->intValue();
        while(true)
        {
            std::this_thread::sleep_for(std::chrono::seconds(1));
            if(value <= 0)
            {
                break;
            }
            this->ui->lcdNumber->display(value - 1);
        }
    });
}

Widget::~Widget()
{
    delete ui;
}
