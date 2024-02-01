#include "mainwindow.h"

#include <QDebug>
#include <QGraphicsLineItem>
#include <QGraphicsScene>
#include <QMessageBox>

#include "../s21_smart_calc.h"
#include "./ui_mainwindow.h"
#include "qcustomplot.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  ui->Plot->xAxis->setRange(-100, 100);
  ui->Plot->yAxis->setRange(-100, 100);

  ui->label_maxX->setStyleSheet("color: black;");
  ui->label_minX->setStyleSheet("color: black;");
  ui->label_maxY->setStyleSheet("color: black;");
  ui->label_minY->setStyleSheet("color: black;");
  ui->label_credit_calc->setStyleSheet("color: black;");
  ui->label_sum_credit->setStyleSheet("color: black;");
  ui->label_term->setStyleSheet("color: black;");
  ui->label_interest->setStyleSheet("color: black;");
  ui->label_deposit_interest->setStyleSheet("color: black;");
  ui->label_deposit_amount->setStyleSheet("color: black;");
  ui->label_deposit_calc->setStyleSheet("color: black;");
  ui->label_deposit_monthly_rep->setStyleSheet("color: black;");
  ui->label_deposit_monthly_withdraw->setStyleSheet("color: black;");
  ui->label_deposit_period->setStyleSheet("color: black;");
  ui->label_deposit_term->setStyleSheet("color: black;");
  ui->label_deposit_tax->setStyleSheet("color: black;");

  ui->lineEdit_maxX->setText("100");
  ui->lineEdit_minX->setText("-100");
  ui->lineEdit_maxY->setText("100");
  ui->lineEdit_minY->setText("-100");

  ui->radioButton_years->setChecked(true);
  ui->radioButton_annuity->setChecked(true);
  ui->radioButton_deposit_months->setChecked(true);
  ui->radioButton_deposit_months_2->setChecked(true);

  connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(onButton1Clicked()));
  connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(onButton2Clicked()));
  connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(onButton3Clicked()));
  connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(onButton4Clicked()));
  connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(onButton5Clicked()));
  connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(onButton6Clicked()));
  connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(onButton7Clicked()));
  connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(onButton8Clicked()));
  connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(onButton9Clicked()));
  connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(onButton0Clicked()));
  connect(ui->pushButton_dot, SIGNAL(clicked()), this,
          SLOT(onButtonDotClicked()));
  connect(ui->pushButton_sin, SIGNAL(clicked()), this,
          SLOT(onButtonSinClicked()));
  connect(ui->pushButton_cos, SIGNAL(clicked()), this,
          SLOT(onButtonCosClicked()));
  connect(ui->pushButton_tan, SIGNAL(clicked()), this,
          SLOT(onButtonTanClicked()));
  connect(ui->pushButton_asin, SIGNAL(clicked()), this,
          SLOT(onButtonAsinClicked()));
  connect(ui->pushButton_acos, SIGNAL(clicked()), this,
          SLOT(onButtonAcosClicked()));
  connect(ui->pushButton_atan, SIGNAL(clicked()), this,
          SLOT(onButtonAtanClicked()));
  connect(ui->pushButton_Log, SIGNAL(clicked()), this,
          SLOT(onButtonLogClicked()));
  connect(ui->pushButton_ln, SIGNAL(clicked()), this,
          SLOT(onButtonLnClicked()));
  connect(ui->pushButton_Power, SIGNAL(clicked()), this,
          SLOT(onButtonPowerClicked()));
  connect(ui->pushButton_mod, SIGNAL(clicked()), this,
          SLOT(onButtonModClicked()));
  connect(ui->pushButton_Sqrt, SIGNAL(clicked()), this,
          SLOT(onButtonSqrtClicked()));
  connect(ui->pushButton_multiply, SIGNAL(clicked()), this,
          SLOT(onButtonMultiplyClicked()));
  connect(ui->pushButton_divide, SIGNAL(clicked()), this,
          SLOT(onButtonDivideClicked()));
  connect(ui->pushButton_add, SIGNAL(clicked()), this,
          SLOT(onButtonAddClicked()));
  connect(ui->pushButton_minus, SIGNAL(clicked()), this,
          SLOT(onButtonMinusClicked()));
  connect(ui->pushButton_left_bracket, SIGNAL(clicked()), this,
          SLOT(onButtonLeftBracketClicked()));
  connect(ui->pushButton_right_bracket, SIGNAL(clicked()), this,
          SLOT(onButtonRightBracketClicked()));
  connect(ui->calculateButton, SIGNAL(clicked()), this,
          SLOT(onCalculateButtonClicked()));
  connect(ui->calculateButton_deposit, SIGNAL(clicked()), this,
          SLOT(onCalculateButtonDepositClicked()));
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_pushButton_1_clicked() {
  QString currentText = ui->label->text();
  ui->label->setText(currentText + "1");
}

