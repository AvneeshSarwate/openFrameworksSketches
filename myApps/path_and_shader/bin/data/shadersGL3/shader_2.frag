#version 150

out vec4 outputColor;
uniform float time;

in vec2 texCoordVarying;
uniform vec2 resolution;

void main()
{
    // gl_FragCoord contains the window relative coordinate for the fragment.
    // we use gl_FragCoord.x position to control the red color value.
    // we use gl_FragCoord.y position to control the green color value.
    // please note that all r, g, b, a values are between 0 and 1.
    
    float windowWidth = 1024.0;
    float windowHeight = 768.0;
    
	float r = gl_FragCoord.x / windowWidth;
	float g = gl_FragCoord.y / windowHeight;

	// r = texCoordVarying.r;
	// g = texCoordVarying.g;

	float b = (sin(time*3.1415)+1)/2;
	float a = 1.0;
	outputColor = vec4(r, g, b, a);
}
