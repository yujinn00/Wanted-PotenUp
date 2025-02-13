#pragma once

#include "IDocumentProcess.h"
#include "DocumentProcess.h"

#include <vector>
#include <functional>

// ������ ó���ϴ� ó���� Ŭ����
class DocumentProcessor
{
public:
    // ���� ó���� ���� �Լ� �����͸� �߰��ϴ� �Լ�
    void AddDocumentProcess(std::function<void(const Document&)> process)
    {
        processes.emplace_back(process);
    }

    // ���� ó�� �Լ�
    void Process(const Document& document)
    {
        for (auto& process : processes)
        {
            process(document);
        }
    }

private:
    // ���� ó���� ����ϴ� �Լ� �����͸� �����ϴ� �迭
    std::vector<std::function<void(const Document&)>> processes;
};
