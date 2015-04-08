//
// Generated by Microsoft (R) HLSL Shader Compiler 9.29.952.3111
//
//
// Buffer Definitions: 
//
// cbuffer cbPerObject
// {
//
//   float4x4 g_mWorld;                 // Offset:    0 Size:    64
//
// }
//
// cbuffer cbPerCamera
// {
//
//   float4x4 g_mViewProj;              // Offset:    0 Size:    64
//
// }
//
//
// Resource Bindings:
//
// Name                                 Type  Format         Dim Slot Elements
// ------------------------------ ---------- ------- ----------- ---- --------
// cbPerObject                       cbuffer      NA          NA    0        1
// cbPerCamera                       cbuffer      NA          NA    1        1
//
//
//
// Input signature:
//
// Name                 Index   Mask Register SysValue Format   Used
// -------------------- ----- ------ -------- -------- ------ ------
// POSITION                 0   xyzw        0     NONE  float   xyzw
// NORMAL                   0   xyz         1     NONE  float       
// TEXCOORD                 0   xy          2     NONE  float       
// TANGENT                  0   xyz         3     NONE  float       
// BITANGENT                0   xyz         4     NONE  float       
//
//
// Output signature:
//
// Name                 Index   Mask Register SysValue Format   Used
// -------------------- ----- ------ -------- -------- ------ ------
// SV_POSITION              0   xyzw        0      POS  float   xyzw
//
vs_5_0
dcl_globalFlags refactoringAllowed
dcl_constantbuffer cb0[4], immediateIndexed
dcl_constantbuffer cb1[4], immediateIndexed
dcl_input v0.xyzw
dcl_output_siv o0.xyzw, position
dcl_temps 2

#line 193 "\\?\C:\Users\admin\Documents\Visual Studio 2010\Projects\Vektoria_2015-02-12a\Vektoria\trunk\VektoriaApp\shaders\Source\transperency.hlsl"
dp4 r0.x, v0.xyzw, cb0[0].xyzw  // f4WorldPos<0:NaN:Inf>
dp4 r0.y, v0.xyzw, cb0[1].xyzw  // f4WorldPos<1:NaN:Inf>
dp4 r0.z, v0.xyzw, cb0[2].xyzw  // f4WorldPos<2:NaN:Inf>
dp4 r0.w, v0.xyzw, cb0[3].xyzw  // f4WorldPos<3:NaN:Inf>
dp4 r1.x, r0.xyzw, cb1[0].xyzw  // output<0:NaN:Inf>
dp4 r1.y, r0.xyzw, cb1[1].xyzw  // output<1:NaN:Inf>
dp4 r1.z, r0.xyzw, cb1[2].xyzw  // output<2:NaN:Inf>
dp4 r1.w, r0.xyzw, cb1[3].xyzw  // output<3:NaN:Inf>
mov o0.xyzw, r1.xyzw  // RenderBlendedDepthVS<0:NaN:Inf,1:NaN:Inf,2:NaN:Inf,3:NaN:Inf>
ret 
// Approximately 10 instruction slots used