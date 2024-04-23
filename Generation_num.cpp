#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

int getRandomNumber(int min, int max) {
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}


int userGuess() {
	int a;
	while (true)
	{
		std::cin >> a;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "Fail! Try again!";
		}else {
			std::cin.ignore(32767, '\n');
			return a;
		}
	}

}

void compareNums(int machineNum, int humanNum) {
	std::string num0 = std::to_string(machineNum);
	std::string num1 = std::to_string(humanNum);
	/*std::cout << num0 << num1;*/
	int length = num0.length();
	int counterСoincidence = 0;
	int counterFullCoincidence = 0;
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length; j++) {
			if (num0[i] == num1[j]&&i==j) {
				counterFullCoincidence++;
				counterСoincidence++;
			}
			else if (num0[i] == num1[j]) {
				counterСoincidence++;
			}
		}
	}
	std::cout << "Your coincidence is " << counterСoincidence<< "\n";
	std::cout << "Your full coincidence is " << counterFullCoincidence << "\n";
}

int main()
{
	srand(static_cast<unsigned int>(time(0)));
	int randNum = getRandomNumber(1, 999);
	std::string num = "one-digit number";
	if (randNum >= 10 && randNum < 100) {
		num = "two-digit number";
	}
	else if (randNum >= 100) {
		num = "three-digit number";
	}
	std::cout << "Computer has guessed a " << num << "\nYou must guess it.\nAfter the next number, you will be informed how many numbers are guessed and how many of them are in their places.";
	bool isGuessed = false;
	while (!isGuessed){
		std::cout << "Your variant is: ";
		int userChoise = userGuess();
		compareNums(randNum, userChoise);
		if (randNum == userChoise) {
			isGuessed = true;
		}
	}
}

