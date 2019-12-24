#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <function.h>
#include <QDebug>

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

void fill_graph_histogram(QSharedPointer<QCustomPlot> &graph, QVector<qreal> &data)
{
    int COUNT_INTERVAL = 20;

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
    int a = ui->first_a_box->value();
    int b = ui->first_b_box->value();
    int count = ui->first_c_box->value();

    auto data = first_task(a,b,count);
    histogram1.reset(new QCustomPlot);
    ui->histograms->addWidget(histogram1.get());
    histogram1->addGraph();
    auto data_for_histograms = create_data_for_histogram(data);
    fill_graph_histogram(histogram1,data_for_histograms);
    histogram1->replot();

    ui->first_m->setText("Медиана:" + QString::number(static_cast<qreal>((a+b))/2));
    ui->first_d->setText("Дисперсия:" + QString::number(static_cast<qreal>(qPow(b-a,2))/12));
    ui->first_s->setText("СКО:" + QString::number(sqrt(static_cast<qreal>(qPow(b-a,2))/12)));

    qreal m = ui->second_m_box->value();
    qreal s = ui->second_s_box->value();
    count = ui->second_c_box->value();

    data = second_task(m,s,count);
    histogram2.reset(new QCustomPlot);
    ui->histograms->addWidget(histogram2.get());
    histogram2->addGraph();
    data_for_histograms = create_data_for_histogram(data);
    fill_graph_histogram(histogram2,data_for_histograms);
    histogram2->replot();

    ui->second_m->setText("Медиана:" + QString::number(m));
    ui->second_d->setText("Дисперсия:" + QString::number(s*s));
    ui->second_s->setText("СКО:" + QString::number(s));

    qreal l = ui->third_l_box->value();
    count = ui->third_c_box->value();

    data = third_task(l,count);
    histogram3.reset(new QCustomPlot);
    ui->histograms->addWidget(histogram3.get());
    histogram3->addGraph();
    data_for_histograms = create_data_for_histogram(data);
    fill_graph_histogram(histogram3,data_for_histograms);
    histogram3->replot();

    ui->third_m->setText("Медиана:" + QString::number(1.0/l));
    ui->third_d->setText("Дисперсия:" + QString::number(qPow(1.0/l,2)));
    ui->third_s->setText("СКО:" + QString::number(1.0/l));

    int n = ui->fourth_n_box->value();
    l = ui->fourth_l_box->value();
    count = ui->fourth_c_box->value();

    data = fourth_task(l,count,n);
    histogram4.reset(new QCustomPlot);
    ui->histograms->addWidget(histogram4.get());
    histogram4->addGraph();
    data_for_histograms = create_data_for_histogram(data);
    fill_graph_histogram(histogram4,data_for_histograms);
    histogram4->replot();

    ui->fourth_m->setText("Медиана:" + QString::number(static_cast<qreal>(n)/l));
    ui->fourth_d->setText("Дисперсия:" + QString::number(static_cast<qreal>(n)/(l*l)));
    ui->fourth_s->setText("СКО:" + QString::number(sqrt(static_cast<qreal>(n)/(l*l))));

    a = ui->fiveth_a_box->value();
    b = ui->fiveth_b_box->value();
    count = ui->fiveth_c_box->value();

    data = fiveth_task(a,b,count);
    histogram5.reset(new QCustomPlot);
    ui->histograms->addWidget(histogram5.get());
    histogram5->addGraph();
    data_for_histograms = create_data_for_histogram(data);
    fill_graph_histogram(histogram5,data_for_histograms);
    histogram5->replot();

    ui->fiveth_m->setText("Медиана:" + QString::number(static_cast<qreal>((a+b))/2));
    ui->fiveth_d->setText("Дисперсия:" + QString::number(static_cast<qreal>(qPow(b-a,2))/12));
    ui->fiveth_s->setText("СКО:" + QString::number(sqrt(static_cast<qreal>(qPow(b-a,2))/12)));

    a = ui->sixth_a_box->value();
    b = ui->sixth_b_box->value();
    count = ui->sixth_c_box->value();

    data = sixth_task(a,b,count);
    histogram6.reset(new QCustomPlot);
    ui->histograms->addWidget(histogram6.get());
    histogram6->addGraph();
    data_for_histograms = create_data_for_histogram(data);
    fill_graph_histogram(histogram6,data_for_histograms);
    histogram6->replot();

    ui->sixth_m->setText("Медиана:" + QString::number(static_cast<qreal>((a+b))/2));
    ui->sixth_d->setText("Дисперсия:" + QString::number(static_cast<qreal>(qPow(b-a,2))/12));
    ui->sixth_s->setText("СКО:" + QString::number(sqrt(static_cast<qreal>(qPow(b-a,2))/12)));

}
