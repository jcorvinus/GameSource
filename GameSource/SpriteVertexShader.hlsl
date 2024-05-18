struct Input
{
	float4 position : SV_POSITION;
	float3 color : COLOR;
	// todo: add texcoord here
};

struct Output
{
	float4 position : SV_POSITION;
	float3 color : COLOR;
};

Output main(Input input)
{
	Output output; 
	output.position = float4(input.position.x, input.position.y, 0, 1);
	output.color = input.color;

	return output;
}