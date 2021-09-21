#version 150

uniform mat4 modelViewProjectionMatrix;
uniform vec4 bbox; //bbox is (x, y, width, height) with x/y being top-left
uniform vec2 resolution;

in vec4 position;
in vec2 texcoord;

out vec2 texCoordVarying;
out vec2 uv;

void main(){
	uv.x = (position.x - bbox.x) / bbox.z;
	uv.y = (position.y - bbox.y) / bbox.w;
	gl_Position = modelViewProjectionMatrix * position;
}
