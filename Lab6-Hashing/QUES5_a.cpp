// AU2140117 SRUSHTI THAKAR
// DATA STRUCTURES AND ALGORITHMS
// LAB 6
// HASHING

// ques 5 : converting a string into a hash function:

// displaying the hash values modulo 17

#include <bits/stdc++.h>
using namespace std;

struct Hash
{
	const int p = 17, m = 1e9 + 7;
	int hash_val = 0;

	void hash_string(const string &s)
	{
		long power = 1;
		for (char ch : s)
		{
			hash_val = (hash_val + (ch + 1 - 'a') * power) % m;
			power = (power * p) % m;
		}
	}

	Hash(const string &s)
	{
		hash_string(s);
	}
};

int main()
{
	const char *s1[6] = {"fist", "sift", "shift", "fast", "faster", "shaft"};
	cout << "hash values calculated with respect to modulo 17: " << endl;
	for (int i = 0; i < 6; i++)
	{
		Hash h(s1[i]);
		cout << "Hash value of " << s1[i] << " : ";
		cout << h.hash_val << '\n';
	}
	return 0;
}

// sample output:

// hash values calculated with respect to modulo 17:
// Hash value of fist : 103910
// Hash value of sift : 100166
// Hash value of shift : 1702654
// Hash value of fast : 103774
// Hash value of faster : 26078805
// Hash value of shaft : 1700342
