\documentclass{article}
\usepackage{amsmath}
\usepackage{amssymb}

\title{Mid-Price Prediction in Financial Markets using Machine Learning: A Feature Engineering Approach}
\author{Evgeniy Kozhevnikov and Denis Rakhmankin, Vega Institute}
\date{}

\begin{document}

\maketitle

\begin{abstract}
This paper presents a method for predicting the mid-price in financial markets using features derived from the Limit Order Book (LOB) and a machine learning model. The method combines sophisticated feature engineering techniques with the LightGBM algorithm, a gradient boosting framework. The features used include various momentum measures, autocorrelation function, Volume Imbalance, Realized Volatility, and Jump Variation.
\end{abstract}

\section{Introduction}
Predicting mid-prices in financial markets is a critical task. This paper presents a method for mid-price prediction using a machine learning approach with carefully engineered features extracted from LOB data.

\section{Methodology}
This section describes the methodology used in the study, including data, Limit Order Book (LOB), and feature engineering techniques.

\subsection{Data}
The study uses high-frequency LOB data for one trading day of the CNHRUB pair from Moscow Exchange.

\subsection{Limit Order Book}
The LOB is an ordered set of price levels with offers for each level. The LOB data is stored using a sorted list of price-volume pairs and a collection (map) for additional information.

\subsection{Feature Engineering}
Feature engineering plays a critical role in enhancing the predictive power of machine learning models. The main features used in this model include Bid-Ask Spread, Weighted mid-price, Momentum, Autocorrelation Function (ACF), Volume Imbalance (VI), Imbalance (IMB) Feature, Realized Volatility, and Jump Variation.

\section{Stationarity and Predictability}
To achieve stationarity, logarithmic returns of the mid-price are used as the target variable. Logarithmic returns capture relative changes in price, providing more meaningful signals for trading strategies. Financial returns data is considered more predictable due to its stationary nature.

\section{Model Evaluation and Validation}
The model's performance is evaluated using the Root Mean Square Error (RMSE), which measures the average magnitude of prediction errors. The LightGBM algorithm is employed for mid-price prediction, known for its speed and efficiency.

\section{Results}
The model achieved a low RMSE on the test set, demonstrating high predictive accuracy.

\section{Conclusion}
The study demonstrates the effectiveness of using machine learning models and carefully engineered features for mid-price prediction in financial markets. The results highlight the potential of these methods in algorithmic trading strategies.

\section{References}
[1] Jakob Albers, Mihai Cucuringu, Sam Howison, Alexander Y. Shestopalof. "Fragmentation, Price Formation, and Cross-Impact in Bitcoin Markets".

[2] Adamantios Ntakaris, Juho Kanniainen, Moncef Gabbouj, Alexandros Iosifidis. "Mid-price prediction based on machine learning methods with technical and quantitative indicators".

\end{document}
