
#ifndef _TRACING_CATEGORIES_H
#define _TRACING_CATEGORIES_H
#pragma once


/** @file
 *  @ingroup tracing
 *
 *  This file contains the tracing categories. In order to add a new category you must add the instance in categories.cpp,
 *  declare the @c extern reference here and then use it with the appropriate functions wherever you want to trace.
 */

namespace tracing {

class Category {
	const char* _name;
	bool _graphics_category;
 public:
	Category(const char* name, bool is_graphics);

	const char* getName() const;

	bool usesGPUCounter() const;
};

extern Category LuaOnFrame;

extern Category DrawSceneTexture;
extern Category UpdateDistortion;

extern Category Tonemapping;
extern Category Bloom;
extern Category BloomBrightPass;
extern Category BloomIterationStep;
extern Category BloomCompositeStep;
extern Category FXAA;
extern Category Lightshafts;
extern Category DrawPostEffects;

extern Category RenderBatchItem;
extern Category RenderBatchBuffer;
extern Category LoadBatchingBuffers;

extern Category SortColliders;
extern Category FindOverlapColliders;
extern Category CollidePair;

extern Category WeaponPostMove;
extern Category ShipPostMove;
extern Category FireballPostMove;
extern Category DebrisPostMove;
extern Category AsteroidPostMove;
extern Category PreMove;
extern Category Physics;
extern Category PostMove;
extern Category CollisionDetection;

extern Category RenderBuffer;

extern Category QueueRender;
extern Category SubmitDraws;
extern Category ApplyLights;
extern Category DrawEffects;

extern Category RepeatingEvents;
extern Category NonrepeatingEvents;

extern Category ParticlesRenderAll;
extern Category ParticlesMoveAll;

extern Category TrailDraw;

extern Category EnvironmentMapping;
extern Category BuildShadowMap;
extern Category RenderScene;
extern Category RenderTrails;
extern Category MoveObjects;
extern Category ProcessParticleEffects;
extern Category TrailsMoveAll;
extern Category Simulation;
extern Category RenderMainFrame;
extern Category MainFrame;
extern Category PageFlip;

extern Category CutsceneStep;
extern Category CutsceneDrawVideoFrame;
extern Category CutsceneProcessDecoder;
extern Category CutsceneProcessVideoData;
extern Category CutsceneProcessAudioData;

extern Category CutsceneFFmpegVideoDecoder;
extern Category CutsceneFFmpegAudioDecoder;
}

#endif // _TRACING_CATEGORIES_H
