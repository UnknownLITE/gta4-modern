#ifndef D9HOOK_HPP
#define D9HOOK_HPP
#include <d3d9.h>
#include <cstdint>
extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

using tEndScene = HRESULT(APIENTRY*)(LPDIRECT3DDEVICE9 pDevice);
using tReset = HRESULT(APIENTRY*)(D3DPRESENT_PARAMETERS* pPresentationParameters);

class d9
{
	friend class d9draw;
public:
	static IDirect3DDevice9* pDevice;
	static tEndScene oEndScene;
	static HWND window;
	static HMODULE hDDLModule;

	static void HookDirectX();
	static void UnHookDirectX();
	static void HookWindow();
	static void UnHookWindow();

	static bool WantsMouse(); // does imgui/d9 want the mouse ?

private:
	static int windowHeight, windowWidth;
	static void* d3d9Device[119];
	static WNDPROC OWndProc;
	static tReset oReset;
	static bool isMouseWanted;

	static BOOL CALLBACK enumWind(HWND handle, LPARAM lp);
	static HWND GetProcessWindow();
	static BOOL GetD3D9Device(void** pTable, size_t size);
	static LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	static HRESULT APIENTRY hkReset(D3DPRESENT_PARAMETERS* pPresentationParameters);
};
#endif /* D9HOOK_HPP */
