// Fragment Shader – file "base.frag"

#version 150 core

in vec2 texCoord0;
//in vec3 fragmentNormal;
//in vec3 lightDirection;
//in vec3 incidentLightPosition;

uniform sampler2D sTex0;

out vec4 fragmentColor0;

void main(void)
{
	fragmentColor0 = texture2D(sTex0, texCoord0);
}
