#pragma once

namespace ly
{
	class Object
	{
	public:
		Object();
		virtual ~Object();

		void Destroy();
		bool IsPendingDestruction() const { return bIsPendingDestruction; }

	private:
		bool bIsPendingDestruction;
	};
}