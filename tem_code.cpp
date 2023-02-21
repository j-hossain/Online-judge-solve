#include <bits/stdc++.h>
using namespace std;

int N, Q;
int X[100010];
int S[400010];
int S2[400010];

void update(const int l, const int r, const int v, const int L, const int R, const int idx) {
   if (L >= l && R <= r) {
      S2[idx] += v;
      S[idx] += v;
      return;
   }
   int M = (L + R) / 2;
   if (l <= M)
      update(l, r, v, L, M, idx * 2);
   if (r >= M + 1)
      update(l, r, v, M + 1, R, idx * 2 + 1);
   S2[idx] = S[idx] + min(S2[idx * 2], S2[idx * 2 + 1]);
}

bool query(const int l, const int r, const int L, const int R, const int idx) {
   if (S2[idx])
      return 1;
   if (L >= l && R <= r)
      return 0;
   int M = (L + R) / 2;
   bool res = 1;
   if (l <= M)
      res = query(l, r, L, M, idx * 2);
   if (res && r >= M + 1)
      res = query(l, r, M + 1, R, idx * 2 + 1);
   return res;
}

void fr(int &to) {
   char t; to ^= to;
   while (!isdigit((t = getchar_unlocked())));
   while (t > 47) { to = (to << 3) + (to << 1) + t - 48; t = getchar_unlocked(); }
}//fr


int main() {
   int T;
   fr(T);
   for (int t = 1; t <= T; t++) {
      printf("Case %d:\n", t);
      memset(S, 0, sizeof(S));
      memset(S2, 0, sizeof(S2));
      fr(N); fr(Q);
      for (int i = 1; i <= N; i++) {
         fr(X[i]);
         if (X[i])
            update(i + 1, min(N + 1, i + X[i]), 1, 1, N + 1, 1);
      }
      while (Q--) {
         int q, p, s;
         fr(q);
         if (q == 1) {
            fr(p); fr(s);
            if (X[p])
               update(p + 1, min(N + 1, p + X[p]), -1, 1, N + 1, 1);
            X[p] = s;
            if (X[p])
               update(p + 1, min(N + 1, p + X[p]), 1, 1, N + 1, 1);
         }
         else {
            fr(s);
            if (s > 0 && (s > N || query(s + 1, N + 1, 1, N + 1, 1)))
               puts("yes");
            else
               puts("no");
         }
      }
   }
   return 0;
}