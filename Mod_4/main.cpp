#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>

using std::cout;

enum class STATES{S2000 = 0,S1000,S2010,S1010,S1001,S2011,S1101,S1011,S2111,S1111,
                 S2211,S1211,S1201,S0211,UNKNOW};


STATES new_state(STATES cur_state, double new_pi1, double new_pi2, double pi1, double pi2)
{
    switch (cur_state)
    {
    case STATES::S2000:
    {
        return STATES::S1000;
    }
    case STATES::S1000:
    {
        return STATES::S2010;
    }
    case STATES::S2010:
    {
        if(new_pi1 < pi1)return STATES::S1010;
        else return STATES::S1001;
    }
    case STATES::S1010:
    {
        if(new_pi1 < pi1)return STATES::S2010;
        else return STATES::S2011;
    }
    case STATES::S1001:
    {
        if(new_pi2 < pi2)return STATES::S2011;
        else return STATES::S2010;
    }
    case STATES::S2011:
    {
        if(new_pi1 < pi1 && new_pi2 < pi2)return STATES::S1011;
        else if(new_pi1 > pi1 && new_pi2 < pi2)return STATES::S1101;
        else if(new_pi1 < pi1 && new_pi2 > pi2)return STATES::S1010;
        else if(new_pi1 > pi1 && new_pi2 > pi2)return STATES::S1001;
        break;
    }
    case STATES::S1101:
    {
        if(new_pi2 < pi2)return STATES::S2111;
        else return STATES::S2011;
    }
    case STATES::S1011:
    {
        if(new_pi1 < pi1 && new_pi2 < pi2)return STATES::S2011;
        else if(new_pi1 > pi1 && new_pi2 < pi2)return STATES::S2111;
        else if(new_pi1 < pi1 && new_pi2 > pi2)return STATES::S2010;
        else if(new_pi1 > pi1 && new_pi2 > pi2)return STATES::S2011;
        break;
    }
    case STATES::S2111:
    {
        if(new_pi1 < pi1 && new_pi2 < pi2)return STATES::S1111;
        else if(new_pi1 > pi1 && new_pi2 < pi2)return STATES::S1101;
        else if(new_pi1 < pi1 && new_pi2 > pi2)return STATES::S1011;
        else if(new_pi1 > pi1 && new_pi2 > pi2)return STATES::S1101;
        break;
    }
    case STATES::S1111:
    {
        if(new_pi1 < pi1 && new_pi2 < pi2)return STATES::S2111;
        else if(new_pi1 > pi1 && new_pi2 < pi2)return STATES::S2211;
        else if(new_pi1 < pi1 && new_pi2 > pi2)return STATES::S2011;
        else if(new_pi1 > pi1 && new_pi2 > pi2)return STATES::S2111;
        break;
    }
    case STATES::S2211:
    {
        if(new_pi1 < pi1 && new_pi2 < pi2)return STATES::S1211;
        else if(new_pi1 > pi1 && new_pi2 < pi2)return STATES::S0211;
        else if(new_pi1 < pi1 && new_pi2 > pi2)return STATES::S1111;
        else if(new_pi1 > pi1 && new_pi2 > pi2)return STATES::S1201;
        break;
    }
    case STATES::S1211:
    {
        if(new_pi1 < pi1 && new_pi2 < pi2)return STATES::S2211;
        else if(new_pi1 > pi1 && new_pi2 < pi2)return STATES::S0211;
        else if(new_pi1 < pi1 && new_pi2 > pi2)return STATES::S2111;
        else if(new_pi1 > pi1 && new_pi2 > pi2)return STATES::S2211;
        break;
    }
    case STATES::S1201:
    {
        if(new_pi2 < pi2)return STATES::S2211;
        else return STATES::S2111;
    }
    case STATES::S0211:
    {
        if(new_pi1 < pi1 && new_pi2 < pi2)return STATES::S0211;
        else if(new_pi1 > pi1 && new_pi2 < pi2)return STATES::S0211;
        else if(new_pi1 < pi1 && new_pi2 > pi2)return STATES::S2111;
        else if(new_pi1 > pi1 && new_pi2 > pi2)return STATES::S2211;
        break;
    }
    default:
    {
        return STATES::UNKNOW;
    }
    }
}

void print_count(std::vector<double> &count)
{
    enum class STATES{S2000 = 0,S1000,S2010,S1010,S1001,S2011,S1101,S1011,S2111,S1111,
                     S2211,S1211,S1201,S0211,UNKNOW};

    std::cout<<std::endl<<"2000 "<<count[0];
    std::cout<<std::endl<<"1000 "<<count[1];
    std::cout<<std::endl<<"2010 "<<count[2];
    std::cout<<std::endl<<"1010 "<<count[3];
    std::cout<<std::endl<<"1001 "<<count[4];
    std::cout<<std::endl<<"2011 "<<count[5];
    std::cout<<std::endl<<"1101 "<<count[6];
    std::cout<<std::endl<<"1011 "<<count[7];
    std::cout<<std::endl<<"2111 "<<count[8];
    std::cout<<std::endl<<"1111 "<<count[9];
    std::cout<<std::endl<<"2211 "<<count[10];
    std::cout<<std::endl<<"1211 "<<count[11];
    std::cout<<std::endl<<"1201 "<<count[12];
    std::cout<<std::endl<<"0211 "<<count[13];
}

