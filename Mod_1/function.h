#ifndef FUNCTION_H
#define FUNCTION_H

#include <QVector>
#include <QMap>
#include <QPair>

constexpr int COUNT_INTERVAL = 20;

int _rand();
void create_arr_values(QVector<qreal> &values, int _r0, int _m, int _a);
QMap<QPair<int,int>,int> create_data_for_histogram(QVector<qreal> &values);
int count_values_period(QPair<qreal,qreal> &&period, QVector<qreal> &values);
qreal expected_value(QVector<qreal> &values);
qreal standart_deviation_value(QVector<qreal> &values);
qreal dispersion_value(QVector<qreal> &values);
qreal check_equability(QVector<qreal> &values, int m);
int length_aperiod(int count, int _r0, int _m, int _a);
int period_value(int count, int _r0, int _m, int _a);

#endif // FUNCTION_H