void MainWindow::on_pushButton_2_clicked() {
  QString currentText = ui->label->text();
  ui->label->setText(currentText + "2");
}

void MainWindow::on_pushButton_3_clicked() {
  QString currentText = ui->label->text();
  ui->label->setText(currentText + "3");
}

void MainWindow::on_pushButton_4_clicked() {
  QString currentText = ui->label->text();
  ui->label->setText(currentText + "4");
}

void MainWindow::on_pushButton_5_clicked() {
  QString currentText = ui->label->text();
  ui->label->setText(currentText + "5");
}

void MainWindow::on_pushButton_6_clicked() {
  QString currentText = ui->label->text();
  ui->label->setText(currentText + "6");
}

void MainWindow::on_pushButton_7_clicked() {
  QString currentText = ui->label->text();
  ui->label->setText(currentText + "7");
}

void MainWindow::on_pushButton_8_clicked() {
  QString currentText = ui->label->text();
  ui->label->setText(currentText + "8");
}

void MainWindow::on_pushButton_9_clicked() {
  QString currentText = ui->label->text();
  ui->label->setText(currentText + "9");
}

void MainWindow::on_pushButton_0_clicked() {
  QString currentText = ui->label->text();
  ui->label->setText(currentText + "0");
}

void MainWindow::on_pushButton_dot_clicked() {
  QString currentText = ui->label->text();
  ui->label->setText(currentText + ".");
}

void MainWindow::on_pushButton_sin_clicked() {
  QString currentText = ui->label->text();
  ui->label->setText(currentText + "sin(");
}

void MainWindow::on_pushButton_cos_clicked() {
  QString currentText = ui->label->text();
  ui->label->setText(currentText + "cos(");
}

void MainWindow::on_pushButton_tan_clicked() {
  QString currentText = ui->label->text();
  ui->label->setText(currentText + "tan(");
}

void MainWindow::on_pushButton_asin_clicked() {
  QString currentText = ui->label->text();
  ui->label->setText(currentText + "asin(");
}

void MainWindow::on_pushButton_acos_clicked() {
  QString currentText = ui->label->text();
  ui->label->setText(currentText + "acos(");
}

void MainWindow::on_pushButton_atan_clicked() {
  QString currentText = ui->label->text();
  ui->label->setText(currentText + "atan(");
}

void MainWindow::on_pushButton_mod_clicked() {
  QString currentText = ui->label->text();
  ui->label->setText(currentText + " % ");
}

void MainWindow::on_pushButton_ln_clicked() {
  QString currentText = ui->label->text();
  ui->label->setText(currentText + "ln(");
}

void MainWindow::on_pushButton_Log_clicked() {
  QString currentText = ui->label->text();
  ui->label->setText(currentText + "log(");
}

void MainWindow::on_pushButton_Power_clicked() {
  QString currentText = ui->label->text();
  ui->label->setText(currentText + "^");
}

void MainWindow::on_pushButton_Sqrt_clicked() {
  QString currentText = ui->label->text();
  ui->label->setText(currentText + "sqrt(");
}

void MainWindow::on_pushButton_multiply_clicked() {
  QString currentText = ui->label->text();
  ui->label->setText(currentText + " * ");
}

