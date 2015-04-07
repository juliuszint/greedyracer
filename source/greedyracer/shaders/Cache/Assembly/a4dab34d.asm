//
// Generated by Microsoft (R) HLSL Shader Compiler 9.29.952.3111
//
//
// Buffer Definitions: 
//
// cbuffer TexInfo
// {
//
//   float4 f4ColorEffect;              // Offset:    0 Size:    16 [unused]
//   float fBlurStrength;               // Offset:   16 Size:     4 [unused]
//   uint uBlur;                        // Offset:   20 Size:     4 [unused]
//   uint uEnhancedEdges;               // Offset:   24 Size:     4 [unused]
//   uint uMeanFilter;                  // Offset:   28 Size:     4 [unused]
//   float fBloomOriginalIntensity;     // Offset:   32 Size:     4 [unused]
//   float fBloomIntensity;             // Offset:   36 Size:     4 [unused]
//   float fBloomOriginalSaturation;    // Offset:   40 Size:     4 [unused]
//   float fBloomSaturation;            // Offset:   44 Size:     4 [unused]
//   float fRayExposure;                // Offset:   48 Size:     4 [unused]
//   float fRayDecay;                   // Offset:   52 Size:     4 [unused]
//   float fRayDensity;                 // Offset:   56 Size:     4 [unused]
//   float fRayWeight;                  // Offset:   60 Size:     4 [unused]
//   float fTimeDelta;                  // Offset:   64 Size:     4 [unused]
//   float fBloomBlurDistance;          // Offset:   68 Size:     4 [unused]
//   float fDoFFar;                     // Offset:   72 Size:     4 [unused]
//   float fDoFNear;                    // Offset:   76 Size:     4 [unused]
//   float2 f2RayLightPos;              // Offset:   80 Size:     8 [unused]
//   float2 f2rcpFrame;                 // Offset:   88 Size:     8
//   float4 f4rcpFrameOpt;              // Offset:   96 Size:    16 [unused]
//   float4 f4DoFParams;                // Offset:  112 Size:    16 [unused]
//
// }
//
//
// Resource Bindings:
//
// Name                                 Type  Format         Dim Slot Elements
// ------------------------------ ---------- ------- ----------- ---- --------
// linearSampler                     sampler      NA          NA    1        1
// pointSampler                      sampler      NA          NA    2        1
// tex2D[7]                          texture  float4          2d   22        1
// depthblurTex                      texture  float4          2d   24        1
// TexInfo                           cbuffer      NA          NA    7        1
//
//
//
// Input signature:
//
// Name                 Index   Mask Register SysValue Format   Used
// -------------------- ----- ------ -------- -------- ------ ------
// SV_POSITION              0   xyzw        0      POS  float       
// TEXCOORD                 0   xy          1     NONE  float   xy  
// TEXCOORD                 2   xyzw        2     NONE  float       
//
//
// Output signature:
//
// Name                 Index   Mask Register SysValue Format   Used
// -------------------- ----- ------ -------- -------- ------ ------
// SV_TARGET                0   xyzw        0   TARGET  float   xyzw
//
ps_5_0
dcl_globalFlags refactoringAllowed
dcl_immediateConstantBuffer { { 0.206984, 0.224527, 0, 0},
                              { 0.525808, -0.231082, 0, 0},
                              { 0.138394, 0.905612, 0, 0},
                              { 0.663301, 0.512984, 0, 0},
                              { -0.400279, 0.372706, 0, 0},
                              { 0.079128, -0.651292, 0, 0},
                              { -0.772607, -0.515122, 0, 0},
                              { -0.384319, -0.149413, 0, 0},
                              { -0.910778, 0.250063, 0, 0},
                              { 0.694015, -0.709893, 0, 0},
                              { -0.196467, -0.379389, 0, 0},
                              { -0.476929, 0.184086, 0, 0},
                              { -0.247328, -0.879846, 0, 0},
                              { 0.420654, -0.714772, 0, 0},
                              { 0.582935, -0.097942, 0, 0},
                              { 0.369184, 0.414064, 0, 0} }
dcl_constantbuffer cb7[6], immediateIndexed
dcl_sampler s1, mode_default
dcl_sampler s2, mode_default
dcl_resource_texture2d (float,float,float,float) t22
dcl_resource_texture2d (float,float,float,float) t24
dcl_input_ps linear v1.xy
dcl_output o0.xyzw
dcl_temps 8

