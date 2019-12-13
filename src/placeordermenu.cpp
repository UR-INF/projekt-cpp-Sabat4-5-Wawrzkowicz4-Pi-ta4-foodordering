#include "placeordermenu.h"
#include "windows.h"
#include "PizzaClasses.h"
#include <fstream>
#include <string>

void PlaceOrderMenu::SetupData()
{
    // -------------------------- widok dostosowania zamowienia -------------------------- //



    auto salt = Ingredient::AddNew(tr("Salt"), Ingredient::NON_COMPONENT);
    auto yeast = Ingredient::AddNew(tr("Yeast"), Ingredient::NON_COMPONENT);


    auto riceFlour = Ingredient::AddNew(tr("Rice flour"), Ingredient::FLOUR);
    auto wheatFlour = Ingredient::AddNew(tr("Wheat flour"), Ingredient::FLOUR);


    // Pizza crusts
    auto italian = PizzaCrust::AddNew(tr("Włoska"), 1);
    auto american = PizzaCrust::AddNew(tr("Amerykańska"), 1.3);


    // Pizza sizes
    auto small = PizzaSize::AddNew(tr("Mała"), 0.7);
    auto medium = PizzaSize::AddNew(tr("Średnia"), 1);
    auto large = PizzaSize::AddNew(tr("Duża"), 1.3);

    // Toppings
    auto ham = Ingredient::AddNew(tr("Szynka"), 8, Ingredient::TOPPING, Ingredient::MIESO);
    auto beef = Ingredient::AddNew(tr("Wołowina"), 9, Ingredient::TOPPING, Ingredient::MIESO);
    auto mince = Ingredient::AddNew(tr("Tuńczyk"), 9, Ingredient::TOPPING, Ingredient::MIESO);
    auto bacon = Ingredient::AddNew(tr("Boczek"), 7, Ingredient::TOPPING, Ingredient::MIESO);
    auto chicken = Ingredient::AddNew(tr("Kurczak"), 7, Ingredient::TOPPING, Ingredient::MIESO);
    auto pepperoni = Ingredient::AddNew(tr("Pepperoni"), 7, Ingredient::TOPPING, Ingredient::MIESO);

    auto tacoMarinade = Ingredient::AddNew(tr("Klasyczny"), 4, Ingredient::TOPPING, Ingredient::SOS);
    auto kebabMarinade = Ingredient::AddNew(tr("Śmietanowo czosnkowy"), 4, Ingredient::TOPPING, Ingredient::SOS);
    auto tandooriMarinade = Ingredient::AddNew(tr("Serowy"), 4, Ingredient::TOPPING, Ingredient::SOS);

    auto corn = Ingredient::AddNew(tr("Kukurydza"), 3, Ingredient::TOPPING, Ingredient::WARZYWA);
    auto onions = Ingredient::AddNew(tr("Cebula"), 3, Ingredient::TOPPING, Ingredient::WARZYWA);
    auto tomatoes = Ingredient::AddNew(tr("Pomidory"), 3, Ingredient::TOPPING, Ingredient::WARZYWA);
    auto jalapenos = Ingredient::AddNew(tr("Jalapeno"), 3, Ingredient::TOPPING, Ingredient::WARZYWA);
    auto mushrooms = Ingredient::AddNew(tr("Pieczarki"), 3, Ingredient::TOPPING, Ingredient::WARZYWA);
    auto pineapples = Ingredient::AddNew(tr("Ananas"), 3, Ingredient::TOPPING, Ingredient::WARZYWA);
    auto blackOlives = Ingredient::AddNew(tr("Oliwki"), 3, Ingredient::TOPPING, Ingredient::WARZYWA);
    auto bellPeppers = Ingredient::AddNew(tr("Papryka"), 3, Ingredient::TOPPING, Ingredient::WARZYWA);

    auto cheddar = Ingredient::AddNew(tr("Cheddar"), 8, Ingredient::TOPPING, Ingredient::SER);
    auto mozzarella = Ingredient::AddNew(tr("Mozzarella"), 8, Ingredient::TOPPING, Ingredient::SER);

    auto basil = Ingredient::AddNew(tr("Bazylia"), Ingredient::TOPPING, Ingredient::DODATEK);
    auto chili = Ingredient::AddNew(tr("Chili"), Ingredient::TOPPING, Ingredient::DODATEK);
    auto oregano = Ingredient::AddNew(tr("Oregano"), Ingredient::TOPPING, Ingredient::DODATEK);
    auto garlicParmesanOil = Ingredient::AddNew(tr("Czosnek"), 0, Ingredient::TOPPING, Ingredient::DODATEK);

    // Drinks
    auto urge = Drink::AddNew(tr("Woda mineralna"), 4);
    auto cocaCola = Drink::AddNew(tr("Coca Cola"), 6);
    auto pepsi = Drink::AddNew(tr("Pepsi"), 6);
    auto fanta = Drink::AddNew(tr("Fanta"), 6);
    auto harnas = Drink::AddNew(tr("Harnaś"), 5);
    auto tatra = Drink::AddNew(tr("Tatra"), 5);


    // Margherita
    Pizza& margherita = Pizza::AddNew(tr("Margarita"));
    margherita.SetSize(medium);
    margherita.SetCrust(wheatFlour, italian);
    margherita.AddComponent(yeast);
    margherita.AddComponent(salt);
    margherita.AddComponent(mozzarella);
    margherita.AddComponent(basil);
    margherita.AddComponent(garlicParmesanOil);


    //Happy Chicken
    Pizza& happyChicken = Pizza::AddNew(tr("Kurczak Pizza"));
    happyChicken.SetSize(medium);
    happyChicken.SetCrust(wheatFlour, italian);
    happyChicken.AddComponent(yeast);
    happyChicken.AddComponent(salt);
    happyChicken.AddComponent(mozzarella);
    happyChicken.AddComponent(chicken);
    happyChicken.AddComponent(jalapenos);
    happyChicken.AddComponent(onions);
    happyChicken.AddComponent(tacoMarinade);


    // Default Kebab Pizza
    Pizza& kebabPizza = Pizza::AddNew(tr("Kebab Pizza"));
    kebabPizza.SetSize(medium);
    kebabPizza.SetCrust(wheatFlour, american);
    kebabPizza.AddComponent(yeast);
    kebabPizza.AddComponent(salt);
    kebabPizza.AddComponent(mozzarella);
    kebabPizza.AddComponent(chicken);
    kebabPizza.AddComponent(bellPeppers);
    kebabPizza.AddComponent(onions);
    kebabPizza.AddComponent(chili);
    kebabPizza.AddComponent(kebabMarinade);


    // Default Cat Free
    Pizza& catFreePizza = Pizza::AddNew(tr("Hawajska Pizza"));
    catFreePizza.SetSize(medium);
    catFreePizza.SetCrust(wheatFlour, american);
    catFreePizza.AddComponent(yeast);
    catFreePizza.AddComponent(salt);
    catFreePizza.AddComponent(mozzarella);
    catFreePizza.AddComponent(cheddar);
    catFreePizza.AddComponent(beef);
    catFreePizza.AddComponent(pineapples);
    catFreePizza.AddComponent(tomatoes);
    catFreePizza.AddComponent(oregano);
    catFreePizza.AddComponent(blackOlives);


    // Default Cow Hugger's
    Pizza& cowHuggersPizza = Pizza::AddNew(tr("Vege Pizza"));
    cowHuggersPizza.SetSize(medium);
    cowHuggersPizza.SetCrust(wheatFlour, italian);
    cowHuggersPizza.AddComponent(yeast);
    cowHuggersPizza.AddComponent(salt);
    cowHuggersPizza.AddComponent(mushrooms);
    cowHuggersPizza.AddComponent(corn);
    cowHuggersPizza.AddComponent(tomatoes);


    // Default Tree Hugger's
    Pizza& treeHuggersPizza = Pizza::AddNew(tr("Chłopska Pizza"));
    treeHuggersPizza.SetSize(medium);
    treeHuggersPizza.SetCrust(wheatFlour, italian);
    treeHuggersPizza.AddComponent(yeast);
    treeHuggersPizza.AddComponent(salt);
    treeHuggersPizza.AddComponent(beef);
    treeHuggersPizza.AddComponent(ham);
    treeHuggersPizza.AddComponent(pepperoni);
    treeHuggersPizza.AddComponent(mince);
    treeHuggersPizza.AddComponent(chicken);
    treeHuggersPizza.AddComponent(bacon);
    treeHuggersPizza.AddComponent(tandooriMarinade);


    // Default Tree Hugger's
    Pizza& test = Pizza::AddNew(tr("Test"));
    treeHuggersPizza.SetSize(medium);
    treeHuggersPizza.SetCrust(wheatFlour, italian);
    treeHuggersPizza.AddComponent(yeast);
    treeHuggersPizza.AddComponent(salt);
    treeHuggersPizza.AddComponent(beef);
    treeHuggersPizza.AddComponent(ham);
    treeHuggersPizza.AddComponent(pepperoni);
    treeHuggersPizza.AddComponent(mince);
    treeHuggersPizza.AddComponent(chicken);
    treeHuggersPizza.AddComponent(bacon);
    treeHuggersPizza.AddComponent(tandooriMarinade);
}


