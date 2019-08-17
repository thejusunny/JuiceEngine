struct PS_INPUT
{
    float4 inPos : SV_POSITION;
    float2 inTexCoord : TEXCOORD;
   
    
};
Texture2D objTexture : TEXTURE : register(t0);
SamplerState objSamplerState : TEXTURE : register(s0); 

float4 main(PS_INPUT input):SV_Target
{

    
    float3 pixelColor = objTexture.Sample(objSamplerState, input.inTexCoord);
    return float4( pixelColor,1.0f);

}