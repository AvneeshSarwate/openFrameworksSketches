#version 150

uniform mat4 modelViewProjectionMatrix;
uniform float time;

in vec4 position;
in vec2 texcoord;

out vec2 texCoordVarying;

void main(){
    vec4 pos = position;
    pos.y += (sin(time+position.x*20)+1.)/2. * 50;
	gl_Position = modelViewProjectionMatrix * pos;
}