PlaceOrderMenu::PlaceOrderMenu(QWidget *parent)
    : QWidget(parent)
{



    SetupData();


    // ---------------------- Main ---------------------- //
    customerInfo = new CustomerInformation;
    cart = new ShoppingCart;
    deliveryPage = new DeliveryWindow(cart);
    deliveryPage->AllocateZipCode();
    pizzaPage = new ChoosePizzaWindow(cart);
    drinkPage = new DrinkWindow(cart);
    confirmPage = new ConfirmWindow(customerInfo);
    cart->hide();


    stackedWidget = new QStackedWidget;
    stackedWidget->addWidget(deliveryPage);
    stackedWidget->addWidget(pizzaPage);
    stackedWidget->addWidget(drinkPage);
    stackedWidget->addWidget(confirmPage);



    // ---------------------- Buttony do nawigacji ----------------------- //
    nextButton = new QPushButton(tr("Dalej"));
    prevButton = new QPushButton(tr("Wstecz"));

    prevButton->setEnabled(false);
    connect(nextButton, SIGNAL(released()), this, SLOT(NextPage()));
    connect(prevButton, SIGNAL(released()), this, SLOT(PrevPage()));



    // --------------------- Button koszyka ---------------------- //
    cartButton = new QPushButton(tr("Koszyk"));
    QDir cartunoPath = QDir::currentPath();
    cartunoPath.cd("img");
    cartButton->setIcon(QIcon(QPixmap(cartunoPath.filePath("cartuno.png"))));
    cartButton->setIconSize(QSize(15, 15));
    cartButton->setCheckable(true);
    connect(cartButton, SIGNAL(released()), this, SLOT(ShowShoppingCart()));




    QHBoxLayout * topRowLayout = new QHBoxLayout;
    topRowLayout->addWidget(cartButton);
    topRowLayout->setAlignment(cartButton, Qt::AlignRight);

    QHBoxLayout *pageLayout = new QHBoxLayout;
    pageLayout->addWidget(stackedWidget);

    QHBoxLayout *buttonsRow = new QHBoxLayout;
    buttonsRow->addWidget(prevButton);
    buttonsRow->addStretch(1);
    buttonsRow->addWidget(nextButton);



    // ------------------------- Main --------------------------- //
    mainLayout = new QVBoxLayout;
    mainLayout->addLayout(topRowLayout);
    mainLayout->addLayout(pageLayout);
    mainLayout->addWidget(cart);
    mainLayout->addLayout(buttonsRow);

    QDir pizzaLogo2Path = QDir::currentPath();
    pizzaLogo2Path.cd("img");
    this->setWindowIcon(QIcon(QPixmap(pizzaLogo2Path.filePath("pizzaLogo2.jpg"))));
    this->setFixedSize(500, 600);
    setLayout(mainLayout);
}

