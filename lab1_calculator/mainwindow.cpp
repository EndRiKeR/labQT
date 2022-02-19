 #include "mainwindow.h"

//Системыне функции
MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowFlags(Qt::WindowCloseButtonHint);
    houstonConnectButtonPLS();
    enableFunctions(0);
    enablePoint(1);
    std::cout << std::endl;
}

MainWindow::~MainWindow()
{
    delete ui;
}

//Все подключения
void MainWindow::houstonConnectButtonPLS()
{
    //Решение бага с двойным подключением: Qt автоматически подключает такие названия.
    //Например, есть кнопка ui->name и если просто создать слот с именем on_name_clicked(),
    //то Qt сам подключит сигнал clicked() к этому слоту внутри вызова ui->setupUi(this).
    //Поэтому, можно либо переименовать название слота, либо не подключать его вручную.
    //www.cyberforum.ru by Humanoid
    connect(ui->btn_0, &QPushButton::clicked, this, &MainWindow::on_btn_numeric_clicked);
    connect(ui->btn_1, &QPushButton::clicked, this, &MainWindow::on_btn_numeric_clicked);
    connect(ui->btn_2, &QPushButton::clicked, this, &MainWindow::on_btn_numeric_clicked);
    connect(ui->btn_3, &QPushButton::clicked, this, &MainWindow::on_btn_numeric_clicked);
    connect(ui->btn_4, &QPushButton::clicked, this, &MainWindow::on_btn_numeric_clicked);
    connect(ui->btn_5, &QPushButton::clicked, this, &MainWindow::on_btn_numeric_clicked);
    connect(ui->btn_6, &QPushButton::clicked, this, &MainWindow::on_btn_numeric_clicked);
    connect(ui->btn_7, &QPushButton::clicked, this, &MainWindow::on_btn_numeric_clicked);
    connect(ui->btn_8, &QPushButton::clicked, this, &MainWindow::on_btn_numeric_clicked);
    connect(ui->btn_9, &QPushButton::clicked, this, &MainWindow::on_btn_numeric_clicked);
    connect(ui->btn_plus, &QPushButton::clicked, this, &MainWindow::on_btn_move_clicked);
    connect(ui->btn_minus, &QPushButton::clicked, this, &MainWindow::on_btn_move_clicked);
    connect(ui->btn_mult, &QPushButton::clicked, this, &MainWindow::on_btn_move_clicked);
    connect(ui->btn_divide, &QPushButton::clicked, this, &MainWindow::on_btn_move_clicked);
    connect(ui->btn_clear, &QPushButton::clicked, this, &MainWindow::clear_clicked);
    connect(ui->btn_delete, &QPushButton::clicked, this, &MainWindow::delete_clicked);
    connect(ui->btn_result, &QPushButton::clicked, this, &MainWindow::result_clicked);
}

//Окна вне калькулятора
void MainWindow::infoForUser() //Сообщение, в котором объясняется работа калькулятора
{
    std::ifstream readMeFile("D:/progectsForCPP/labQT/lab1_calculator/READ_ME");
    std::string temp;
    std::string str;
    if (readMeFile.is_open()) {
        while (getline(readMeFile, temp)) {
            str += temp;
            str += '\n';
        }
    }
    QMessageBox msgBox;
    msgBox.setText("Используя этот калькулятор Вы соглашаетесь с условиями пользовательского соглашения.");
    msgBox.setInformativeText("Вы согласны?");
    msgBox.setDetailedText(str.c_str());
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::Yes);
    int answer = msgBox.exec();
    switch (answer) {
    case QMessageBox::Yes:
        break;
    case QMessageBox::No:
        QMessageBox::information(0, "ERROR", "Очень жаль.");
        MainWindow::~MainWindow();
        break;
    default:
        MainWindow::~MainWindow();
        break;
    }
}

//Функции кнопок
//Эта функция отслеживает нажатие на циферки и текущее число
void MainWindow::on_btn_numeric_clicked()
{
    QPushButton* btn = (QPushButton *)sender();
    md.valueUser = atof(btn->text().toStdString().c_str());
    md.operationType = Add;
    updateLabel(btn);
    doMath(&md);
    outputMD();
    enableFunctions(1);
    if (md.MoveNext == None) {
        enableResult(0);
    }
    if (md.point) {
        enablePoint(0);
    }
    textErrorsChecker();
}

