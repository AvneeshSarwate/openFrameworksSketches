#version 150

out vec4 outputColor;
in vec2 uv;

uniform vec2 resolution;


void main()
{
    // gl_FragCoord contains the window relative coordinate for the fragment.
    // we use gl_FragCoord.x position to control the red color value.
    // we use gl_FragCoord.y position to control the green color value.
    // please note that all r, g, b, a values are between 0 and 1.
    
    float windowWidth = 1024.0;
    float windowHeight = 768.0;
    
	float xn = gl_FragCoord.x / windowWidth;
	float yn = gl_FragCoord.y / windowHeight;

	outputColor = vec4(uv.x, uv.y, 1, 1);
}