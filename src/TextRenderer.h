#pragma once
#include <GL/glew.h>
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include <ft2build.h>
#include FT_FREETYPE_H

#include <map>
#include <string>

struct Character {

	GLuint		TextureID;	// Her glif dokusunun doku kimligi
	glm::ivec2	Size;		// glif boyutu
	glm::ivec2	Bearing;	// glifin sol-ust kosesinden glifin
							// taban cizgisine olan mesafe(yatak)
	GLuint		Advance;	// bir sonraki glifin kimligi 
};

class TextRenderer
{
public:
	TextRenderer(
		std::string text,
		std::string font,
		int			size,
		glm::vec3	color,
		GLuint		program);
	~TextRenderer();

	void draw();
	void setPosition(glm::vec2 _position);
	void setText(std::string _text);

private:
	std::string					text;
	GLfloat						scale;
	glm::vec3					color;
	glm::vec2					position;

	GLuint						VAO, VBO, program;
	std::map<GLchar, Character> Characters;
};

