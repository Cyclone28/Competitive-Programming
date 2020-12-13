#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < q; i++)
    {
        long long x;
        cin >> x;
        long long res = 0;

        int right = 0;
        long long sum = 0;
        //左端で場合分け
        for(int left = 0; left < n; left++){
            while(right < n && sum + a[right] <= x){
                sum += a[right];
                right++;
            }

            res += right - left;

            if(right == left) right++;
            else sum -= a[left];
        }

        cout << res << endl;
    }
    return 0;
}