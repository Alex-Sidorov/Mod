#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qcustomplot.h>
#include <QSharedPointer>
#include <QtConcurrent>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_enter_clicked();

private:
    Ui::MainWindow *ui;

    QSharedPointer<QCustomPlot> histogram1;
    QSharedPointer<QCustomPlot> histogram2;
    QSharedPointer<QCustomPlot> histogram3;
    QSharedPointer<QCustomPlot> histogram4;
    QSharedPointer<QCustomPlot> histogram5;
    QSharedPointer<QCustomPlot> histogram6;
};

#endif // MAINWINDOW_H