PlaceOrderMenu::~PlaceOrderMenu()
{

}

void PlaceOrderMenu::EnterLastWindow()
{

    connect(nextButton, SIGNAL(released()), this, SLOT(ConfirmOrder()));
    lastWindow = true;
    cartButton->hide();
    cart->show();


    customerInfo->name = deliveryPage->GetName();
    customerInfo->number = deliveryPage->GetPhone();
    customerInfo->delivery = deliveryPage->IsDelivery();
    customerInfo->zipCode = deliveryPage->GetZip();
    customerInfo->address = deliveryPage->GetAddress();
    customerInfo->state = deliveryPage->GetZip();

    if (customerInfo->IsDataValid() && cart->GetNumItems() > 0)
    {
        nextButton->setEnabled(true);
    }
    else
    {
        nextButton->setEnabled(false);
    }


    cart->DeliveryFee(customerInfo->delivery);


    confirmPage->SetCustomerInfo();
    nextButton->setText(tr("Potwierdź zamowienie"));
}

void PlaceOrderMenu::ExitLastWindow()
{

    disconnect(nextButton, SIGNAL(released()), this, SLOT(ConfirmOrder()));
    lastWindow = false;

    cartButton->show();
    cart->hide();
    nextButton->setText(tr("Dalej"));
}

void PlaceOrderMenu::NextPage()
{
    stackedWidget->setCurrentIndex(stackedWidget->currentIndex() + 1);

    if (stackedWidget->currentIndex() == stackedWidget->count() - 1)
    {
        EnterLastWindow();
    }
    else if (stackedWidget->currentIndex() != 0)
    {
        prevButton->setEnabled(true);
    }
}

void PlaceOrderMenu::PrevPage()
{

    stackedWidget->setCurrentIndex(stackedWidget->currentIndex() - 1);

    if (lastWindow)
    {
        nextButton->setEnabled(true);
        ExitLastWindow();
    }
}

void PlaceOrderMenu::ShowShoppingCart()
{
     cartButton->isChecked() ? cart->show() : cart->hide();
}

void PlaceOrderMenu::ConfirmOrder(){


    QString fName = customerInfo->name;
    QString linkToFile = QDir::currentPath();
    linkToFile.append("/receipts");
    QDir dir = linkToFile;

    if (!dir.exists())
    {
        dir.mkpath(".");
    }

    linkToFile = dir.absolutePath();


    SetCurrentDirectoryA(linkToFile.toStdString().c_str());


    fName.append(".txt");
    std::ofstream receipt;

    receipt.open(fName.toStdString().c_str());
    receipt << "";

    cart->CreateReceipt(receipt);

    receipt.close();
    linkToFile.append("/");


    linkToFile.append(fName);
    ShellExecuteA(NULL, "open", linkToFile.toStdString().c_str() , NULL, NULL, SW_SHOW);

    // Czyszczenie starych danych
    delete customerInfo;
    delete cart;

    // nowe koszyk i custInfo
    cart = new ShoppingCart;
    customerInfo = new CustomerInformation;


    mainLayout->insertWidget(mainLayout->count()-1,cart);
    ExitLastWindow();
    deliveryPage->ClearText();

    // powrot na poczatek programu
    stackedWidget->setCurrentIndex(0);

    exit(0);
}


















