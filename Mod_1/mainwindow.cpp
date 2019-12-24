#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::fill_graph_histogram(QSharedPointer<QCustomPlot> &graph, QVector<qreal> &data)
{

    graph->setMinimumSize(400,500);
    auto max_value = QtConcurrent::run([&]
    {
        qreal result = 0;
        foreach(auto item,data)
        {
            if(result<item)
            {
                result = item;
            }
        }
        return result;
    });

    auto scene = new QCPBars(graph->xAxis, graph->yAxis);

    QPen pen;
    pen.setWidthF(5);
    pen.setColor(QColor(50, 50, 100));
    graph->graph(0)->setPen(pen);
    graph->graph(0)->setBrush(QColor(50, 50, 250, 70));

    QVector<qreal> ticks(COUNT_INTERVAL);
    for(int i = 0; i <COUNT_INTERVAL; i++)
    {
        ticks[i] = i;
    }

    scene->addData(ticks,data);
    scene->setWidth(1);

    QSharedPointer<QCPAxisTickerFixed> fixedTicker(new QCPAxisTickerFixed);
    fixedTicker->setTickStep(1);

    graph->xAxis->setTicker(fixedTicker);
    graph->xAxis->setTickLength(0, 10);
    graph->xAxis->grid()->setVisible(true);
    graph->xAxis->setRange(0,COUNT_INTERVAL);

    graph->yAxis->setRange(0,max_value.result()*1.5);
    graph->yAxis->setPadding(2);
    graph->yAxis->grid()->setSubGridVisible(true);

    QPen gridPen;
    gridPen.setStyle(Qt::SolidLine);
    gridPen.setColor(QColor(0, 0, 0, 25));
    graph->yAxis->grid()->setPen(gridPen);
    gridPen.setStyle(Qt::DotLine);
    graph->yAxis->grid()->setSubGridPen(gridPen);
}

void MainWindow::on_enter_clicked()
{
    histogram.reset(new QCustomPlot);
    ui->histogram->addWidget(histogram.get());
    histogram->addGraph();

    QVector<qreal> values;
    create_arr_values(values,ui->r0_box->value(),ui->m_box->value(),ui->a_box->value());
    auto map_for_histogram = create_data_for_histogram(values);
    QVector<qreal> vector_for_histogram(map_for_histogram.size());
    int index = 0;
    foreach(auto item, map_for_histogram)
    {
        vector_for_histogram[index] = item;
        vector_for_histogram[index] /=ui->m_box->value();
        index++;
    }
    fill_graph_histogram(histogram,vector_for_histogram);
    histogram->replot();

    for(int i = 0; i < values.count();i++)
    {
        values[i]/=ui->m_box->value();
    }

    ui->expected->setText("Мат. ожидание:" + QString::number(expected_value(values),'f'));
    ui->sd->setText("СКО:" + QString::number(standart_deviation_value(values),'f'));
    ui->dispersion->setText("Дисперсия:" + QString::number(dispersion_value(values),'f'));
    ui->check_equability->setText("Результат проверки равномерности:" +
                                  QString::number(check_equability(values,ui->m_box->value()))+
                                  " -> " +
                                  QString::number(M_PI/4));
    ui->lenght->setText("Длина аппериодичности:" +
                        QString::number(length_aperiod(5000000,ui->r0_box->value(),ui->m_box->value(),ui->a_box->value())));
    ui->period->setText("Период:" +
                        QString::number(period_value(5000000,ui->r0_box->value(),ui->m_box->value(),ui->a_box->value())));
}
