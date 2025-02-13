#include "Document.h"
#include "DocumentProcess.h"
#include "DocumentProcessor.h"

#include "TranslateIntoFrenchProcess.h"
#include "SpellcheckProcess.h"
#include "RepaginateProcess.h"

#include <iostream>

// 문서 처리자를 구성하는 함수
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
	// 문서 객체 생성
	Document doc1("Jake Oh", "2025.02.13", "C++ Programming");
	Document doc2("Ian Tim", "2024.01.31", "Hello Iphone");

	// 문서 처리자 객체 생성
	DocumentProcessor* processor = Configure();

	// 첫 번째 문서 처리
	std::cout << "첫 번째 문서 처리\n";
	processor->Process(doc1);
	std::cout << "\n";

	// 두 번째 문서 처리
	std::cout << "두 번째 문서 처리\n";
	processor->Process(doc2);
	std::cout << "\n";

	// 메모리 해제
	delete processor;

	return 0;
}
