#pragma once

#include "Document.h"

// ���� ó�� �������̽� (��)
class IDocumentProcess
{
public:
    virtual void Process(const Document& document) = 0;
};
