#include <function.h>
#include <algorithm>
#include <QtMath>
#include <QDebug>

int r0 = 0;
int m = 0;
int a = 0;

int _rand()
{
    return r0 = (a * r0) % m;
}

void create_arr_values(QVector<qreal> &values, int _r0, int _m, int _a)
{
    r0 = _r0;
    m = _m;
    a = _a;
    for (int i = 0; i < m; i++)
    {
        values.push_back(_rand());
    }
}

int count_values_period(QPair<qreal,qreal> &&period, QVector<qreal> &values)
{
    int result = 0;
    foreach(auto item, values)
    {
        if(item >= period.first && item < period.second)
        {
            result++;
        }
    }
    return result;
}

QMap<QPair<int,int>,int> create_data_for_histogram(QVector<qreal> &values)
{
    QMap<QPair<int,int>,int> data;
    int count = values.size();
    int period = count/COUNT_INTERVAL;

    int range = 0;
    while (true)
    {
        if(data.count() + 1 == COUNT_INTERVAL)
        {
            data.insert(qMakePair(range,count),count_values_period(qMakePair(range,count),values));
            break;
        }
        else
        {
            data.insert(qMakePair(range,range+period),count_values_period(qMakePair(range,range+period),values));
        }
        range += period;

    }
    return data;
}

qreal expected_value(QVector<qreal> &values)
{
    qreal result = 0.0;
    int count = values.size();
    for(int i = 0; i < count; i++)
    {
        result += values[i];
    }
    return result/count;
}

qreal standart_deviation_value(QVector<qreal> &values)
{
    return sqrt(dispersion_value(values));
}

qreal dispersion_value(QVector<qreal> &values)
{
    auto expected = expected_value(values);
    qreal result = 0;
    foreach (auto item, values)
    {
        result += qPow((item - expected),2);
    }
    return result/values.size();
}

QVector<qreal> normalize_values(QVector<qreal> &values, int m)
{
    int count = values.count();
    QVector<qreal> result(count);
    for (int i = 0; i < count; i++)
    {
        result[i] = values[i] / m;
    }
    return result;
}

int count_true_pair(QVector<qreal> &&values)
{
    int count = values.size();
    int result = 0;
    for(int i = 0; i < count - 1; i+=2)
    {
        if(((values[i]*values[i]) + (values[i+1]*values[i+1])) < 1)
        {
            result++;
        }
    }

    qDebug()<<result;
    return result;
}

qreal check_equability(QVector<qreal> &values, int m)
{
    return 2.0*count_true_pair(normalize_values(values,m))/m;
}

int period_value(int count, int _r0, int _m, int _a)
{
    r0 = _r0;
    m = _m;
    a = _a;
    QVector<qreal> values(count);
    for (int i = 0; i < count;i++)
    {
        values[i] = static_cast<qreal>(_rand())/_m;
    }

    qreal check_v = values[count - 1];

    int index = 0;
    int i1 = -1;
    int i2 = -1;
    while(i2 == -1)
    {
        if(values[index] == check_v)
        {
            if(i1 == -1)
            {
                i1 = index;
            }
            else
            {
                i2 = index;
            }
        }
        index++;
    }
    return i2 - i1;
}

int length_aperiod(int count, int _r0, int _m, int _a)
{
    int period = period_value(count, _r0, _m, _a);

    r0 = _r0;
    QVector<qreal> values(count);
    for (int i = 0; i < count;i++)
    {
        values[i] = static_cast<qreal>(_rand())/_m;
    }

    int i3 = 0;
    while(period + i3 < count && values[i3] != values[period + i3])
    {
        i3++;
    }
    return i3 + period >= count ? 0 : i3 + period;
}
