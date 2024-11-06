import pandas as pd
import numpy as np

class LinearRegression:
    ws: list[float]     # intercept
    b: float            # slope

    def __init__(self) -> None:
        return

    def train(self, X: pd.DataFrame, y: pd.Series, epochs=10_000, alpha=0.01) -> None:
        self.ws = [0.0] * len(X.columns)
        self.b = 0.0

        for _ in range(epochs):
            part_calcs = [np.dot(X.iloc[i], self.ws) + self.b - y[i] for i in range(len(X))]

            # Обновляем ws
            for j in range(len(X.columns)):
                # Обновляем ws[j]
                dw_j = 0.0
                for i in range(len(X)):
                    dw_j += X.iloc[i, j] * part_calcs[i]
                dw_j *= 2 / len(X)
                self.ws[j] -= alpha * dw_j
            
            # Обновляем b
            db = 0.0
            for i in range(len(X)):
                db += part_calcs[i]
            db *= 2 / len(X)
            self.b -= alpha * db
        
        return
    
    def predict(self, X: pd.DataFrame) -> pd.Series:
        return pd.Series(
            np.dot(X.iloc[i], self.ws) + self.b \
            for i in range(len(X))
        )
