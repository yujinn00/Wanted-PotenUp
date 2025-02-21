#include "Bounds.h"

bool Bounds::Intersects(const Bounds& other) const
{
    // �ٸ� ������ ���� ������ ������ �ٱ��� �ִ� ���.
    if (other.x > MaxX()) return false;

    // �ٸ� ������ ���� ������ ���� �ٱ��� �ִ� ���.
    if (other.MaxX() < x) return false;

    // �ٸ� ������ ���� ������ �Ʒ������� ��� ���.
    if (other.y > MaxY()) return false;

    // �ٸ� ������ ���� ������ �������� ��� ���.
    if (other.MaxY() < y) return false;

    //return !(other.x > GetMaxX() || other.GetMaxX() < x || other.y > GetMaxY() || other.GetMaxY() < y);
    return true;
}
