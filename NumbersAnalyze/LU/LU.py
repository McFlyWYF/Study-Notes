import numpy as np

"""
:compute L and U
:params:A
:return:L,U
"""


def LU(A):
    a = np.array(A)
    n = len(a)

    L = np.zeros([n, n])
    U = np.zeros([n, n])

    for i in range(n - 1):
        x = a[:, i]
        x[i + 1:] = x[i + 1:] / x[i]
        x[0:i + 1] = np.zeros(i + 1)

        L[:, i] = x
        L[i][i] = 1

        for j in range(i + 1, n):
            A[j, :] = A[j, :] - x[j] * A[i, :]

        a = np.array(A)

    L[i + 1][i + 1] = 1
    U = a
    return L, U


"""
:compute D and X 
:params:L,U,B
:return X
"""""


def compute(L, U, B):
    U = U.astype('float')

    D = np.linalg.solve(L, B)
    print('D：', D)
    X = np.linalg.solve(U, D)
    print('1607094158-王宇飞')
    return X


if __name__ == '__main__':
    A = np.array([[2, 2, 3], [4, 7, 7], [-2, 4, 5]])
    B = np.array([[3, 1, -7]])
    B = B.T
    B = B.astype('float')
    L, U = LU(A)
    print('L：', L)
    print('U：', U)
    X = compute(L, U, B)
    print('X：', X)
