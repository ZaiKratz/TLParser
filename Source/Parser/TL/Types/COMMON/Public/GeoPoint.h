#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class GeoPoint : public TLBaseObject
{
public:
	GeoPoint();
	GeoPoint(double Long, double lat);

	~GeoPoint();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	double GetLong() const
	{
		 return this->Long;
	}

	double Getlat() const
	{
		 return this->lat;
	}

private:
	double Long;
	 double lat;
};
} //end namespace block
