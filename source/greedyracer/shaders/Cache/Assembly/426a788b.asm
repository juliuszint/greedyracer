//
// Generated by Microsoft (R) HLSL Shader Compiler 9.29.952.3111
//
//
// Buffer Definitions: 
//
// cbuffer TexInfo
// {
//
//   float4 f4ColorAmbient;             // Offset:    0 Size:    16 [unused]
//   float fA;                          // Offset:   16 Size:     4 [unused]
//   float fH;                          // Offset:   20 Size:     4 [unused]
//   float fBumpStrength;               // Offset:   24 Size:     4 [unused]
//   float frTransparency;              // Offset:   28 Size:     4 [unused]
//   float4 f4ColorSSS;                 // Offset:   32 Size:    16 [unused]
//   float4 f4SSSBRDFParams;            // Offset:   48 Size:    16 [unused]
//   uint uImage;                       // Offset:   64 Size:     4 [unused]
//   uint uGlow;                        // Offset:   68 Size:     4 [unused]
//   uint uSpecular;                    // Offset:   72 Size:     4 [unused]
//   uint uBump;                        // Offset:   76 Size:     4 [unused]
//   uint uImageBlack;                  // Offset:   80 Size:     4 [unused]
//   uint uGlowAsImage;                 // Offset:   84 Size:     4 [unused]
//   uint uSpecularAsImage;             // Offset:   88 Size:     4 [unused]
//   uint uHeightAsImage;               // Offset:   92 Size:     4 [unused]
//   uint uImageWhite;                  // Offset:   96 Size:     4 [unused]
//   uint uGlowWhite;                   // Offset:  100 Size:     4 [unused]
//   uint uSpecularWhite;               // Offset:  104 Size:     4 [unused]
//   uint uHeight;                      // Offset:  108 Size:     4 [unused]
//   uint uShadingOn;                   // Offset:  112 Size:     4 [unused]
//   uint uGlowAsAmbient;               // Offset:  116 Size:     4 [unused]
//   uint uChromaKeying;                // Offset:  120 Size:     4
//   uint uEnvironment;                 // Offset:  124 Size:     4 [unused]
//   uint uPOM;                         // Offset:  128 Size:     4 [unused]
//   uint uTexBRDF;                     // Offset:  132 Size:     4 [unused]
//   uint uTexSSS;                      // Offset:  136 Size:     4 [unused]
//   uint uReflectionMap;               // Offset:  140 Size:     4 [unused]
//   uint uixPos;                       // Offset:  144 Size:     4 [unused]
//   uint uiyPos;                       // Offset:  148 Size:     4 [unused]
//   uint uixPics;                      // Offset:  152 Size:     4 [unused]
//   uint uiyPics;                      // Offset:  156 Size:     4 [unused]
//
// }
//
//
// Resource Bindings:
//
// Name                                 Type  Format         Dim Slot Elements
// ------------------------------ ---------- ------- ----------- ---- --------
// linearSampler                     sampler      NA          NA    0        1
// tex2D[0]                          texture  float4          2d   15        1
// TexInfo                           cbuffer      NA          NA    5        1
//
//
//
// Input signature:
//
// Name                 Index   Mask Register SysValue Format   Used
// -------------------- ----- ------ -------- -------- ------ ------
// SV_POSITION              0   xyzw        0      POS  float       
// NORMAL                   0   xyz         1     NONE  float       
// TANGENT                  0   xyz         2     NONE  float       
// BITANGENT                0   xyz         3     NONE  float       
// TEXCOORD                 0   xy          4     NONE  float   xy  
// TEXCOORD                 2   xyzw        5     NONE  float       
//
//
// Output signature:
//
// Name                 Index   Mask Register SysValue Format   Used
// -------------------- ----- ------ -------- -------- ------ ------
// SV_Target                0   xyzw        0   TARGET  float   xyzw
//
ps_5_0
dcl_globalFlags refactoringAllowed
dcl_constantbuffer cb5[8], immediateIndexed
dcl_sampler s0, mode_default
dcl_resource_texture2d (float,float,float,float) t15
dcl_input_ps linear v4.xy
dcl_output o0.xyzw
dcl_temps 7

