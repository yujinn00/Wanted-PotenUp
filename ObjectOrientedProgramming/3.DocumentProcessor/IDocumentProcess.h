#pragma once

#include "Document.h"

// 문서 처리 인터페이스 (명세)
class IDocumentProcess
{
public:
    virtual void Process(const Document& document) = 0;
};