//Точка в числе
void MainWindow::on_btn_point_clicked()
{
    QPushButton* btn = (QPushButton *)sender();
    md.operationType = Point;
    doMath(&md);
    updateLabel(btn);
    outputMD();
    enableFunctions(0);
    enableDelete(1);
    textErrorsChecker();
}

// Удаление
void MainWindow::delete_clicked()
{
    QPushButton* btn = (QPushButton *)sender();
    md.operationType = Del;
    updateLabel(btn);
    if (myContainCharItStr(ui->lbl_main->text().toStdString(), '.')) {
        md.point = true;
    } else {
        md.point = false;
        md.pointDeep = 0;
        enablePoint(1);
    }
    md.visual = ui->lbl_main->text().toStdString();
    doMath(&md);
    outputMD();
    textErrorsChecker();
}

//Общая функция для всех действий
void MainWindow::on_btn_move_clicked()
{
    QPushButton* btn = (QPushButton *)sender();
    switch (btn->text().toStdString()[0]) {
    case '+':
        md.operationType = Plus;
        break;
    case '-':
        md.operationType = Minus;
        break;
    case '/':
        md.operationType = Div;
        break;
    case '*':
        md.operationType = Mult;
        break;
    default:
        ui->lbl_main->setText("Ошибка в действиях");
        break;
    }
    doMath(&md);
    logicErrors("Вы попытались поделить на ноль.\nПокайтесь и начните заново.", btn);
    outputMD();
    enableMoves(0);
    enableNum(1);
    textErrorsChecker();
}

//Вывод результата
void MainWindow::result_clicked()
{
    QPushButton* btn = (QPushButton *)sender();
    md.operationType = Res;
    doMath(&md);
    logicErrors("Вы попытались поделить на ноль.\nПокайтесь и начните заново.", btn);
    outputMD();
    enableFunctions(0);
    enableNum(0);
    textErrorsChecker();
}

//Очистка
void MainWindow::clear_clicked()
{
    QPushButton* btn = (QPushButton *)sender();
    md.operationType = Clear;
    doMath(&md);
    updateLabel(btn);
    outputMD();

    enableFunctions(0);
    enablePoint(1);
    enableNum(1);
}

//С плюса на минус и наоборот
void MainWindow::on_btn_swap_clicked()
{
    QPushButton* btn = (QPushButton *)sender();
    md.operationType = Swap;
    doMath(&md);
    updateLabel(btn);
    outputMD();
    textErrorsChecker();
}

//Обратное число от числа
void MainWindow::on_btn_werewolf_clicked()
{
    QPushButton* btn = (QPushButton *)sender();
    md.operationType = Werewolf;
    doMath(&md);
    logicErrors("Вы попытались поделить на ноль.\nПокайтесь и начните заново.", btn);
    enableResult(0);
    enablePoint(0);
    enableDelete(0);
    enableNum(0);
    if (md.MoveNext != None) {
        enableResult(1);
    }
    textErrorsChecker();
    outputMD();
}

//Корень от числа
void MainWindow::on_btn_sqrt_clicked()
{
    QPushButton* btn = (QPushButton *)sender();
    md.operationType = Sqrt;
    doMath(&md);
    logicErrors("Вы попытались взять корень от отрицательного числа.\nПокайтесь и начните заново.", btn);
    enableResult(0);
    enablePoint(0);
    enableDelete(0);
    enableNum(0);
    if (md.MoveNext != None) {
        enableResult(1);
    }
    textErrorsChecker();
    outputMD();
}

//Возведение во вторую степень
void MainWindow::on_btn_pow2_clicked()
{
    QPushButton* btn = (QPushButton *)sender();
    md.operationType = Pow;
    doMath(&md);
    updateLabel(btn);
    enableResult(0);
    enablePoint(0);
    enableDelete(0);
    enableNum(0);
    if (md.MoveNext != None) {
        enableResult(1);
    }
    textErrorsChecker();
    outputMD();
}

//Работа с памятью
//Добавить число в память
void MainWindow::on_btn_m_plus_clicked()
{
    md.operationType = MPlus;
    doMath(&md);
    outputMD();
    textErrorsChecker();
}

//Вычесть число из памяти
void MainWindow::on_btn_m_minus_clicked()
{
    md.operationType = MMinus;
    doMath(&md);
    outputMD();
    textErrorsChecker();
}

//Вывести результат памяти
void MainWindow::on_btn_mr_clicked()
{
    QPushButton* btn = (QPushButton *)sender();
    md.operationType = MResult;
    doMath(&md);
    updateLabel(btn);
    enableFunctions(0);
    enableMoves(1);
    enableNum(0);
    if (md.MoveNext != None) {
        enableResult(1);
    }
    textErrorsChecker();
    outputMD();
}

