#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class InputGeoPoint : public TLBaseObject
{
public:
	InputGeoPoint();
	InputGeoPoint(double lat, double Long);

	~InputGeoPoint();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	double lat;
	 double Long;
};
} //end namespace block
