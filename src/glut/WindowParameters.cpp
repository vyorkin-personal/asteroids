#include "glut/WindowParameters.hpp"

namespace glut {
    WindowParameters::WindowParameters(const char* title, const Point2i& position,
	const Size& size, const bool fullscreen):
	title{title}, position{position},
	size{size}, fullscreen{fullscreen} {
    
	clearColor = Color4f::Black;
	doubleBuffer = true;
	multisampling = true;
    }

    unsigned int WindowParameters::getDisplayModeFlag() const {
        unsigned int flag = GLUT_RGBA;

        if (doubleBuffer)
            flag |= GLUT_DOUBLE;
        if (depthBuffer)
            flag |= GLUT_DEPTH;
        if (multisampling)
            flag |= GLUT_MULTISAMPLE;

        return flag;
    }

    unsigned int WindowParameters::getClearFlag() const {
	unsigned int flag = GL_COLOR_BUFFER_BIT;

	if (depthBuffer)
	    flag |= GL_DEPTH_BUFFER_BIT;
	if (stencilBuffer)
	    flag |= GL_STENCIL_BUFFER_BIT;
	if (accumBuffer)
	    flag |= GL_ACCUM_BUFFER_BIT;

	return flag;
    }

    WindowParameters WindowParameters::Default = WindowParameters(
	"OpenGL window",
	Point2i(POSITION_X_DEFAULT, POSITION_Y_DEFAULT),
	Size(WIDTH_DEFAULT, HEIGHT_DEFAULT)
    );
}
