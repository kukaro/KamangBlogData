TRIANGLE = ['  *  ', ' * * ', '*****']


def make_triangle(n):
    res = []
    if n == 3:
        return TRIANGLE
    else:
        for x in make_triangle(int(n / 2)):
            tmp = ''
            for sp in range(n // 2):
                tmp += ' '
            res.append(tmp + x + tmp)
        for x in make_triangle(int(n / 2)):
            res.append(x + ' ' + x)
        return res


if __name__ == '__main__':
    N = int(input())
    for atom in make_triangle(N):
        print(atom)
