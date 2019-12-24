#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSharedPointer>
#include <QtConcurrent>

#include <qcustomplot.h>
#include <function.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    static void fill_graph_histogram(QSharedPointer<QCustomPlot> &graph, QVector<qreal> &data);
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_enter_clicked();

private:
    Ui::MainWindow *ui;
    QSharedPointer<QCustomPlot> histogram;
};

#endif // MAINWINDOW_H
