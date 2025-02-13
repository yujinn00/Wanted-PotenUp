#pragma once

#include <string>

// Document Ŭ����
class Document
{
public:
    Document(const std::string& author, const std::string& date, const std::string& text)
        : author(author), documentDate(date), text(text)
    {
    }

    std::string GetText() const { return text; };
    void SetText(const std::string& text) { this->text = text; }

    std::string GetDocumentDate() const { return documentDate; }
    void SetDocumentDate(const std::string& documentDate) { this->documentDate = documentDate; }

    std::string GetAuthor() const { return author; }
    void SetAuthor(const std::string& author) { this->author = author; }

private:
    // Document�� ����
    std::string author;

    // Document�� ��¥
    std::string documentDate;

    // Document�� �ؽ�Ʈ
    std::string text;
};
