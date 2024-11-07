import pandas as pd
import numpy as np

# Используется L2-регуляризация
# Err = MSE + l2_coef * (W1^2 + W2^2 + ... + Wk^2)
class LinearRegression:
    W: list[float]     # intercept
    b: float           # slope

    def fit(self, X: pd.DataFrame, y: pd.Series, epochs=10_000, speed_coef=0.01, l2_coef=0.1) -> None:
        self.W = [0.0] * len(X.columns)
        self.b = 0.0

        for _ in range(epochs):
            part_calcs = [np.dot(X.iloc[i], self.W) + self.b - y[i] for i in range(len(X))]

            # Обновляем W
            for j in range(len(X.columns)):
                # Обновляем W[j]
                dw_j = 0.0
                for i in range(len(X)):
                    dw_j += X.iloc[i, j] * part_calcs[i]
                dw_j *= 2.0 / len(X)
                dw_j += 2.0 * l2_coef * self.W[j]
                self.W[j] -= speed_coef * dw_j
            
            # Обновляем b
            db = 0.0
            for i in range(len(X)):
                db += part_calcs[i]
            db *= 2.0 / len(X)
            db += 2.0 * l2_coef * self.b
            self.b -= speed_coef * db
        
        return
    
    def predict(self, X: pd.DataFrame) -> pd.Series:
        return pd.Series(
            np.dot(X.iloc[i], self.W) + self.b \
            for i in range(len(X))
        )
