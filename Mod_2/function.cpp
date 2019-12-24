#include <function.h>
#include <algorithm>
#include <QtMath>
#include <QDebug>

QVector<qreal> first_task(int a, int b, int count)
{
    QVector<qreal> result(count);
    for(int i = 0; i <count; i++)
    {
        result[i] = (a + static_cast<qreal>((b - a)*rand())/RAND_MAX);
    }
    return result;
}

QVector<qreal> second_task(qreal m, qreal s, int count)
{
    QVector<qreal> result(count);
    const int N = 12;
    for (int i = 0; i < count; i++)
    {
        qreal sum = 0.0;
        for (int j = 0; j < N; j++)
        {
            sum += static_cast<qreal>(rand());
        }
        result[i] = m + s*sqrt(12/N)*(sum - N/2);
        result[i] = abs(result[i])/RAND_MAX/20;
    }
    return result;
}

QVector<qreal> third_task(qreal l, int count)
{
    QVector<qreal> result(count);
    for(int i = 0; i <count; i++)
    {
        result[i] = abs(-1/l*qLn(static_cast<qreal>(rand())/RAND_MAX));
    }
    return result;
}

QVector<qreal> fourth_task(qreal l, int count, int n)
{
    QVector<qreal> result(count);
    for (int i = 0; i < count; i++)
    {
        qreal sum = 1;
        for (int j = 0; j < n; j++)
        {
            sum *= static_cast<qreal>(rand())/RAND_MAX;
        }

        result[i] = abs(-1/l*qLn(static_cast<qreal>(sum)));
    }
    return result;
}

QVector<qreal> fiveth_task(int a, int b, int count)
{
    QVector<qreal> result(count);
    for(int i = 0; i <count; i++)
    {
        qreal r1 = 0.0;
        qreal r2 = 0.0;
        while(r1 >= r2)
        {
            r1 = static_cast<qreal>(rand())/RAND_MAX;
            r2 = static_cast<qreal>(rand())/RAND_MAX;
        }
        result[i] = abs(a + static_cast<qreal>(b - a)*r1);
    }
    return result;
}

QVector<qreal> sixth_task(int a, int b, int count)
{
    QVector<qreal> result(count);
    for(int i = 0; i < count; i++)
    {
        result[i] = first_task(a/2,b/2,1)[0] + first_task(a/2,b/2,1)[0];
    }
    return result;
}

int count_values_period(QPair<int,int> &&period, QVector<qreal> &values)
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

QVector<qreal> create_data_for_histogram(QVector<qreal> &data)
{
    QVector<qreal> result(20);

    for(int i = 0; i < 20; i++)
    {
        result[i] = count_values_period(qMakePair(i,i+1),data);
    }
    return result;
}