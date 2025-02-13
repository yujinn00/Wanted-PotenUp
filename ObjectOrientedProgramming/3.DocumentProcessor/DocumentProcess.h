#pragma once

#include "Document.h"

#include <iostream>

// 문서를 처리하는 유틸리티 클래스
// 맞춤법 검사, 페이지 재설정, 번역 기능 포함
class DocumentProcess
{
public:
	static void TranslateIntoFrench(const Document& document)
	{
		std::cout << "프랑스어 변역 완료\n";
	}

	static void SpellCheck(const Document& document)
	{
		std::cout << "문서 맞춤법 검사 완료\n";
	}

	static void Repaginate(const Document& document)
	{
		std::cout << "문서 페이지 재설정 완료\n";
	}
};
