#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/GeoPoint.h"

//begin namespace block
namespace COMMON
{
class GeoPointEmpty : public TLBaseObject
{
public:
	GeoPointEmpty();
	~GeoPointEmpty();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
};
} //end namespace block