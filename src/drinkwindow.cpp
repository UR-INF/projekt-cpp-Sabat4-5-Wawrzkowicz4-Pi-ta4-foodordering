#include "drinkwindow.h"
#include "modelclasses.h"

DrinkWindow::DrinkWindow(ShoppingCart *cartPtr,QWidget *parent) : QWidget(parent),cart(cartPtr)
{






    // -------------------------- label ------------------------- //
    QLabel *header = new QLabel(tr("Wybierz napój"));
    header->setAlignment(Qt::AlignHCenter);
    QFont font;
    font.setPointSize(15);
    header->setFont(font);



    // ------------------------ lista ------------------------ //
    drinkListView = new QListView;
    drinkListView->setModel(new DrinkListModel);



    // ---------------------- add button ----------------------- //
    QPushButton *addButton = new QPushButton(tr("Dodaj do koszyka"));
    connect(addButton,SIGNAL(released()),this,SLOT(AddItemToCart()));



    // ------------------------- Main --------------------------- //
    QVBoxLayout *mainLayout = new QVBoxLayout;
    QVBoxLayout *actionLayout = new QVBoxLayout;

    actionLayout->addWidget(addButton);
    mainLayout->addWidget(header);
    mainLayout->addWidget(drinkListView);
    mainLayout->addLayout(actionLayout);

    setLayout(mainLayout);
}
void DrinkWindow::AddItemToCart()
{
    Drink d = drinkListView->model()->data(drinkListView->currentIndex(), Qt::UserRole).value<Drink>();
    cart->AddToCart(&d);
}





















