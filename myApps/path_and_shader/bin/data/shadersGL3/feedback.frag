#version 150

out vec4 outputColor;
uniform float time;
uniform sampler2DRect currentColor;
uniform sampler2DRect currentDepth;
uniform sampler2DRect lastColor;
uniform sampler2DRect lastDepth; 

uniform vec2 resolution;

in vec2 texCoordVarying;
in vec2 uv;

float sinN(float t) { return (sin(t)+1)/2;}

void main()
{
    // gl_FragCoord contains the window relative coordinate for the fragment.
    // we use gl_FragCoord.x position to control the red color value.
    // we use gl_FragCoord.y position to control the green color value.
    // please note that all r, g, b, a values are between 0 and 1.
    
    float windowWidth = 1024.0;
    float windowHeight = 768.0;
    vec4 col = texture(currentColor, gl_FragCoord.xy);
    vec4 lastCol = texture(lastColor, gl_FragCoord.xy);
    
	
	outputColor = vec4(mix(col, lastCol, 0.9));
}
