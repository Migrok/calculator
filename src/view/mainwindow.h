#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "qcustomplot.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private slots:
  void on_pushButton_1_clicked();

  void on_pushButton_2_clicked();

  void on_pushButton_3_clicked();

  void on_pushButton_4_clicked();

  void on_pushButton_5_clicked();

  void on_pushButton_6_clicked();

  void on_pushButton_7_clicked();

  void on_pushButton_8_clicked();

  void on_pushButton_9_clicked();

  void on_pushButton_0_clicked();

  void on_pushButton_dot_clicked();

  void on_pushButton_sin_clicked();

  void on_pushButton_cos_clicked();

  void on_pushButton_tan_clicked();

  void on_pushButton_asin_clicked();

  void on_pushButton_acos_clicked();

  void on_pushButton_atan_clicked();

  void on_pushButton_mod_clicked();

  void on_pushButton_ln_clicked();

  void on_pushButton_Log_clicked();

  void on_pushButton_Power_clicked();

  void on_pushButton_Sqrt_clicked();

  void on_pushButton_multiply_clicked();

  void on_pushButton_divide_clicked();

  void on_pushButton_add_clicked();

  void on_pushButton_minus_clicked();

  void on_pushButton_equals_clicked();

  void on_pushButton_delete_clicked();

  void on_pushButton_left_bracket_clicked();

  void on_pushButton_right_bracket_clicked();

  void on_pushButton_x_clicked();

  void on_graphicsView_rubberBandChanged(const QRect &viewportRect,
                                         const QPointF &fromScenePoint,
                                         const QPointF &toScenePoint);

  void on_calculateButton_clicked();

  void on_radioButton_months_clicked();

  void on_radioButton_years_clicked();

  void annuityCredit();

  void differentiatedCredit();

  void on_radioButton_annuity_clicked();

  void on_radioButton_differentiated_clicked();

  void on_calculateButton_deposit_clicked();

  void on_radioButton_deposit_months_clicked();

  void on_radioButton_deposit_years_clicked();

  void on_checkBox_deposit_capital_clicked();

 private:
  Ui::MainWindow *ui;
  bool isXPressed = false;
};

#endif  // MAINWINDOW_H