void print_states(STATES state)
{
    switch (state)
    {
    case STATES::S2000:
    {
        std::cout<<"->2000"<<std::endl;
        break;
    }
    case STATES::S1000:
    {
        std::cout<<"->1000"<<std::endl;
        break;
    }
    case STATES::S2010:
    {
        std::cout<<"->2010"<<std::endl;
        break;
    }
    case STATES::S1010:
    {
        std::cout<<"->1010"<<std::endl;
        break;
    }
    case STATES::S1001:
    {
        std::cout<<"->1001"<<std::endl;
        break;
    }
    case STATES::S2011:
    {
        std::cout<<"->2011"<<std::endl;
        break;
    }
    case STATES::S1101:
    {
        std::cout<<"->1101"<<std::endl;
        break;
    }
    case STATES::S1011:
    {
        std::cout<<"->1011"<<std::endl;
        break;
    }
    case STATES::S2111:
    {
        std::cout<<"->2111"<<std::endl;
        break;
    }
    case STATES::S1111:
    {
        std::cout<<"->1111"<<std::endl;
        break;
    }
    case STATES::S2211:
    {
        std::cout<<"->2211"<<std::endl;
        break;
    }
    case STATES::S1211:
    {
        std::cout<<"->1211"<<std::endl;
        break;
    }
    case STATES::S1201:
    {
        std::cout<<"->1201"<<std::endl;
        break;
    }
    case STATES::S0211:
    {
        std::cout<<"->0211"<<std::endl;
        break;
    }
    default:
    {
        std::cout<<"UNKNOW"<<std::endl;
    }
    }
}

double get_probability_working(std::vector<double> &probability, double pi)
{
    return 1 - pi*(probability[static_cast<int>(STATES::S1010)]+
                   probability[static_cast<int>(STATES::S1011)]+
                   probability[static_cast<int>(STATES::S1111)]+
                   probability[static_cast<int>(STATES::S1211)]);
}

double get_lenght_queue(std::vector<double> &probability)
{
    return 1*(probability[static_cast<int>(STATES::S1101)]+
              probability[static_cast<int>(STATES::S2111)]+
              probability[static_cast<int>(STATES::S1111)])+
           2*(probability[static_cast<int>(STATES::S2211)]+
              probability[static_cast<int>(STATES::S1211)]+
              probability[static_cast<int>(STATES::S1201)]+
              probability[static_cast<int>(STATES::S0211)]);
}

double get_average_time_in_system(std::vector<double> &probability, double pi)
{
    auto Lc = 1*(probability[static_cast<int>(STATES::S2000)]+
              probability[static_cast<int>(STATES::S1000)]+
              probability[static_cast<int>(STATES::S2010)]+
              probability[static_cast<int>(STATES::S1010)]+
              probability[static_cast<int>(STATES::S1001)]+
              probability[static_cast<int>(STATES::S2011)]+
              probability[static_cast<int>(STATES::S1011)])+
           2*(probability[static_cast<int>(STATES::S1101)]+
              probability[static_cast<int>(STATES::S2111)]+
              probability[static_cast<int>(STATES::S1111)])+
           3*(probability[static_cast<int>(STATES::S2211)]+
              probability[static_cast<int>(STATES::S1211)]+
              probability[static_cast<int>(STATES::S1201)]+
              probability[static_cast<int>(STATES::S0211)]);

    auto A = (1-pi)*(probability[static_cast<int>(STATES::S1001)]+
                    probability[static_cast<int>(STATES::S2011)]+
                    probability[static_cast<int>(STATES::S1101)]+
                    probability[static_cast<int>(STATES::S1011)]+
                    probability[static_cast<int>(STATES::S2111)]+
                    probability[static_cast<int>(STATES::S1111)]+
                    probability[static_cast<int>(STATES::S2211)]+
                    probability[static_cast<int>(STATES::S1211)]+
                    probability[static_cast<int>(STATES::S1201)]+
                    probability[static_cast<int>(STATES::S0211)]);
    return Lc/A;
}

void print_characteristics(std::vector<double> &probability, double pi1, double pi2)
{
    std::cout<<std::endl<<"Q="<<get_probability_working(probability,pi1);
    std::cout<<std::endl<<"Lq="<<get_lenght_queue(probability);
    std::cout<<std::endl<<"Wc="<<get_average_time_in_system(probability,pi2);
}

int main()
{
    srand(time(nullptr));

    std::vector<int> count(14);

    double pi1 = 0.3;
    double pi2 = 0.5;

    std::cout<<"pi1:";
    std::cin>>pi1;
    std::cout<<std::endl<<"pi2:";
    std::cin>>pi2;

    STATES state = STATES::S2000;
    int count_iteration = 10000;

    std::cout<<std::endl;
    for (int i = 0; i < count_iteration; i++)
    {
        count[static_cast<unsigned int>(state)]++;
        print_states(state);
        double rand_pi1 = static_cast<double>(rand())/RAND_MAX;
        double rand_pi2 = static_cast<double>(rand())/RAND_MAX;
        state = new_state(state,rand_pi1,rand_pi2,pi1,pi2);
    }

    std::vector<double> probability(count.size());
    std::transform(count.begin(),count.end(),probability.begin(),[&](int value)
    {
        return  static_cast<double>(value)/count_iteration;
    });

    std::cout<<std::endl;
    print_count(probability);

    std::cout<<std::endl;
    print_characteristics(probability,pi1,pi2);
    return 0;
}
