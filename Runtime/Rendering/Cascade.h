/*
Copyright(c) 2016-2018 Panos Karabelas

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and / or sell
copies of the Software, and to permit persons to whom the Software is furnished
to do so, subject to the following conditions :

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#pragma once

//= INCLUDES ==================
#include <memory>
#include "../Core/EngineDefs.h"
//=============================

namespace Directus
{
	class Camera;
	class Context;
	class D3D11_RenderTexture;
	namespace Math
	{
		class Matrix;
		class Vector3;
	}

	class ENGINE_CLASS Cascade
	{
	public:
		Cascade(int resolution, Camera* camera, Context* context);
		~Cascade() {}

		void SetAsRenderTarget();
		void* GetShaderResource();
		Math::Matrix ComputeProjectionMatrix(int cascadeIndex, const Math::Vector3& centerPos, const Math::Matrix& viewMatrix);
		float GetSplit(int cascadeIndex);

	private:
		std::unique_ptr<D3D11_RenderTexture> m_depthMap;
		int m_resolution;
		Camera* m_camera;
	};
}