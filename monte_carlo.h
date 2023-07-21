#ifndef _MONTE_CARLO_H
#define _MONTE_CARLO_H

#include <vector>

class MonteCarlo {
    public:
        MonteCarlo(
            double initial_price,
            double drift,
            double volatility,
            int trading_period,
            int n_simulations
            );

        std::vector<std::vector<double> > simulation();

    private:
            double ip;
            double d;
            double v;
            int p;
            int ns;
    };

#endif