#line 99 "\\?\C:\Users\admin\Documents\Visual Studio 2010\Projects\Vektoria_2015-02-12a\Vektoria\trunk\VektoriaApp\shaders\Source\sprites.hlsl"
sample_indexable(texture2d)(float,float,float,float) r0.xyzw, v4.xyxx, t15.xyzw, s0  // f4TexCol<0:Inf,1:Inf,2:Inf,3:Inf>
ine r1.x, l(0, 0, 0, 0), cb5[7].z
if_nz r1.x

#line 106
  resinfo_indexable(texture2d)(float,float,float,float)_uint r1.xy, l(0), t15.xyzw  // iWidth<0>, iHeight<0>, iLevels<0>

#line 109
  utof r1.x, r1.x
  mul r2.x, r1.x, v4.x  // f2TexCoord2<0:Inf>
  utof r1.x, r1.y
  mul r2.y, r1.x, v4.y  // f2TexCoord2<1:Inf>

#line 114
  ld_indexable(texture2d)(float,float,float,float) r1.xyz, l(0, 0, 0, 0), t15.xyzw  // f4ChromaKey<0:Inf,1:Inf,2:Inf,3:Inf>

#line 123
  add r2.zw, r2.xxxy, l(0.000000, 0.000000, -0.500000, -0.500000)  // f2TexPos1<0:Inf,1:Inf>
  add r3.xy, r2.xyxx, l(0.500000, -0.500000, 0.000000, 0.000000)  // f2TexPos2<0:Inf,1:Inf>
  add r3.zw, r2.xxxy, l(0.000000, 0.000000, -0.500000, 0.500000)  // f2TexPos3<0:Inf,1:Inf>
  add r2.xy, r2.xyxx, l(0.500000, 0.500000, 0.000000, 0.000000)  // f2TexPos4<0:Inf,1:Inf>
  ftoi r4.xy, r2.zwzz
  mov r4.zw, l(0,0,0,0)
  ld_indexable(texture2d)(float,float,float,float) r4.xyzw, r4.xyzw, t15.xyzw  // f4Col1<0:Inf,1:Inf,2:Inf,3:Inf>
  ftoi r5.xy, r3.xyxx
  mov r5.zw, l(0,0,0,0)
  ld_indexable(texture2d)(float,float,float,float) r5.xyzw, r5.xyzw, t15.xyzw  // f4Col2<0:Inf,1:Inf,2:Inf,3:Inf>
  ftoi r3.xy, r3.zwzz
  mov r3.zw, l(0,0,0,0)
  ld_indexable(texture2d)(float,float,float,float) r3.xyzw, r3.xyzw, t15.xyzw  // f4Col3<0:Inf,1:Inf,2:Inf,3:Inf>
  ftoi r6.xy, r2.xyxx
  mov r6.zw, l(0,0,0,0)
  ld_indexable(texture2d)(float,float,float,float) r6.xyzw, r6.xyzw, t15.xyzw  // f4Col4<0:Inf,1:Inf,2:Inf,3:Inf>
  eq r1.w, r4.x, r1.x
  eq r2.x, r4.y, r1.y
  and r1.w, r1.w, r2.x
  eq r2.x, r4.z, r1.z
  and r1.w, r1.w, r2.x
  if_nz r1.w
    mov r4.x, l(0)  // f4Col1<0: 0f>
    mov r4.y, l(0)  // f4Col1<1: 0f>
    mov r4.z, l(0)  // f4Col1<2: 0f>
    mov r4.w, l(0)  // f4Col1<3: 0f>
  endif 
  eq r1.w, r5.x, r1.x
  eq r2.x, r5.y, r1.y
  and r1.w, r1.w, r2.x
  eq r2.x, r5.z, r1.z
  and r1.w, r1.w, r2.x
  if_nz r1.w
    mov r5.xyzw, l(0,0,0,0)  // f4Col2<0: 0f,1: 0f,2: 0f,3: 0f>
  endif 
  eq r1.w, r3.x, r1.x
  eq r2.x, r3.y, r1.y
  and r1.w, r1.w, r2.x
  eq r2.x, r3.z, r1.z
  and r1.w, r1.w, r2.x
  if_nz r1.w
    mov r3.x, l(0)  // f4Col3<0: 0f>
    mov r3.y, l(0)  // f4Col3<1: 0f>
    mov r3.z, l(0)  // f4Col3<2: 0f>
    mov r3.w, l(0)  // f4Col3<3: 0f>
  endif 

