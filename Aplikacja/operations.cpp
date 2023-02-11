#include "operations.h"
#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <math.h>
#include <stdio.h>

bool operations::proba(long long liczba) {
	long long pierw = sqrt(liczba);
	bool flag_ = 0;
	for (long long i = 2; i <= pierw; i++) {
		if (liczba % i == 0) {
			flag_ = 1;
			break;
		}
	}
	if (flag_ == 0) {
		return 1;
	}
	else {
		return 0;
	}
}

long long operations::euklides(long long a, long long b) {
	long long q;
	long long r[3];
	long long s[3];
	bool flag = 0;


	if (a > b) {
		r[0] = a;
		r[1] = b;
		s[0] = 1;
		s[1] = 0;
	}
	else {
		r[0] = b;
		r[1] = a;
		s[0] = 0;
		s[1] = 1;
	}

	do {
		q = r[0] / r[1];
		r[2] = r[0] - (q * r[1]);
		s[2] = s[0] - (q * s[1]);

		if (r[2] == 1) {
			flag = 1;
			if (s[2] > 0) {
				return s[2];
			}
			else {
				s[2] = s[2] + b;
				return s[2];
			}
		}
		else if (r[2] == 0) {
			flag = 1;
			std::cout << "Brak rozwiazania" << std::endl;
			return -1;
		}
		else {
			r[0] = r[1];
			r[1] = r[2];
			s[0] = s[1];
			s[1] = s[2];
		}
	} while (flag == 0);
	return 0;
}

long long operations::powmd(long long a, long long b, long long c) {

	std::vector <unsigned long long > bin;
	std::vector <unsigned long long > powMod;
	std::vector <unsigned long long > pow;
	unsigned long long wynik = 0;
	unsigned long long x, y, z = 1;
	y = b;
	do {
		x = y % 2;
		y = y / 2;
		bin.push_back(x);
	} while (y != 0);
	for (long long i = 0; i < bin.size(); i++) {
		//std::cout << bin[i] << " ";
	}
	//std::cout << std::endl;
	for (long long i = 0; i < bin.size(); i++) {
		if (bin[i] == 1) {
			if (i == 0) {
				pow.push_back(1);
			}
			else if (i == 1) {
				pow.push_back(2);
			}
			else {
				for (long long j = i - 1; j >= 0; j--) {
					z = z * 2;
				}
				pow.push_back(z);
				z = 1;
			}
		}
	}
	//std::cout << b << " = ";
	for (long long i = 0; i < pow.size(); i++) {
		//std::cout << pow[i] << " ";
	}
	long long first;
	std::vector <unsigned long long > tab;
	long long pom = 0;
	first = a % c;
	tab.push_back(first);
	//std::cout << std::endl;
	//std::cout << pom << " " << tab[0] << std::endl;
	pom++;
	for (int i = 2; i <= pow[pow.size() - 1]; i *= 2) {
		long long temp = i / 2;
		long long temp2 = 0;
		temp2 = tab[pom - 1] * tab[pom - 1];
		temp2 = temp2 % c;
		//std::cout << i << " " << temp2 << std::endl;
		tab.push_back(temp2);
		pom++;
	}
	for (long long i = 0; i < pow.size(); i++) {
		long long temp = 0;
		long long x = pow[i];
		while (x != 0) {
			x = x / 2;
			temp++;
		}
		//std::cout << std::endl;
		//std::cout << "Potega,z mod c " << pow[i] << " ";
		z = tab[temp - 1];
		//std::cout << z << std::endl;
		powMod.push_back(z);
		z = 1;
	}
	//std::cout << std::endl;
	if (powMod.size() > 1) {
		wynik = (powMod[powMod.size() - 1] * powMod[powMod.size() - 2]) % c;
		for (long long i = powMod.size() - 3; i >= 0; i--) {
			wynik = wynik * powMod[i];
			wynik = wynik % c;
		}
	}
	else wynik = powMod[0];

	return wynik;
}