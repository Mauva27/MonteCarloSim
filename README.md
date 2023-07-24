<h1>Monte Carlo Sim </h1>

Simple Monte Carlo simulation algorithm used for financial applications. Simulaties the future value of an investment in the stock market based on a simple geometric Brownian motion model.

<h2>Geometric Brownian Motion Model</h2>

The geometric Brownian motion model is widely used in finance to simulate the price movement of assets, such as stocks. It assumes that the logarithm of the asset's price follows a random walk with drift and volatility.

The formula for the geometric Brownian motion is as follows:

$dS=\mu⋅S⋅dt+\sigma⋅S⋅dW$

where:

$dS$ is the change in the asset's price over a small time window $dt$. $S$ is the current price of the asset, $\mu$ is the "drift" or expected return, and $\sigma$ is the volatility or standard deviation of the asset's returns. Here $dW$ is the Wiener process, representing random noise following a standard normal distribution.

<h2>Monte Carlo Simulation Algorithm</h2>

MC simulations are statistical tools used to estimate outcomes through repeated random sampling. In the context of finance, it involves generating multiple potential price paths for an asset based on the geometric Brownian motion model.

<h2>Step-by-step description of the MC simulation algorithm</h2>

<h3>Define the parameters</h3>

Let's consider MSFT

```
initial_price = 275
```

The starting price of the asset (e.g., the current stock price).

```
drift =  0.05           
```
The annual expected return of the asset (e.g., 0.05 for 5%).
```
volatility: 0.035       
```
The annual volatility of the asset (e.g., 0.035 for 3.5%).
```
trading_perioed = 252   
```
The number of trading days for the simulation (e.g., 252 for one year).
```
n_simulations = 100     
````
The number of simulations to run to generate price paths.

<h3>Calculate the time step $dt$</h3>

Assuming daily trading, divide the total time horizon by the number of trading days in a year (e.g., $dt=1/252$)

<h3>Initialize a random number generator and a normal distribution</h3>

Use a random number generator to get random values following a standard normal distribution with zero mean and standard deviation $\sigma$= 1.

<h3>Run the Monte Carlo simulation loop</h3>

For each run, create an empty price path vector to store the asset's prices over time. The current price is set as the first element of the price path.

For each trading day, compute the daily returns using the geometric Brownian motion equation and the random value from the normal distribution.

Multiply the current price by the daily return to get the new price for the next day.

<!-- Append the new price to the price path.
Repeat the process for the entire time horizon.
Return the set of simulated price paths:
After completing all simulations, return the collection of price paths, each representing a potential price trajectory of the asset.
Example Implementation

As an example, we have provided implementations of the Monte Carlo simulation algorithm in Python and C++ in separate code files. The code demonstrates how to run the simulation and visualize the results using matplotlib in Python and standard output in C++. -->


<h2>NOTE</h2>
Please note that this example uses a simplified geometric Brownian motion model for illustrative purposes. In real-world financial applications, more complex models and additional factors may be considered for more accurate simulations.