void MainWindow::on_pushButton_divide_clicked() {
  QString currentText = ui->label->text();
  ui->label->setText(currentText + " / ");
}

void MainWindow::on_pushButton_add_clicked() {
  QString currentText = ui->label->text();
  ui->label->setText(currentText + " + ");
}

void MainWindow::on_pushButton_minus_clicked() {
  QString currentText = ui->label->text();
  if (currentText == "") {
    ui->label->setText(currentText + "-");
  } else {
    ui->label->setText(currentText + " - ");
  }
}

void MainWindow::on_pushButton_left_bracket_clicked() {
  QString currentText = ui->label->text();
  ui->label->setText(currentText + "(");
}

void MainWindow::on_pushButton_right_bracket_clicked() {
  QString currentText = ui->label->text();
  ui->label->setText(currentText + ")");
}

void MainWindow::on_pushButton_delete_clicked() {
  QString currentText = ui->label->text();
  if (!currentText.isEmpty()) {
    currentText.chop(1);
    ui->label->setText(currentText);
  }
}

void MainWindow::on_pushButton_x_clicked() {
  QString currentText = ui->label->text();
  isXPressed = true;
  ui->label->setText(currentText + "x");
}

void MainWindow::on_pushButton_equals_clicked() {
  QString currentText = ui->label->text();
  std::string str = currentText.toStdString();
  if (isXPressed) {
    double minX = ui->lineEdit_minX->text().toDouble();
    double maxX = ui->lineEdit_maxX->text().toDouble();
    double minY = ui->lineEdit_minY->text().toDouble();
    double maxY = ui->lineEdit_maxY->text().toDouble();
    double step = 0.1;
    double y = 0;
    ui->Plot->clearGraphs();
    ui->Plot->addGraph();
    for (double x = minX; x <= maxX; x += step) {
      std::string modifiedStr = str;
      size_t found = modifiedStr.find('x');
      while (found != std::string::npos) {
        std::string replacement =
            (x < 0) ? "(" + std::to_string(x) + ")" : std::to_string(x);
        modifiedStr.replace(found, 1, replacement);
        found = modifiedStr.find('x', found + replacement.size());
      }
      const char* expression = modifiedStr.c_str();
      char* rpn = convertToRPN(expression);
      y = evaluateRPN(rpn);
      free(rpn);
      ui->Plot->graph(0)->addData(x, y);
    }
    ui->Plot->xAxis->setRange(minX, maxX);
    ui->Plot->yAxis->setRange(minY, maxY);
    ui->Plot->replot();
  } else {
    const char* expression = str.c_str();
    char* rpn = convertToRPN(expression);
    double result = evaluateRPN(rpn);
    free(rpn);
    QString resultString = QString::number(result, 'f', 7);
    ui->label_2->setText(currentText + " = " + resultString);
  }
  ui->label->setText("");
  isXPressed = false;
}

void MainWindow::on_graphicsView_rubberBandChanged(
    const QRect& viewportRect, const QPointF& fromScenePoint,
    const QPointF& toScenePoint) {}

void MainWindow::on_radioButton_months_clicked() {
  ui->radioButton_years->setChecked(false);
  ui->radioButton_months->setChecked(true);
}

void MainWindow::on_radioButton_years_clicked() {
  ui->radioButton_years->setChecked(true);
  ui->radioButton_months->setChecked(false);
}

void MainWindow::on_radioButton_annuity_clicked() {
  ui->radioButton_annuity->setChecked(true);
  ui->radioButton_differentiated->setChecked(false);
}

void MainWindow::on_radioButton_differentiated_clicked() {
  ui->radioButton_annuity->setChecked(false);
  ui->radioButton_differentiated->setChecked(true);
}

void MainWindow::on_calculateButton_clicked() {
  if (ui->radioButton_annuity->isChecked()) {
    annuityCredit();
  } else {
    differentiatedCredit();
  }
}

