#include <iostream>
#include <cmath>
using namespace std;

//点 (ベクトル) を扱える構造体
struct Pt
{
    double x, y;

    //加算
    // P(x1, y1) + Q(x2, y2) = R(x1 + x2, y1 + y2)
    Pt operator+(const Pt &P)
    {
        Pt ret;
        ret.x = x + P.x;
        ret.y = y + P.y;
        return ret;
    }

    //減算
    //P(x1, y1) - Q(x2, y2) = R(x1 - x2, y1 - y2)
    Pt operator-(const Pt &P)
    {
        Pt ret;
        ret.x = x - P.x;
        ret.y = y - P.y;
        return ret;
    }

    //乗算(1)
    //P(x, y) * N = Q(x * N, y * N);
    Pt operator*(const int N)
    {
        Pt ret;
        ret.x = x * N;
        ret.y = y * N;
        return ret;
    }

    //除算
    //P(x, y) / N = Q(x / N, y / N)
    //N = 0 のとき continue
    Pt operator/(const int N)
    {
        if (N == 0)
            continue;
        else
        {
            Pt ret;
            ret.x = x / N;
            ret.y = y / N;
            return ret;
        }
    }

    //マイナス
    //-P(x, y) = Q(-x, -y)
    void operator-()
    {
        x = -x;
        y = -y;
    }

    //乗算(2)
    //P(x1, y1) * Q(x2, y2) = R(x1 * x2 - y1 * y2, x1 * y2 + y1 * x2)
    Pt operator*(const Pt &P)
    {
        Pt ret;
        ret.x = x * P.x - y * P.y;
        ret.y = x * P.y + y * P.x;
        return ret;
    }

    //絶対値
    //P(x, y).abs() = sqrt(x * x + y * y)
    double abs()
    {
        double ret;
        ret = sqrt(x * x + y * y);
        return ret;
    }

    //内積
    //P(x1, y1).dot(Q(x2, y2)) = x1 * x2 + y1 * y2
    double dot(const Pt &P)
    {
        double ret;
        ret = x * P.x + y * P.y;
        return ret;
    }

    //行列式
    //P(x1, y1).det(Q(x2, y2)) = x1 * y2 - y1 * x2
    double det(const Pt &P)
    {
        double ret;
        ret = x * P.y - y * P.x;
        return ret;
    }

    //偏角を返す
    //P(x, y).arg() = atan2(y, x)
    double arg()
    {
        double ret;
        ret = atan2(y, x);
        return ret;
    }

    //Ptのソート
    inline bool operator<(const Pt &a, const Pt &b)
    {
        if (sgn(a.x - b.x))
            return sgn(a.x - b.x) < 0;
        return sgn(a.y - b.y) < 0;
    }
};