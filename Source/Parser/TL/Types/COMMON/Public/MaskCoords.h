#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class MaskCoords : public TLBaseObject
{
public:
	MaskCoords();
	MaskCoords(int32 n, double x, double y, double zoom);

	~MaskCoords();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	int32 Getn() const
	{
		 return this->n;
	}

	double Getx() const
	{
		 return this->x;
	}

	double Gety() const
	{
		 return this->y;
	}

	double Getzoom() const
	{
		 return this->zoom;
	}

private:
	int32 n;
	 double x;
	 double y;
	 double zoom;
};
} //end namespace block
