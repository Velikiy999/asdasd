#pragma once
#include <stdio.h>
#include <iostream>
class Game
{
private:
	long long n;
	long long m;

	void AssignValue(char var) {

		long long buff;

		if (var == 'n') {

			std::cout << ("Введiть значення для n: ");
			scanf_s("%lld", &buff);
			while (getchar() != '\n') {
				continue;
			}

			try {

				this->n = buff > 0 ? buff : throw std::exception("Значення n має бути бiльше за 0!");
			}
			catch (std::exception e) {
				std::cout << e.what() << " Спробуйте ще!\n";
				AssignValue('n');
			}
		}
		else {
			std::cout << ("Введiть значення для m: ");
			scanf_s("%lld", &buff);
			while (getchar() != '\n') {
				continue;
			}
			try {
				this->m = buff > 0 && buff <= 2 * pow(10, 9) ? buff : throw std::exception("Значення n має бути менше за 2*10^9!");
			}
			catch (std::exception e) {
				std::cout << e.what() << " Спробуйте ще!\n";
				AssignValue('m');
			}
		}
	}

	void CalculateResult(void) {
		std::cout << "Алiса отримає " << (this->n - 1) * (this->m - 1) + 1 << " шматочкiв сиру!\n";
	}

	bool AskToContinue() {

		std::cout << "Бажаєте почати знову? Введiть 'y' для продовження роботи! ";
		char Choice;

		std::cin >> Choice;

		switch (Choice)
		{
		case 'y':
			return true;
		default:
			return false;
		}
	}

public:
	void Play() {

		bool toContinue = true;

		while (toContinue)
		{
			AssignValue('n');
			AssignValue('m');
			CalculateResult();
			toContinue = AskToContinue();
		}
	}
};

