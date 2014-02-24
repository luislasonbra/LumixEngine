#pragma once


#include "core/pod_array.h"


namespace Lux
{
namespace FS
{
	class FileSystem;
	class IFile;
}

class Renderer;
class Shader;
class Texture;


class Material
{
	public:
		Material(Renderer& renderer);

		void load(const char* path, FS::FileSystem& file_system);
		void apply();
		void setShader(Shader* shader) { m_shader = shader; }
		void addTexture(Texture* texture) { m_textures.push(texture); }
		Shader* getShader() { return m_shader; }
		bool isReady() const { return m_is_ready; }

	private:
		void loaded(FS::IFile* file, bool success);

	private:
		Shader*	m_shader;
		PODArray<Texture*> m_textures;
		Renderer& m_renderer;
		bool m_is_ready;
};


} // ~namespace Lux