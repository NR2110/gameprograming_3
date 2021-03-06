#pragma once

#include <d3d11.h>
#include <d3dcompiler.h>
#include <DirectXMath.h>

#include <memory>
#include <wrl.h>
using Microsoft::WRL::ComPtr;

#include <assert.h>

namespace Adollib {
	class Shader
	{
	protected:
		ComPtr<ID3D11VertexShader>		VS = nullptr; // 頂点シェーダ
		ComPtr<ID3D11PixelShader>		PS = nullptr; // ピクセルシェーダ
		ComPtr<ID3D11GeometryShader>	GS = nullptr; // ジオメトリシェーダ
		ComPtr<ID3D11HullShader>		HS = nullptr; //　ハルシェーダ
		ComPtr<ID3D11DomainShader>		DS = nullptr; //　ドメインネームシェーダ

		HRESULT Compile(WCHAR* filename, LPCSTR method, LPCSTR shaderModel, ID3DBlob** ppBlobOut);


	public:

		Shader() { /*ZeroMemory(this, sizeof(Shader));*/ }
		virtual ~Shader();

		void Load_VS(const char* csoName,ID3D11InputLayout** inputLayout,D3D11_INPUT_ELEMENT_DESC* inputElementDesc,  UINT numElements);
		void Load_PS(const char* cso_name);
		void Load_GS(const char* cso_name);
		void Load_HS(const char* cso_name);
		void Load_DS(const char* cso_name);

		void Activate();
	};


	//----------------------------------------------
	//
	//	頂点データ構造体定義
	//
	//----------------------------------------------

	struct VERTEX
	{
		DirectX::XMFLOAT3 Pos;	//位置
		DirectX::XMFLOAT3 Normal;//法線
		DirectX::XMFLOAT2 Tex;	//UV座標
		DirectX::XMFLOAT4 Color;	//頂点色
	};
}