void MainWindow::annuityCredit() {
  double loanAmount = ui->lineEdit_sum_credit->text().toDouble();
  double interestRate = ui->lineEdit_percent->text().toDouble();
  int loanTerm = ui->lineEdit_term->text().toInt();
  if (ui->radioButton_years->isChecked()) {
    loanTerm *= 12;
  }
  const char* annuityRateStr =
      "(interestRate*(1+interestRate)^loanTerm)/((1+interestRate)^loanTerm-1)";
  double monthlyInterestRate = interestRate / 12 / 100;
  std::string monthlyInterestRateStr = std::to_string(monthlyInterestRate);
  std::string loanTermStr = std::to_string(loanTerm);
  std::string modifiedStr = annuityRateStr;
  size_t found = modifiedStr.find("interestRate");
  while (found != std::string::npos) {
    modifiedStr.replace(found, 12, monthlyInterestRateStr);
    found = modifiedStr.find("interestRate",
                             found + monthlyInterestRateStr.length());
  }
  found = modifiedStr.find("loanTerm");
  while (found != std::string::npos) {
    modifiedStr.replace(found, 8, loanTermStr);
    found = modifiedStr.find("loanTerm", found + loanTermStr.length());
  }
  const char* expression = modifiedStr.c_str();
  char* rpn = convertToRPN(expression);
  double annuityRate = evaluateRPN(rpn);
  free(rpn);
  double monthlyPayment = loanAmount * annuityRate;
  double overpayment = (monthlyPayment - loanAmount / loanTerm) * loanTerm;
  double finalSum = monthlyPayment * loanTerm;

  //для отладки
  // qDebug() << "Сумма кредита: " << loanAmount;
  // qDebug() << "Процентная ставка: " << interestRate;
  // qDebug() << "Срок кредита: " << loanTerm;
  // qDebug() << "Формула аннуитета: " << modifiedStr;
  // qDebug() << "Коэффициент аннуитета: " << annuityRate;
  // qDebug() << "Месячный платеж: " << monthlyPayment;
  // qDebug() << "Переплата: " << overpayment;
  // qDebug() << "Суммарный платеж: " << finalSum;

  QString message =
      "Месячный платеж: " + QString::number(monthlyPayment, 'f', 2) + "\n" +
      "Переплата: " + QString::number(overpayment, 'f', 2) + "\n" +
      "Суммарный платеж: " + QString::number(finalSum, 'f', 2);
  QMessageBox::information(this, "Расчет аннуитетного кредита", message);
}

void MainWindow::differentiatedCredit() {
  double loanAmount = ui->lineEdit_sum_credit->text().toDouble();
  double interestRate = ui->lineEdit_percent->text().toDouble();
  int loanTerm = ui->lineEdit_term->text().toInt();
  if (ui->radioButton_years->isChecked()) {
    loanTerm *= 12;
  }
  double loanBody = loanAmount / loanTerm;
  double interestPayment = loanAmount * (interestRate / 100 / 12);
  double firstPayment = loanBody + interestPayment;
  double overpayment = interestPayment;
  double finalSum = firstPayment;
  loanAmount = loanAmount - loanBody;
  for (int i = 1; i < (int)loanTerm - 1; i++) {
    interestPayment = loanAmount * (interestRate / 100 / 12);
    finalSum = finalSum + loanBody + interestPayment;
    overpayment = overpayment + interestPayment;
    loanAmount = loanAmount - loanBody;
  }
  interestPayment = loanAmount * (interestRate / 100 / 12);
  double lastPayment = loanBody + interestPayment;
  finalSum = finalSum + lastPayment;
  overpayment = overpayment + interestPayment;
  loanAmount = loanAmount - loanBody;

  // qDebug() << "Процентная ставка: " << interestRate;
  // qDebug() << "Срок кредита: " << loanTerm;
  // qDebug() << "Тело кредита: " << loanBody;
  // qDebug() << "Первый платеж: " << firstPayment;
  // qDebug() << "Последний платеж: " << lastPayment;
  // qDebug() << "Переплата: " << overpayment;
  // qDebug() << "Суммарный платеж: " << finalSum;

  QString message =
      "Первый платеж: " + QString::number(firstPayment, 'f', 2) + "\n" +
      "Средний платеж: " +
      QString::number((lastPayment + firstPayment) / 2, 'f', 2) + "\n" +
      "Последний платеж: " + QString::number(lastPayment, 'f', 2) + "\n" +
      "Переплата: " + QString::number(overpayment, 'f', 2) + "\n" +
      "Суммарный платеж: " + QString::number(finalSum, 'f', 2);
  QMessageBox::information(this, "Расчет дифференцированного кредита", message);
}

