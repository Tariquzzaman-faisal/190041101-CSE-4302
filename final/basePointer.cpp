#include <iostream>
#define MAX 6
using namespace std;

class base
{
public:
	const int fs = -1;
	int *ara;
	int kCount = 0, tS;
	double Lf = 0;

	void init(int n)
	{
		ara = new int[n];
		tS = n;
		for (int i = 0; i < n; i++)
			ara[i] = fs;
	}
	int hash(int key)
	{
		return key % tS;
	}
	virtual int f(int i)
	{
		return i;
	}

	virtual int getIndex(int key, int i = 0)
	{
		return (hash(key) + f(i) % tS) % tS;
	}

	bool insert(int key)
	{
		int idx;
		for (int i = 0; i < MAX; i++)
		{
			idx = getIndex(key, i);
			if (ara[idx] == fs)
			{
				kCount++;
				ara[idx] = key;
				Lf = kCount / (double)tS;
				cout << "Inserted: Index-" << idx << " (L.F=" << Lf << ")\n";
				return true;
			}
			else
			{
				cout << "Collision: Index-" << idx << "\n";
			}
		}
		cout << "Input Abandoned\n";
		return false;
	}
};

class LinearProbing : public base
{
public:
	LinearProbing(int n) { init(n); }
};

class QuadraticProbing : public base
{
public:
	int f(int i) { return i * i; }
	QuadraticProbing(int n) { init(n); }
};

class Hash_Double : public base
{
public:
	int R;

	int hash2(int key)
	{
		return R - key % R;
	}
	int getIndex(int key, int i = 0)
	{
		return (hash(key) + (f(i) * hash2(key)) % tS) % tS;
	}

	Hash_Double(int n, int _R = 7)
	{
		init(n);
		R = _R;
	}
};

int main()
{
	base *H;
	int type, n, q;
	cin >> type >> n >> q;

	switch (type)
	{
	case 1:
		H = new LinearProbing(n);
		break;
	case 2:
		H = new QuadraticProbing(n);
		break;
	case 3:
		H = new Hash_Double(n);
		break;

	default:
		break;
	}

	for (int i = 0; i < q; i++)
	{
		cin >> n;
		H->insert(n);
	}

	return 0;
}

/*
1 10 7
35
45
73
36
5
24
13
99
*/