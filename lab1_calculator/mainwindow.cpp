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
    std::ifstream readMeFile("E:/myProgects/labQT/lab1_calculator/READ_ME");
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

void MainWindow::updateLabel(QPushButton* btn)
{
    QString str = ui->lbl_main->text();
    if (btn != nullptr) {
        switch(md.operationType) {
        case Add:
            if (str != "0" && md.valueNow != 0.0) {
                ui->lbl_main->setText(str + btn->text());
            } else {
                ui->lbl_main->setText(btn->text());
            }
            break;
        case Point:
            ui->lbl_main->setText(str + btn->text());
            break;
        case Del:
            if (str.size() > 1) {
                ui->lbl_main->setText(QString::fromStdString(str.toStdString().substr(0, str.size() - 1)));
            } else {
                ui->lbl_main->setText("0");
            }
            break;
        case Plus:
            ui->lbl_main->setText(QString::number(md.valueRes, 'g', 15));
            break;
        case Minus:
            ui->lbl_main->setText(QString::number(md.valueRes, 'g', 15));
            break;
        case Div:
            ui->lbl_main->setText(QString::number(md.valueRes, 'g', 15));
            break;
        case Mult:
            ui->lbl_main->setText(QString::number(md.valueRes, 'g', 15));
            break;
        case Res:
            ui->lbl_main->setText(QString::number(md.valueRes, 'g', 15));
            break;
        case Clear:
            ui->lbl_main->setText(QString::number(md.valueNow, 'g', 15));
            break;
        case Swap:
            ui->lbl_main->setText(QString::number(md.valueNow, 'g', 15));
            break;
        case Werewolf:
            ui->lbl_main->setText(QString::number(md.valueNow, 'g', 15));
            break;
        case Sqrt:
            ui->lbl_main->setText(QString::number(md.valueNow, 'g', 15));
            break;
        case Pow:
            ui->lbl_main->setText(QString::number(md.valueNow, 'g', 15));
            break;
        case MResult:
            ui->lbl_main->setText(QString::number(md.valueNow, 'g', 15));
            break;
        case MClear:
            ui->lbl_main->setText(QString::number(md.valueNow, 'g', 15));
            break;
        default:
            ui->lbl_main->setText("Ошибка выведения");
            break;
        }
    } else {
        ui->lbl_main->setText("Ошибка указателя на кнопку");
    }

}

void MainWindow::outputMD()
{
    std::cout << "Value Now: " << md.valueNow << std::endl
              << "Value Res: " << md.valueRes << std::endl
              << "Value User: " << md.valueUser << std::endl
              << "Op type: " << md.operationType << std::endl
              << "Next move type: " << md.MoveNext << std::endl
              << "Memory: " << md.memory.valueNow << std::endl
              << "Point deep: " << md.pointDeep << std::endl << std::endl;
}

//Функции кнопок
void MainWindow::on_btn_numeric_clicked() //Эта функция отслеживает нажатие на циферки и текущее число
{
    QPushButton* btn = (QPushButton *)sender();
    md.valueUser = atof(btn->text().toStdString().c_str());
    md.operationType = Add;
    updateLabel(btn);
    doMath(&md);
    outputMD();

    enableFunctions(1);
    if (md.MoveNext == 'None') {
        enableResult(0);
    }

}

void MainWindow::on_btn_point_clicked() //Точка в числе
{
    QPushButton* btn = (QPushButton *)sender();
    md.operationType = Point;
    doMath(&md);
    updateLabel(btn);
    outputMD();

    enablePoint(0);
}

bool MyContainCharItStr(std::string str, const char& ch)
{
    bool result = false;
    for (size_t i = str.size() - 1; i >= 0; --i) {
        if (str[i] == ch) {
            result = true;
            break;
        }
    }
    return result;
}

void MainWindow::delete_clicked() // Удаление
{
    QPushButton* btn = (QPushButton *)sender();
    md.operationType = Del;
    updateLabel(btn);
    if (MyContainCharItStr(ui->lbl_main->text().toStdString(), '.')) {
        md.point = true;
    } else {
        md.point = false;
        md.pointDeep = 0;
    }
    doMath(&md);
    outputMD();
}

