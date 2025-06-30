/*
* Dynamic Programing(���� ��ȹ��)
* 
* [�ڷ���, Ŭ����(�Լ�), ������, �ڷᱸ��]
* �˰��� ����, �Ƿ�, �ڵ带 �ۼ��ϴ� �ɷ��� ���ϱ� ���� ����
* ���α׷��� ������ �� ������ �ִ°�?(���� �Ƿ�)
*/

/*
* �˰��� ���� ����
* - ����, Ž��, Ʈ�� ��ȸ, �׷��� ��ȸ, Ž��(DFS, BFS)
* - ������ȹ��, �׸��� �˰���, ���� Ž��...
* ������ Ǫ�� �ذ� ���̵� �������� ������ ��
*/

/*
* DP ����
* - ���������� ��ȹ�� �����.
* - �ߺ��Ǵ� ������ �� ���� ����ؼ� �ذ��ϰ� �ʹ�.
* - �޸𸮿� ����� �ؼ� ����ϰڴ�.
*/

// 1. �Ǻ���ġ ����
// 1, 1 , 2, 3, 5, 8, 13 ......

#include <iostream>
#include <vector>


int Fibonacci(int n)
{
	if (n == 0) { return 0; }
	if (n == 1) { return 1; }
	//if (n == 3) { return 3; }
	//if (n == 4) { return 5; }

	// �ݺ���, ��ͷ�

	return Fibonacci(n - 1) + Fibonacci(n - 2);

}

/*
* �� ��� ����� �Ǻ���ġ ������ �ð��� �����ɸ���?
* n�� ���ڰ� Ŀ���� Ŀ������ Fibonacci�Լ��� ��� ������ �ȴ�.
* ��� �Լ��� ����ϸ� n�� Ŀ���� Ŀ������ ���ÿ� �޸𸮰� ���̰ڱ��� => ���� ���� �÷ο�
* �ߺ��� �߻��ϴ� ������ �ذ��ϱ� ���ؼ� �޸� ������ Ȯ���ؼ� ������ �صξ��ٰ� ����ϰڴ�.(�޸������̼�)
*/

/*
* ���� ��ȹ���� ���� ��Ŀ��� 
* Top - down ��� : ��� ������� ����, �����̳� ����
* bottom - up ��� : �ݺ���, �����̳� ����
*/