#line 100 "\\?\C:\Users\admin\Documents\Visual Studio 2010\Projects\Vektoria_2015-02-12a\Vektoria\trunk\VektoriaApp\shaders\source\depthoffield.hlsl"
mov r0.xy, v1.xyxx  // f2CenterCoord<0,1>
mov r0.zw, cb7[5].zzzw  // f2OffsetConversion<0,1>
sample_indexable(texture2d)(float,float,float,float) r1.xyz, v1.xyxx, t22.xyzw, s1  // f3CenterColor<0:Inf,1:Inf,2:Inf>
mov r1.xyz, r1.xyzx  // f3ColorSum<0:Inf,1:Inf,2:Inf>
mov r2.xyz, l(1.000000,1.000000,1.000000,0)  // f3TotalContribution<0: 1f,1: 1f,2: 1f>
sample_indexable(texture2d)(float,float,float,float) r3.xy, v1.xyxx, t24.xyzw, s2  // f2CenterDepthBlur<1:Inf>
mov r3.xy, r3.xyxx  // f2CenterDepthBlur<0:Inf,1:Inf>
mov r3.x, r3.x  // fCenterDepth<0:Inf>

#line 111
mov r3.y, r3.y  // fCenterBlur<0:Inf>

#line 114
lt r1.w, l(0.000000), r3.y
if_nz r1.w

#line 117
  mul r1.w, r3.y, l(0.003500)  // fCoCSize<0:Inf:[0f,1.#INFf]>
  mov r2.w, l(0)  // i<0: 0>
  mov r4.xyz, r1.xyzx  // f3ColorSum<0:NaN:Inf,1:NaN:Inf,2:NaN:Inf>
  mov r5.xyz, r2.xyzx  // f3TotalContribution<0:NaN:Inf,1:NaN:Inf,2:NaN:Inf>
  mov r3.z, r2.w  // i<0>
  loop 
    mov r3.w, r3.z
    ult r4.w, r3.w, l(16)
    breakc_z r4.w
    mov r3.w, icb[r3.w + 0].x  // f2KernelVal<0:[-0.910778f,0.694015f]>
    mul r3.w, r1.w, r3.w  // fOffset<0:NaN:Inf>
    add r6.xy, r0.xyxx, r3.wwww
    add r6.xy, r0.zwzz, r6.xyxx  // f2TapCoord<0:NaN:Inf,1:NaN:Inf>
    sample_l_indexable(texture2d)(float,float,float,float) r7.xyz, r6.xyxx, t22.xyzw, s1, r3.y
    mov r7.xyz, r7.xyzx  // f3TapColor<0:Inf,1:Inf,2:Inf>
    sample_l_indexable(texture2d)(float,float,float,float) r6.xy, r6.xyxx, t24.xyzw, s2, l(0.000000)
    mov r6.xy, r6.xyxx  // f2TapDepthBlur<0:Inf,1:Inf>

#line 132
    lt r3.w, r3.x, r6.x
    movc r3.w, r3.w, l(1.000000), r6.y  // fTabContribution<0:Inf>
    mul r6.xyz, r3.wwww, r7.xyzx
    add r4.xyz, r4.xyzx, r6.xyzx  // f3ColorSum<0:NaN:Inf,1:NaN:Inf,2:NaN:Inf>
    add r5.xyz, r3.wwww, r5.xyzx  // f3TotalContribution<0:NaN:Inf,1:NaN:Inf,2:NaN:Inf>

#line 119
    iadd r3.z, r3.z, l(1)  // i<0>
  endloop 
  mov r1.xyz, r4.xyzx  // f3ColorSum<0:NaN:Inf,1:NaN:Inf,2:NaN:Inf>

#line 114
else 
  mov r5.xyz, l(1.000000,1.000000,1.000000,0)  // f3TotalContribution<0: 1f,1: 1f,2: 1f>
endif 

#line 139
div r0.xyz, r1.xyzx, r5.xyzx  // f3FinalColor<0:NaN:Inf,1:NaN:Inf,2:NaN:Inf>
mov o0.xyz, r0.xyzx  // PS_DepthofField<0:NaN:Inf,1:NaN:Inf,2:NaN:Inf>
mov o0.w, l(1.000000)  // PS_DepthofField<3: 1f>
ret 
// Approximately 43 instruction slots used