//Очистить память
void MainWindow::on_btn_mc_clicked()
{
    QPushButton* btn = (QPushButton *)sender();
    md.operationType = MClear;
    doMath(&md);
    updateLabel(btn);
    outputMD();
    textErrorsChecker();
}

//Далее идут функции для группого и не очень включения/выключения кнопок
void MainWindow::enableMoves(int i)
{
    ui->btn_minus->setEnabled(i);
    ui->btn_plus->setEnabled(i);
    ui->btn_mult->setEnabled(i);
    ui->btn_divide->setEnabled(i);
}

void MainWindow::enableDelete(int i)
{
    ui->btn_delete->setEnabled(i);
}

void MainWindow::enableResult(int i)
{
    ui->btn_result->setEnabled(i);
}

void MainWindow::enablePoint(int i)
{
    ui->btn_point->setEnabled(i);
}

//Отключить числовую панель
void MainWindow::enableNum(int i)
{
    ui->btn_0->setEnabled(i);
    ui->btn_1->setEnabled(i);
    ui->btn_2->setEnabled(i);
    ui->btn_3->setEnabled(i);
    ui->btn_4->setEnabled(i);
    ui->btn_5->setEnabled(i);
    ui->btn_6->setEnabled(i);
    ui->btn_7->setEnabled(i);
    ui->btn_8->setEnabled(i);
    ui->btn_9->setEnabled(i);
}

//Вкл\выкл функций памяти
void MainWindow::enableMFunctions(int i)
{
    ui->btn_m_minus->setEnabled(i);
    ui->btn_m_plus->setEnabled(i);
    ui->btn_mr->setEnabled(i);
    ui->btn_mc->setEnabled(i);
}

//Вкл\выкл всех функций в целом
void MainWindow::enableFunctions(int i)
{
    enablePoint(i);
    enableMoves(i);
    enableResult(i);
    enableDelete(i);
    enableMFunctions(i);
    ui->btn_swap->setEnabled(i);
    ui->btn_werewolf->setEnabled(i);
    ui->btn_sqrt->setEnabled(i);
    ui->btn_pow2->setEnabled(i);
}

//Отключение всех кнопок, кроме (С)
void MainWindow::enableAllBtn(int i)
{
    enableFunctions(i);
    enableNum(i);
}

//Вспомогательные функции, которые заменяют реально существующие или помогающие с дебагом и ошибками
//Вывод структуры mathData
void MainWindow::outputMD()
{
    std::cout << "Value Now: " << md.valueNow << std::endl
              << "Value Res: " << md.valueRes << std::endl
              << "Value User: " << md.valueUser << std::endl
              << "Op type: " << md.operationType << std::endl
              << "Next move type: " << md.MoveNext << std::endl
              << "Memory: " << md.memory.valueNow << std::endl
              << "Point: " << md.point << std::endl
              << "Point deep: " << md.pointDeep << std::endl
              << "Error: " << md.error << std::endl << std::endl;
}

//Проверка на излишне большой текст (15+ символов)
bool MainWindow::checkBigText()
{
    bool result = false;
    if (ui->lbl_main->text().size() > 15 && md.operationType == Add) { // 15 знаков
        result = true;
    }
    if (md.valueNow > 1e+14 || md.valueNow < -1e+14) {
        result = true;
    }
    if (md.memory.valueNow > 1e+14 || md.memory.valueNow < -1e+14) {
        result = true;
    }
    return result;
}

//Вынесение повторяющего куска кода с проверкой на ошибки
void MainWindow::textErrorsChecker()
{
    if (checkBigText()) {
        enableAllBtn(0);
        ui->lbl_main->setText("REALLY?");
        QMessageBox::information(0, "ERROR", "Слишком большой текст.\nПокайтесь и начните заново.");
    }
}

//Проверки на логические ошибки
void MainWindow::logicErrors(QString str, QPushButton* btn)
{
    if (!md.error) {
        updateLabel(btn);
    } else {
        enableAllBtn(0);
        ui->lbl_main->setText("REALLY?");
        QMessageBox::information(0, "ERROR", str);
    }
}

//.contains() доступен только в C++25 (cppreference.com) :(
bool myContainCharItStr(std::string str, const char& ch)
{
    bool result = false;
    for (size_t i = 0; i < str.size(); ++i) {
        if (str[i] == ch) {
            result = true;
            break;
        }
    }
    return result;
}
