#include <iostream>

int L, W, x, y, R, a, v, s;

void calc()
{
}

int main()
{
    while (std::cin >> L >> W >> x >> y >> R >> a >> v >> s)
    {
        if (L == 0 && W == 0 && x == 0 && y == 0 && R == 0 && a == 0 && v == 0 && s == 0)
        {
            break;
        }
        std::cout << L << " " << W << " " << x << " " << y << " " << R << " " << a << " " << v << " " << s << std::endl;
    }
}