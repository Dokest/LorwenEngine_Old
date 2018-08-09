#version 330 core

layout (location = 0) in vec2 position;
layout (location = 1) in vec4 spriteColour;

out vec4 SpriteColor;

uniform mat4 pr_matrix = mat4(1.0);
uniform mat4 vw_matrix = mat4(1.0);
uniform mat4 ml_matrix = mat4(1.0);

void main()
{
	gl_Position = pr_matrix * vec4(position.x, position.y, 0.0, 1.0);
	//gl_Position = vec4(position.x, position.y, 0.0, 0.0);
	SpriteColor = spriteColour;
}


//		Position.x,  Position.y + Size.y,			Color.x, Color.y, Color.z, Color.w,
//		Position.x + Size.x,  Position.y + Size.y,	Color.x, Color.y, Color.z, Color.w,
//		Position.x + Size.x,  Position.y,			Color.x, Color.y, Color.z, Color.w,
//		Position.x,  Position.y,					Color.x, Color.y, Color.z, Color.w,


//		float vertex[] = {
//			 /* VERTEX */		/* COLOR */
//			-0.5f,  0.5f,			0.0f, 0.0f, 1.0f, 1.0f,
//			 0.5f,  0.5f,			0.0f, 0.0f, 1.0f, 1.0f,
//			 0.5f, -0.5f,			0.0f, 0.0f, 1.0f, 1.0f,
//			-0.5f, -0.5f,			0.0f, 0.0f, 1.0f, 1.0f
//		};
//
//		glGenVertexArrays(1, &VAO);
//
//		glGenBuffers(1, &VBO);
//		glBindBuffer(GL_ARRAY_BUFFER, VBO);
//		
//		glBindVertexArray(VAO);
//		glEnableVertexAttribArray(0);
//		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 6, (const void*)0);
//
// 		glEnableVertexAttribArray(1);
// 		glVertexAttribPointer(1, 4, GL_FLOAT, GL_TRUE, sizeof(float) * 6, (const void*) (2 * sizeof(float)));
//
//		glBufferData(GL_ARRAY_BUFFER, sizeof(vertex), vertex, GL_STATIC_DRAW);
//
//		unsigned int ind[] = 
//		{
//			0, 1, 2,
//			2, 3, 0
//		};
//
//		glGenBuffers(1, &IBO);
//		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
//		glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof(unsigned int), ind, GL_STATIC_DRAW);
