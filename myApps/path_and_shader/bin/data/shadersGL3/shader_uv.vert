#version 150

uniform mat4 modelViewProjectionMatrix;
uniform vec4 bbox; //bbox is (x, y, width, height) with x/y being top-left

in vec4 position;
out vec2 uv;

void main(){
	uv.x = (position.x - bbox.x) / bbox.z;
	uv.y = (position.y - bbox.y) / bbox.w;
	gl_Position = modelViewProjectionMatrix * position;
}
