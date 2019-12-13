#include "confirmwindow.h"
#include "shoppingcart.h"
#include "PizzaClasses.h"
#include <iomanip>
#include <iostream>

using namespace  std;


ShoppingCart::ShoppingCart(QWidget *parent) : QWidget(parent)

{
   //----------------------- koszyk ---------------------------------//



    // ------------------- dodanie oplaty za dostawe do koszyka ------------------- //

    shoppingList = new QTreeWidget;
    deliveryItem = new QTreeWidgetItem;
    deliveryItem->setText(0, "1");
    deliveryItem->setText(1, "Dostawa");


    deliveryItem->setText(2, "7");



    // ----------------------- button usuwania elementu listy ------------------------- //
    QPushButton *deleteButton = new QPushButton(tr("Usuń z zamówienia"));
    QLabel *sumLabel = new QLabel(tr("Razem"));
    sumNumLabel = new QLabel(tr("0"));
    QHBoxLayout *sumRow = new QHBoxLayout;
    sumRow->addWidget(sumLabel);
    sumRow->addWidget(sumNumLabel);



    // ----------------- elementy listy ----------------- //
    shoppingList->setColumnCount(3);
    shoppingList->setHeaderHidden(true);
    shoppingList->setColumnWidth(0, 50);
    shoppingList->setColumnWidth(1, 300);
    shoppingList->setColumnWidth(2, 50);



    // -------------------------- Main -------------------------- //
    QVBoxLayout *mainLayout = new QVBoxLayout;

    mainLayout->addWidget(shoppingList);
    mainLayout->addLayout(sumRow);
    mainLayout->addWidget(deleteButton);
    mainLayout->setAlignment(deleteButton, Qt::AlignRight);
    connect(deleteButton, SIGNAL(released()), this, SLOT(DeleteLine()));
    setLayout(mainLayout);
}

ShoppingCart::~ShoppingCart()
{
    delete shoppingList;
    delete sumNumLabel;
}

void ShoppingCart::AddToCart(Merchandise* m)
{
    QTreeWidgetItem *newItem = new QTreeWidgetItem;
    newItem->setText(0, m->GetQuantityText());
    newItem->setText(1, m->GetNameText());
    newItem->setText(2, m->GetPriceText());
    newItem->setText(3, m->GetDescriptionText());
    shoppingList->addTopLevelItem(newItem);
    UpdateSum();
}

void ShoppingCart::UpdateSum()
{
    QString amount;
    int sum = 0;

    for(int i = 0; i < shoppingList->topLevelItemCount(); i++)
    {
         amount = shoppingList->topLevelItem(i)->text(2);
         sum += amount.toInt();
    }

    sumNumLabel->setText(QString::number(sum));
}

void ShoppingCart::DeliveryFee(bool delivery)
{
    if (delivery)
    {
        if (deliveryItem == NULL)
        {
            deliveryItem = new QTreeWidgetItem;
            deliveryItem->setText(0,"1");
            deliveryItem->setText(1,"Dostawa");
            deliveryItem->setText(2,"7");
        }

        shoppingList->addTopLevelItem(deliveryItem);
    }
    else
    {
        delete deliveryItem;
        deliveryItem = NULL;
    }
}





void ShoppingCart::CreateReceipt(ofstream &receipt)
{

    if (receipt.is_open())
    {
        ReceiptHeader(receipt);

        for (int i = 0; i < shoppingList->topLevelItemCount(); i++)
        {
            receipt << setw(8) << left << GetQuantityString(i)
                    << setw(40) << left << GetNameString(i)
                    << setw(7) << right << GetPriceString(i)

                    << setw(7) << right << "8%"
                    << "\n"
                    << GetDescriptionString(i)
                    << "\n";
        }

        ReceiptFooter(receipt);
    }
    else
    {
        qDebug() << "Nie mozna otworzyc pliku.";
    }
}

int ShoppingCart::GetNumItems()
{
    return shoppingList->topLevelItemCount();
}

string ShoppingCart::GetQuantityString(int itemIndex)
{
    return shoppingList->topLevelItem(itemIndex)->text(0).toStdString().append(" x");
}

string ShoppingCart::GetNameString(int itemIndex)
{
    return shoppingList->topLevelItem(itemIndex)->text(1).toStdString();
}

string ShoppingCart::GetPriceString(int itemIndex)
{
    return shoppingList->topLevelItem(itemIndex)->text(2).toStdString().append("zl");
}

string ShoppingCart::GetDescriptionString(int itemIndex)
{
    std::string description = shoppingList->topLevelItem(itemIndex)->text(3).toStdString();
    return description;
}

void ShoppingCart::ReceiptHeader(ofstream &receipt)
{
    time_t time = std::time(0);


    time = time + 1 * 60 * 60;



    receipt << "<*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*>\n";

    receipt << "                                                                       \n";

    receipt << "                          Knajpa u Wieśka                              \n";

    receipt << "                          Telefon: 0 700 00                            \n";

    receipt << "                 Adres: ul. Smaczna 66 Rzeszów 36-112                  \n";

    receipt << "                          nip: 111 222 333 4                           \n";

    receipt << "                                                                       \n";

    receipt << "<*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*>\n";




    receipt << setw(71) << right << std::put_time(std::gmtime(&time), "%c") <<"\n\n\n\n";

    receipt << setw(8) << left << "Sztuki" << setw(40) << left << "Opis" << setw(7) << right << "Cena" << setw(7) << right << "Vat" << "\n";

    receipt << "-----------------------------------------------------------------------\n";

}





void ShoppingCart::ReceiptFooter(ofstream &receipt)
{

    static double tax  = 0.08;
    receipt << "\n\n\n";

    receipt << "-----------------------------------------------------------------------\n\n";

    receipt << "\t\t\t\t\t\tRazem\n";

    receipt << "\t\t\t\t\t\t-------------\n";

    receipt << "\t\t\t\t\t\t" << sumNumLabel->text().toStdString() << "\n\n";

    receipt << "\t\t\t\t\t\tBezVat\n";

    receipt << "\t\t\t\t\t\t-------------\n";

    receipt << "\t\t\t\t\t\t" << QString::number(sumNumLabel->text().toInt() - sumNumLabel->text().toInt()*tax).toStdString() << "\n\n";

    receipt << "\t\t\t\t\t\tVat\n";

    receipt << "\t\t\t\t\t\t-------------\n";

    receipt << "\t\t\t\t\t\t" << QString::number(sumNumLabel->text().toInt()*tax).toStdString();

    receipt << "\n\n\n";

    receipt << "<*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*>\n";

    receipt << "                          Zapraszamy ponownie !!!                      \n";

    receipt << "                                Smacznego !                            \n";

    receipt << "<*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*>\n\n";
}


void ShoppingCart::DeleteLine()
{
    if (shoppingList->currentItem() != deliveryItem)
    {
        delete shoppingList->currentItem();
    }

    UpdateSum();
}

