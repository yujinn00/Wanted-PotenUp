#include <iostream>
#include <vector>

int main()
{
	// ���� ���� ����
	std::vector<int> vector;

	// ������� Ȯ��
	//if (vector.size() == 0)	// ��ȣ X
	if (vector.empty())			// ��ȣ O
	{
		std::cout << "���Ͱ� ������ϴ�.\n";
	}

	// �ڷ� ����
	for (int ix = 0; ix < 1000; ++ix)
	{
		//vector.push_back(ix + 1);		// ��ȣ X
		vector.emplace_back(ix + 1);	// ��ȣ O
	}

	// ��� ���� => end() �Լ��� ������ ��� ���� ��ġ�� ����Ŵ
	for (auto it = vector.begin(); it != vector.end();)
	{
		it = vector.erase(it);
		if (it != vector.end())
		{
			++it;
		}
	}

	//size_t size = vector.size();
	for (int ix = 0; ix < (int)vector.size(); ++ix)
	{
		// ���� ����
		//std::cout << vector.at(ix) << " ";	// ��ȣ X
		std::cout << vector[ix] << " ";			// ��ȣ O
	}

	// ��� �Ұ� => ���� ���� ������ �������� ��쿡�� delete�� �ؾ� ��
	vector.clear();

	// ������� Ȯ��
	if (vector.empty())
	{
		std::cout << "���Ͱ� ������ϴ�.\n";
	}

	/*
	�����͸� ����� �ٽ� ä�� �����̸� �� resize(0)
	�뷮 ������ ���� ���� �̸� �޸� Ȯ���ϸ� �� reserve(n)
	�޸𸮸� ����ȭ�ϰ� �ʹٸ� �� shrink_to_fit()
	*/

	// ũ�� ����
	vector.resize(0);

	// ���� Ȯ�� => ���Ҵ� ���� / ���� ����ȭ
	vector.reserve(0);

	// ũ�� ���� �� ��� => capacity�� ����
	vector.shrink_to_fit();

	return 0;
}
