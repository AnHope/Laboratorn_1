#include<iostream>
#include<limits>
#include<random>

int main()
{
	std::cout <<  "Игра \"Камни\".\n"
			"Правила: 2 игрока - пользователь и компьютер - делают ходы по очереди.\n"
			"Есть куча, в ней N камней (N = 10..20 - выбирается случайным образом)\n"
			"За ход игрок обязан взять 1, 2 или 3 камня.\n"
			"Кто забрал последний камень - проиграл." << std::endl;
	std::cout << "\n";
	std::default_random_engine rnd;
		std::random_device rdev;
		rnd.seed(rdev());
		std::uniform_int_distribution<> stones {10,20};
		std::uniform_int_distribution<> k {1,3};
		new_game:
		int N=stones(rnd);
		 while (N > 0)
		 {
		        int m=3;
		        std::cout << "В кучке "<< N << " камней" << std::endl;
		        int num;
		        do {
		        	menu_retry:
		            std::cout << "Ваш ход: ";
		        	if (not (std::cin >> num)) {
		        		std::cout "Не корректный ввод.\nТребуется ввести 1, 2 или 3" << std::endl;
		            	std::cin.clear();
		            	std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
		            	goto menu_retry;
		            }
		            } while (num <=0 || num>m || num>N);
		        N -= num;
		        std::cout << "В кучке "<< N << " камней" << std::endl;
		        if (N <= 0) {
		            std::cout << "Вы проиграли" << std::endl;
		        continue;
		        }
		        int k1=k(rnd);
		        std::cout << "Мой ход: " << k1 << std::endl;
		        N = N-k1;
		        if (N <= 0) {
		        	std::cout << "Компьютер проиграл" << std::endl;
		        	 continue;
		        }
		 }
     	std::cout << "Играем снова? 1 - да, 0 - нет" << std::endl;
     	int choice;
     	std::cin>>choice;
		if (choice==1)
			goto new_game;
     	if (choice==0)
     		std::cout << "До свидания!" << std::endl;
	return 0;
}
