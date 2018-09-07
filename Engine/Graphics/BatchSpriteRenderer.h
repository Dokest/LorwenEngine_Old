#pragma once

#include "Maths/Maths.h"

#include "BaseRenderer.h"

#include "IndexBuffer.h"
#include "VertexBuffer.h"
#include "VertexBufferLayout.h"
#include "VertexArray.h"

#include <vector>

#define RENDERER_MAX_SPRITES	60000
#define RENDERER_VERTEX_SIZE	sizeof(BatchSprite)
#define RENDERER_SPRITE_SIZE	RENDERER_VERTEX_SIZE * 4
#define RENDERER_BUFFER_SIZE	RENDERER_SPRITE_SIZE * RENDERER_MAX_SPRITES
#define RENDERER_INDICES_SIZE	RENDERER_MAX_SPRITES * 6

#define SHADER_VERTEX_INDEX	0
#define SHADER_COLOR_INDEX	1

struct BatchSprite
{
	Maths::Vec2 Vertex;
	Maths::Vec4 Color;
};

struct RenderObject
{
	class LSpriteComponent* sprite;
	BatchSprite* vertexArray;
};


class BatchSpriteRenderer : public BaseRenderer
{
private:
	VertexBuffer* m_VBO;
	unsigned int m_VBOI;
	VertexArray* m_VAO;
	unsigned int m_VAOI;
	IndexBuffer* m_IBO;
	VertexBufferLayout* m_Layout;
	
	unsigned int VBO;
	unsigned int VAO;
	unsigned int IBO;

	BatchSprite* m_SpritesBuffer;
	BatchSprite* m_Buffer;

	unsigned int m_IndexCount;

	std::vector<class LSpriteComponent> m_Sprites;

	int CurrentSprites;
	int MaxSprites;

public:
	BatchSpriteRenderer();
	~BatchSpriteRenderer();

	void Init();

	void SubmitSprite(class SpriteRen* sprite);
	void SubmitSprite(std::vector<class SpriteRen*>* sprites, GLenum drawType);

	void Submit(LRenderableComponent* renderable);
	void Submit(LSpriteComponent& sprite);

	void Init2();
	void Submit2(LSpriteComponent& sprite);
	void Render2();

	void Render();



	void Begin();
	void End();

};
