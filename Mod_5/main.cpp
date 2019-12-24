#include <iostream>
#include <math.h>

double get_average_lenght_queue(double w)
{
    return w/(1-w);
}

double get_average_time_in_queue(double w, double l)
{
    return get_average_lenght_queue(w)/l;
}

double get_propability(int number, double w)
{
    return pow(w,number)*(1 - w);
}

int main()
{
    double l = 0.0;
    std::cout << "l:";
    std::cin>>l;

    double u = 0.0;
    while(u == 0.0)
    {
        std::cout << std::endl << "u:";
        std::cin>>u;
    }

    int count = 0;
    std::cout << std::endl << "count:";
    std::cin>>count;

    double w = l/u;
    for(int i = 0; i < count; i++)
    {
        std::cout << std::endl  << "P" << i << " = " << get_propability(i,w);
    }

    std::cout << std::endl;
    std::cout << std::endl << "Lq = " << get_average_lenght_queue(w);
    std::cout << std::endl << "Wq = " << get_average_time_in_queue(w,l);
    return 0;
}