#line 134
  eq r1.x, r6.x, r1.x
  eq r1.y, r6.y, r1.y
  and r1.x, r1.y, r1.x
  eq r1.y, r6.z, r1.z
  and r1.x, r1.y, r1.x
  if_nz r1.x
    mov r6.xyzw, l(0,0,0,0)  // f4Col4<0: 0f,1: 0f,2: 0f,3: 0f>
  endif 
  frc r1.x, r2.z  // f2TexPos1<0:NaN>
  frc r1.y, r2.w  // f2TexPos1<1:NaN>

#line 138
  mov r1.z, -r4.w
  add r1.z, r1.z, r5.w
  mul r1.z, r1.x, r1.z
  add r1.z, r4.w, r1.z  // fAlpha<0:NaN:Inf>
  mov r1.w, -r3.w
  add r1.w, r1.w, r6.w
  mul r1.w, r1.x, r1.w
  add r1.w, r3.w, r1.w
  mov r2.x, -r1.z
  add r1.w, r1.w, r2.x
  mul r1.w, r1.y, r1.w
  add r0.w, r1.z, r1.w  // fAlpha<0:NaN:Inf>

#line 148
  mov r1.z, -r4.x
  add r1.z, r1.z, r5.x
  mul r1.z, r1.x, r1.z
  add r1.z, r4.x, r1.z  // f4Col1<0:NaN:Inf>
  mov r1.w, -r4.y
  add r1.w, r1.w, r5.y
  mul r1.w, r1.x, r1.w
  add r1.w, r4.y, r1.w  // f4Col1<1:NaN:Inf>
  mov r2.x, -r4.z
  add r2.x, r2.x, r5.z
  mul r2.x, r1.x, r2.x
  add r2.x, r4.z, r2.x  // f4Col1<2:NaN:Inf>

#line 153
  mov r2.y, -r3.x
  add r2.y, r2.y, r6.x
  mul r2.y, r1.x, r2.y
  add r2.y, r3.x, r2.y  // f4Col3<0:NaN:Inf>
  mov r2.z, -r3.y
  add r2.z, r2.z, r6.y
  mul r2.z, r1.x, r2.z
  add r2.z, r3.y, r2.z  // f4Col3<1:NaN:Inf>
  mov r2.w, -r3.z
  add r2.w, r2.w, r6.z
  mul r1.x, r1.x, r2.w
  add r1.x, r3.z, r1.x  // f4Col3<2:NaN:Inf>

#line 158
  mov r2.w, -r1.z
  add r2.y, r2.w, r2.y
  mul r2.y, r1.y, r2.y
  add r0.x, r1.z, r2.y  // f4TexCol<0:NaN:Inf>
  mov r1.z, -r1.w
  add r1.z, r1.z, r2.z
  mul r1.z, r1.y, r1.z
  add r0.y, r1.w, r1.z  // f4TexCol<1:NaN:Inf>
  mov r1.z, -r2.x
  add r1.x, r1.z, r1.x
  mul r1.x, r1.y, r1.x
  add r0.z, r2.x, r1.x  // f4TexCol<2:NaN:Inf>
  mov r0.w, r0.w  // f4TexCol<3:NaN:Inf>

#line 101
endif 

#line 170
mov o0.xyzw, r0.xyzw  // RenderSpritesPS<0:NaN:Inf,1:NaN:Inf,2:NaN:Inf,3:NaN:Inf>
ret 
// Approximately 117 instruction slots used