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

			std::cout << ("Ââåäiòü çíà÷åííÿ äëÿ n: ");
			scanf_s("%lld", &buff);
			while (getchar() != '\n') {
				continue;
			}

			try {

				this->n = buff > 0 ? buff : throw std::exception("Çíà÷åííÿ n ìàº áóòè áiëüøå çà 0!");
			}
			catch (std::exception e) {
				std::cout << e.what() << " Ñïðîáóéòå ùå!\n";
				AssignValue('n');
			}
		}
		else {
			std::cout << ("Ââåäiòü çíà÷åííÿ äëÿ m: ");
			scanf_s("%lld", &buff);
			while (getchar() != '\n') {
				continue;
			}
			try {
				this->m = buff > 0 && buff <= 2 * pow(10, 9) ? buff : throw std::exception("Çíà÷åííÿ n ìàº áóòè ìåíøå çà 2*10^9!");
			}
			catch (std::exception e) {
				std::cout << e.what() << " Ñïðîáóéòå ùå!\n";
				AssignValue('m');
			}
		}
	}

	void CalculateResult(void) {
		std::cout << "Àëiñà îòðèìàº " << (this->n - 1) * (this->m - 1) + 1 << " øìàòî÷êiâ ñèðó!\n";
	}

	bool AskToContinue() {

		std::cout << "Áàæàºòå ïî÷àòè çíîâó? Ââåäiòü 'y' äëÿ ïðîäîâæåííÿ ðîáîòè! ";
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
