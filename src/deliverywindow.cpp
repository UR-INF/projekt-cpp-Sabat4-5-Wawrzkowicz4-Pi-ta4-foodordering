#include "deliverywindow.h"
#include <fstream>
#include <QDebug>
#include <QFile>
#include <QDir>

using namespace std;


DeliveryWindow::DeliveryWindow(QWidget *parent) : QWidget(parent)
{
 //--------------------widok dostawy-----------------------//



    // ------------------- dostawa ------------------- //
    QLabel *header = new QLabel(tr("Wybierz sposób dostawy"));
    QFont font;
    font.setPointSize(15);
    header->setFont(font);

    QPushButton *deliveryButton = new QPushButton(tr("Dostawa do domu"));
    QPushButton *pickUpButton = new QPushButton(tr("Odbiór na miejscu"));

    pickUpButton->setFixedSize(130, 30);
    deliveryButton->setFixedSize(100, 30);

    connect(deliveryButton, SIGNAL(released()), this, SLOT(HomeDelivery()));
    connect(pickUpButton, SIGNAL(released()), this, SLOT(PickUp()));



    // --------------------- dane klienta --------------------- //
    QGroupBox *infoGroup = new QGroupBox(tr("Imię/nazwisko i telefon"));
    QVBoxLayout *infoLayout = new QVBoxLayout;

    QLabel *nameLabel = new QLabel(tr("Imię/nazwisko"));
    QLabel *phoneLabel = new QLabel(tr("Telefon"));

    nameLine = new QLineEdit;
    nameLine->setFixedSize(300, 20);
    phoneLine = new QLineEdit;
    phoneLine->setFixedSize(300, 20);


    QIntValidator* numberValidator = new QIntValidator(100000000, 999999999, this);
    phoneLine->setValidator(numberValidator);

    QHBoxLayout *nameRow = new QHBoxLayout;
    nameRow->addWidget(nameLabel);
    nameRow->addStretch(1);
    nameRow->addWidget(nameLine);

    QHBoxLayout *phoneRow = new QHBoxLayout;
    phoneRow->addWidget(phoneLabel);
    phoneRow->addStretch(1);
    phoneRow->addWidget(phoneLine);

    infoLayout->addLayout(nameRow);
    infoLayout->addLayout(phoneRow);
    infoGroup->setLayout(infoLayout);



    // ------------------------- adres ------------------------- //
    addressGroup = new QGroupBox(tr("Dane adresowe"));
    QVBoxLayout *addressLayout = new QVBoxLayout;

    QLabel *adressLabel = new QLabel(tr("Adres"));
    QLabel *zipCodeLabel = new QLabel(tr("Kod pocztowy"));
    QLabel *stateLabel = new QLabel(tr("Miasto"));

    addressLine = new QLineEdit;
    addressLine->setFixedSize(300, 20);

    zipCodeLine = new QLineEdit;
    zipCodeLine->setFixedSize(300, 20);


    QIntValidator* zipCodeValidator = new QIntValidator(0, 99999, this);
    zipCodeLine->setValidator(zipCodeValidator);

    stateLine = new QLineEdit;
    stateLine->setFixedSize(300, 20);
    stateLine->setEnabled(false);

    QHBoxLayout *addressRow = new QHBoxLayout;
    addressRow->addWidget(adressLabel);
    addressRow->addStretch();
    addressRow->addWidget(addressLine);

    QHBoxLayout *zipCodeRow = new QHBoxLayout;
    zipCodeRow->addWidget(zipCodeLabel);
    zipCodeRow->addStretch();
    zipCodeRow->addWidget(zipCodeLine);

    QHBoxLayout *stateRow = new QHBoxLayout;
    stateRow->addWidget(stateLabel);
    stateRow->addStretch();
    stateRow->addWidget(stateLine);

    addressLayout->addLayout(addressRow);
    addressLayout->addLayout(zipCodeRow);
    addressLayout->addLayout(stateRow);

    addressGroup->setLayout(addressLayout);
    addressGroup->hide();




    // -------------------- wyświetlanie wyboru -------------------- //
    QHBoxLayout *chooseRow = new QHBoxLayout;
    chooseRow->addWidget(deliveryButton);
    chooseRow->addWidget(pickUpButton);

    QHBoxLayout *alternativeRow = new QHBoxLayout;
    QLabel *text = new QLabel(tr("Wybrałeś: "));
    chosenAlternative = new QLabel(tr(""));
    alternativeRow->addWidget(text);
    alternativeRow->addWidget(chosenAlternative);



    // -------------------------- Main -------------------------- //
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(header);
    mainLayout->addLayout(chooseRow);
    mainLayout->addWidget(infoGroup);
    mainLayout->addWidget(addressGroup);
    mainLayout->addLayout(alternativeRow);

    mainLayout->setAlignment(header,Qt::AlignTop);
    mainLayout->setAlignment(chooseRow,Qt::AlignLeft);
    setLayout(mainLayout);

    PickUp();

    AllocateZipCode();

    connect(zipCodeLine, QLineEdit::textChanged,
    [this]
    {
        UpdateCity();
    });
}

QString DeliveryWindow::GetName()
{
    return nameLine->text();
}

QString DeliveryWindow::GetPhone()
{
    return phoneLine->text();
}

QString DeliveryWindow::GetAddress()
{
    return addressLine->text();
}

QString DeliveryWindow::GetZip()
{
    return zipCodeLine->text();
}

QString DeliveryWindow::GetState()
{
    return stateLine->text();
}

void DeliveryWindow::UpdateCity()
{

    auto it = zipCode.find(GetZip());

    if (it != zipCode.end())
    {
        stateLine->setText(it.value());
    }
    else
    {
        stateLine->setText("");
    }
}

void DeliveryWindow::ClearText()
{
    nameLine->clear();
    phoneLine->clear();
    addressLine->clear();
    stateLine->clear();
    zipCodeLine->clear();
}

void DeliveryWindow::AllocateZipCode()
{
    QDir path = QDir::currentPath();
    QFile file(path.absoluteFilePath("zipcodes.txt"));

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Nie można otworzyc listy adresów.";
        return;
    }

    QTextStream input(&file);
    while (!input.atEnd())
    {
        QString line = input.readLine();
        QStringList list = line.split('\t');

        zipCode[list.at(0)] = list.at(1);
    }

    file.close();
}

bool DeliveryWindow::IsDelivery()
{
    return delivery;
}

void DeliveryWindow::PickUp()
{
    delivery = false;
    addressGroup->hide();
    chosenAlternative->setText(tr("Odbiór na miejscu"));
}

void DeliveryWindow::HomeDelivery()
{
    delivery = true;
    addressGroup->show();
    chosenAlternative->setText(tr("Dostawa do domu"));
}














