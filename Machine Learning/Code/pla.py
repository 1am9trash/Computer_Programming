import numpy as np


# dim 維度, num 產生線性可分測資數量
def createLinearSepartedData(dim, num, shift, x=0, y=0):
    wei = np.random.rand(1, dim + 1)
    wei[0][0] = shift
    if (x or y) and dim == 2:
        wei[0][1] = x
        wei[0][2] = y

    data = np.zeros((num, dim + 2))
    # print(data.shape)

    for i in range(num):
        # print (data[i][0:dim].shape, np.random.rand(dim).shape)
        data[i][0] = 1
        data[i][1:dim + 1] = np.random.rand(dim) * 1000 - 500

        # print (wei[0].shape, data[i][0:dim].shape)
        # print (wei, data[i])
        val = wei[0].dot(data[i][0:dim + 1])
        # print (val)
        if (val > 0):
            data[i][dim + 1] = 1
        else:
            data[i][dim + 1] = -1

    return data


# dim 維度, num 測資數量, dim含1
def PLATrain(data):
    dim = data.shape[1] - 1
    num = data.shape[0]
    wei = np.zeros((1, dim))
    # print (data[0].shape)
    # print (wei[0].shape)

    i = 0
    while i < num:
        if data[i][-1] * (wei[0].dot(data[i][0:-1])) <= 0:
            wei += data[i][-1] * data[i][0:-1]
            i = 0
        else:
            i += 1
    return wei


def draw2D(data, wei):
    import matplotlib.pyplot as plt

    plt.figure()
    plt.xlim(-500, 500)
    plt.ylim(-500, 500)

    plt.title("PLA traing model")
    plt.xlabel("X")
    plt.ylabel("Y")

    yesId = np.where(data[:, 3] == 1)
    noId = np.where(data[:, 3] == -1)
    # print (yesId)
    # print (noId)
    plt.scatter(data[yesId, 1], data[yesId, 2],
                marker='o', color='g', label="YES", s=20)
    plt.scatter(data[noId, 1], data[noId, 2],
                marker='x', color='r', label="NO", s=20)
    plt.legend(loc='upper right')

    x = np.linspace(-500, 500)
    y = (-wei[0][0] - wei[0][1] * x) / wei[0][2]
    # print (wei)
    # print (y)
    # print (x[0], y[0])
    plt.plot(x, y)

    plt.show()


if __name__ == '__main__':
    dim, num, shift, x, y = map(int, input().split())
    data = createLinearSepartedData(dim, num, shift, x, y)
    wei = PLATrain(data)

    # print (data.shape)
    # print (data)
    # print (wei.shape)
    # print (wei)

    if (dim == 2):
        draw2D(data, wei)
