#include<iostream>
#include<limits>
#include<random>

int main()
{
	std::cout << "���� \"�����\".\n"
			"�������: 2 ������ - ������������ � ��������� - ������ ���� �� �������.\n"
			"���� ����, � ��� N ������ (N = 10..20 - ���������� ��������� �������)\n"
			"�� ��� ����� ������ ����� 1, 2 ��� 3 �����.\n"
			"��� ������ ��������� ������ - ��������." << std::endl;
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
		        std::cout <<"� ����� "<< N << " ������" << std::endl;
		        int num;
		        do {
		        	menu_retry:
		            std::cout << "��� ���: ";
		        	if (not (std::cin >> num)) {
		        		std::cout << "�� ���������� ����.\n��������� ������ 1, 2 ��� 3" << std::endl;
		            	std::cin.clear();
		            	std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
		            	goto menu_retry;
		            }
		            } while (num <=0 || num>m || num>N);
		        N -= num;
		        std::cout << "� ���� " << N << " ������" << std::endl;
		        if (N <= 0) {
		            std::cout << "�� ���������" << std::endl;
		        continue;
		        }
		        int k1=k(rnd);
		        std::cout << "��� ���:" << k1 << std::endl;
		        N = N-k1;
		        if (N <= 0) {
		        	std::cout << "��������� ��������" << std::endl;
		        	 continue;
		        }
		 }
     	std::cout << "������ �����? 1 - ��, 0 - ���" << std::endl;
     	int choice;
     	std::cin>>choice;
		if (choice==1)
			goto new_game;
     	if (choice==0)
     		std::cout << "�� ��������!" << std::endl;
	return 0;
}
