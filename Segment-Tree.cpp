/*
RMQ:[0, n-1]について、区間ごとの最小値を管理する
update(i, x): i番目の要素をxに更新 O(log(n))
quary(a, b): [a, b) での最小要素取得 O(log(n))
*/

templete <typename T>
struct RMQ {
    const T INF = numeric_limits<T>::max(); //type:TでのINF
    int n;             //葉の数
    vector<T> dat;     //完全二分木の配列
    RMQ(int n_) : n(), dat(n_ * 4, INF) {   //葉の数は 2^x の形
        int x = 1;
        while(n_ > x) {
            x *= 2;
        }
        n = x;
    }

    void update(int i, T x){  // i: 更新したい数列の位置 x: 更新後の値
        i += n - 1;           // i番目は配列上ではn - 1 + i番目に格納
        dat[i] = x;           // 更新
        while(i > 0) {        //親をたどりつつ最小値を更新していく
            i = (i - 1) / 2;  //親
            dat[i] = min(dat[i * 2 + 1], dat[i * 2 + 2]); //子の要素を比較して更新していく
        }
    }

    //[a, b) の最小値をO(log(n))で取得するぞーー！
    T quary(int a, int b) { return query_sub(a, b, 0, 0, n); } //[a, b) の最小値を取得する
    T query_sub(int a, int b, int k, int l, int r) {
        // k:現在見てるノードの位置 [l, r):dat[k]が表す区間
        if(r <= a || b <= l) { // 範囲外時は考えない
            return INF;
        }
        else if(a <= l && r <= b){  //範囲内なので自身の値を返す
            return dat[k];
        }
        else{ //一部区間がかぶってるとき
            T vl = query_sub(a, b, k * 2 + 1, l, (l + r) / 2); //子をたどっていく
            T vr = query_sub(a, b, k * 2 + 2, (l + r) / 2, r); //子をたどっていく
            return min(vl, vr);
        }
    }
};