#pragma once

#include "Document.h"

#include <iostream>

// ������ ó���ϴ� ��ƿ��Ƽ Ŭ����
// ����� �˻�, ������ �缳��, ���� ��� ����
class DocumentProcess
{
public:
	static void TranslateIntoFrench(const Document& document)
	{
		std::cout << "�������� ���� �Ϸ�\n";
	}

	static void SpellCheck(const Document& document)
	{
		std::cout << "���� ����� �˻� �Ϸ�\n";
	}

	static void Repaginate(const Document& document)
	{
		std::cout << "���� ������ �缳�� �Ϸ�\n";
	}
};
