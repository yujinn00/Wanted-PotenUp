#pragma once

// 사각형 영역을 표현하는 클래스.
class Bounds
{
public:
    // 생성자.
    Bounds(float x, float y, float width = 1.0f, float height = 1.0f)
        : x(x), y(y), width(width), height(height)
    {
    }

    // Getter.
    float X() const { return x; }
    float Y() const { return y; }
    float Width() const { return width; }
    float Height() const { return height; }

    float MaxX() const { return x + width; }
    float MaxY() const { return y + height; }

    // 다른 사각형과 교차하는지 확인.
    bool Intersects(const Bounds& other) const;

    // Setter.
    void SetX(float x) { this->x = x; }
    void SetY(float y) { this->y = y; }
    void SetWidth(float width) { this->width = width; }
    void SetHeight(float height) { this->height = height; }

private:
    // 좌측 상단 기준.
    float x = 0.0f;
    float y = 0.0f;
    float width = 1.0f;
    float height = 1.0f;
};