int FinoDP(int n) // Bottom - Up (�ݺ���, �����̳�)
{
	if (n <= 1) { return n; }

	// �����͸� ������ �����̳ʸ� ������ּ���.
	//
	std::vector<int> dp(n + 1, 0); // n���� �� ������ �ִ� �迭�� ���� �����ȴ�.

	// bottom - up ������ dp[n]���� �����ϱ� ���ؼ� dp[0]-dp[n] ä�� ������ ���̴�.

	dp[0] = 0;
	dp[1] = 1;

	for (int i = 2; i <= n; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	return dp[n];
}

class FiboRecursive // Top - Down
{
private:
	std::vector<int> dp;

public:
	FiboRecursive(int n)
	{
		dp.resize(n + 1, -1);
		dp[0] = 0;
		dp[1] = 1;		
	}

	int FiboRecur(int n)
	{
		// dp�� ���� �̹� �����Ѵٸ� -1�� �ƴϸ�
		// ����Լ� return ����, �Ʒ��� �ڱ��ڽ� �Լ��� �����Ѵ�.
		if (dp[n] != -1)
		{
			return dp[n];
		}

		dp[n] = FiboRecur(n - 1) + FiboRecur(n - 2);
		return dp[n];

		//return FiboRecur(n - 1) + FiboRecur(n - 2);
	}

};

/*
* ��� ������ ����
* 
* ����� �����µ� 1��� �����ų� 2����� �ѹ��� �����ų�. �ΰ��� ������� ����� ���� �� �ֽ��ϴ�.
* ��ܿ��� ������ ���� ���� �����ϴµ�,
* �������, 2��° ����� �ö󰡱� ���ؼ��� �ΰ��� ����� �����մϴ�. (1+1) (2)
* �̶� ���� �ּ����� ������� n�� ����� ������ ����� �����غ�����
* �ٽ� ���̵�� : n��° ����� �ּ������� �ö�� �Ѵ�. 1ĭ�� ���� �� vs 2ĭ�� ���� �� ���� �� �־�� �Ѵ�.
*/

/*
* ����� ������ ����� ���� ���غ�����
* 2��° ����� �ö󰡱� ���� ��� : (1,1), (2) = 2
* CountStep(1) = 1;
* CountStep(2) = 2;
*/

/*
* cache : ĳ��(�ӽ÷� ����� ������ ����) ����
* ��µǴ� ������ ���� �� �����͸� �����ؼ� ����ϸ� ������ ����� �� �ִ�.
* �޸� ������ ����� �ؾ��Ѵ�. -ĳ��- : ����ȭ ��� �� �ϳ��̴�.(�ð��� Ȯ���� �� �ִ�)
*/

#include <unordered_map>

class GameCache
{
private:

	struct UserData
	{
		int level;
		int exps;
		int damage;
	};
	std::unordered_map<int, int> exps; // �ؽø� �̿��� �ڷᱸ��, Ž������ �ſ� ������, ������ ���� ����Ǵ� �����̳�
	std::unordered_map<int, int> damage;
	
	//std::unordered_map<int, UserData> damage;

public:

	int CaculateDamage(int level)
	{
		if (damage.find(level) != damage.end())
		{
			return damage[level];
		}

		int damages = level * (level + 50);
		damage[level] = damages;
		return damages;
	}

	int CalculateExp(int level)
	{
		// 5���� ���� �Ƿ��� ����ġ 1->2, 2->3, 3->4, 4->5

		if (exps.find(level) != exps.end())
		{
			std::cout << "ĳ�ÿ��� �����͸� ������" << "(����" << level << " : " << exps[level] << std::endl;
			return exps[level];
		}

		// ���ӿ��� ���� �� �ʿ��� ����ġ�� ���ϴ� ����
		// y = x^2 + 2x+1;

		int exp = level * (level + 100); // 101, 204
		exps[level] = exp;
		return exp;
	}
};

int CountStep(int n) // Bottom-Up ������� �����غ�����
{
	// DP�� �ѹ� �� ������ �ۼ��غ�����.
	std::vector<int> dp(n + 1, -1); // n+1�ϴ� ������ dp[6] 0���� �������� �� 7��° �����͸� ����ؾ� �Ѵ�.
	
	dp[0] = 0;
	dp[1] = 1;

	// 1, 1, 2, 3, 5, 8

	for (int i = 2; i <= n;i++)
	{
		dp[n] = dp[n - 1] + dp[n - 2];
	}
	return dp[n];
}

int main()
{
	std::cout << "====�Ǻ���ġ ��� ����====" << std::endl;
	
	std::cout << "����� : " << Fibonacci(3) << std::endl;
	
	std::cout << "�Ǻ���ġ�� 25��° ���ڸ� ����غ�����" << Fibonacci(25) << std::endl;
	// ��� ������� �����ϸ� �ð� �ʰ��� �߻��մϴ�.

	std::cout << "====�Ǻ���ġ DP Bottom-Up ����====" << std::endl;
	std::cout << "����� : " << FinoDP(6) << std::endl;

	std::cout << "====�Ǻ���ġ DP Top-Down ����====" << std::endl;
	FiboRecursive fibo(6);
	std::cout << "����� : " << fibo.FiboRecur(2) << std::endl;

	std::cout << "��� ������ ����� �� ���" << std::endl;
	std::cout << "n��° ����� ������ ���� �ʿ��� ����� �� : " << CountStep(10) << std::endl;

	std::cout << "���� ĳ�� ������ ���� " << std::endl;

	GameCache gameCache;

	std::cout << "1���� ����ġ : " << gameCache.CalculateExp(1) << std::endl;
	std::cout << "2���� ����ġ : " << gameCache.CalculateExp(2) << std::endl;	

	std::cout << "1���� ���ݷ� : " << gameCache.CaculateDamage(1) << std::endl;	
	std::cout << "2���� ���ݷ� : " << gameCache.CaculateDamage(2) << std::endl;	


}