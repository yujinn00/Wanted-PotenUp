#pragma once

class Ladder
{
public:
	Ladder(float length = 0.0f)
		: length(length)
	{
	}

	// 게터 및 세터
	float GetLength() const { return length; }
	void SetLength(float length) { this->length = length; }

private:
	float length = 0.0f;
};
