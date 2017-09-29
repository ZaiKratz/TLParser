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

	double Getlat() const
	{
		 return this->lat;
	}

	double GetLong() const
	{
		 return this->Long;
	}

private:
	double lat;
	 double Long;
};
} //end namespace block