void MainWindow::on_calculateButton_deposit_clicked() {
  double depositAmount = ui->lineEdit_deposit_amount->text().toDouble();
  double depositTerm = ui->lineEdit_deposit_term->text().toDouble();
  double interestRate = ui->lineEdit_deposit_interest->text().toDouble();
  double interestTax = ui->lineEdit_deposit_tax->text().toDouble();
  double monthlyReplenishment =
      ui->lineEdit_deposit_monthly_rep->text().toDouble();
  double monthlyWithdrawal =
      ui->lineEdit_deposit_monthly_withdraw->text().toDouble();
  double finalDeposit = depositAmount;
  double sumPayment = 0;
  double sumTax = 0;
  double yearsMonthlyInterest = 0;

  if (ui->radioButton_deposit_months_2->isChecked()) {
    depositTerm = depositTerm / 12;
  }

  for (int month = 1; month <= depositTerm * 12; ++month) {
    depositAmount += monthlyReplenishment;
    finalDeposit += monthlyReplenishment;
    double monthlyInterestRate = interestRate / 100.0 / 12.0;
    double monthlyInterest = depositAmount * monthlyInterestRate;
    if (interestTax > 0) {
      double tax = monthlyInterest * (interestTax / 100);
      sumTax += tax;
      monthlyInterest -= tax;
    }

    yearsMonthlyInterest += monthlyInterest;
    if (ui->checkBox_deposit_capital->isChecked()) {
      if (ui->radioButton_deposit_months->isChecked()) {
        depositAmount += monthlyInterest;
      } else {
        if (month % 12 == 0) {
          depositAmount += yearsMonthlyInterest;
          yearsMonthlyInterest = 0;
        }
      }
    }
    finalDeposit += monthlyInterest;
    sumPayment += monthlyInterest;
    if (monthlyWithdrawal > 0) {
      depositAmount -= monthlyWithdrawal;
      finalDeposit -= monthlyWithdrawal;
    }
  }

  // qDebug() << "Сумма депозита: " << depositAmount;
  // qDebug() << "Срок кредита: " << depositTerm;
  // qDebug() << "Процентная ставка: " << interestRate;
  // qDebug() << "Налог: " << interestTax;
  // qDebug() << "Пополнение: " << monthlyReplenishment;
  // qDebug() << "Снятие: " << monthlyWithdrawal;
  // qDebug() << "Сумма выплат: " << sumPayment;
  // qDebug() << "Конечный депозит: " << finalDeposit;
  // qDebug() << "Сумма налогов: " << sumTax;
  // qDebug() << "Сумма пополнений: " << monthlyReplenishment * (depositTerm *
  // 12 - 1);

  QString message =
      "Начисленные проценты: " + QString::number(sumPayment, 'f', 2) + "\n" +
      "Сумма налога: " + QString::number(sumTax, 'f', 2) + "\n" +
      "Конечный депозит: " + QString::number(finalDeposit, 'f', 2) + "\n" +
      "Сумма пополнений: " +
      QString::number(monthlyReplenishment * depositTerm * 12, 'f', 2) + "\n" +
      "Сумма снятий: " +
      QString::number(monthlyWithdrawal * depositTerm * 12, 'f', 2);
  QMessageBox::information(this, "Расчет дифференцированного кредита", message);
}

void MainWindow::on_radioButton_deposit_months_clicked() {
  ui->radioButton_deposit_months->setChecked(true);
  ui->radioButton_deposit_years->setChecked(false);
}

void MainWindow::on_radioButton_deposit_years_clicked() {
  ui->radioButton_deposit_months->setChecked(false);
  ui->radioButton_deposit_years->setChecked(true);
}

void MainWindow::on_checkBox_deposit_capital_clicked() {}
