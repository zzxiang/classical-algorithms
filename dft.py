# Discrete Fourier Transform
# https://jakevdp.github.io/blog/2013/08/28/understanding-the-fft/

import numpy as np

def dft(x):
    """Compute the discrete Fourier Transform of the 1D array x"""
    x = np.asarray(x, dtype=float)
    N = x.shape[0]
    n = np.arange(N)
    k = n.reshape((N, 1))
    M = np.exp(-2j * np.pi * k * n / N)
    return np.dot(M, x)

x = np.random.random(1024)
print(np.allclose(dft(x), np.fft.fft(x)))

