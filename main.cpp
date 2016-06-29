#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <algorithm>

using namespace std;

typedef pair<int, string> Pair;
typedef vector<Pair> CACHE_TYPE;

bool PairComp(const Pair& lhs, const Pair& rhs)
{
	return lhs.first < rhs.first;
}

int calc(const string& s)
{
	int result = 0;
	for (string::const_iterator si = s.begin(); si != s.end(); ++si)
	{
		for (string::const_iterator sj = si; sj != s.end(); ++sj)
		{
			if (*si > *sj)
				result++;
		}
	}
	return result;
}

int main()
{
	int len, count;
	cin >> len >> count;

	CACHE_TYPE cache;
	cache.reserve(count);

	string s;
	for (int i = 0; i < count; ++i)
	{
		cin >> s;
		cache.push_back(make_pair(calc(s), s));
	}

	sort(cache.begin(), cache.end(), PairComp);

	for (CACHE_TYPE::iterator it = cache.begin(); it != cache.end(); ++it)
	{
		cout << it->second << endl;
	}
	return 0;
}
