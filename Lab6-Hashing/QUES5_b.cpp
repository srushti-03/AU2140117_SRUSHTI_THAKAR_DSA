// AU2140117 SRUSHTI THAKAR
// DATA STRUCTURES AND ALGORITHMS
// LAB 6
// HASHING


// ques5 : converting a string into a hash function:

//displaying the hash values modulo 37

#include <bits/stdc++.h>
using namespace std;

struct Hash {
	const int p = 37, m = 1e9 + 7;
	int hash_val = 0;

    void hash_string(const string &s) {
		long power = 1;
		for(char ch: s) {
			hash_val = (hash_val + (ch + 1 - 'a') * power) % m;
			power = (power * p) % m;
		}
	}

	Hash(const string &s) {
		hash_string(s);
	}
};

int main() {
	const char* s1[6] = {"fist", "sift", "shift", "fast", "faster", "shaft"};
    cout<<"hash values calculated with respect to modulo 37: "<<endl;
    for(int i=0; i<6; i++){
	Hash h(s1[i]);
	cout << "Hash value of " << s1[i] <<" : ";
	cout<< h.hash_val << '\n';
    }
	return 0;
}


//sample output:


// hash values calculated with respect to modulo 37: 
// Hash value of fist : 1039410
// Hash value of sift : 1021626
// Hash value of shift : 37799774
// Hash value of fast : 1039114
// Hash value of faster : 258601138
// Hash value of shaft : 37788822



//sample output:

