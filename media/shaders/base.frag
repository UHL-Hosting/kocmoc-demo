// Fragment Shader – file "base.frag"

#version 150 core

in vec2 texCoord0;
in vec3 fragmentNormal;
in vec3 worldSpacePosition;
in vec3 shadowUV;

uniform sampler2D sDiffuse;
uniform sampler2D sSpecular;
uniform sampler2D sNormal;
uniform sampler2D sShadow;

uniform mat3 normalMatrix;
uniform vec3 cameraPosition;

out vec4 fragmentColor0;

void main(void)
{
	const vec3 lightDirection = normalize(vec3(-1.0f, -1.0f, -1.0f));
	const vec3 ambientIntensity = vec3(0.01f, 0.01f, 0.01f);

	

	vec3 diffuseColor = texture(sDiffuse, texCoord0).rgb;
	vec3 specularColor = texture(sSpecular, texCoord0).rgb;
	float shinyness = texture(sSpecular, texCoord0).r * 50.0f;
	vec3 normal = texture2D(sNormal, texCoord0).xyz * 2 - 1; // unpack to [-1, 1], 
	vec3 transformed = normalize(normalMatrix * (normal * vec3(-1, 1, -1))); // and flip strangely...???

//	if (worldSpacePosition.x > 0)
//		transformed = normalize(fragmentNormal);

	vec3 ambientTerm = diffuseColor * ambientIntensity;
	float diffuseFactor =  max(dot(-lightDirection, transformed.xyz), 0);
	vec3 diffuseTerm = diffuseColor * diffuseFactor;



	vec3 viewVector = normalize(cameraPosition - worldSpacePosition);
	vec3 reflected = normalize(reflect(lightDirection, transformed.xyz));

	vec3 specularTerm = specularColor * pow(max(dot(viewVector, reflected), 0), shinyness);




	fragmentColor0 = vec4(ambientTerm + diffuseTerm + specularTerm, 1);
//	fragmentColor0 = vec4(shadowUV.zzz / -2 + 0.5, 1);
//	fragmentColor0 = texture(sShadow, shadowUV.xy / 2 + 0.5);
}
