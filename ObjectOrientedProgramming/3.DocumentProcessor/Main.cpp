#include "Document.h"
#include "DocumentProcess.h"
#include "DocumentProcessor.h"

#include "TranslateIntoFrenchProcess.h"
#include "SpellcheckProcess.h"
#include "RepaginateProcess.h"

#include <iostream>

// ���� ó���ڸ� �����ϴ� �Լ�
DocumentProcessor* Configure()
{
	DocumentProcessor* processor = new DocumentProcessor();

	processor->AddDocumentProcess(DocumentProcess::TranslateIntoFrench);
	processor->AddDocumentProcess(DocumentProcess::SpellCheck);
	processor->AddDocumentProcess(DocumentProcess::Repaginate);

	return processor;
}

int main()
{
	// ���� ��ü ����
	Document doc1("Jake Oh", "2025.02.13", "C++ Programming");
	Document doc2("Ian Tim", "2024.01.31", "Hello Iphone");

	// ���� ó���� ��ü ����
	DocumentProcessor* processor = Configure();

	// ù ��° ���� ó��
	std::cout << "ù ��° ���� ó��\n";
	processor->Process(doc1);
	std::cout << "\n";

	// �� ��° ���� ó��
	std::cout << "�� ��° ���� ó��\n";
	processor->Process(doc2);
	std::cout << "\n";

	// �޸� ����
	delete processor;

	return 0;
}
