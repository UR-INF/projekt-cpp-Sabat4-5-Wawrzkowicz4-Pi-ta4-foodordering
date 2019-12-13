#include "confirmwindow.h"

ConfirmWindow::ConfirmWindow(CustomerInformation *clientPtr, QWidget *parent)
    : QWidget(parent),clientInfo(clientPtr)
{



    // ------------------------- label ------------------------- //
    QLabel *nameLabel = new QLabel(tr("Imię/nazwisko"));
    QLabel *phoneLabel = new QLabel(tr("Telefon"));
    QLabel *addressLabel = new QLabel(tr("Adres dostawy"));
    QLabel *zipLabel = new QLabel(tr("Kod Pocztowy"));
    QLabel *stateLabel = new QLabel(tr("Miasto"));

    name = new QLabel;
    phone = new QLabel;
    address = new QLabel;
    state = new QLabel;
    zip = new QLabel;

    QHBoxLayout *nameRow = new QHBoxLayout;
    nameRow->addWidget(nameLabel);
    nameRow->addWidget(name);

    QHBoxLayout *zipRow = new QHBoxLayout;
    zipRow->addWidget(zipLabel);
    zipRow->addWidget(zip);

    QHBoxLayout *addressRow = new QHBoxLayout;
    addressRow->addWidget(addressLabel);
    addressRow->addWidget(address);

    QHBoxLayout *stateRow = new QHBoxLayout;
    stateRow->addWidget(stateLabel);
    stateRow->addWidget(state);

    QHBoxLayout *phoneRow = new QHBoxLayout;
    phoneRow->addWidget(phoneLabel);
    phoneRow->addWidget(phone);



    // -------------------------- dane osobowe --------------------------- //
    infoGroup = new QGroupBox;
    QVBoxLayout *infoLayout = new QVBoxLayout;

    infoLayout->addLayout(nameRow);
    infoLayout->addLayout(phoneRow);

    infoGroup->setLayout(infoLayout);
    infoGroup->setFixedSize(400,50);



    // ---------------------- dane dostawy --------------------- //
    deliveryGroup = new QGroupBox;
    QVBoxLayout *deliveryLayout = new QVBoxLayout;
    deliveryLayout->addLayout(addressRow);
    deliveryLayout->addLayout(stateRow);
    deliveryLayout->addLayout(zipRow);

    deliveryGroup->setLayout(deliveryLayout);
    deliveryGroup->setFixedSize(400,80);



    // -------------------------- Main  -------------------------- //
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(infoGroup);
    mainLayout->addWidget(deliveryGroup);
    setLayout(mainLayout);   
}

void ConfirmWindow::SetCustomerInfo()
{


    name->setText(clientInfo->name);
    phone->setText(clientInfo->number);
    state->setText(clientInfo->state);
    address->setText(clientInfo->address);
    zip->setText(clientInfo->zipCode);


    clientInfo->delivery?deliveryGroup->show():deliveryGroup->hide();
}
















