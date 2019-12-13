#include "pizzawindow.h"
#include "PizzaClasses.h"
#include "modelclasses.h"
#include <QtGlobal>


PizzaWindow::PizzaWindow(ShoppingCart *cartPtr,QWidget *parent) : QWidget(parent), cart(cartPtr)
{

    setWindowFlags(Qt::WindowTitleHint);
    pizza = Pizza::GetSelectedPizza();


    // ---------------------- Opis ------------------------ //
    QLabel *description = new QLabel(Pizza::GetSelectedPizza().GetName());
    description->setFont(QFont("Courier", 16, QFont::Bold, true));

    QFrame *descriptionLine;
    descriptionLine = new QFrame;
    descriptionLine->setFrameShape(QFrame::HLine);
    descriptionLine->setFrameShadow(QFrame::Sunken);

    QVBoxLayout *descriptionRow = new QVBoxLayout;
    descriptionRow->addWidget(description);
    descriptionRow->addWidget(descriptionLine);



    // --------------------- Rozmiar pizzy ---------------------- //
    QHBoxLayout *typeAndSizeLayout = new QHBoxLayout;
    QVBoxLayout *sizeLayout = new QVBoxLayout;
    typeAndSizeLayout->addLayout(sizeLayout);

    QLabel *sizeLabel = new QLabel(tr("Rozmiar"));
    sizeLayout->addWidget(sizeLabel);

    QAbstractItemModel* pizzaSizeModel = new PizzaSizeListModel();
    pizzaSize = new QComboBox;
    pizzaSize->setModel(pizzaSizeModel);
    pizzaSize->setCurrentIndex(pizza.GetPizzaSize().GetId());
    sizeLayout->addWidget(pizzaSize);

    connect(pizzaSize, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
    [this]
    {
        PizzaSize ps = pizzaSize->itemData(pizzaSize->currentIndex()).value<PizzaSize>();
        pizza.SetSize(ps);
        CalculatePrice();
    });



    // ---------------------- rodzaj ciasta -------------------- //
    QVBoxLayout *crustLayout = new QVBoxLayout;
    typeAndSizeLayout->addLayout(crustLayout);

    QLabel *pizzaDoughLabel = new QLabel(tr("Ciasto"));
    crustLayout->addWidget(pizzaDoughLabel);

    QAbstractItemModel* pizzaCrustModel = new PizzaCrustListModel();
    pizzaCrust = new QComboBox;
    pizzaCrust->setModel(pizzaCrustModel);
    pizzaCrust->setCurrentIndex(pizza.GetPizzaCrust().GetId());
    crustLayout->addWidget(pizzaCrust);

    connect(pizzaCrust, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
    [this]
    {
        PizzaCrust pc = pizzaCrust->itemData(pizzaCrust->currentIndex()).value<PizzaCrust>();
        pizza.SetCrust(pc);
        CalculatePrice();
    });



    // ---------------------- ilosc ----------------------- //
    QHBoxLayout *priceAndQuantityLayout = new QHBoxLayout;
    QVBoxLayout *quantityLayout = new QVBoxLayout;
    priceAndQuantityLayout->addLayout(quantityLayout);

    QLabel *quantityLabel = new QLabel(tr("Ilość"));
    quantityLabel->setAlignment(Qt::AlignCenter);
    quantityLabel->setFont(QFont("Sans Serif", 14));
    quantityLayout->addWidget(quantityLabel);

    QHBoxLayout *quantityDisplayLayout = new QHBoxLayout;
    QPushButton *reduceQuantityButton = new QPushButton("-");
    reduceQuantityButton->setMaximumWidth(25);
    quantityDisplayLayout->addWidget(reduceQuantityButton);
    quantityDisplayLayout->addStretch();

    quantityDisplay = new QLabel(QString::number(pizza.GetQuantity()));
    quantityDisplay->setAlignment(Qt::AlignCenter);
    quantityDisplay->setFont(QFont("Sans Serif", 14));
    quantityDisplayLayout->addWidget(quantityDisplay);

    QPushButton *increaseQuantityButton = new QPushButton("+");
    increaseQuantityButton->setMaximumWidth(25);
    quantityDisplayLayout->addWidget(increaseQuantityButton);
    quantityLayout->addLayout(quantityDisplayLayout);

    connect(increaseQuantityButton, QPushButton::clicked,
    [this]
    {
        pizza.IncrementQuantity();
        quantityDisplay->setText(QString::number(pizza.GetQuantity()));
        CalculatePrice();
    });

    connect(reduceQuantityButton, QPushButton::clicked,
    [this]
    {
        pizza.DecrementQuantity();
        quantityDisplay->setText(QString::number(pizza.GetQuantity()));
        CalculatePrice();
    });



    // ------------------------- cena ------------------------- //
    QVBoxLayout *priceLayout = new QVBoxLayout;
    priceAndQuantityLayout->addStretch();
    priceAndQuantityLayout->addSpacing(75);
    priceAndQuantityLayout->addLayout(priceLayout);

    QLabel *priceLabel = new QLabel(tr("Cena"));
    priceLabel->setFont(QFont("Sans Serif", 14));
    priceLabel->setAlignment(Qt::AlignCenter);
    priceLayout->addWidget(priceLabel);

    priceDisplay = new QLabel("");
    priceDisplay->setAlignment(Qt::AlignCenter);
    priceDisplay->setFont(QFont("Sans Serif", 14));
    priceLayout->addWidget(priceDisplay);



    // --------------------- edycja pizzy --------------------- //
    QGroupBox *bottomGroupBox = new QGroupBox;
    QGridLayout *bottomLayout = new QGridLayout;


    for (int i = 1; i < Ingredient::TOTAL_NUM_TOPPING_TYPES; ++i)
    {
        QLabel *l = new QLabel(Ingredient::GetToppingTypeString((Ingredient::ToppingType)i));
        bottomLayout->addWidget(l, 0, i);
    }



    QVector<int> numRows(Ingredient::TOTAL_NUM_TOPPING_TYPES, 1);

    for (Ingredient i : Ingredient::GetIngredientList())
    {
        if (i.GetIngredientType() == Ingredient::TOPPING)
        {
            QCheckBox *c = new QCheckBox(i.GetName());
            bottomLayout->addWidget(c, numRows[i.GetToppingType()], i.GetToppingType());
            ++numRows[i.GetToppingType()];

            if (pizza.ContainsIngredient(i))
            {
                c->setChecked(true);
            }

            connect(c, QCheckBox::stateChanged,
            [&,this,i,c]
            {
                if (c->isChecked())
                    pizza.AddComponent(i);
                else
                    pizza.RemoveComponent(i);
                CalculatePrice();
            });
        }
    }

    bottomGroupBox->setLayout(bottomLayout);



    // ----------------- dodanie do koszyka ------------------ //
    QPushButton *exitButton = new QPushButton(tr("Anuluj"));
    QPushButton *addButton = new QPushButton(tr("Dodaj do koszyka"));

    connect(exitButton, SIGNAL(released()), this, SLOT(Exit()));
    connect(addButton, SIGNAL(released()), this, SLOT(AddOrder()));
    QHBoxLayout *buttonsRow = new QHBoxLayout;
    buttonsRow->addWidget(exitButton);



    // ------------------------- Main --------------------------- //
    QGroupBox *topLeftGroupBox = new QGroupBox;
    QVBoxLayout *topLeftLayout = new QVBoxLayout;
    topLeftLayout->addLayout(descriptionRow);
    topLeftLayout->addStretch();
    topLeftLayout->addLayout(typeAndSizeLayout);
    topLeftLayout->addLayout(buttonsRow);
    topLeftGroupBox->setLayout(topLeftLayout);

    QGroupBox *topRightGroupBox = new QGroupBox;
    QVBoxLayout *topRightLayout = new QVBoxLayout;
    topRightLayout->addLayout(priceAndQuantityLayout);
    topRightLayout->addStretch();
    topRightLayout->addWidget(addButton);
    topRightGroupBox->setLayout(topRightLayout);

    QHBoxLayout *topLayout = new QHBoxLayout;
    topLayout->addWidget(topLeftGroupBox);
    topLayout->addWidget(topRightGroupBox);

    mainLayout = new QVBoxLayout(this);
    mainLayout->addLayout(topLayout);
    mainLayout->addWidget(bottomGroupBox);

    setWindowTitle(description->text());
    setLayout(mainLayout);


    CalculatePrice();
}

PizzaWindow::~PizzaWindow()
{
}

void PizzaWindow::AddOrder()
{
    cart->AddToCart(&pizza);
    Exit();
}

void PizzaWindow::CalculatePrice()
{


    int price = pizza.GetPrice();
    priceDisplay->setText(QString::number(price).append("zł"));
}

void PizzaWindow::Exit()
{
    delete this;
}