void MainWindow::on_btn_move_clicked() //Общая функция для всех действий
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
    updateLabel(btn);
    outputMD();

    enableMoves(0);
}

void MainWindow::result_clicked() //Вывод результата
{
    QPushButton* btn = (QPushButton *)sender();
    md.operationType = Res;
    doMath(&md);
    updateLabel(btn);
    outputMD();

    enableFunctions(0);
}

void MainWindow::clear_clicked() //Очистка
{
    QPushButton* btn = (QPushButton *)sender();
    md.operationType = Clear;
    doMath(&md);
    updateLabel(btn);
    outputMD();

    enableFunctions(0);
    enablePoint(0);
}

void MainWindow::on_btn_swap_clicked()
{
    QPushButton* btn = (QPushButton *)sender();
    md.operationType = Swap;
    doMath(&md);
    updateLabel(btn);
    outputMD();
}

void MainWindow::on_btn_werewolf_clicked()
{
    QPushButton* btn = (QPushButton *)sender();
    md.operationType = Werewolf;
    doMath(&md);
    updateLabel(btn);
    outputMD();
}

void MainWindow::on_btn_sqrt_clicked()
{
    QPushButton* btn = (QPushButton *)sender();
    md.operationType = Sqrt;
    doMath(&md);
    updateLabel(btn);
    outputMD();
}

void MainWindow::on_btn_pow2_clicked()
{
    QPushButton* btn = (QPushButton *)sender();
    md.operationType = Pow;
    doMath(&md);
    updateLabel(btn);
    outputMD();
}

void MainWindow::on_btn_m_plus_clicked()
{
    md.operationType = MPlus;
    doMath(&md);
    outputMD();
}

void MainWindow::on_btn_m_minus_clicked()
{
    md.operationType = MMinus;
    doMath(&md);
    outputMD();
}

void MainWindow::on_btn_mr_clicked()
{
    QPushButton* btn = (QPushButton *)sender();
    md.operationType = MResult;
    doMath(&md);
    updateLabel(btn);
    outputMD();
}

void MainWindow::on_btn_mc_clicked()
{
    QPushButton* btn = (QPushButton *)sender();
    md.operationType = MClear;
    doMath(&md);
    updateLabel(btn);
    outputMD();
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

void MainWindow::enableSwap(int i)
{
    ui->btn_swap->setEnabled(i);
}

void MainWindow::enableWerewolf(int i)
{
    ui->btn_werewolf->setEnabled(i);
}

void MainWindow::enableSQRT(int i)
{
    ui->btn_sqrt->setEnabled(i);
}

void MainWindow::enablePOW2(int i)
{
    ui->btn_pow2->setEnabled(i);
}

void MainWindow::enableMPlus(int i)
{
    ui->btn_m_plus->setEnabled(i);
}

void MainWindow::enableMMinus(int i)
{
    ui->btn_m_minus->setEnabled(i);
}

void MainWindow::enableMClear(int i)
{
    ui->btn_mc->setEnabled(i);
}

void MainWindow::enableMResult(int i)
{
    ui->btn_mr->setEnabled(i);
}

void MainWindow::enableMFunctions(int i)
{
    enableMPlus(i);
    enableMMinus(i);
    enableMResult(i);
    enableMClear(i);
}

void MainWindow::enableFunctions(int i)
{
    enableDelete(i);
    enableMFunctions(i);
    enableSwap(i);
    enableWerewolf(i);
    enableSQRT(i);
    enablePOW2(i);
    enablePoint(i);
    enableMoves(i);
    enableResult(i);
}

void MainWindow::enableAllBtn(int i)
{
    enableDelete(i);
    enableMoves(i);
    enableNum(i);
    enablePoint(i);
    enableResult(i);
    enableSwap(i);
    enableWerewolf(i);
    enableSQRT(i);
    enablePOW2(i);
    enableMFunctions(i);
}
