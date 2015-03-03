#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <GL/glew.h>
#include <GL/glut.h>

#include "vector2f.h"
#include "display.h"

#include "application.h"

#include "shader.h"

Application::Application() {
	// TODO
	lights.clear();
	blocks.clear();

	srand48(time(0));

	// TODO: not yet assigned.
	width_ = -1;
	height_ = -1;
	fragmentShader_ = -1;
	shaderProgram_ = -1;	
}

Application::~Application() {
	// TODO : delete and empty lights.
	// TODO : delete and empty blocks.
	// TODO : delete and free shader.
}

void Application::size(int w, int h) {
	width_ = w;
	height_ = h;
}

void Application::setupObjects() {

	int lightCount = 2 + (int) (drand48() * 1);
	int blockCount = 5 + (int) (drand48() * 1);

	// Create lights in the scene.
	for(int i=1; i<=lightCount; i++) {
		// TODO : define Vector2f class.
		Vector2f* location = new Vector2f( (float) drand48() * width_, (float) drand48() * height_ );
		lights.push_back(new Light(location, (float) drand48() * 30.0, (float) drand48() * 30.0, (float) drand48() * 30.0));
	}

	// Create blocks in the scene.
	for(int i=1; i<=blockCount; i++) {
		int w = 50;
		int h = 50;
		int x = (int) (drand48() * (width_-w));
		int y = (int) (drand48() * (height_-h));
		blocks.push_back(new Block(x, y, w, h));
	}
}

void Application::initialize() {

	//DEBUG
	printf("SHADER SOURCE\n%s\n", shader_src);

	// TODO : This is mainly display initialization. Come up with a proper class for it.
	shaderProgram_ = glCreateProgram();
	fragmentShader_ = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader_, 1, &shader_src, NULL);
	glCompileShader(fragmentShader_);

	GLint compile_status;
	glGetShaderiv(fragmentShader_, GL_COMPILE_STATUS, &compile_status);
	if( !compile_status ) {
		fprintf(stderr, "Shader unable to compile.");
	}

	glAttachShader(shaderProgram_, fragmentShader_);
	glLinkProgram(shaderProgram_);
	glValidateProgram(shaderProgram_);

	// DEBUG
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width_, height_, 0, 1, -1);
	glMatrixMode(GL_MODELVIEW);
	// END

	glEnable(GL_STENCIL_TEST);
	glClearColor(0.0, 0.0,  0.0, 0.0);
}

void Application::drawBlocks() {

	glColor3f(0.0, 0.0, 0.0);
	std::vector< Block* >::iterator iBlock;
	for(iBlock=blocks.begin(); iBlock!=blocks.end(); ++iBlock) {
		std::vector< Vector2f* > vertices;
		vertices = (*iBlock)->GetVertices();
		glBegin(GL_QUADS);
			std::vector< Vector2f* >::iterator iVertex;
			for(iVertex=vertices.begin(); iVertex!=vertices.end(); iVertex++) {
				glVertex2i((*iVertex)->X(), (*iVertex)->Y());
			}
		glEnd();
	}
}

void Application::drawLights(Light* light) {

		// Begin Shader Program
		glUseProgram(shaderProgram_);

		// Light Location
		GLint u_light_location;
		u_light_location = glGetUniformLocation(shaderProgram_, "lightLocation");
		if( u_light_location == -1 ) {
			fprintf(stderr, "Could not bind 'lightLocation'.\n");
			exit(0);
		}

		glUniform2f(u_light_location, light->Location()->X(), height_ - light->Location()->Y());

		// Light Color
		GLint u_light_color;
		u_light_color = glGetUniformLocation(shaderProgram_, "lightColor");
		if( u_light_color == -1 ) {
			fprintf(stderr, "Could not bind 'lightColor'.\n");
			exit(0);
		}

		glUniform3f(u_light_color, light->Red(), light->Green(), light->Blue());
		// End Shader Program

		glEnable(GL_BLEND);
		glBlendFunc(GL_ONE, GL_ONE);

		glBegin(GL_QUADS);
			glVertex2f(0.0, 0.0);
			glVertex2f(0.0, height_);
			glVertex2f(width_, height_);
			glVertex2f(width_, 0.0);
		glEnd();

		glDisable(GL_BLEND);
		glUseProgram(0);
		glClear(GL_STENCIL_BUFFER_BIT);
}

void Application::drawBlockShadows(Light* light) {

	std::vector< Block* >::iterator iBlock;
	// And for each light, loop in blocks.
	for(iBlock=blocks.begin(); iBlock!=blocks.end(); ++iBlock) {
		std::vector< Vector2f* > vertices;
		vertices = (*iBlock)->GetVertices();
		// Loop in vertices.
		for(unsigned int i=0; i<vertices.size(); i++) {
			//DEBUG
			//printf("Vertex(%.1f, %.1f)\n", vertices[i]->X(), vertices[i]->Y());
			Vector2f currentVertex = *vertices[i];
			Vector2f nextVertex = *vertices[(i+1) % vertices.size()];
			Vector2f edge = nextVertex.sub( currentVertex );
			Vector2f normal(edge.Y(), -edge.X());
			Vector2f lightToCurrent = currentVertex.sub( *(light)->Location() );
			if( normal.dot( lightToCurrent ) > 0 ) {

				Vector2f lightToNext = nextVertex.sub( *(light)->Location() );
				Vector2f point1 = currentVertex.add( lightToCurrent.scale(width_) );
				Vector2f point2 = nextVertex.add( lightToNext.scale(width_) );

				glBegin(GL_QUADS);
					glVertex2f(currentVertex.X(), currentVertex.Y());
					glVertex2f(point1.X(), point1.Y());
					glVertex2f(point2.X(), point2.Y());
					glVertex2f(nextVertex.X(), nextVertex.Y());
				glEnd();

			}
		}
	}
}

void Application::drawAllShadows() {

	std::vector< Light* >::iterator iLight;

	// Loop in lights
	for(iLight=lights.begin(); iLight!=lights.end(); ++iLight) {

		// DEBUG
		glColorMask(false, false, false, false);
		glStencilFunc(GL_ALWAYS, 1, 1);
		glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);
		// END

		drawBlockShadows(*iLight);

		glStencilOp(GL_KEEP, GL_KEEP, GL_KEEP);
		glStencilFunc(GL_EQUAL, 0, 1);
		glColorMask(true, true, true, true);

		drawLights(*iLight);
	}

}

void Application::render() {

	glClear(GL_COLOR_BUFFER_BIT);

	// Compute and draw shadows.
	drawAllShadows();

	// For now, just draw blocks.
	drawBlocks();
}

void Application::cleanup() {

	glDeleteShader(fragmentShader_);
	glDeleteProgram(shaderProgram_);
}