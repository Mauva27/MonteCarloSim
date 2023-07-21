#include "monte_carlo.h"
#include <iostream>
#include <cmath>
#include <random>


MonteCarlo::MonteCarlo(
    double initial_price,
    double drift,
    double volatility,
    int trading_period, 
    int n_simulations
)
{
    this -> ip = initial_price;  // Initial equity price
    this -> d  = drift;          // Annual expected return (/ 100%)
    this -> v  = volatility;     
    this -> p  = trading_period;
    this -> ns = n_simulations;

    std::cout << "initial price: " << this -> ip << std::endl;
    std::cout << "drift: " << this -> d << std::endl;
    std::cout << "volatility: " << this -> v << std::endl;
    std::cout << "period: " << this -> p << std::endl;
    std::cout << "s_sim: " << this -> ns << std::endl;

}

std::vector<std::vector<double> > MonteCarlo::simulation ()
{
    double dt = 1.0 / this -> p; // inverse of the trading period

    // create a normal random generator
    std::default_random_engine generator;
    std::normal_distribution<double> distribution(0.0, 1.0);

    std::vector<std::vector<double> > price_trajectory(this -> p, std::vector<double>(this -> ns, 0.0));


    for (int i = 0; i < this -> ns; ++i){
        price_trajectory[0][i] = this -> ip;
        for (int j = 1; j < this -> p; ++j){
            double random_normal   = distribution(generator);
            double daily_return    = exp((this-> d - 0.5 * this -> v * this -> v) * dt + this -> v * sqrt(dt) * random_normal);
            price_trajectory[j][i] = price_trajectory[j-1][i] * daily_return;
        }
    }
    return price_trajectory;
}

int main() {
    // parameters for MonteCarlo Object
    double initial_price = 100.0;
    double drift         = 0.05; // AER of 5%
    double volatitliy    = 0.2; // Annual volatility of 20%
    int trading_period   =  252; // Number of trading days 
    int n_simulations    = 100;  // Number of simulations to be executed 

    // call MC Object
    MonteCarlo MC(initial_price, drift,volatitliy,trading_period,n_simulations);

    //run MC simulation 
    std::vector<std::vector<double> > simulated_price_trajectory =  MC.simulation();

    //print output
    for (int i = 0; i < n_simulations; ++i) {
        std::cout << "Simulation " << i + 1 << std::endl;
        for (int j = 0; j < trading_period; ++j) {
            std::cout << "Day " << j + 1 << ": " << simulated_price_trajectory[j][i] << std::endl;
        }
        std::cout << "\n";
    }

    return 0;
}