/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#ifndef _OVERHEAD_CONTROLLER_H
#define _OVERHEAD_CONTROLLER_H

#include "CameraController.h"


class COverheadController : public CCameraController
{
public:
	COverheadController();

	const std::string GetName() const { return "ta"; }

	void KeyMove(float3 move);
	void MousePress(int x, int y, int button) { /* empty */ }
	void MouseRelease(int x, int y, int button) { /* empty */ }
	void MouseMove(float3 move);
	void ScreenEdgeMove(float3 move);
	void MouseWheelMove(float move);

	void Update();
	float3 GetPos() const;
	void SetPos(const float3& newPos);

	float3 SwitchFrom() const;
	void SwitchTo(bool showText);

	void GetState(StateMap& sm) const;
	bool SetState(const StateMap& sm);

	bool flipped;

private:
	void UpdateVectors();

private:
	float middleClickScrollSpeed;
	float height;
	float oldAltHeight;
	bool changeAltHeight;
	float maxHeight;
	float tiltSpeed;
	float angle;

	static constexpr float DEFAULT_ANGLE = 0.464f;
};

#endif // _OVERHEAD_CONTROLLER_H
