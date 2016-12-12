//莫比乌斯 mu 函数
const int PMAX = 100001;
VI P, M; bitset<PMAX> isC; int mu[PMAX], cc[PMAX];
VI dd[PMAX];
#define ii (i*P[j])

void sieve()
{
	mu[1] = 1; FOR(i, 2, PMAX){
		if (!isC[i]) P.PB(i),mu[i]=-1;
		for (int j=0;j<SZ(P)&&ii<PMAX;++j){
			isC[ii]=1;if (!(i%P[j])){
				mu[ii] = 0;
				break;
			}
			else{
				mu[ii] = -mu[i];
			}
		}
	}

	FOR(i, 1, PMAX) if (mu[i]){
		M.PB(i);
		for (int j=i;j<PMAX;j+=i) dd[j].PB(i);
	}
}
#undef ii

const int N = int(1e5) + 9;
int a[N];
int n;

int main()
{

#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif

	sieve();

	Rush{
		RST(cc); REP_C(i, RD(n)){
			RD(a[i]); ECH(d, dd[a[i]]) ++cc[*d];
		}
		LL z = 0; REP(i, n){
			int c0 = 0; ECH(d, dd[a[i]]) c0 += mu[*d]*(cc[*d]-1);
			z += (LL)c0*(n-1-c0);
		}
		OT((LL)n*(n-1)*(n-2)/6-z/2);
	}
}
