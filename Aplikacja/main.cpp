/*
		APLIKACJA KRYPTOGRAFICZNA
----------------------------------------
		Autor:	Ewelina Kolba
		Data:	23.10.2022
*/
#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <math.h>
#include <stdio.h>
#include "operations.h"

int main(int argc, char* argv[]) {
	long long tryb = 0;
	operations operation;

	while (tryb != 3) {
		long long  p, q, temp, tryb = 0, operacja = 0;
		bool czy_pierwsza = 0;
		long long n, fi, e, d = -1, s;
		std::vector <long long> ascii;
		std::string message;
		std::vector <long long> szyfr;

		std::cout << "=== Aplikacja kryptograficzna ===" << std::endl;
		std::cout << "Wybierz rodzaj szyfrowania: " << std::endl;
		std::cout << "1. RSA" << std::endl;
		std::cout << "2. Podstawieniowy" << std::endl;
		std::cout << "3. Exit" << std::endl;
		std::cin >> tryb;
		if (tryb == 1) {
			std::cout << "Wybierz operacje: " << std::endl;
			std::cout << "1. Szyfrowanie" << std::endl;
			std::cout << "2. Odszyfrowywanie" << std::endl;
			std::cin >> operacja;
			if (tryb == 1) {
				do {
					std::cout << "Podaj p: " << std::endl;
					std::cin >> p;
					czy_pierwsza = operation.proba(p);
				} while (czy_pierwsza == 0);
				czy_pierwsza = 0;

				do {
					std::cout << "Podaj q: ";
					std::cin >> q;

					czy_pierwsza = operation.proba(q);
				} while (czy_pierwsza == 0);

				n = p * q;
				fi = (p - 1) * (q - 1);

				do {
					std::cout << "Podaj e: ";
					std::cin >> e;
					if (e > 1 && e < fi) {
						d = operation.euklides(e, fi);
					}
				} while (d == -1);

				std::cout << "Podaj wiadomosc: ";
				std::cin.ignore(std::numeric_limits < std::streamsize >::max(), '\n');
				std::getline(std::cin, message);
				std::cout << std::endl;

				//------------------------------------------------------------------------------
				//szyfrowanie
				if (operacja == 1) {
					for (long long i = 0; i < message.size(); i++) {
						std::cout << (long long)message[i] << " ";
						szyfr.push_back(operation.powmd(message[i], e, n));
					}
					std::cout << std::endl << "ZASZYFROWANA WIADOMOSC: " << std::endl;
					for (long long i = 0; i < szyfr.size(); i++) {
						std::cout << szyfr[i] << " ";
					}
					std::cout << std::endl;
				}
				//------------------------------------------------------------------------------
				//odszyfrowywanie
				if (operacja == 2) {
					std::string s = "";
					long long x;
					std::cout << "Message: " << message << std::endl;
					std::cout << "size: " << message.size() << std::endl;

					for (int i = 0; i < message.size(); i++) {
						std::cout << "i: " << i << std::endl;
						if ((int)message[i] != 32 && i != message.size() - 1) {
							std::cout << "warunek 1" << std::endl;
							s += message[i];
						}
						else if (i == message.size() - 1 && (int)message[i] != 32) {
							std::cout << "warunek 2" << std::endl;
							s += message[i];
							std::cout << "s: " << s << std::endl;
							x = static_cast<long long>(std::stoi(s));
							szyfr.push_back(x);
							s = "";
						}
						else if ((int)message[i] == 32) {
							std::cout << "warunek 3" << std::endl;
							std::cout << "s: " << s << std::endl;
							x = static_cast<long long>(std::stoi(s));
							szyfr.push_back(x);
							s = "";
						}
					}

					for (long long i = 0; i < szyfr.size(); i++) {
						ascii.push_back(operation.powmd(szyfr[i], d, n));
					}
					std::cout << std::endl << "ODSZYFROWANA WIADOMOSC: " << std::endl;
					for (long long i = 0; i < ascii.size(); i++) {
						std::cout << ascii[i] << " ";
					}
					std::cout << std::endl;
					for (long long i = 0; i < ascii.size(); i++) {
						std::cout << char(ascii[i]);
					}
					std::cout << std::endl;
				}
			}
		}
		else if (tryb == 2) {
			char alf[36] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','0','1','2','3','4','5','6','7','8','9' };

			int klucz,a;
			bool flag;
			char x;

			std::cout << "Podaj klucz" << std::endl;
			std::cin >> klucz;

			std::cout << "Wybierz operacje: " << std::endl;
			std::cout << "1. Szyfrowanie" << std::endl;
			std::cout << "2. Odszyfrowywanie" << std::endl;
			std::cin >> operacja;
			if (operacja == 1) {
				std::cout << "Podaj wiadomosc: ";
				std::cin.ignore(std::numeric_limits < std::streamsize >::max(), '\n');
				std::getline(std::cin, message);
				std::cout << std::endl;
				int dlugosc = message.length();

				for (int i = 0; i < dlugosc; i++) {
					if (message[i] > 95) //gdy napotkamy małą literę zamieniamy ją na dużą
						message[i] = (char)(message[i] - 32); //przesuwając o 32 miejsca w kodzie ASCII
				}
				std::cout << message << std::endl;
				for (int i = 0; i < dlugosc; i++) {

					x = message[i];
					flag = 0;
					for (int j = 0; j < 36; j++) {
						if (x == alf[j]) {
							flag = 1;
							if (klucz + j > 35) {
								a = (klucz + j) - 36;
								message[i] = alf[a];
								std::cout << message[i];
								continue;
							}
							else {
								message[i] = alf[klucz + j];
								std::cout << message[i];
								continue;
							}
						}
						else {
							continue;
						}
					}
					if (!flag) std::cout << message[i];
				}
			}
			else {
				std::cout << "Podaj szyfr: ";
				std::cin.ignore(std::numeric_limits < std::streamsize >::max(), '\n');
				std::getline(std::cin, message);
				std::cout << std::endl;
				int dlugosc = message.length();
				for (int i = 0; i < dlugosc; i++) {
					if (message[i] > 95) //gdy napotkamy małą literę zamieniamy ją na dużą
						message[i] = (char)(message[i] - 32); //przesuwając o 32 miejsca w kodzie ASCII
				}
				//std::cout << temp << std::endl;
				for (int i = 0; i < dlugosc; i++) {
					x = message[i];
					flag = 0;
					for (int j = 0; j < 36; j++) {
						if (x == alf[j]) {
							flag = 1;
							if (j - klucz < 0) {
								a = (j - klucz) + 36;
								message[i] = alf[a];
								std::cout << message[i];
								continue;
							}
							else {
								message[i] = alf[j - klucz];
								std::cout << message[i];
								continue;
							}
						}
						else {
							continue;
						}
					}
					if (!flag) std::cout << message[i];
				}
				std::cout << std::endl;
			}
		}
		else {
			std::cout << "Zakończono" << std::endl;
			return 0;
		}
	}
}