#pragma once
#include <wrl.h>
namespace Engine {
	class DXGIDebug : public Microsoft::WRL::ComPtr<IDXGIDebug>
	{
	public:
		DXGIDebug() = default;
		static inline DXGIDebug& Get() { return pInstance; };
		void Enable();
		void getLiveObjects();

	private:
		static DXGIDebug pInstance;
		void getInterface();
	};
}
