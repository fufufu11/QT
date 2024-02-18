#include "widget.h"
#include "ui_widget.h"
#include <fstream>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    std::ifstream file("D:\\config.txt");
    std::string line;
    while(std::getline(file,line))
    {
        ui->comboBox->addItem(QString::fromStdString(line));
    }
    file.close();

}

Widget::~Widget()
{
    delete ui;
}
