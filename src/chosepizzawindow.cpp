#include "chosepizzawindow.h"
#include "PizzaClasses.h"
#include <iostream>
#include <QDebug>

ChoosePizzaWindow::ChoosePizzaWindow(ShoppingCart *cartPtr, QWidget *parent) : QWidget(parent),cart(cartPtr)
{


    QVBoxLayout *mainLayout = new QVBoxLayout;



    // -------------------------- label ------------------------- //
    QLabel *header = new QLabel(tr("Menu"));
    header->setAlignment(Qt::AlignHCenter);
    QFont font;
    font.setPointSize(22);
    header->setFont(font);
    mainLayout->addWidget(header);



    // -------------------------- menu button -------------------------- //
    for (int i = 0; i < Pizza::GetPizzaList().size(); ++i)
    {
        QPushButton *button = new QPushButton(Pizza::GetPizzaList()[i].GetName());
        button->setFont(QFont("Sans Serif", 14));
        button->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        connect(button, QPushButton::released, [i, this] {Pizza::GetPizzaList()[i].Select(); ShowWindow();});
        mainLayout->addWidget(button);
    }

    setLayout(mainLayout);
}

void ChoosePizzaWindow::ShowWindow(){
    PizzaWindow *addPizza = new PizzaWindow(cart);
    addPizza->show();
}
